// Copyright 2017 Korniakov Kirill

#ifndef MODULES_COMPLEX_NUMBER_INCLUDE_COMPLEX_CALCULATOR_H_
#define MODULES_COMPLEX_NUMBER_INCLUDE_COMPLEX_CALCULATOR_H_

#include <string>

/** @defgroup complex-number Complex Numbers Algebra
  @{
    This module contains:
        - A definition of complex number as a class
        - Calculator class which performs the calculations
  @}
*/

//! @addtogroup complex-number
//! @{

/**
 * @brief Class for complex numbers algebra
 */
class ComplexCalculator {
 public:
    ComplexCalculator();

    /**
     * @brief Functor override
     * @param[in] argc Nuber of comand line arguments
     * @param[in] argv Command line arguments
     * @return Output expression
     */
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double z1_real;
        double z1_imaginary;
        double z2_real;
        double z2_imaginary;
        char operation;
    } Arguments;
};

//! @}

#endif  // MODULES_COMPLEX_NUMBER_INCLUDE_COMPLEX_CALCULATOR_H_
