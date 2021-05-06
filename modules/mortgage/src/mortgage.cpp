// Copyright 2021 Schekotilova Julia

#include "include/mortgage.h"

mortgage::mortgage(int _cost, int _downPayment, int _creditTerm,
  double _interestRate) : cost(_cost), downPayment(_downPayment),
  creditTerm(_creditTerm), interestRate(_interestRate) {}

int mortgage::getCost() const {
  return cost;
}

int mortgage::getDownPayment() const {
  return downPayment;
}

int mortgage::getCreditTerm() const {
  return creditTerm;
}

double mortgage::getInterestRate() const {
  return interestRate;
}

int mortgage::getTotalFee() const {
  return totalFee;
}

double mortgage::getMonthlyRate() const {
  return monthlyRate;
}

int mortgage::getMonthlyPayment() const {
  return monthlyPayment;
}

void mortgage::setCost(const int& cost) {
  this->cost = cost;
}

void mortgage::setDownPayment(const int& downPayment) {
  this->downPayment = downPayment;
}

void mortgage::setCreditTerm(const int& creditTerm) {
  this->creditTerm = creditTerm;
}

void mortgage::setInterestRate(const double& interestRate) {
  this->interestRate = interestRate;
}

void mortgage::calc() {
  double tmp;
  cost -= downPayment;
  creditTerm *= 12;
  monthlyRate = ((interestRate) / 100) / 12;
  tmp = pow((1 + monthlyRate), creditTerm);
  monthlyPayment = cost * monthlyRate * (tmp / (tmp - 1));
  totalFee = monthlyPayment * creditTerm;
}
