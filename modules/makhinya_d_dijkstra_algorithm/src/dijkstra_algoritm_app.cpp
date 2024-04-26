// Copyright 2024 Safarov Nurlan
#include "include/dijkstra_algoritm_app.h"
#include <cstring>
#include <sstream>

bool DijkstraAlgorithmApp::validate(int argc, char* argv[]) {
  if (argc == 1 || std::strcmp(argv[1], "--help") == 0) {
      help(argv[0]);
      return false;
  }

  // Check if the number of arguments is correct
  if (argc < 4) {
      help(argv[0], "Insufficient arguments provided.");
      return false;
  }

  // Check if the vertex arguments are valid integers
  for (int i = 1; i < argc - 1; ++i) {
      try {
        int vertex = std::stoi(argv[i]);
        if (vertex < 0) {
            help(argv[0], "Vertex arguments must be non-negative integers.");
            return false;
        }
      } catch (const std::invalid_argument& e) {
          help(argv[0], "Invalid input: vertex arguments must be integers.");
          return false;
      }
  }

  return true;
}

void DijkstraAlgorithmApp::help(const char *appName, const char *msg) {
  std::stringstream message;

  message << "This is an application for using Dijkstra's ";
  message << "algorithm to find the shortest path in a graph.\n";

  DijkstraAlgorithmMsg = message.str();
}

std::string DijkstraAlgorithmApp::dijkstra_algorithm_application(int argc,
                                                          char* argv[]) {
  if (validate(argc, argv)) {
      // Parse arguments
      uint32_t start_vertex = std::stoi(argv[1]);
      uint32_t end_vertex = std::stoi(argv[2]);

      // Add edges to the graph
      for (int i = 3; i < argc - 1; i += 3) {
          uint32_t from_vertex = std::stoi(argv[i]);
          uint32_t to_vertex = std::stoi(argv[i + 1]);
          uint64_t weight = std::stoull(argv[i + 2]);
          obj.add_directed_edge(from_vertex, to_vertex, weight);
      }

      // Find shortest path
      uint64_t result = obj.find_shortest_path(start_vertex, end_vertex);

      // Return result
      std::string output = "Shortest path length: " + std::to_string(result);
      return output;
  } else {
    return "Incorrect program arguments. Try again.";
  }

  return DijkstraAlgorithmMsg;
}
