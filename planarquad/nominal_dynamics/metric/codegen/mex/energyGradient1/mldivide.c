/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mldivide.c
 *
 * Code generation for function 'mldivide'
 *
 */

/* Include files */
#include "mldivide.h"
#include "eml_int_forloop_overflow_check.h"
#include "energyGradient1_data.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo fb_emlrtRSI = {
    20,         /* lineNo */
    "mldivide", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" /* pathName
                                                                         */
};

static emlrtRSInfo gb_emlrtRSI = {
    42,      /* lineNo */
    "mldiv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" /* pathName
                                                                         */
};

static emlrtRSInfo
    hb_emlrtRSI =
        {
            67,        /* lineNo */
            "lusolve", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo
    ib_emlrtRSI =
        {
            109,          /* lineNo */
            "lusolveNxN", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo
    jb_emlrtRSI =
        {
            112,          /* lineNo */
            "lusolveNxN", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo
    kb_emlrtRSI =
        {
            124,          /* lineNo */
            "InvAtimesX", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo lb_emlrtRSI = {
    26,        /* lineNo */
    "xgetrfs", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrfs.m" /* pathName */
};

static emlrtRSInfo mb_emlrtRSI = {
    27,        /* lineNo */
    "xgetrfs", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrfs.m" /* pathName */
};

static emlrtRSInfo nb_emlrtRSI = {
    30,       /* lineNo */
    "xgetrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrf.m" /* pathName */
};

static emlrtRSInfo ob_emlrtRSI = {
    55,        /* lineNo */
    "xzgetrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgetrf.m" /* pathName */
};

static emlrtRSInfo pb_emlrtRSI = {
    63,        /* lineNo */
    "xzgetrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgetrf.m" /* pathName */
};

static emlrtRSInfo qb_emlrtRSI = {
    45,      /* lineNo */
    "xgeru", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgeru."
    "m" /* pathName */
};

static emlrtRSInfo rb_emlrtRSI =
    {
        45,     /* lineNo */
        "xger", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "blas\\xger.m" /* pathName */
};

static emlrtRSInfo sb_emlrtRSI = {
    15,     /* lineNo */
    "xger", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xger.m" /* pathName */
};

static emlrtRSInfo tb_emlrtRSI = {
    41,      /* lineNo */
    "xgerx", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgerx.m" /* pathName */
};

static emlrtRSInfo ub_emlrtRSI = {
    54,      /* lineNo */
    "xgerx", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgerx.m" /* pathName */
};

static emlrtRSInfo vb_emlrtRSI = {
    18,       /* lineNo */
    "xgetrs", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrs.m" /* pathName */
};

static emlrtRSInfo wb_emlrtRSI = {
    36,        /* lineNo */
    "xzgetrs", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgetrs.m" /* pathName */
};

static emlrtRSInfo xb_emlrtRSI = {
    59,      /* lineNo */
    "xtrsm", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm."
    "m" /* pathName */
};

static emlrtRSInfo yb_emlrtRSI = {
    51,      /* lineNo */
    "xtrsm", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xtrsm.m" /* pathName */
};

static emlrtRSInfo
    ac_emlrtRSI =
        {
            90,              /* lineNo */
            "warn_singular", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRTEInfo n_emlrtRTEI = {
    16,         /* lineNo */
    19,         /* colNo */
    "mldivide", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" /* pName
                                                                         */
};

/* Function Definitions */
int32_T mldivide(const emlrtStack *sp, const real_T A[36],
                 const real_T B_data[], int32_T B_size, real_T Y_data[])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack k_st;
  emlrtStack l_st;
  emlrtStack m_st;
  emlrtStack st;
  real_T b_A[36];
  real_T smax;
  int32_T A_tmp;
  int32_T Y_size;
  int32_T a;
  int32_T info;
  int32_T j;
  int32_T jA;
  int32_T jp1j;
  int32_T k;
  int8_T ipiv[6];
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  k_st.prev = &j_st;
  k_st.tls = j_st.tls;
  l_st.prev = &k_st;
  l_st.tls = k_st.tls;
  m_st.prev = &l_st;
  m_st.tls = l_st.tls;
  if (B_size != 6) {
    emlrtErrorWithMessageIdR2018a(sp, &n_emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  st.site = &fb_emlrtRSI;
  Y_size = 6;
  for (a = 0; a < 6; a++) {
    Y_data[a] = B_data[a];
  }
  b_st.site = &gb_emlrtRSI;
  c_st.site = &hb_emlrtRSI;
  d_st.site = &ib_emlrtRSI;
  e_st.site = &kb_emlrtRSI;
  f_st.site = &lb_emlrtRSI;
  memcpy(&b_A[0], &A[0], 36U * sizeof(real_T));
  g_st.site = &nb_emlrtRSI;
  for (a = 0; a < 6; a++) {
    ipiv[a] = (int8_T)(a + 1);
  }
  info = 0;
  for (j = 0; j < 5; j++) {
    int32_T b_tmp;
    int32_T mmj_tmp;
    mmj_tmp = 4 - j;
    b_tmp = j * 7;
    jp1j = b_tmp + 2;
    jA = 7 - j;
    a = 0;
    smax = muDoubleScalarAbs(b_A[b_tmp]);
    for (k = 2; k < jA; k++) {
      real_T s;
      s = muDoubleScalarAbs(b_A[(b_tmp + k) - 1]);
      if (s > smax) {
        a = k - 1;
        smax = s;
      }
    }
    if (b_A[b_tmp + a] != 0.0) {
      if (a != 0) {
        a += j;
        ipiv[j] = (int8_T)(a + 1);
        for (k = 0; k < 6; k++) {
          jA = j + k * 6;
          smax = b_A[jA];
          A_tmp = a + k * 6;
          b_A[jA] = b_A[A_tmp];
          b_A[A_tmp] = smax;
        }
      }
      a = (b_tmp - j) + 6;
      h_st.site = &ob_emlrtRSI;
      for (A_tmp = jp1j; A_tmp <= a; A_tmp++) {
        b_A[A_tmp - 1] /= b_A[b_tmp];
      }
    } else {
      info = j + 1;
    }
    h_st.site = &pb_emlrtRSI;
    i_st.site = &qb_emlrtRSI;
    j_st.site = &rb_emlrtRSI;
    k_st.site = &sb_emlrtRSI;
    jA = b_tmp + 8;
    l_st.site = &tb_emlrtRSI;
    for (A_tmp = 0; A_tmp <= mmj_tmp; A_tmp++) {
      smax = b_A[(b_tmp + A_tmp * 6) + 6];
      if (smax != 0.0) {
        a = (jA - j) + 4;
        l_st.site = &ub_emlrtRSI;
        if ((jA <= a) && (a > 2147483646)) {
          m_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&m_st);
        }
        for (jp1j = jA; jp1j <= a; jp1j++) {
          b_A[jp1j - 1] += b_A[((b_tmp + jp1j) - jA) + 1] * -smax;
        }
      }
      jA += 6;
    }
  }
  if ((info == 0) && (!(b_A[35] != 0.0))) {
    info = 6;
  }
  f_st.site = &mb_emlrtRSI;
  g_st.site = &vb_emlrtRSI;
  for (A_tmp = 0; A_tmp < 5; A_tmp++) {
    int8_T i;
    i = ipiv[A_tmp];
    if (i != A_tmp + 1) {
      smax = Y_data[A_tmp];
      Y_data[A_tmp] = Y_data[i - 1];
      Y_data[i - 1] = smax;
    }
  }
  for (k = 0; k < 6; k++) {
    jA = 6 * k;
    if (Y_data[k] != 0.0) {
      a = k + 2;
      for (A_tmp = a; A_tmp < 7; A_tmp++) {
        Y_data[A_tmp - 1] -= Y_data[k] * b_A[(A_tmp + jA) - 1];
      }
    }
  }
  h_st.site = &wb_emlrtRSI;
  i_st.site = &xb_emlrtRSI;
  for (k = 5; k >= 0; k--) {
    jA = 6 * k;
    smax = Y_data[k];
    if (smax != 0.0) {
      smax /= b_A[k + jA];
      Y_data[k] = smax;
      j_st.site = &yb_emlrtRSI;
      for (A_tmp = 0; A_tmp < k; A_tmp++) {
        Y_data[A_tmp] -= Y_data[k] * b_A[A_tmp + jA];
      }
    }
  }
  if (info > 0) {
    d_st.site = &jb_emlrtRSI;
    e_st.site = &ac_emlrtRSI;
    warning(&e_st);
  }
  return Y_size;
}

/* End of code generation (mldivide.c) */
