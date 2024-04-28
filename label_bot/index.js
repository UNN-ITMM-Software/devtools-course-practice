const http = require('http');
const { Octokit } = require("@octokit/rest");
const { createAppAuth } = require("@octokit/auth-app");

const port = process.env.PORT || 80;

const owner = "UNN-ITMM-Software";
const repo = "devtools-course-practice";

const octokit = new Octokit({
    authStrategy: createAppAuth,
    auth: {
      appId: 857664,
      privateKey: process.env.PRIVATE_KEY,
      installationId: 48548365,
    },
});

async function putLabNumber(pull_id) {
    const pullInfo = await octokit.rest.pulls.get({
        owner: owner,
        repo: repo,
        pull_number: pull_id,
    });

    let task_id = pullInfo.data.title.match(/\d+/);
    if (!task_id)
        return;

    task_id = parseInt(task_id[0]);
    if (task_id < 1 || task_id > 3)
        return;

    const pullFiles = await octokit.rest.pulls.listFiles({
        owner: owner,
        repo: repo,
        pull_number: pull_id,
    });

    if (pullFiles.data.length == 0 ||
        pullFiles.data.length == 1 && pullFiles.data[0].filename == "lab-guide/topics.md") {
        return;
    }
    octokit.rest.issues.addLabels({
        owner: owner,
        repo: repo,
        issue_number: pull_id,
        labels: ["lab " + task_id],
    });
    if (task_id == "2" && new Date(pullInfo.data.created_at) >= new Date("2024-04-15T08:00:00Z") ||
        task_id == "3" && new Date(pullInfo.data.created_at) >= new Date("2024-05-02T08:00:00Z")) {
        octokit.rest.issues.addLabels({
            owner: owner,
            repo: repo,
            issue_number: pull_id,
            labels: ["delayed"],
        });
    }
}

async function checkReadiness(pull_id) {
    // Count number of unique approvers
    const result = await octokit.rest.pulls.listReviews({
        owner: owner,
        repo: repo,
        pull_number: pull_id,
    });

    let approvers = new Set();
    result.data.forEach(entry => {
        if (entry.state == 'APPROVED') {
            approvers.add(entry.user.login);
        }
    });

    if (approvers.size < 2)
        return;

    // Put a readiness label
    octokit.rest.issues.addLabels({
        owner: owner,
        repo: repo,
        issue_number: pull_id,
        labels: ["Ready for merge"],
    });
}

// Put labels to existing pull requests
// installationOctokit.paginate(installationOctokit.rest.pulls.list, {
//     owner: owner,
//     repo: repo,
//     state: "all",
//     sort: "created",
//     direction: "asc",
// })
// .then(pulls => {
//     pulls.forEach(pull => {
//         putLabNumber(pull.number);
//     });
// });

http.createServer(function (req, res) {
    res.setHeader('Access-Control-Allow-Origin', '*');
    if (req.method == "GET") {
        if (req.url !== "/names") {
            res.end();
            return;
        }

        let real_names = {};
        octokit.paginate(octokit.rest.repos.listCommits, {
            owner: owner,
            repo: repo,
            path: "lab-guide/topics.md",
        })
        .then(commits => {
            let processed = 0;
            commits.forEach(commit => {
                octokit.rest.repos.getCommit({
                    owner: owner,
                    repo: repo,
                    ref: commit.sha,
                })
                .then(commit_data => {
                    processed += 1;
                    commit_data.data.files.forEach(file => {
                        if (file.filename == "lab-guide/topics.md") {
                            let matched = file.patch.match(/\-\|.*\|\w*\|.*\|\n\+\|.*\|(.+)\|.*\|/);
                            if (!matched || matched.length < 2)
                                return;
                            real_names[commit_data.data.author.login] = matched[1].trim();
                        }
                    });
                    if (processed == commits.length) {
                        res.statusCode = 200;
                        res.setHeader('Content-Type', 'application/json');
                        res.write(JSON.stringify(real_names));
                        res.end();
                    }
                });
            })
        });
        return;
    }

    // Get JSON data for POST request
    let body = '';
    req.on('data', chunk => {
        body += chunk.toString();
    });
    req.on('end', () => {
        try {
            body = JSON.parse(body);
            putLabNumber(body.pull_request.number);
            if (body.review.state == "approved") {
                checkReadiness(body.pull_request.number);
            }
        } catch(error) {
            console.log(body);
            console.log(error.message);
        }
        res.end();
    });
}).listen(port);
