// Copyright 2021 Kiseleva Anastasia

#ifndef MODULES_3D_SHAPES_VOLUME_INCLUDE_VOLUME_APP_H_
#define MODULES_3D_SHAPES_VOLUME_INCLUDE_VOLUME_APP_H_

#include <string>
#include "include/3d_shapes_volume.h"

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
};

#endif  // MODULES_3D_SHAPES_VOLUME_INCLUDE_VOLUME_APP_H_
