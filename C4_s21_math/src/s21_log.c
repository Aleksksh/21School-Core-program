#include "s21_math.h"

/*  вычисляет натуральный логарифм */
long double s21_log(double x) {
  long double res = 0;
  int pow_of_E = 0;
  if (x < 0.0 || (!(x >= 0.0) && !(x < 0.0)) || x == S21_NAN)
    res = S21_NAN;
  else if (x == S21_INF || x == -S21_INF)
    res = S21_INF;
  else if (x == 0.0)
    res = -S21_INF;
  else if (x == 1.0)
    res = 0;
  else if (x > 0.0) {
    long double calc_value = res;
    for (; x >= S21_EXP; x /= S21_EXP, pow_of_E++) continue;
    for (int i = 0; i < 100; i++) {
      calc_value = res;
      res = calc_value +
            2 * (x - s21_exp(calc_value)) / (x + s21_exp(calc_value));
    }
  }
  return (long double)res + pow_of_E;
}
