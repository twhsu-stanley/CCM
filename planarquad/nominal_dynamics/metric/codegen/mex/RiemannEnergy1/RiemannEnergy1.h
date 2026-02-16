/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * RiemannEnergy1.h
 *
 * Code generation for function 'RiemannEnergy1'
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
real_T RiemannEnergy1(const emlrtStack *sp, const real_T c[18], real_T n,
                      real_T D, real_T N, const real_T T[27],
                      const real_T T_dot[27], const real_T w[9]);

/* End of code generation (RiemannEnergy1.h) */
