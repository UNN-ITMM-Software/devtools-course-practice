// Copyright 2024 Safarov Nurlan
#include "include/dijkstra_algoritm_app.h";

#include <sstream>
#include <cstring>

bool DijkstraAlgorithmApp::validate(int argc, char* argv[]) {
    if (argc == 1 || std::strcmp(argv[1], "--help") == 0 || std::strcmp(argv[1], "-h") == 0) {
        help(argv[0], 0);
        return false;
    }

    int check = argc - 3;
    if (check % 3 != 0) {
        help(argv[0], -1);
        return false;
    }

    for (int i = 1; i < argc; ++i) {
        int v = atoi(argv[i]);
        if (v < 0 || v >= 20) {
            help(argv[0], -1);
            return false;
        }
    }

    return true;
}

void DijkstraAlgorithmApp::help(const char* application, int check_code) {
  std::ostringstream help_msg;

  if (check_code != 0) {
    help_msg << "Incorrect program arguments. Try again or refer to "
    << "the help for this program by entering the argument \"--help\" or \"-h\"";
  } else {
    help_msg << "Usage  " << application
             << " to work with Dijkstra's algorithm to find"
             << "the shortest path from the starting vertex to the required one. ";

    help_msg << "Example: " << application
             << " 0 1 0 3 5 0 1 8, where the first argument is the "
             << "initial vertex and the second argument is the final one. Each "
             << "of the following 3 arguments defines the edges "
             << "of a weighted digraph" << std::endl;
  }

  dijkstra_algorithm_msg = help_msg.str();
}

std::string DijkstraAlgorithmApp::dijkstra_algorithm_application(int argc, char* argv[]) {
  if (!validate(argc, argv)) {
    return dijkstra_algorithm_msg;
  }

  uint32_t start_vertex = atoi(argv[1]);
  uint32_t end_vertex = atoi(argv[2]);

  for (int i = 3; i < argc - 1; i += 3) {
    uint32_t from_vertex = atoi(argv[i]);
    uint32_t to_vertex = atoi(argv[i + 1]);
    uint64_t weight = std::stoull(argv[i + 2]);
    obj.add_directed_edge(from_vertex, to_vertex, weight);
  }

  uint64_t result = obj.find_shortest_path(start_vertex, end_vertex);

  std::string output;

  if (result == std::numeric_limits<uint64_t>::max()) {
    output = "There is no path between the vertices you specified.";
    return output;
  }

  output = "Shortest path length: " + std::to_string(result);

  return output;
}
