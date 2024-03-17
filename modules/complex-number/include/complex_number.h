// Copyright 2017 Korniakov Kirill

#ifndef MODULES_COMPLEX_NUMBER_INCLUDE_COMPLEX_NUMBER_H_
#define MODULES_COMPLEX_NUMBER_INCLUDE_COMPLEX_NUMBER_H_

//! @addtogroup complex-number
//! @{

/**
 * @brief A class which represents a single complex number
 *
 * Complex number is a pair of values @p x and @p y named as Real and Imaginary
 * parts.
 */
class ComplexNumber {
 public:
    ComplexNumber();

    /**
     * @brief Constructor
     * @param[in] real Real part of complex number
     * @param[in] imag Imaginary part of complex number
     */
    ComplexNumber(const double real, const double imag);

    /**
     * @brief Copy constructor
     * @param[in] z Copy of complex number
     */
    ComplexNumber(const ComplexNumber& z);

    /**
     * @brief Assign operator
     * @param[in] z Copy of complex number
     * @return Current object with changed values
     */
    ComplexNumber& operator=(const ComplexNumber& z);

    /**
     * @brief Getter for a real part of complex number
     * @return Real part
     * @see getIm
     */
    double getRe() const;

    /**
     * @brief Getter for an imaginary part of complex number
     * @return Imaginary part
     * @see getRe
     */
    double getIm() const;

    /**
     * @brief Setter for a real part of complex number
     * @param[in] real A new real part
     * @see setIm
     */
    void setRe(const double real);

    /**
     * @brief Setter for an imaginary part of complex number
     * @param[in] imag A new imaginary part
     * @see setRe
     */
    void setIm(const double imag);

    /**
     * @brief Sum operator
     * @param[in] z Second operand
     * @return Result of operation
     */
    ComplexNumber operator + (const ComplexNumber& z) const;

    /**
     * @brief Subtract operator
     * @param[in] z Second operand
     * @return Result of operation
     */
    ComplexNumber operator - (const ComplexNumber& z) const;

    /**
     * @brief Multiply operator
     * @param[in] z Second operand
     * @return Result of operation
     */
    ComplexNumber operator * (const ComplexNumber& z) const;

    /**
     * @brief Divide operator
     * @param[in] z Second operand
     * @return Result of operation
     */
    ComplexNumber operator / (const ComplexNumber& z) const;

    /**
     * @brief Comparison operator
     * @param[in] z Second operand
     * @return True if both Real and Imaginary parts are equal
     *
     * If you want to compare only Real or Imaginary parts individually,
     * see @ref getRe() and @ref getIm().
     */
    bool operator == (const ComplexNumber& z) const;

    /**
     * @brief Comparison operator
     * @param[in] z Second operand
     * @return True if both Real and Imaginary parts are different
     *
     * If you want to compare only Real or Imaginary parts individually,
     * see @ref getRe() and @ref getIm().
     */
    bool operator != (const ComplexNumber& z) const;

 private:
    bool equalsZero(const ComplexNumber& z) const;
    double real_;
    double imaginary_;
};

//! @}

#endif  // MODULES_COMPLEX_NUMBER_INCLUDE_COMPLEX_NUMBER_H_
