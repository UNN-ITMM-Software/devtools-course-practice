// Copyright 2024 Kiselev Igor

#include "include/Billinear_interpolation.h"

BillinearInterpolation::BillinearInterpolation(
    std::vector<std::vector<Color>> sr) {
  std::size_t n = sr.size();
  std::size_t m = sr[0].size();
  source =
      std::vector<std::vector<Color>>(n, std::vector<Color>(m, Color(0, 0, 0)));
  for (std::size_t i = 0; i < n; i++) {
    for (std::size_t j = 0; j < m; j++) {
      source[i][j] = sr[i][j];
    }
  }
}

BillinearInterpolation::BillinearInterpolation(
    const BillinearInterpolation &bi) {
  std::size_t n = bi.source.size();
  std::size_t m = bi.source[0].size();
  source =
      std::vector<std::vector<Color>>(n, std::vector<Color>(m, Color(0, 0, 0)));
  for (std::size_t i = 0; i < n; i++) {
    for (std::size_t j = 0; j < m; j++) {
      source[i][j] = bi.source[i][j];
    }
  }
}

BillinearInterpolation::BillinearInterpolation(BillinearInterpolation &&bi) {
  source = std::move(bi.source);
}

BillinearInterpolation &
BillinearInterpolation::operator=(BillinearInterpolation &&bi) {
  if (&bi != this) {
    source = std::move(bi.source);
  }
  return *this;
}

BillinearInterpolation &
BillinearInterpolation::operator=(const BillinearInterpolation &bi) {
  if (&bi != this) {
    source = bi.source;
  }
  return *this;
}

std::vector<std::vector<Color>> BillinearInterpolation::twoCore() {
  std::size_t n = source.size();
  std::size_t m = source[0].size();
  std::vector<std::vector<Color>> ans =
      std::vector<std::vector<Color>>(n, std::vector<Color>(m, Color(0, 0, 0)));
  n--;
  m--;
  for (std::size_t i = 0; i < n; i++) {
    for (std::size_t j = 0; j < m; j++) {
      Color res = Calculation(i, j, i + 1, j + 1);
      ans[i][j] = res;
    }
  }
  for (std::size_t i = 0; i < n; i++) {
    ans[i][m] = source[i][m];
  }
  for (std::size_t i = 0; i < m; i++) {
    ans[n][i] = source[n][i];
  }
  return ans;
}

std::vector<std::vector<Color>> BillinearInterpolation::threeCore() {
  std::size_t n = source.size();
  std::size_t m = source[0].size();
  std::vector<std::vector<Color>> ans =
      std::vector<std::vector<Color>>(n, std::vector<Color>(m, Color(0, 0, 0)));
  n--;
  m--;
  for (std::size_t i = 1; i < n; i++) {
    for (std::size_t j = 1; j < m; j++) {
      Color res = Calculation(i - 1, j - 1, i + 1, j + 1);
      ans[i][j] = res;
    }
  }
  for (std::size_t i = 0; i < n; i++) {
    ans[i][m] = source[i][m];
    ans[i][0] = source[i][0];
  }
  for (std::size_t i = 0; i < m; i++) {
    ans[n][i] = source[n][i];
    ans[0][i] = source[0][i];
  }
  return ans;
}

Color BillinearInterpolation::Calculation(std::size_t x1, std::size_t y1,
                                          std::size_t x2, std::size_t y2) {
  Color lu = source[x1][y1];
  Color ru = source[x2][y1];
  Color ld = source[x1][y2];
  Color rd = source[x2][y2];
  Color h1 = Color(0, 0, 0);
  Color h2 = Color(0, 0, 0);

  h1.setColor(lu.getR() + (ru.getR() - lu.getR()) * (x2 - x1) / (2 * x2 - x1),
              lu.getG() + (ru.getG() - lu.getG()) * (x2 - x1) / (2 * x2 - x1),
              lu.getB() + (ru.getB() - lu.getB()) * (x2 - x1) / (2 * x2 - x1));

  h2.setColor(ld.getR() + (rd.getR() - ld.getR()) * (x2 - x1) / (2 * x2 - x1),
              ld.getG() + (rd.getG() - ld.getG()) * (x2 - x1) / (2 * x2 - x1),
              ld.getB() + (rd.getB() - ld.getB()) * (x2 - x1) / (2 * x2 - x1));

  Color ans = Color(0, 0, 0);
  ans.setColor(h1.getR() + (h2.getR() - h1.getR()) * (y2 - y1) / (2 * y2 - y1),
               h1.getG() + (h2.getG() - h1.getG()) * (y2 - y1) / (2 * y2 - y1),
               h1.getB() + (h2.getB() - h1.getB()) * (y2 - y1) / (2 * y2 - y1));
  return ans;
}

int BillinearInterpolation::getSize() { return source.size(); }
