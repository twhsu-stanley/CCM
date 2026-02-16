/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xdotc.c
 *
 * Code generation for function 'xdotc'
 *
 */

/* Include files */
#include "xdotc.h"
#include "rt_nonfinite.h"

/* Function Definitions */
real_T xdotc(int32_T n, const real_T x[36], int32_T ix0, const real_T y[36],
             int32_T iy0)
{
  real_T d;
  int32_T k;
  d = 0.0;
  if (n >= 1) {
    int32_T i;
    i = (uint8_T)n;
    for (k = 0; k < i; k++) {
      d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
    }
  }
  return d;
}

/* End of code generation (xdotc.c) */
