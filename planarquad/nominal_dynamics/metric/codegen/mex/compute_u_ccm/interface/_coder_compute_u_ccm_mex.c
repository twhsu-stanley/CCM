/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_compute_u_ccm_mex.c
 *
 * Code generation for function '_coder_compute_u_ccm_mex'
 *
 */

/* Include files */
#include "_coder_compute_u_ccm_mex.h"
#include "_coder_compute_u_ccm_api.h"
#include "compute_u_ccm_data.h"
#include "compute_u_ccm_initialize.h"
#include "compute_u_ccm_terminate.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void compute_u_ccm_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                               const mxArray *prhs[14])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 14) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 14, 4,
                        13, "compute_u_ccm");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "compute_u_ccm");
  }
  /* Call the function. */
  compute_u_ccm_api(prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&compute_u_ccm_atexit);
  compute_u_ccm_initialize();
  compute_u_ccm_mexFunction(nlhs, plhs, nrhs, prhs);
  compute_u_ccm_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "windows-1252", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_compute_u_ccm_mex.c) */
