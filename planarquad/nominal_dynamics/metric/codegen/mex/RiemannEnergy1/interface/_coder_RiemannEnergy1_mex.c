/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_RiemannEnergy1_mex.c
 *
 * Code generation for function '_coder_RiemannEnergy1_mex'
 *
 */

/* Include files */
#include "_coder_RiemannEnergy1_mex.h"
#include "RiemannEnergy1_data.h"
#include "RiemannEnergy1_initialize.h"
#include "RiemannEnergy1_terminate.h"
#include "_coder_RiemannEnergy1_api.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void RiemannEnergy1_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                                const mxArray *prhs[7])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 7, 4,
                        14, "RiemannEnergy1");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 14,
                        "RiemannEnergy1");
  }
  /* Call the function. */
  RiemannEnergy1_api(prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&RiemannEnergy1_atexit);
  RiemannEnergy1_initialize();
  RiemannEnergy1_mexFunction(nlhs, plhs, nrhs, prhs);
  RiemannEnergy1_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "windows-1252", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_RiemannEnergy1_mex.c) */
