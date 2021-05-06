// Copyright 2021 Schekotilova Julia

#ifndef MODULES_MORTGAGE_INCLUDE_MORTGAGE_H_
#define MODULES_MORTGAGE_INCLUDE_MORTGAGE_H_

#include <cmath>

class mortgage {
  int cost;
  int downPayment;
  int creditTerm;
  double interestRate;
  int totalFee;
  double monthlyPayment;
  double monthlyRate;
 public:
  mortgage(int cost, int downPayment, int creditTerm, double interestRate);
  void calc();
  void setCost(const int& cost);
  void setDownPayment(const int& cost);
  void setCreditTerm(const int& cost);
  void setInterestRate(const double& cost);
  int getCost() const;
  int getDownPayment() const;
  int getCreditTerm() const;
  double getInterestRate() const;
  int getTotalFee() const;
  double getMonthlyRate() const;
  int getMonthlyPayment() const;
};

#endif  // MODULES_MORTGAGE_INCLUDE_MORTGAGE_H_
