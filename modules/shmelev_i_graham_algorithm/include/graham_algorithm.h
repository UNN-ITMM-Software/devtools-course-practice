// Copyright 2024 Shmelev Ivan

#ifndef MODULES_SHMELEV_I_GRAHAM_ALGORITHM_INCLUDE_GRAHAM_ALGORITHM_H_
#define MODULES_SHMELEV_I_GRAHAM_ALGORITHM_INCLUDE_GRAHAM_ALGORITHM_H_



class GrahamScan {
 public:
    static std::vector<std::pair<double, double>> convexHull
                        (std::vector<std::pair<double, double>>& points);
 private:
    static int orientation(std::pair<double, double>& p,
             std::pair<double, double>& q, std::pair<double, double>& r);
    static std::vector<std::pair<double, double>> sortPoints
                        (std::vector<std::pair<double, double>>& points);
};

#endif  // MODULES_SHMELEV_I_GRAHAM_ALGORITHM_INCLUDE_GRAHAM_ALGORITHM_H_
