/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * RiemannEnergy1.c
 *
 * Code generation for function 'RiemannEnergy1'
 *
 */

/* Include files */
#include "RiemannEnergy1.h"
#include "RiemannEnergy1_data.h"
#include "W_fcn1.h"
#include "eml_int_forloop_overflow_check.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo
    emlrtRSI =
        {
            13,               /* lineNo */
            "RiemannEnergy1", /* fcnName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\RiemannEnergy1.m" /* pathName
                                                                           */
};

static emlrtRSInfo
    b_emlrtRSI =
        {
            15,               /* lineNo */
            "RiemannEnergy1", /* fcnName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\RiemannEnergy1.m" /* pathName
                                                                           */
};

static emlrtRSInfo
    c_emlrtRSI =
        {
            16,               /* lineNo */
            "RiemannEnergy1", /* fcnName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\RiemannEnergy1.m" /* pathName
                                                                           */
};

static emlrtRSInfo
    d_emlrtRSI =
        {
            19,               /* lineNo */
            "RiemannEnergy1", /* fcnName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\RiemannEnergy1.m" /* pathName
                                                                           */
};

static emlrtRSInfo e_emlrtRSI = {
    51,                  /* lineNo */
    "reshapeSizeChecks", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    113,               /* lineNo */
    "computeDimsData", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI =
    {
        94,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI =
    {
        69,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" /* pathName */
};

static emlrtRSInfo r_emlrtRSI = {
    20,         /* lineNo */
    "mldivide", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" /* pathName
                                                                         */
};

static emlrtRSInfo s_emlrtRSI = {
    42,      /* lineNo */
    "mldiv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" /* pathName
                                                                         */
};

static emlrtRSInfo
    t_emlrtRSI =
        {
            67,        /* lineNo */
            "lusolve", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo
    u_emlrtRSI =
        {
            109,          /* lineNo */
            "lusolveNxN", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo
    v_emlrtRSI =
        {
            112,          /* lineNo */
            "lusolveNxN", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo
    w_emlrtRSI =
        {
            124,          /* lineNo */
            "InvAtimesX", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo x_emlrtRSI = {
    26,        /* lineNo */
    "xgetrfs", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrfs.m" /* pathName */
};

static emlrtRSInfo y_emlrtRSI = {
    30,       /* lineNo */
    "xgetrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrf.m" /* pathName */
};

static emlrtRSInfo ab_emlrtRSI = {
    55,        /* lineNo */
    "xzgetrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgetrf.m" /* pathName */
};

static emlrtRSInfo bb_emlrtRSI = {
    63,        /* lineNo */
    "xzgetrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgetrf.m" /* pathName */
};

static emlrtRSInfo cb_emlrtRSI = {
    20,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_"
    "overflow_check.m" /* pathName */
};

static emlrtRSInfo db_emlrtRSI = {
    45,      /* lineNo */
    "xgeru", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgeru."
    "m" /* pathName */
};

static emlrtRSInfo eb_emlrtRSI =
    {
        45,     /* lineNo */
        "xger", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "blas\\xger.m" /* pathName */
};

static emlrtRSInfo fb_emlrtRSI = {
    15,     /* lineNo */
    "xger", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xger.m" /* pathName */
};

static emlrtRSInfo gb_emlrtRSI = {
    54,      /* lineNo */
    "xgerx", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgerx.m" /* pathName */
};

static emlrtRSInfo
    hb_emlrtRSI =
        {
            90,              /* lineNo */
            "warn_singular", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRTEInfo
    emlrtRTEI =
        {
            18,               /* lineNo */
            7,                /* colNo */
            "RiemannEnergy1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\RiemannEnergy1.m" /* pName
                                                                           */
};

static emlrtBCInfo
    emlrtBCI =
        {
            1,                /* iFirst */
            9,                /* iLast */
            19,               /* lineNo */
            21,               /* colNo */
            "gamma_s",        /* aName */
            "RiemannEnergy1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\RiemannEnergy1.m", /* pName
                                                                            */
            0 /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    80,                  /* lineNo */
    13,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    85,                  /* lineNo */
    23,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    87,                  /* lineNo */
    23,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI =
    {
        138,                   /* lineNo */
        23,                    /* colNo */
        "dynamic_size_checks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI =
    {
        133,                   /* lineNo */
        23,                    /* colNo */
        "dynamic_size_checks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    16,         /* lineNo */
    19,         /* colNo */
    "mldivide", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" /* pName
                                                                         */
};

static emlrtRTEInfo h_emlrtRTEI = {
    58,                   /* lineNo */
    23,                   /* colNo */
    "assertValidSizeArg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\assertValidSizeArg.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    64,                   /* lineNo */
    15,                   /* colNo */
    "assertValidSizeArg", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\assertValidSizeArg.m" /* pName */
};

/* Function Definitions */
real_T RiemannEnergy1(const emlrtStack *sp, const real_T c[18], real_T n,
                      real_T D, real_T N, const real_T T[27],
                      const real_T T_dot[27], const real_T w[9])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
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
  emlrtStack n_st;
  emlrtStack o_st;
  emlrtStack st;
  real_T c_data[324];
  real_T gamma_data[162];
  real_T gamma_s_data[162];
  real_T tmp_data[18];
  real_T X_data[6];
  real_T E;
  int32_T c_size[2];
  int32_T gamma_s_size[2];
  int32_T gamma_size[2];
  int32_T A_tmp;
  int32_T b_k;
  int32_T i;
  int32_T j;
  int32_T jA;
  int32_T jp1j;
  int32_T k;
  int32_T kAcol;
  boolean_T out;
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
  n_st.prev = &m_st;
  n_st.tls = m_st.tls;
  o_st.prev = &n_st;
  o_st.tls = n_st.tls;
  /*  "1" indicates that this function is for code generation  */
  /*  Compute the Riemann Energy using the pseudospectral method */
  /*      gamma = zeros(n,N+1); */
  /*      gamma_s = zeros(n,N+1); */
  /*      for i = 1:n    */
  /*         gamma(i,:) = c((i-1)*(D+1)+1:i*(D+1),:)'*T;       % gamma(i) is
   * 1*(N+1); the ith elment of gamma on all the (N+1) nodes */
  /*         gamma_s(i,:) = c((i-1)*(D+1)+1:i*(D+1),:)'*T_dot; */
  /*      end    */
  /*  vectorized format to improve computational efficiency */
  st.site = &emlrtRSI;
  b_st.site = &e_emlrtRSI;
  c_st.site = &f_emlrtRSI;
  if ((D + 1.0 != muDoubleScalarFloor(D + 1.0)) ||
      muDoubleScalarIsInf(D + 1.0) || (D + 1.0 < -2.147483648E+9) ||
      (D + 1.0 > 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &h_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
  if (D + 1.0 <= 0.0) {
    E = 0.0;
  } else {
    E = D + 1.0;
  }
  if (!(E <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
  c_st.site = &f_emlrtRSI;
  if ((n != muDoubleScalarFloor(n)) || muDoubleScalarIsInf(n) ||
      (n < -2.147483648E+9) || (n > 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &h_emlrtRTEI, "Coder:MATLAB:NonIntegerInput",
        "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
  if (n <= 0.0) {
    E = 0.0;
  } else {
    E = n;
  }
  if (!(E <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI, "Coder:MATLAB:pmaxsize",
                                  "Coder:MATLAB:pmaxsize", 0);
  }
  if ((int32_T)(D + 1.0) > 18) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if ((int32_T)n > 18) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  out = ((int32_T)(D + 1.0) >= 0);
  if ((!out) || ((int32_T)n < 0)) {
    out = false;
  }
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  if ((int32_T)(D + 1.0) * (int32_T)n != 18) {
    emlrtErrorWithMessageIdR2018a(
        &st, &d_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  kAcol = (int32_T)(D + 1.0);
  jA = (int32_T)n;
  c_size[0] = (int32_T)n;
  c_size[1] = (int32_T)(D + 1.0);
  for (i = 0; i < kAcol; i++) {
    for (A_tmp = 0; A_tmp < jA; A_tmp++) {
      c_data[A_tmp + (int32_T)n * i] = c[i + (int32_T)(D + 1.0) * A_tmp];
    }
  }
  /*  the ith row corresponds to the ith element */
  st.site = &b_emlrtRSI;
  b_st.site = &h_emlrtRSI;
  if ((int32_T)(D + 1.0) != 3) {
    if (((int32_T)n == 1) && ((int32_T)(D + 1.0) == 1)) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &f_emlrtRTEI, "Coder:toolbox:mtimes_noDynamicScalarExpansion",
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI, "MATLAB:innerdim",
                                    "MATLAB:innerdim", 0);
    }
  }
  b_st.site = &g_emlrtRSI;
  mtimes(c_data, c_size, T, gamma_data, gamma_size);
  st.site = &c_emlrtRSI;
  b_st.site = &h_emlrtRSI;
  b_st.site = &g_emlrtRSI;
  mtimes(c_data, c_size, T_dot, gamma_s_data, gamma_s_size);
  E = 0.0;
  i = (int32_T)(N + 1.0);
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, N + 1.0, mxDOUBLE_CLASS,
                                (int32_T)(N + 1.0), &emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (k = 0; k < i; k++) {
    real_T A[36];
    real_T b_gamma_data[18];
    real_T smax;
    int32_T info;
    int8_T ipiv[6];
    if (((int32_T)((uint32_T)k + 1U) < 1) ||
        ((int32_T)((uint32_T)k + 1U) > 9)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)k + 1U), 1, 9,
                                    &emlrtBCI, (emlrtConstCTX)sp);
    }
    kAcol = gamma_s_size[0];
    for (A_tmp = 0; A_tmp < kAcol; A_tmp++) {
      tmp_data[A_tmp] = gamma_s_data[A_tmp + gamma_s_size[0] * k];
    }
    st.site = &d_emlrtRSI;
    b_st.site = &d_emlrtRSI;
    kAcol = gamma_size[0];
    for (A_tmp = 0; A_tmp < kAcol; A_tmp++) {
      b_gamma_data[A_tmp] = gamma_data[A_tmp + gamma_size[0] * k];
    }
    c_st.site = &d_emlrtRSI;
    W_fcn1(&c_st, b_gamma_data, gamma_size[0], A);
    if (gamma_s_size[0] != 6) {
      emlrtErrorWithMessageIdR2018a(&b_st, &g_emlrtRTEI, "MATLAB:dimagree",
                                    "MATLAB:dimagree", 0);
    }
    c_st.site = &r_emlrtRSI;
    for (A_tmp = 0; A_tmp < 6; A_tmp++) {
      X_data[A_tmp] = gamma_s_data[A_tmp + 6 * k];
    }
    d_st.site = &s_emlrtRSI;
    e_st.site = &t_emlrtRSI;
    f_st.site = &u_emlrtRSI;
    g_st.site = &w_emlrtRSI;
    h_st.site = &x_emlrtRSI;
    i_st.site = &y_emlrtRSI;
    for (A_tmp = 0; A_tmp < 6; A_tmp++) {
      ipiv[A_tmp] = (int8_T)(A_tmp + 1);
    }
    info = 0;
    for (j = 0; j < 5; j++) {
      int32_T b_tmp;
      int32_T mmj_tmp;
      mmj_tmp = 4 - j;
      b_tmp = j * 7;
      jp1j = b_tmp + 2;
      jA = 7 - j;
      kAcol = 0;
      smax = muDoubleScalarAbs(A[b_tmp]);
      for (b_k = 2; b_k < jA; b_k++) {
        real_T s;
        s = muDoubleScalarAbs(A[(b_tmp + b_k) - 1]);
        if (s > smax) {
          kAcol = b_k - 1;
          smax = s;
        }
      }
      if (A[b_tmp + kAcol] != 0.0) {
        if (kAcol != 0) {
          kAcol += j;
          ipiv[j] = (int8_T)(kAcol + 1);
          for (b_k = 0; b_k < 6; b_k++) {
            jA = j + b_k * 6;
            smax = A[jA];
            A_tmp = kAcol + b_k * 6;
            A[jA] = A[A_tmp];
            A[A_tmp] = smax;
          }
        }
        A_tmp = (b_tmp - j) + 6;
        j_st.site = &ab_emlrtRSI;
        for (jA = jp1j; jA <= A_tmp; jA++) {
          A[jA - 1] /= A[b_tmp];
        }
      } else {
        info = j + 1;
      }
      j_st.site = &bb_emlrtRSI;
      k_st.site = &db_emlrtRSI;
      l_st.site = &eb_emlrtRSI;
      m_st.site = &fb_emlrtRSI;
      jA = b_tmp + 8;
      for (A_tmp = 0; A_tmp <= mmj_tmp; A_tmp++) {
        smax = A[(b_tmp + A_tmp * 6) + 6];
        if (smax != 0.0) {
          kAcol = (jA - j) + 4;
          n_st.site = &gb_emlrtRSI;
          if ((jA <= kAcol) && (kAcol > 2147483646)) {
            o_st.site = &cb_emlrtRSI;
            check_forloop_overflow_error(&o_st);
          }
          for (jp1j = jA; jp1j <= kAcol; jp1j++) {
            A[jp1j - 1] += A[((b_tmp + jp1j) - jA) + 1] * -smax;
          }
        }
        jA += 6;
      }
    }
    if ((info == 0) && (!(A[35] != 0.0))) {
      info = 6;
    }
    for (jA = 0; jA < 5; jA++) {
      int8_T i1;
      i1 = ipiv[jA];
      if (i1 != jA + 1) {
        smax = X_data[jA];
        X_data[jA] = X_data[i1 - 1];
        X_data[i1 - 1] = smax;
      }
    }
    for (b_k = 0; b_k < 6; b_k++) {
      kAcol = 6 * b_k;
      if (X_data[b_k] != 0.0) {
        A_tmp = b_k + 2;
        for (jA = A_tmp; jA < 7; jA++) {
          X_data[jA - 1] -= X_data[b_k] * A[(jA + kAcol) - 1];
        }
      }
    }
    for (b_k = 5; b_k >= 0; b_k--) {
      kAcol = 6 * b_k;
      smax = X_data[b_k];
      if (smax != 0.0) {
        smax /= A[b_k + kAcol];
        X_data[b_k] = smax;
        for (jA = 0; jA < b_k; jA++) {
          X_data[jA] -= X_data[b_k] * A[jA + kAcol];
        }
      }
    }
    if (info > 0) {
      f_st.site = &v_emlrtRSI;
      g_st.site = &hb_emlrtRSI;
      warning(&g_st);
    }
    b_st.site = &h_emlrtRSI;
    n_t = (ptrdiff_t)6;
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    smax = ddot(&n_t, &tmp_data[0], &incx_t, &X_data[0], &incy_t);
    E += smax * w[k];
    /*  noite that W_fcn needs to be selected for each specific example.  */
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  return E;
}

/* End of code generation (RiemannEnergy1.c) */
