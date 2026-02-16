/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * energyGradient1_terminate.c
 *
 * Code generation for function 'energyGradient1_terminate'
 *
 */

/* Include files */
#include "energyGradient1_terminate.h"
#include "_coder_energyGradient1_mex.h"
#include "energyGradient1.h"
#include "energyGradient1_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void c_energyGradient1_emx_free_dtor(const emlrtStack *sp,
                                            const void *r);

static void emlrtExitTimeCleanupDtorFcn(const void *r);

/* Function Definitions */
static void c_energyGradient1_emx_free_dtor(const emlrtStack *sp, const void *r)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = NULL;
  energyGradient1_emx_free(&st);
}

static void emlrtExitTimeCleanupDtorFcn(const void *r)
{
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void energyGradient1_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtPushHeapReferenceStackR2021a(
      &st, false, NULL, (void *)&emlrtExitTimeCleanupDtorFcn, NULL, NULL, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtPushHeapReferenceStackR2021a(&st, true, NULL,
                                    (void *)&c_energyGradient1_emx_free_dtor,
                                    NULL, NULL, NULL);
  energyGradient1_emx_free(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void energyGradient1_terminate(void)
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (energyGradient1_terminate.c) */
