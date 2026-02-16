/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * norm.c
 *
 * Code generation for function 'norm'
 *
 */

/* Include files */
#include "norm.h"
#include "eml_int_forloop_overflow_check.h"
#include "energyGradient1_data.h"
#include "energyGradient1_emxutil.h"
#include "energyGradient1_types.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo k_emlrtRSI = {
    119,    /* lineNo */
    "norm", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\norm.m" /* pathName
                                                                        */
};

static emlrtRSInfo l_emlrtRSI = {
    147,        /* lineNo */
    "mat2norm", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\norm.m" /* pathName
                                                                        */
};

static emlrtRSInfo m_emlrtRSI = {
    148,        /* lineNo */
    "mat2norm", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\norm.m" /* pathName
                                                                        */
};

static emlrtRSInfo n_emlrtRSI = {
    156,        /* lineNo */
    "mat2norm", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\norm.m" /* pathName
                                                                        */
};

static emlrtRSInfo p_emlrtRSI = {
    28,    /* lineNo */
    "svd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pathName
                                                                          */
};

static emlrtRSInfo q_emlrtRSI = {
    107,          /* lineNo */
    "callLAPACK", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pathName
                                                                          */
};

static emlrtRSInfo r_emlrtRSI = {
    31,       /* lineNo */
    "xgesvd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pathName */
};

static emlrtRSInfo s_emlrtRSI = {
    205,            /* lineNo */
    "ceval_xgesvd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pathName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    48,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

static emlrtRTEInfo l_emlrtRTEI = {
    45,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    111,          /* lineNo */
    5,            /* colNo */
    "callLAPACK", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pName
                                                                          */
};

static emlrtRTEInfo gb_emlrtRTEI = {
    31,       /* lineNo */
    33,       /* colNo */
    "xgesvd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    98,       /* lineNo */
    20,       /* colNo */
    "xgesvd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = {
    131,      /* lineNo */
    9,        /* colNo */
    "xgesvd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = {
    129,      /* lineNo */
    33,       /* colNo */
    "xgesvd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = {
    156,    /* lineNo */
    5,      /* colNo */
    "norm", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\matfun\\norm.m" /* pName
                                                                        */
};

static emlrtRTEInfo lb_emlrtRTEI = {
    129,      /* lineNo */
    9,        /* colNo */
    "xgesvd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pName */
};

/* Function Definitions */
real_T b_norm(const emlrtStack *sp, const emxArray_real_T *x)
{
  static const char_T fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 'g', 'e', 's', 'v', 'd'};
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_real_T *A;
  emxArray_real_T *s;
  emxArray_real_T *superb;
  const real_T *x_data;
  real_T y;
  real_T *A_data;
  real_T *s_data;
  real_T *superb_data;
  int32_T i;
  int32_T minnm;
  boolean_T MATRIX_INPUT_AND_P_IS_TWO;
  boolean_T VECTOR_INPUT_AND_P_IS_NUMERIC;
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
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  VECTOR_INPUT_AND_P_IS_NUMERIC = false;
  MATRIX_INPUT_AND_P_IS_TWO = false;
  if ((x->size[0] == 1) || (x->size[1] == 1)) {
    VECTOR_INPUT_AND_P_IS_NUMERIC = true;
  } else {
    MATRIX_INPUT_AND_P_IS_TWO = true;
  }
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    y = 0.0;
  } else if (MATRIX_INPUT_AND_P_IS_TWO) {
    int32_T m_tmp;
    int32_T n_tmp;
    st.site = &k_emlrtRSI;
    m_tmp = x->size[0];
    n_tmp = x->size[1];
    y = 0.0;
    b_st.site = &l_emlrtRSI;
    if (x->size[1] > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    VECTOR_INPUT_AND_P_IS_NUMERIC = (x->size[0] > 2147483646);
    for (minnm = 0; minnm < n_tmp; minnm++) {
      b_st.site = &m_emlrtRSI;
      if (VECTOR_INPUT_AND_P_IS_NUMERIC) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (i = 0; i < m_tmp; i++) {
        real_T absx;
        absx = muDoubleScalarAbs(x_data[i + x->size[0] * minnm]);
        if (muDoubleScalarIsNaN(absx) || (absx > y)) {
          y = absx;
        }
      }
    }
    if ((!muDoubleScalarIsInf(y)) && (!muDoubleScalarIsNaN(y))) {
      b_st.site = &n_emlrtRSI;
      c_st.site = &p_emlrtRSI;
      d_st.site = &q_emlrtRSI;
      e_st.site = &r_emlrtRSI;
      emxInit_real_T(&e_st, &A, 2, &gb_emlrtRTEI, true);
      i = A->size[0] * A->size[1];
      A->size[0] = x->size[0];
      A->size[1] = x->size[1];
      emxEnsureCapacity_real_T(&e_st, A, i, &gb_emlrtRTEI);
      A_data = A->data;
      minnm = x->size[0] * x->size[1];
      for (i = 0; i < minnm; i++) {
        A_data[i] = x_data[i];
      }
      minnm = muIntScalarMin_sint32(n_tmp, m_tmp);
      emxInit_real_T(&e_st, &s, 1, &kb_emlrtRTEI, true);
      i = s->size[0];
      s->size[0] = minnm;
      emxEnsureCapacity_real_T(&e_st, s, i, &hb_emlrtRTEI);
      s_data = s->data;
      emxInit_real_T(&e_st, &superb, 1, &lb_emlrtRTEI, true);
      if (minnm > 1) {
        i = superb->size[0];
        superb->size[0] = minnm - 1;
        emxEnsureCapacity_real_T(&e_st, superb, i, &jb_emlrtRTEI);
        superb_data = superb->data;
      } else {
        i = superb->size[0];
        superb->size[0] = 1;
        emxEnsureCapacity_real_T(&e_st, superb, i, &ib_emlrtRTEI);
        superb_data = superb->data;
      }
      n_t = LAPACKE_dgesvd(102, 'N', 'N', (ptrdiff_t)x->size[0],
                           (ptrdiff_t)x->size[1], &A_data[0],
                           (ptrdiff_t)x->size[0], &s_data[0], NULL,
                           (ptrdiff_t)1, NULL, (ptrdiff_t)1, &superb_data[0]);
      emxFree_real_T(&e_st, &superb);
      emxFree_real_T(&e_st, &A);
      f_st.site = &s_emlrtRSI;
      if ((int32_T)n_t < 0) {
        if ((int32_T)n_t == -1010) {
          emlrtErrorWithMessageIdR2018a(&f_st, &l_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&f_st, &k_emlrtRTEI,
                                        "Coder:toolbox:LAPACKCallErrorInfo",
                                        "Coder:toolbox:LAPACKCallErrorInfo", 5,
                                        4, 14, &fname[0], 12, (int32_T)n_t);
        }
      }
      if ((int32_T)n_t > 0) {
        emlrtErrorWithMessageIdR2018a(&c_st, &m_emlrtRTEI,
                                      "Coder:MATLAB:svd_NoConvergence",
                                      "Coder:MATLAB:svd_NoConvergence", 0);
      }
      y = s_data[0];
      emxFree_real_T(&st, &s);
    }
  } else if (VECTOR_INPUT_AND_P_IS_NUMERIC) {
    int32_T n_tmp;
    n_tmp = x->size[0] * x->size[1];
    if (n_tmp < 1) {
      y = 0.0;
    } else {
      n_t = (ptrdiff_t)n_tmp;
      incx_t = (ptrdiff_t)1;
      y = dnrm2(&n_t, (real_T *)&x_data[0], &incx_t);
    }
  } else {
    y = rtNaN;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return y;
}

/* End of code generation (norm.c) */
