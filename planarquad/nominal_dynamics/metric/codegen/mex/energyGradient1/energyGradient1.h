/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * energyGradient1.h
 *
 * Code generation for function 'energyGradient1'
 *
 */

#pragma once

/* Include files */
#include "energyGradient1_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void energyGradient1(const emlrtStack *sp, const real_T c[18], real_T n,
                     real_T D, real_T N, const real_T T[27],
                     const real_T T_dot[27], const real_T w[9],
                     emxArray_real_T *g);

void energyGradient1_emx_free(const emlrtStack *sp);

void energyGradient1_emx_init(const emlrtStack *sp);

void energyGradient1_init(void);

/* End of code generation (energyGradient1.h) */
