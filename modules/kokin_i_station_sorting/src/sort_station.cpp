// Copyright 2024 Kokin Ivan

#include "../include/sort_station.h"
#include <math.h>
#include <cctype>
#include <stack>

double SortStationDerived::evaluateFunction(const std::string& expression) {
    std::string postfix = convertToPostfix(expression);
    return evaluatePostfixExpression(postfix);
}

double SortStationDerived::evaluatePostfixExpression(
        const std::string& postfix) {
    std::stack<double> stack;
    for (char c : postfix) {
        if (isdigit(c)) {
            stack.push(static_cast<double>(c - '0'));
        } else {
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            stack.push(applyOperator(a, b, c));
        }
    }
    return stack.top();
}

double SortStationDerived::applyOperator(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return std::pow(a, b);
        default: return 0.0;
    }
}

std::string SortStationDerived::convertToPostfix(
        const std::string& expression) {
    std::string postfix;
    std::stack<char> stack;
    for (char c : expression) {
        if (isdigit(c)) {
            postfix += c;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            if (!stack.empty() && stack.top() == '(') {
                stack.pop();
            }
        } else {
            while (!stack.empty() && precedence[stack.top()] >= precedence[c]) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }
    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }
    return postfix;
}
