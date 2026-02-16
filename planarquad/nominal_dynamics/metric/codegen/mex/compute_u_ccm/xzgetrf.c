/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzgetrf.c
 *
 * Code generation for function 'xzgetrf'
 *
 */

/* Include files */
#include "xzgetrf.h"
#include "compute_u_ccm_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo t_emlrtRSI = {
    55,        /* lineNo */
    "xzgetrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgetrf.m" /* pathName */
};

static emlrtRSInfo u_emlrtRSI = {
    63,        /* lineNo */
    "xzgetrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgetrf.m" /* pathName */
};

static emlrtRSInfo w_emlrtRSI = {
    45,      /* lineNo */
    "xgeru", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgeru."
    "m" /* pathName */
};

static emlrtRSInfo x_emlrtRSI =
    {
        45,     /* lineNo */
        "xger", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "blas\\xger.m" /* pathName */
};

static emlrtRSInfo y_emlrtRSI = {
    15,     /* lineNo */
    "xger", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xger.m" /* pathName */
};

static emlrtRSInfo ab_emlrtRSI = {
    54,      /* lineNo */
    "xgerx", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgerx.m" /* pathName */
};

/* Function Definitions */
int32_T xzgetrf(const emlrtStack *sp, real_T A[36], int32_T ipiv[6])
{
  static const int32_T offsets[4] = {0, 1, 2, 3};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  int32_T a;
  int32_T b_j;
  int32_T info;
  int32_T j;
  int32_T jp1j;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  _mm_storeu_si128(
      (__m128i *)&ipiv[0],
      _mm_add_epi32(
          _mm_set1_epi32(1),
          _mm_add_epi32(_mm_set1_epi32(0),
                        _mm_loadu_si128((const __m128i *)&offsets[0]))));
  ipiv[4] = 5;
  ipiv[5] = 6;
  info = 0;
  for (j = 0; j < 5; j++) {
    real_T smax;
    int32_T b_tmp;
    int32_T jA;
    int32_T mmj_tmp;
    mmj_tmp = 4 - j;
    b_tmp = j * 7;
    jp1j = b_tmp + 2;
    jA = 7 - j;
    a = 0;
    smax = muDoubleScalarAbs(A[b_tmp]);
    for (k = 2; k < jA; k++) {
      real_T s;
      s = muDoubleScalarAbs(A[(b_tmp + k) - 1]);
      if (s > smax) {
        a = k - 1;
        smax = s;
      }
    }
    if (A[b_tmp + a] != 0.0) {
      if (a != 0) {
        a += j;
        ipiv[j] = a + 1;
        for (k = 0; k < 6; k++) {
          jA = j + k * 6;
          smax = A[jA];
          b_j = a + k * 6;
          A[jA] = A[b_j];
          A[b_j] = smax;
        }
      }
      b_j = (b_tmp - j) + 6;
      st.site = &t_emlrtRSI;
      for (a = jp1j; a <= b_j; a++) {
        A[a - 1] /= A[b_tmp];
      }
    } else {
      info = j + 1;
    }
    st.site = &u_emlrtRSI;
    b_st.site = &w_emlrtRSI;
    c_st.site = &x_emlrtRSI;
    d_st.site = &y_emlrtRSI;
    jA = b_tmp + 8;
    for (b_j = 0; b_j <= mmj_tmp; b_j++) {
      smax = A[(b_tmp + b_j * 6) + 6];
      if (smax != 0.0) {
        a = (jA - j) + 4;
        e_st.site = &ab_emlrtRSI;
        if ((jA <= a) && (a > 2147483646)) {
          f_st.site = &v_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }
        for (jp1j = jA; jp1j <= a; jp1j++) {
          A[jp1j - 1] += A[((b_tmp + jp1j) - jA) + 1] * -smax;
        }
      }
      jA += 6;
    }
  }
  if ((info == 0) && (!(A[35] != 0.0))) {
    info = 6;
  }
  return info;
}

/* End of code generation (xzgetrf.c) */
