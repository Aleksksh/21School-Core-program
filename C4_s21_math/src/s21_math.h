#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>

#define S21_PRECISION 1e-9
#define S21_INF 1.0 / 0.0
#define S21_NAN 0.0 / 0.0
#define EPS_20 1E-20
#define EPS_18 1E-18
#define EPS_16 1E-16
#define S21_EXP 2.71828182845904523536028747135266250
#define S21_PI 3.141592653589793238
#define LN2 0.693147180559945309417232121458176568
#define LN10 2.3025850929940456840179914546844
#define DBL_MAXIMUM 1E20

/*  вычисляет абсолютное значение целого числа */
int s21_abs(int x);
/*  возвращает значение e, возведенное в заданную степень */
long double s21_exp(double x);
/*  вычисляет абсолютное значение числа с плавающей точкой */
long double s21_fabs(double x);
/*  возвращает ближайшее целое число, не меньшее заданного значения */
long double s21_ceil(double x);
/*  возвращает ближайшее целое число, не превышающее заданное значение */
long double s21_floor(double x);
/*  вычисляет натуральный логарифм */
long double s21_log(double x);
/*  вычисляет квадратный корень */
long double s21_sqrt(double x);
/*  возводит число в заданную степень */
long double s21_pow(double base, double exp);
/*  остаток операции деления с плавающей точкой */
long double s21_fmod(double x, double y);
/*  вычисляет арктангенс */
long double s21_atan(double x);
long double s21_fact(int n);
/*  вычисляет арксинус */
long double s21_asin(double x);
/*  вычисляет арккосинус */
long double s21_acos(double x);
/*  вычисляет синус */
long double s21_sin(double x);
/*  вычисляет косинус */
long double s21_cos(double x);
/*  вычисляет тангенс */
long double s21_tan(double x);

#endif  // SRC_S21_MATH_H_
