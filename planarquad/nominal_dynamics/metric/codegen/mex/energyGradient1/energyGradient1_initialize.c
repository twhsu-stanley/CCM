/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * energyGradient1_initialize.c
 *
 * Code generation for function 'energyGradient1_initialize'
 *
 */

/* Include files */
#include "energyGradient1_initialize.h"
#include "_coder_energyGradient1_mex.h"
#include "energyGradient1.h"
#include "energyGradient1_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void energyGradient1_once(const emlrtStack *sp);

/* Function Definitions */
static void energyGradient1_once(const emlrtStack *sp)
{
  emlrtStack st;
  mex_InitInfAndNan();
  st.prev = sp;
  st.tls = sp->tls;
  st.site = NULL;
  energyGradient1_emx_init(&st);
  energyGradient1_init();
}

void energyGradient1_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    energyGradient1_once(&st);
  }
}

/* End of code generation (energyGradient1_initialize.c) */
