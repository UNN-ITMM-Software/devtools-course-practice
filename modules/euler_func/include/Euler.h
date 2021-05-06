// Copyright 2021 Mishin Ilya

#ifndef MODULES_EULER_FUNC_INCLUDE_EULER_H_
#define MODULES_EULER_FUNC_INCLUDE_EULER_H_

int64_t phi(int64_t n) {
    if (n == 0) {
        return 0;
    }
    if (n < 0) {
        throw(1);
    }
    int64_t result = n;
    for (int64_t i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    if (n > 1)
        result -= result / n;
    return result;
}


#endif  // MODULES_EULER_FUNC_INCLUDE_EULER_H_
