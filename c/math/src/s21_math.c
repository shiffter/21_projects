#include "s21_math.h"

int count_digits(long long x) {
  int count = 0;
  while (x != 0) {
    x = x / 10;
    count++;
  }
  return count;
}

int s21_abs(int x) {
  if (x < 0) {
    x = -x;
  }
  return x;
}

long double s21_acos(double x) {
  long double result;
  if (s21_isnan(x) == 1 || s21_fabs(x) > 1.0 || s21_isinf(x) ||
      s21_isinf(x) == -1)
    result = s21_nan;
  else if (x == 1)
    result = 0.0;
  else if (x == -1)
    result = s21_pi;
  else if (x < 0)
    result = s21_pi - s21_acos(s21_fabs(x));
  else
    result = s21_atan(s21_sqrt(1.0 - (x * x)) / x);
  return result;
}

long double s21_asin(double x) {
  long double result;
  if (s21_isnan(x) == 1 || s21_fabs(x) > 1.0 || s21_isinf(x) ||
      s21_isinf(x) == -1)
    result = s21_nan;
  else if (x == 1)
    result = s21_pi / 2;
  else if (x == -1)
    result = -s21_pi / 2;
  else if (x < 0)
    result = -s21_asin(s21_fabs(x));
  else
    result = s21_atan(x / s21_sqrt(1.0 - (x * x)));
  return result;
}

long double s21_atan(double x) {
  long double res = s21_fabs(x), delta = s21_fabs(x), upper = s21_fabs(x);
  long double xx = x * x;
  if (s21_isnan(x) == 1) {
    res = s21_nan;
  } else if (s21_isinf(x) == 1) {
    res = s21_pi2;
  } else if (s21_isinf(x) == 1) {
    res = -s21_pi2;
  } else {
    if (s21_fabs(x) > 1.0) {
      res = s21_pi2 - s21_atan(1.0 / res);
    } else {
      for (long double i = 3.0L; s21_fabs(delta) > 1e-7; i += 2) {
        upper *= xx * (-1);
        delta = upper / i;
        res += delta;
      }
    }
  }
  return __builtin_signbit(x) ? -res : res;
}

long double s21_ceil(double x) {
  long double result = 0;
  if (x != x || s21_isinf(x) || s21_isinf(x)) {
    result = x;
  } else {
    if (x < 0) {
      result = (long long)x;
    } else if (x > 0) {
      if ((long double)(long long)x != x) {
        result = (long long)x + 1;
      } else {
        result = (long long)x;
      }
    }
  }
  return result;
}

long double s21_cos(double x) {
  long double res = 0;
  if (s21_isnan(x) || s21_isinf(x) || s21_isinf(x) == -1) {
    res = s21_nan;
  } else {
    x = s21_fmod(x, 2 * s21_pi);
    long double add = 1;
    for (int i = 1; i < 100; i++) {
      long double previous = res;
      res += add;
      add *= -1 * x * x / (i * 2) / (i * 2 - 1);
      if (s21_fabs(res - previous) < 1e-6) {
        break;
      }
    }
  }
  return res;
}

unsigned long long int s21_fact(long int x) {
  unsigned long long int res = 1;
  for (long int i = 2; i <= x; i++) {
    res *= i;
  }
  return res;
}

long double s21_exp(double arg) {
  long double result = 1;
  long double t = arg;
  if (s21_isinf(arg) == -1) {
    result = 0.0;
  } else if (s21_isinf(arg) == 1) {
    result = s21_inf;
  } else if (s21_isnan(arg)) {
    result = s21_nan;
  } else {
    for (double i = 2; i < 1500; i++) {
      result += t;
      t *= arg / i;
    }
    if (arg < -20) {
      result = 0.0;
    }
  }
  return result;
}

long double s21_fabs(double x) {
  if (x < 0) {
    x = -x;
  }
  return x;
}

long double s21_floor(double x) {  // use POW to truncate a double
  long double result = 0;
  long long long_x = (long long)x;
  if (x != x || s21_isinf(x) || s21_isinf(x) == -1) {
    result = x;
  } else {
    if (x > 0) {
      result = long_x;
    } else if (x < 0) {
      long double temp = x + 0.000001;

      if (count_digits(long_x) > 15) {
        temp += 0.000500;
      } else if (count_digits(long_x) > 14) {
        temp += 0.000050;
      }
      if ((long long)temp != long_x) {
        result += long_x;
      } else {
        result += long_x - 1;
      }
    }
  }
  return result;
}

long double s21_fmod(double x, double y) {
  long double result = 0;

  if (s21_isnan(x) || s21_isnan(y)) {
    return s21_nan;
  }
  if (s21_fabs(x) <= s21_eps && y != 0) {
    return x;
  }
  if (s21_isinf(x) && !s21_isnan(x) && !s21_isnan(y)) {
    return s21_nan;
  }
  if (s21_fabs(y) <= s21_eps && !s21_isnan(x)) {
    return s21_nan;
  }
  if (s21_isinf(y) && !s21_isnan(y) && !s21_isinf(x)) {
    return x;
  }

  int interger = x / y;
  result = (long double)x - interger * (long double)y;
  return result;
}

long double s21_log(double x) {
  long double result = 0;
  double comp = 0;
  int degree = 0;
  if (s21_isinf(x) == 1) {
    result = s21_inf;
  } else if (x == 0) {
    result = s21_minf;
  } else if (s21_isnan(x) || x < 0 || s21_isinf(x) == -1) {
    result = s21_nan;
  } else {
    for (; x >= s21_e; x /= s21_e, degree++) continue;
    for (int i = 0; i < 100; i++) {
      comp = result;
      result = comp + 2 * (x - s21_exp(comp)) / (x + s21_exp(comp));
    }
    result += degree;
  }
  return result;
}

long double s21_pow(double value, double exp) {
  long double result = 0.0;
  if (exp == 0) {
    return result = 1.0;
  }
  if (s21_isnan(value) || s21_isnan(exp)) {
    return s21_nan;
  }
  if (s21_isinf(value)) {
    if (exp < 0)
      return result = 0.0;
    else if (s21_isnan(exp))
      return result = s21_nan;
    else
      return result = s21_inf;
  }
  if (s21_isinf(exp) == 1 && value != 0) {
    if (s21_fabs(value) > 0 && s21_fabs(value) < 1.0)
      return 0.0;
    else if (value > 1.0 || value < 0)
      return result = s21_inf;
    else if (value == 1)
      return result = s21_nan;
  } else if (s21_isinf(exp) == -1) {
    if (s21_fabs(value) >= 0 && s21_fabs(value) < 1.0)
      return s21_inf;
    else
      return result = 0.0;
  }
  if ((exp / (int)exp == 1.0) && ((int)exp % 2 == 1) &&
      __builtin_signbit(value)) {
    result = -s21_exp(exp * s21_log(s21_fabs(value)));

  } else if (value > 0) {
    result = s21_exp(exp * s21_log(s21_fabs(value)));
  } else if (value == 0.0) {
    if (exp < 0.0 || s21_isinf(exp) == -1)
      result = s21_inf;
    else
      result = 0.0;
  } else {
    result = s21_nan;
  }
  return result;
}

long double s21_sin(double x) {
  long double result = 0;
  if (s21_isnan(x) || s21_isinf(x)) {
    result = s21_nan;
  } else {
    if (s21_fabs(x) > (2 * s21_pi)) x = s21_fmod(x, s21_2pi);
    result = x;
    long double num = x, den = 1.0, delta = num / den;
    long double xx = x * x;
    for (long double i = 3; s21_fabs(delta) > 1e-10; i += 2) {
      num *= -xx;
      den *= i * (i - 1);
      delta = num / den;
      result += delta;
    }
  }
  return result;
}

long double s21_sqrt(double x) {
  long double result;
  if (s21_isinf(x) == -1) {
    result = s21_nan;
  } else {
    result = s21_pow(x, 0.5);
  }
  return result;
}

long double s21_tan(double x) {
  long double res = 0;
  if (s21_isnan(x) || s21_isinf(x) || s21_isinf(x) == -1) {
    res = s21_nan;
  } else {
    res = s21_sin(x) / s21_cos(x);
  }
  return res;
}
