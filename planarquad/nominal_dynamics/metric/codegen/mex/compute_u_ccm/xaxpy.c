/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xaxpy.c
 *
 * Code generation for function 'xaxpy'
 *
 */

/* Include files */
#include "xaxpy.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>

/* Function Definitions */
void b_xaxpy(int32_T n, real_T a, const real_T x[36], int32_T ix0, real_T y[6],
             int32_T iy0)
{
  int32_T k;
  if (!(a == 0.0)) {
    int32_T i;
    int32_T scalarLB;
    int32_T vectorUB;
    scalarLB = (n / 2) << 1;
    vectorUB = scalarLB - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      __m128d r;
      i = (iy0 + k) - 1;
      r = _mm_loadu_pd(&y[i]);
      _mm_storeu_pd(&y[i],
                    _mm_add_pd(r, _mm_mul_pd(_mm_set1_pd(a),
                                             _mm_loadu_pd(&x[(ix0 + k) - 1]))));
    }
    for (k = scalarLB; k < n; k++) {
      i = (iy0 + k) - 1;
      y[i] += a * x[(ix0 + k) - 1];
    }
  }
}

void c_xaxpy(int32_T n, real_T a, const real_T x[6], int32_T ix0, real_T y[36],
             int32_T iy0)
{
  int32_T k;
  if (!(a == 0.0)) {
    int32_T i;
    int32_T scalarLB;
    int32_T vectorUB;
    scalarLB = n / 2 * 2;
    vectorUB = scalarLB - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      __m128d r;
      __m128d r1;
      i = (iy0 + k) - 1;
      r = _mm_loadu_pd(&x[(ix0 + k) - 1]);
      r = _mm_mul_pd(_mm_set1_pd(a), r);
      r1 = _mm_loadu_pd(&y[i]);
      r = _mm_add_pd(r1, r);
      _mm_storeu_pd(&y[i], r);
    }
    for (k = scalarLB; k < n; k++) {
      i = (iy0 + k) - 1;
      y[i] += a * x[(ix0 + k) - 1];
    }
  }
}

void xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[36], int32_T iy0)
{
  int32_T k;
  if (!(a == 0.0)) {
    for (k = 0; k < n; k++) {
      int32_T i;
      i = (iy0 + k) - 1;
      y[i] += a * y[(ix0 + k) - 1];
    }
  }
}

/* End of code generation (xaxpy.c) */
