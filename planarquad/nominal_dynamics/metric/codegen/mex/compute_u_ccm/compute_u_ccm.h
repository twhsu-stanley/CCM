/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * compute_u_ccm.h
 *
 * Code generation for function 'compute_u_ccm'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void compute_u_ccm(const emlrtStack *sp, const real_T x[6],
                   const real_T x_nom[6], const real_T u_nom[2], real_T Erem,
                   const real_T gamma_s[54], const real_T H[9],
                   real_T controller_lambda, int8_T use_cp, real_T cp_quantile,
                   const real_T plant_fx[6], const real_T plant_fx_nom[6],
                   const real_T plant_Bx[12], const real_T plant_Bx_nom[12],
                   const real_T plant_Bwx[36], real_T u[3]);

/* End of code generation (compute_u_ccm.h) */
