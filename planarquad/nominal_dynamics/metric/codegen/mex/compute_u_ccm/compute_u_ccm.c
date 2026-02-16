/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * compute_u_ccm.c
 *
 * Code generation for function 'compute_u_ccm'
 *
 */

/* Include files */
#include "compute_u_ccm.h"
#include "W_fcn1.h"
#include "compute_u_ccm_data.h"
#include "compute_u_ccm_mexutil.h"
#include "inv.h"
#include "mrdivide_helper.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "xzgetrf.h"
#include "xzpotrf.h"
#include "xzsvdc.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    12,                                                        /* lineNo */
    "compute_u_ccm",                                           /* fcnName */
    "C:\\ACXIS Code\\CCM\\planarquad\\metric\\compute_u_ccm.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    13,                                                        /* lineNo */
    "compute_u_ccm",                                           /* fcnName */
    "C:\\ACXIS Code\\CCM\\planarquad\\metric\\compute_u_ccm.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    14,                                                        /* lineNo */
    "compute_u_ccm",                                           /* fcnName */
    "C:\\ACXIS Code\\CCM\\planarquad\\metric\\compute_u_ccm.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    19,                                                        /* lineNo */
    "compute_u_ccm",                                           /* fcnName */
    "C:\\ACXIS Code\\CCM\\planarquad\\metric\\compute_u_ccm.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    22,                                                        /* lineNo */
    "compute_u_ccm",                                           /* fcnName */
    "C:\\ACXIS Code\\CCM\\planarquad\\metric\\compute_u_ccm.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    30,                                                        /* lineNo */
    "compute_u_ccm",                                           /* fcnName */
    "C:\\ACXIS Code\\CCM\\planarquad\\metric\\compute_u_ccm.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    34,                                                        /* lineNo */
    "compute_u_ccm",                                           /* fcnName */
    "C:\\ACXIS Code\\CCM\\planarquad\\metric\\compute_u_ccm.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    37,                                                        /* lineNo */
    "compute_u_ccm",                                           /* fcnName */
    "C:\\ACXIS Code\\CCM\\planarquad\\metric\\compute_u_ccm.m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    21,    /* lineNo */
    "inv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m" /* pathName
                                                                       */
};

static emlrtRSInfo q_emlrtRSI = {
    22,    /* lineNo */
    "inv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m" /* pathName
                                                                       */
};

static emlrtRSInfo r_emlrtRSI = {
    173,      /* lineNo */
    "invNxN", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\inv.m" /* pathName
                                                                       */
};

static emlrtRSInfo db_emlrtRSI = {
    12,     /* lineNo */
    "chol", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\chol.m" /* pathName
                                                                        */
};

static emlrtRSInfo eb_emlrtRSI = {
    84,     /* lineNo */
    "chol", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\chol.m" /* pathName
                                                                           */
};

static emlrtRSInfo fb_emlrtRSI = {
    101,    /* lineNo */
    "chol", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\chol.m" /* pathName
                                                                           */
};

static emlrtRSInfo gb_emlrtRSI = {
    16,       /* lineNo */
    "xpotrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xpotrf.m" /* pathName */
};

static emlrtRSInfo hb_emlrtRSI = {
    19,        /* lineNo */
    "xzpotrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzpotrf.m" /* pathName */
};

static emlrtRSInfo ib_emlrtRSI = {
    58,        /* lineNo */
    "zpotrfU", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzpotrf.m" /* pathName */
};

static emlrtRSInfo kb_emlrtRSI = {
    53,        /* lineNo */
    "zpotrfU", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzpotrf.m" /* pathName */
};

static emlrtRSInfo ob_emlrtRSI = {
    18,    /* lineNo */
    "svd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" /* pathName
                                                                       */
};

static emlrtRSInfo pb_emlrtRSI = {
    28,    /* lineNo */
    "svd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pathName
                                                                          */
};

static emlrtRSInfo qb_emlrtRSI = {
    107,          /* lineNo */
    "callLAPACK", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pathName
                                                                          */
};

static emlrtRSInfo rb_emlrtRSI = {
    34,       /* lineNo */
    "xgesvd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pathName */
};

static emlrtRSInfo mc_emlrtRSI = {
    20,                /* lineNo */
    "mrdivide_helper", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_"
    "helper.m" /* pathName */
};

static emlrtRTEInfo b_emlrtRTEI = {
    109,    /* lineNo */
    27,     /* colNo */
    "chol", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\chol.m" /* pName
                                                                           */
};

/* Function Definitions */
void compute_u_ccm(const emlrtStack *sp, const real_T x[6],
                   const real_T x_nom[6], const real_T u_nom[2], real_T Erem,
                   const real_T gamma_s[54], const real_T H[9],
                   real_T controller_lambda, int8_T use_cp, real_T cp_quantile,
                   const real_T plant_fx[6], const real_T plant_fx_nom[6],
                   const real_T plant_Bx[12], const real_T plant_Bx_nom[12],
                   const real_T plant_Bwx[36], real_T u[3])
{
  static const int32_T iv[2] = {1, 6};
  static const char_T rfmt[6] = {'%', '1', '4', '.', '6', 'e'};
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  real_T Theta[36];
  real_T b_x[36];
  real_T c_x[36];
  real_T b[9];
  real_T Y[6];
  real_T s[6];
  real_T A[3];
  real_T b_s;
  real_T constraint_tightening;
  real_T d;
  real_T d1;
  real_T n1x;
  real_T n1xinv;
  int32_T i;
  int32_T info;
  int32_T j;
  int32_T k;
  int32_T kAcol;
  int32_T pipk;
  char_T TRANSA;
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
  /*  Formulate it as a min-norm CLF QP problem */
  /*  min [u' slack] H [u; slack] */
  /*  Constraints : A[u; slack] + B <= 0 */
  /*  */
  /*  Output: u = [uc, slack] */
  if (use_cp != 0) {
    int32_T ipiv[6];
    int32_T idxAjjp1;
    int8_T p[6];
    boolean_T b_p;
    boolean_T exitg1;
    st.site = &emlrtRSI;
    b_st.site = &emlrtRSI;
    c_st.site = &emlrtRSI;
    W_fcn1(x, b_x);
    c_st.site = &p_emlrtRSI;
    memset(&Theta[0], 0, 36U * sizeof(real_T));
    d_st.site = &r_emlrtRSI;
    memcpy(&c_x[0], &b_x[0], 36U * sizeof(real_T));
    e_st.site = &s_emlrtRSI;
    xzgetrf(&e_st, c_x, ipiv);
    for (i = 0; i < 6; i++) {
      p[i] = (int8_T)(i + 1);
    }
    for (k = 0; k < 5; k++) {
      i = ipiv[k];
      if (i > k + 1) {
        pipk = p[i - 1];
        p[i - 1] = p[k];
        p[k] = (int8_T)pipk;
      }
    }
    for (k = 0; k < 6; k++) {
      idxAjjp1 = 6 * (p[k] - 1);
      Theta[k + idxAjjp1] = 1.0;
      for (j = k + 1; j < 7; j++) {
        i = (j + idxAjjp1) - 1;
        if (Theta[i] != 0.0) {
          kAcol = j + 1;
          for (info = kAcol; info < 7; info++) {
            pipk = (info + idxAjjp1) - 1;
            Theta[pipk] -= Theta[i] * c_x[(info + 6 * (j - 1)) - 1];
          }
        }
      }
    }
    for (j = 0; j < 6; j++) {
      pipk = 6 * j;
      for (k = 5; k >= 0; k--) {
        kAcol = 6 * k;
        i = k + pipk;
        d = Theta[i];
        if (d != 0.0) {
          Theta[i] = d / c_x[k + kAcol];
          for (info = 0; info < k; info++) {
            idxAjjp1 = info + pipk;
            Theta[idxAjjp1] -= Theta[i] * c_x[info + kAcol];
          }
        }
      }
    }
    c_st.site = &q_emlrtRSI;
    n1x = 0.0;
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j < 6)) {
      b_s = 0.0;
      for (info = 0; info < 6; info++) {
        b_s += muDoubleScalarAbs(b_x[info + 6 * j]);
      }
      if (muDoubleScalarIsNaN(b_s)) {
        n1x = rtNaN;
        exitg1 = true;
      } else {
        if (b_s > n1x) {
          n1x = b_s;
        }
        j++;
      }
    }
    n1xinv = 0.0;
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j < 6)) {
      b_s = 0.0;
      for (info = 0; info < 6; info++) {
        b_s += muDoubleScalarAbs(Theta[info + 6 * j]);
      }
      if (muDoubleScalarIsNaN(b_s)) {
        n1xinv = rtNaN;
        exitg1 = true;
      } else {
        if (b_s > n1xinv) {
          n1xinv = b_s;
        }
        j++;
      }
    }
    constraint_tightening = 1.0 / (n1x * n1xinv);
    if ((n1x == 0.0) || (n1xinv == 0.0) || (constraint_tightening == 0.0)) {
      d_st.site = &bb_emlrtRSI;
      warning(&d_st);
    } else if (muDoubleScalarIsNaN(constraint_tightening) ||
               (constraint_tightening < 2.2204460492503131E-16)) {
      char_T str[14];
      d_st.site = &cb_emlrtRSI;
      y = NULL;
      m = emlrtCreateCharArray(2, &iv[0]);
      emlrtInitCharArrayR2013a(&d_st, 6, m, &rfmt[0]);
      emlrtAssign(&y, m);
      b_y = NULL;
      m = emlrtCreateDoubleScalar(constraint_tightening);
      emlrtAssign(&b_y, m);
      e_st.site = &vc_emlrtRSI;
      emlrt_marshallIn(&e_st, b_sprintf(&e_st, y, b_y, &c_emlrtMCI),
                       "<output of sprintf>", str);
      d_st.site = &cb_emlrtRSI;
      b_warning(&d_st, str);
    }
    b_st.site = &db_emlrtRSI;
    c_st.site = &eb_emlrtRSI;
    d_st.site = &gb_emlrtRSI;
    e_st.site = &hb_emlrtRSI;
    info = 0;
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j < 6)) {
      pipk = j * 6;
      kAcol = pipk + j;
      constraint_tightening = 0.0;
      if (j >= 1) {
        for (k = 0; k < j; k++) {
          n1x = Theta[pipk + k];
          constraint_tightening += n1x * n1x;
        }
      }
      n1x = Theta[kAcol] - constraint_tightening;
      if (n1x > 0.0) {
        n1x = muDoubleScalarSqrt(n1x);
        Theta[kAcol] = n1x;
        if (j + 1 < 6) {
          idxAjjp1 = kAcol + 7;
          f_st.site = &kb_emlrtRSI;
          zlacgv(&f_st, j, pipk + 1);
          if (j >= 1) {
            constraint_tightening = -1.0;
            n1xinv = 1.0;
            TRANSA = 'T';
            m_t = (ptrdiff_t)j;
            n_t = (ptrdiff_t)(5 - j);
            lda_t = (ptrdiff_t)6;
            incx_t = (ptrdiff_t)1;
            incy_t = (ptrdiff_t)6;
            dgemv(&TRANSA, &m_t, &n_t, &constraint_tightening, &Theta[pipk + 6],
                  &lda_t, &Theta[pipk], &incx_t, &n1xinv, &Theta[kAcol + 6],
                  &incy_t);
          }
          f_st.site = &ib_emlrtRSI;
          zlacgv(&f_st, j, pipk + 1);
          constraint_tightening = 1.0 / n1x;
          i = (kAcol + 6 * (4 - j)) + 7;
          for (k = idxAjjp1; k <= i; k += 6) {
            Theta[k - 1] *= constraint_tightening;
          }
        }
        j++;
      } else {
        Theta[kAcol] = n1x;
        info = j + 1;
        exitg1 = true;
      }
    }
    if (info == 0) {
      pipk = 6;
    } else {
      pipk = info - 1;
    }
    i = pipk - 2;
    for (j = 0; j <= i; j++) {
      kAcol = j + 2;
      c_st.site = &fb_emlrtRSI;
      if (kAcol <= pipk) {
        memset(&Theta[(j * 6 + kAcol) + -1], 0,
               (uint32_T)((pipk - kAcol) + 1) * sizeof(real_T));
      }
    }
    if (info != 0) {
      emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:posdef",
                                    "MATLAB:posdef", 0);
    }
    for (i = 0; i < 6; i++) {
      for (kAcol = 0; kAcol < 6; kAcol++) {
        d = 0.0;
        for (pipk = 0; pipk < 6; pipk++) {
          d += Theta[i + 6 * pipk] * plant_Bwx[pipk + 6 * kAcol];
        }
        b_x[i + 6 * kAcol] = d;
      }
    }
    st.site = &b_emlrtRSI;
    b_p = true;
    for (k = 0; k < 36; k++) {
      if (b_p) {
        d = b_x[k];
        if (muDoubleScalarIsInf(d) || muDoubleScalarIsNaN(d)) {
          b_p = false;
        }
      } else {
        b_p = false;
      }
    }
    if (b_p) {
      b_st.site = &ob_emlrtRSI;
      c_st.site = &pb_emlrtRSI;
      d_st.site = &qb_emlrtRSI;
      e_st.site = &rb_emlrtRSI;
      xzsvdc(&e_st, b_x, s);
    } else {
      for (info = 0; info < 6; info++) {
        s[info] = rtNaN;
      }
    }
    if (!muDoubleScalarIsNaN(s[0])) {
      pipk = 1;
    } else {
      pipk = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 7)) {
        if (!muDoubleScalarIsNaN(s[k - 1])) {
          pipk = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (pipk == 0) {
      constraint_tightening = s[0];
    } else {
      constraint_tightening = s[pipk - 1];
      i = pipk + 1;
      for (k = i; k < 7; k++) {
        d = s[k - 1];
        if (constraint_tightening < d) {
          constraint_tightening = d;
        }
      }
    }
    /*  maximum singular value % this is locally Lipschitz */
    st.site = &c_emlrtRSI;
    if (Erem < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    constraint_tightening =
        constraint_tightening * cp_quantile * muDoubleScalarSqrt(Erem);
  } else {
    constraint_tightening = 0.0;
  }
  st.site = &d_emlrtRSI;
  b_st.site = &d_emlrtRSI;
  W_fcn1(x, b_x);
  for (i = 0; i < 6; i++) {
    s[i] = gamma_s[i + 48];
  }
  b_st.site = &mc_emlrtRSI;
  mrdiv(&b_st, s, b_x);
  for (i = 0; i < 2; i++) {
    d = 0.0;
    for (kAcol = 0; kAcol < 6; kAcol++) {
      d += s[kAcol] * plant_Bx[kAcol + 6 * i];
    }
    A[i] = d;
  }
  A[2] = -1.0;
  st.site = &e_emlrtRSI;
  b_st.site = &e_emlrtRSI;
  W_fcn1(x_nom, b_x);
  for (i = 0; i < 6; i++) {
    Y[i] = gamma_s[i];
  }
  b_st.site = &mc_emlrtRSI;
  mrdiv(&b_st, Y, b_x);
  b_s = 0.0;
  n1x = 0.0;
  d = u_nom[0];
  d1 = u_nom[1];
  for (i = 0; i < 6; i++) {
    b_s += s[i] * (plant_fx[i] + (plant_Bx[i] * d + plant_Bx[i + 6] * d1));
    n1xinv = plant_fx_nom[i] + (plant_Bx_nom[i] * d + plant_Bx_nom[i + 6] * d1);
    s[i] = n1xinv;
    n1x += Y[i] * n1xinv;
  }
  constraint_tightening += (b_s - n1x) + controller_lambda * Erem;
  /*  Analytic solution */
  if (constraint_tightening <= 0.0) {
    constraint_tightening = 0.0;
  } else {
    st.site = &f_emlrtRSI;
    inv(&st, H, b);
    n1x = 0.0;
    for (i = 0; i < 3; i++) {
      n1x += ((A[0] * b[3 * i] + A[1] * b[3 * i + 1]) - b[3 * i + 2]) * A[i];
    }
    if (n1x < 1.0E-8) {
      constraint_tightening = 0.0;
    } else {
      st.site = &g_emlrtRSI;
      inv(&st, H, b);
      n1x = 0.0;
      for (i = 0; i < 3; i++) {
        n1x += ((A[0] * b[3 * i] + A[1] * b[3 * i + 1]) - b[3 * i + 2]) * A[i];
      }
      constraint_tightening = 2.0 * constraint_tightening / n1x;
    }
  }
  st.site = &h_emlrtRSI;
  inv(&st, H, b);
  constraint_tightening *= -0.5;
  d = A[0];
  d1 = A[1];
  for (i = 0; i < 3; i++) {
    u[i] = (constraint_tightening * b[3 * i] * d +
            constraint_tightening * b[3 * i + 1] * d1) -
           constraint_tightening * b[3 * i + 2];
  }
  /*  uc = u_nom + u(1:nu); */
  /*  slack = u(end); */
}

/* End of code generation (compute_u_ccm.c) */
