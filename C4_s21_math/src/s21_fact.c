#include "s21_math.h"

long double s21_fact(int n) { return (n < 2) ? 1 : n * s21_fact(n - 1); }
