// Copyright 2024 Andrey Karagodin

#include "include/figure_surface_app.h"

#include "include/figure_surface.h"

bool FigureSurfaceApp::validate(const int argc, char* argv[]) {
  if (argc < 2) {
    help(argv[0]);
    return false;
  }
  if (std::strcmp(argv[1], "--help") == 0) {
    help(argv[0]);
    return false;
  }
  if (std::strcmp(argv[1], "--shapes") == 0) {
    shapes();
    return false;
  }
  return true;
}

void FigureSurfaceApp::shapes(const char** msg) {
  std::stringstream ss;
  if (msg) ss << "Error: " << msg << '\n';
  ss << "List of shapes: \n";
  ss << " 1 : Parallepiped. Requires 3 arguments (e.g: 1 10 12 14)\n";
  ss << " 2 : Cylinder Side. Requires 2 arguments (e.g: 2 10 12)\n";
  ss << " 3 : Cylinder Full. Requires 2 arguments (e.g: 3 10 12)\n";
  ss << " 4 : Cone Side. Requires 2 arguments (e.g: 4 10 12)\n";
  ss << " 5 : Cone Full. Requires 2 arguments (e.g: 5 10 12)\n";
  ss << " 6 : Sphere. Requires 1 argument (e.g: 6 10)\n";
  message_ = ss.str();
}

void FigureSurfaceApp::help(const char* appName, const char* msg) {
  std::stringstream ss;

  if (msg) ss << "Error: " << msg << '\n';

  ss << "Calculator for calculating the surface area of geometric figures\n";
  ss << "Provide an argument for shape and its parameters\n";
  ss << "Example usage:\n";
  ss << " $ " << appName << " 1 10 12 14 \n";
  ss << " $ " << appName << " 2 40 23 \n";
  ss << " $ " << appName << " 5 15 20 \n";
  ss << " $ " << appName << " 6 30 \n";

  ss << "For getting list of shapes run with --shapes\n";

  message_ = ss.str();
}

std::string FigureSurfaceApp::getOperationType(const char* arg) {
  std::string op;
  if (std::strcmp(arg, "1") == 0) {
    op = "1";
  } else if (strcmp(arg, "2") == 0) {
    op = "2";
  } else if (strcmp(arg, "3") == 0) {
    op = "3";
  } else if (strcmp(arg, "4") == 0) {
    op = "4";
  } else if (strcmp(arg, "5") == 0) {
    op = "5";
  } else if (strcmp(arg, "6") == 0) {
    op = "6";
  } else {
    throw std::logic_error("Wrong operation format!");
  }
  return op;
}

std::string FigureSurfaceApp::operator()(const int argc, char* argv[]) {
  std::string operation;
  std::ostringstream stream;

  if (!validate(argc, argv)) {
    return message_;
  }
  try {
    operation = getOperationType(argv[1]);
  } catch (const std::exception& e) {
    return e.what();
  }

  try {
    if (operation == "1") {
      if (argc != 5) {
        help(argv[0], "ERROR: Should be 4 arguments.\n\n");
        return message_;
      }
      const double a = std::stod(argv[2]);
      const double b = std::stod(argv[3]);
      const double c = std::stod(argv[4]);
      stream << figureSurface.fnCalculateSurfaceParallelepiped(a, b, c);
    } else if (operation == "2") {
      if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return message_;
      }
      const double r = std::stod(argv[2]);
      const double h = std::stod(argv[3]);
      stream << figureSurface.fnCalculateSurfaceCylinderSide(r, h);
    } else if (operation == "3") {
      if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return message_;
      }
      const double r = std::stod(argv[2]);
      const double h = std::stod(argv[3]);
      stream << figureSurface.fnCalculateSurfaceCylinderFull(r, h);
    } else if (operation == "4") {
      if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return message_;
      }
      const double r = std::stod(argv[2]);
      const double l = std::stod(argv[3]);
      stream << figureSurface.fnCalculateSurfaceConeSide(r, l);
    } else if (operation == "5") {
      if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return message_;
      }
      const double r = std::stod(argv[2]);
      const double l = std::stod(argv[3]);
      stream << figureSurface.fnCalculateSurfaceConeFull(r, l);
    } else if (operation == "6") {
      if (argc != 3) {
        help(argv[0], "ERROR: Should be 2 arguments.\n\n");
        return message_;
      }
      const double r = std::stod(argv[2]);
      stream << figureSurface.fnCalculateSurfaceSphere(r);
    }
  } catch (const std::exception& e) {
    return e.what();
  }
  message_ = stream.str();
  return message_;
}
