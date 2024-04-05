// Copyright 2024 Kiselev Igor

#include "include/Billinear_interpolation.h"

BillinearInterpolation::BillinearInterpolation
(std::vector<std::vector<Color>> sr) {
    size_t n = sr.size();
    size_t m = sr[0].size();
    source = std::vector<std::vector<Color>>
        (n, std::vector<Color>(m, Color(0, 0, 0)));
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            source[i][j] = sr[i][j];
        }
    }
}

BillinearInterpolation::BillinearInterpolation
(const BillinearInterpolation& bi) {
    size_t n = bi.source.size();
    size_t m = bi.source[0].size();
    source = std::vector<std::vector<Color>>(n, std::vector<Color>
        (m, Color(0, 0, 0)));
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            source[i][j] = bi.source[i][j];
        }
    }
}

std::vector<std::vector<Color>> BillinearInterpolation::twoCore() {
    size_t n = source.size();
    size_t m = source[0].size();
    n--;
    m--;
    std::vector<std::vector<Color>> ans = std::vector<std::vector<Color>>
        (n, std::vector<Color>(m, Color(0, 0, 0)));
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            Color res = Calculation(i, j, i + 1, j + 1);
            ans[i][j] = res;
        }
    }
    return ans;
}

std::vector<std::vector<Color>> BillinearInterpolation::threeCore() {
    size_t n = source.size();
    size_t m = source[0].size();
    n--;
    m--;
    std::vector<std::vector<Color>> ans = std::vector<std::vector<Color>>
        (n - 1, std::vector<Color>(m - 1, Color(0, 0, 0)));
    for (size_t i = 1; i < n; i++) {
        for (size_t j = 1; j < m; j++) {
            Color res = Calculation(i - 1, j - 1, i + 1, j + 1);
            ans[i - 1][j - 1] = res;
        }
    }
    return ans;
}

Color BillinearInterpolation::
    Calculation(size_t x1, size_t y1, size_t x2, size_t y2) {
    Color lu = source[x1][y1];  // Left Up
    Color ru = source[x2][y1];  // Right Up
    Color ld = source[x1][y2];  // Left Down
    Color rd = source[x2][y2];  // Right Down
    Color h1 = Color(0, 0, 0);  // Helper 1
    Color h2 = Color(0, 0, 0);  // Helper 2

    h1.setR(lu.getR() + (ru.getR() - lu.getR()) * (x2 - x1) / (2 * x2 - x1));
    h1.setG(lu.getG() + (ru.getG() - lu.getG()) * (x2 - x1) / (2 * x2 - x1));
    h1.setB(lu.getB() + (ru.getB() - lu.getB()) * (x2 - x1) / (2 * x2 - x1));

    h2.setR(ld.getR() + (rd.getR() - ld.getR()) * (x2 - x1) / (2 * x2 - x1));
    h2.setG(ld.getG() + (rd.getG() - ld.getG()) * (x2 - x1) / (2 * x2 - x1));
    h2.setB(ld.getB() + (rd.getB() - ld.getB()) * (x2 - x1) / (2 * x2 - x1));

    Color ans = Color(0, 0, 0);
    ans.setR(h1.getR() + (h2.getR() - h1.getR()) * (y2 - y1) / (2 * y2 - y1));
    ans.setG(h1.getG() + (h2.getG() - h1.getG()) * (y2 - y1) / (2 * y2 - y1));
    ans.setB(h1.getB() + (h2.getB() - h1.getB()) * (y2 - y1) / (2 * y2 - y1));
    return ans;
}
