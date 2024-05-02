// Copyright 2024 Kulaev Zhenya

#include "include/increasing_cont.h"

void streaching(std::vector<int>& image, int old_min,
    int old_max, int new_min, int new_max) {
    if (old_min == old_max || image.empty()) return;
    for (auto& pix : image) {
        pix = (pix - old_min) * (new_max - new_min) /
                (old_max - old_min) + new_min;
    }
}

void increase_contrast(std::vector<int>& image, size_t m, size_t n,
    int new_min, int new_max) {
    if (image.empty()) return;

    int global_min = *std::min_element(image.begin(), image.end());
    int global_max = *std::max_element(image.begin(), image.end());

    streaching(image, global_min, global_max, new_min, new_max);
}
