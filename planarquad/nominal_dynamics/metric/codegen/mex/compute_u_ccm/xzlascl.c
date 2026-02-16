/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzlascl.c
 *
 * Code generation for function 'xzlascl'
 *
 */

/* Include files */
#include "xzlascl.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Function Definitions */
void b_xzlascl(real_T cfrom, real_T cto, real_T A[36])
{
  real_T cfromc;
  real_T ctoc;
  int32_T i;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    real_T cfrom1;
    real_T cto1;
    real_T mul;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((muDoubleScalarAbs(cfrom1) > muDoubleScalarAbs(ctoc)) &&
        (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (muDoubleScalarAbs(cto1) > muDoubleScalarAbs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    for (i = 0; i <= 34; i += 2) {
      __m128d r;
      r = _mm_loadu_pd(&A[i]);
      r = _mm_mul_pd(r, _mm_set1_pd(mul));
      _mm_storeu_pd(&A[i], r);
    }
  }
}

void xzlascl(real_T cfrom, real_T cto, real_T A[6])
{
  real_T cfromc;
  real_T ctoc;
  boolean_T notdone;
  cfromc = cfrom;
  ctoc = cto;
  notdone = true;
  while (notdone) {
    __m128d r;
    __m128d r1;
    real_T cfrom1;
    real_T cto1;
    real_T mul;
    cfrom1 = cfromc * 2.0041683600089728E-292;
    cto1 = ctoc / 4.9896007738368E+291;
    if ((muDoubleScalarAbs(cfrom1) > muDoubleScalarAbs(ctoc)) &&
        (ctoc != 0.0)) {
      mul = 2.0041683600089728E-292;
      cfromc = cfrom1;
    } else if (muDoubleScalarAbs(cto1) > muDoubleScalarAbs(cfromc)) {
      mul = 4.9896007738368E+291;
      ctoc = cto1;
    } else {
      mul = ctoc / cfromc;
      notdone = false;
    }
    r = _mm_loadu_pd(&A[0]);
    r1 = _mm_set1_pd(mul);
    _mm_storeu_pd(&A[0], _mm_mul_pd(r, r1));
    r = _mm_loadu_pd(&A[2]);
    _mm_storeu_pd(&A[2], _mm_mul_pd(r, r1));
    r = _mm_loadu_pd(&A[4]);
    _mm_storeu_pd(&A[4], _mm_mul_pd(r, r1));
  }
}

/* End of code generation (xzlascl.c) */
