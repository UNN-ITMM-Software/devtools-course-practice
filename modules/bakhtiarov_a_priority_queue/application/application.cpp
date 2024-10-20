// Copyright 2024 Fedotov Kirill

#include <iostream>

#include "include/priority_queue_app.h"

int main(int argc, char* argv[]) {
  PriorityQueueApplication application;
  std::cout << application.ProcessQueueOperations(argc, argv) << std::endl;
  return 0;
}
