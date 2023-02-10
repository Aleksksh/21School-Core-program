#include "s21_math.h"

/*  остаток операции деления с плавающей точкой */
long double s21_fmod(double x, double y) {
  long double res = 0.0;
  if (!(x >= 0) && !(x < 0))
    res = S21_NAN;
  else if (!(y >= 0) && !(y < 0))
    res = S21_NAN;
  else if ((x != S21_NAN && y == 0))
    res = S21_NAN;
  else if (y == -S21_INF || y == S21_INF)
    res = x;
  else if ((x == -S21_INF || x == S21_INF) && y != S21_NAN)
    res = S21_NAN;
  else if (x == 0.0 && y != 0.0)
    res = 0.0;
  else {
    long long int mod = 0;
    mod = x / y;
    res = (long double)x - mod * (long double)y;
  }
  return res;
}
