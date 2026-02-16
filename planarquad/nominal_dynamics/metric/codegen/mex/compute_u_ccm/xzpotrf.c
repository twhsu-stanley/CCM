/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzpotrf.c
 *
 * Code generation for function 'xzpotrf'
 *
 */

/* Include files */
#include "xzpotrf.h"
#include "compute_u_ccm_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo lb_emlrtRSI = {
    121,      /* lineNo */
    "zlacgv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzpotrf.m" /* pathName */
};

/* Function Definitions */
void zlacgv(const emlrtStack *sp, int32_T n, int32_T ix0)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (n > 0) {
    int32_T b;
    b = (ix0 + n) - 1;
    st.site = &lb_emlrtRSI;
    if ((ix0 <= b) && (b > 2147483646)) {
      b_st.site = &v_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
  }
}

/* End of code generation (xzpotrf.c) */
