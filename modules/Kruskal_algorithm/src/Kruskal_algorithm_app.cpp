// Copyright 2021 Gushchin Artem

#include "include/Kruskal_algorithm.h"
#include "include/Kruskal_algorithm_app.h"

#include <string>
#include <sstream>
#include <tuple>
#include <vector>

KruskalAlgorithm::KruskalAlgorithm() : message_("") {}

void KruskalAlgorithm::help(
        const std::string& appname,
        const std::string& message) {
    message_ =
        std::string(message) +
          "This is a Kruskal algorithm application.\n\n"
          "Please provide arguments in the following format:\n\n"

          "  $ " + appname + " <number_of_vertex> "
          "<edge_1_x> <edge_1_y> <edge_1_weight> ... "
          "<edge_N_x> <edge_N_y> <edge_N_weight> \n\n"

          "Where all arguments are integer numbers, "
          "N is number of edges\n";
}

bool KruskalAlgorithm::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if ((argc - 2) % 3 != 0) {
        help(argv[0], "ERROR: Incorrect arguments count.\n\n");
        return false;
    }
    return true;
}

double parseInt(const std::string& arg) {
    return std::stoi(arg);
}

std::string KruskalAlgorithm::operator()(int argc, const char** argv) {
    using weightedEdge = std::tuple<int, int, int>;
    std::vector<weightedEdge> edges;
    int numberOfVertices = 0;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    try {
        numberOfVertices = parseInt(argv[1]);

        for (int i = 2; i < argc; i += 3) {
            weightedEdge parsedEdge = { parseInt(argv[i]),
                                        parseInt(argv[i + 1]),
                                        parseInt(argv[i + 2]) };

            edges.push_back(std::move(parsedEdge));
        }
    }
    catch(const std::invalid_argument& ia) {
        return "Cannot parse arguments to integer type";
    }

    Graph g(numberOfVertices);

    for (const auto& currEdge : edges)
        g.addEdge(std::get<0>(currEdge), std::get<1>(currEdge),
                  std::get<2>(currEdge));

    g.Kruskal();

    std::ostringstream stream;
    auto MST = g.get_MST();

    for (int i = 0; i < static_cast<int>(MST.size()); ++i)
        stream << "Edge: (" << MST[i].second.first << ", "
               << MST[i].second.second << "), weight: "
               << MST[i].first << std::endl;

    message_ = stream.str();
    return message_;
}
