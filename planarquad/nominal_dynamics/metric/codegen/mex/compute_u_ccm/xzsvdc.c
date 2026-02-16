/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzsvdc.c
 *
 * Code generation for function 'xzsvdc'
 *
 */

/* Include files */
#include "xzsvdc.h"
#include "compute_u_ccm_data.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xscal.h"
#include "xzlangeM.h"
#include "xzlascl.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo sb_emlrtRSI = {
    431,      /* lineNo */
    "xzsvdc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo tb_emlrtRSI = {
    418,      /* lineNo */
    "xzsvdc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo ub_emlrtRSI = {
    415,      /* lineNo */
    "xzsvdc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo vb_emlrtRSI = {
    404,      /* lineNo */
    "xzsvdc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo wb_emlrtRSI = {
    377,      /* lineNo */
    "xzsvdc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo xb_emlrtRSI = {
    375,      /* lineNo */
    "xzsvdc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo yb_emlrtRSI = {
    358,      /* lineNo */
    "xzsvdc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo ac_emlrtRSI = {
    144,      /* lineNo */
    "xzsvdc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo bc_emlrtRSI = {
    138,      /* lineNo */
    "xzsvdc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo cc_emlrtRSI = {
    106,      /* lineNo */
    "xzsvdc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo dc_emlrtRSI = {
    101,      /* lineNo */
    "xzsvdc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pathName */
};

static emlrtRSInfo gc_emlrtRSI = {
    21,                   /* lineNo */
    "scaleVectorByRecip", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\scaleVectorByRecip.m" /* pathName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    293,      /* lineNo */
    13,       /* colNo */
    "xzsvdc", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzsvdc.m" /* pName */
};

/* Function Definitions */
void xzsvdc(const emlrtStack *sp, real_T A[36], real_T S[6])
{
  emlrtStack b_st;
  emlrtStack st;
  real_T e[6];
  real_T s[6];
  real_T work[6];
  real_T anrm;
  real_T b;
  real_T cscale;
  real_T nrm;
  real_T rt;
  real_T scale;
  real_T sm;
  real_T sn;
  real_T snorm;
  real_T sqds;
  int32_T i;
  int32_T ii;
  int32_T iter;
  int32_T k;
  int32_T m;
  int32_T q;
  int32_T qp1;
  int32_T qs;
  int32_T scalarLB;
  boolean_T doscale;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  for (i = 0; i < 6; i++) {
    s[i] = 0.0;
    e[i] = 0.0;
    work[i] = 0.0;
  }
  doscale = false;
  anrm = xzlangeM(A);
  cscale = anrm;
  if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
    doscale = true;
    cscale = 6.7178761075670888E-139;
    b_xzlascl(anrm, cscale, A);
  } else if (anrm > 1.4885657073574029E+138) {
    doscale = true;
    cscale = 1.4885657073574029E+138;
    b_xzlascl(anrm, cscale, A);
  }
  for (q = 0; q < 5; q++) {
    __m128d r;
    boolean_T apply_transform;
    qp1 = q + 2;
    m = q + 6 * q;
    i = m + 1;
    apply_transform = false;
    st.site = &dc_emlrtRSI;
    nrm = xnrm2(&st, 6 - q, A, m + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (A[m] < 0.0) {
        sqds = -nrm;
      } else {
        sqds = nrm;
      }
      s[q] = sqds;
      st.site = &cc_emlrtRSI;
      if (muDoubleScalarAbs(sqds) >= 1.0020841800044864E-292) {
        b_st.site = &gc_emlrtRSI;
        xscal(&b_st, 6 - q, 1.0 / sqds, A, m + 1);
      } else {
        qs = (m - q) + 6;
        scalarLB = ((((qs - m) / 2) << 1) + m) + 1;
        iter = scalarLB - 2;
        for (k = i; k <= iter; k += 2) {
          r = _mm_loadu_pd(&A[k - 1]);
          _mm_storeu_pd(&A[k - 1], _mm_div_pd(r, _mm_set1_pd(s[q])));
        }
        for (k = scalarLB; k <= qs; k++) {
          A[k - 1] /= s[q];
        }
      }
      A[m]++;
      s[q] = -s[q];
    } else {
      s[q] = 0.0;
    }
    for (qs = qp1; qs < 7; qs++) {
      i = q + 6 * (qs - 1);
      if (apply_transform) {
        xaxpy(6 - q, -(xdotc(6 - q, A, m + 1, A, i + 1) / A[m]), m + 1, A,
              i + 1);
      }
      e[qs - 1] = A[i];
    }
    if (q + 1 <= 4) {
      st.site = &bc_emlrtRSI;
      nrm = b_xnrm2(&st, 5 - q, e, q + 2);
      if (nrm == 0.0) {
        e[q] = 0.0;
      } else {
        if (e[q + 1] < 0.0) {
          e[q] = -nrm;
        } else {
          e[q] = nrm;
        }
        st.site = &ac_emlrtRSI;
        sm = e[q];
        if (muDoubleScalarAbs(e[q]) >= 1.0020841800044864E-292) {
          b_st.site = &gc_emlrtRSI;
          b_xscal(&b_st, 5 - q, 1.0 / e[q], e, q + 2);
        } else {
          scalarLB = ((((5 - q) / 2) << 1) + q) + 2;
          iter = scalarLB - 2;
          for (k = qp1; k <= iter; k += 2) {
            r = _mm_loadu_pd(&e[k - 1]);
            _mm_storeu_pd(&e[k - 1], _mm_div_pd(r, _mm_set1_pd(sm)));
          }
          for (k = scalarLB; k < 7; k++) {
            e[k - 1] /= sm;
          }
        }
        e[q + 1]++;
        e[q] = -e[q];
        for (ii = qp1; ii < 7; ii++) {
          work[ii - 1] = 0.0;
        }
        for (qs = qp1; qs < 7; qs++) {
          b_xaxpy(5 - q, e[qs - 1], A, (q + 6 * (qs - 1)) + 2, work, q + 2);
        }
        for (qs = qp1; qs < 7; qs++) {
          c_xaxpy(5 - q, -e[qs - 1] / e[q + 1], work, q + 2, A,
                  (q + 6 * (qs - 1)) + 2);
        }
      }
    }
  }
  m = 4;
  s[5] = A[35];
  e[4] = A[34];
  e[5] = 0.0;
  iter = 0;
  snorm = 0.0;
  for (q = 0; q < 6; q++) {
    sqds = s[q];
    nrm = sqds;
    if (sqds != 0.0) {
      rt = muDoubleScalarAbs(sqds);
      nrm = rt;
      s[q] = rt;
      if (q + 1 < 6) {
        e[q] /= sqds / rt;
      }
    }
    if (q + 1 < 6) {
      sqds = e[q];
      if (sqds != 0.0) {
        rt = muDoubleScalarAbs(sqds);
        e[q] = rt;
        s[q + 1] *= rt / sqds;
      }
    }
    snorm =
        muDoubleScalarMax(snorm, muDoubleScalarMax(muDoubleScalarAbs(nrm),
                                                   muDoubleScalarAbs(e[q])));
  }
  exitg1 = false;
  while ((!exitg1) && (m + 2 > 0)) {
    if (iter >= 75) {
      emlrtErrorWithMessageIdR2018a(sp, &c_emlrtRTEI,
                                    "Coder:MATLAB:svd_NoConvergence",
                                    "Coder:MATLAB:svd_NoConvergence", 0);
    } else {
      boolean_T exitg2;
      scalarLB = m + 1;
      ii = m + 1;
      exitg2 = false;
      while (!(exitg2 || (ii == 0))) {
        nrm = muDoubleScalarAbs(e[ii - 1]);
        if ((nrm <= 2.2204460492503131E-16 * (muDoubleScalarAbs(s[ii - 1]) +
                                              muDoubleScalarAbs(s[ii]))) ||
            (nrm <= 1.0020841800044864E-292) ||
            ((iter > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
          e[ii - 1] = 0.0;
          exitg2 = true;
        } else {
          ii--;
        }
      }
      if (ii == m + 1) {
        i = 4;
      } else {
        qs = m + 2;
        i = m + 2;
        exitg2 = false;
        while ((!exitg2) && (i >= ii)) {
          qs = i;
          if (i == ii) {
            exitg2 = true;
          } else {
            nrm = 0.0;
            if (i < m + 2) {
              nrm = muDoubleScalarAbs(e[i - 1]);
            }
            if (i > ii + 1) {
              nrm += muDoubleScalarAbs(e[i - 2]);
            }
            rt = muDoubleScalarAbs(s[i - 1]);
            if ((rt <= 2.2204460492503131E-16 * nrm) ||
                (rt <= 1.0020841800044864E-292)) {
              s[i - 1] = 0.0;
              exitg2 = true;
            } else {
              i--;
            }
          }
        }
        if (qs == ii) {
          i = 3;
        } else if (qs == m + 2) {
          i = 1;
        } else {
          i = 2;
          ii = qs;
        }
      }
      switch (i) {
      case 1:
        rt = e[m];
        e[m] = 0.0;
        for (k = scalarLB; k >= ii + 1; k--) {
          st.site = &yb_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&s[k - 1], &rt, &scale, &sn);
          if (k > ii + 1) {
            nrm = e[k - 2];
            rt = -sn * nrm;
            e[k - 2] = nrm * scale;
          }
        }
        break;
      case 2:
        rt = e[ii - 1];
        e[ii - 1] = 0.0;
        st.site = &xb_emlrtRSI;
        for (k = ii + 1; k <= m + 2; k++) {
          st.site = &wb_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&s[k - 1], &rt, &scale, &sn);
          nrm = e[k - 1];
          rt = -sn * nrm;
          e[k - 1] = nrm * scale;
        }
        break;
      case 3:
        nrm = s[m + 1];
        scale = muDoubleScalarMax(
            muDoubleScalarMax(
                muDoubleScalarMax(muDoubleScalarMax(muDoubleScalarAbs(nrm),
                                                    muDoubleScalarAbs(s[m])),
                                  muDoubleScalarAbs(e[m])),
                muDoubleScalarAbs(s[ii])),
            muDoubleScalarAbs(e[ii]));
        sm = nrm / scale;
        nrm = s[m] / scale;
        rt = e[m] / scale;
        sqds = s[ii] / scale;
        b = ((nrm + sm) * (nrm - sm) + rt * rt) / 2.0;
        nrm = sm * rt;
        nrm *= nrm;
        if ((b != 0.0) || (nrm != 0.0)) {
          rt = b * b + nrm;
          st.site = &vb_emlrtRSI;
          if (rt < 0.0) {
            emlrtErrorWithMessageIdR2018a(
                &st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
          }
          rt = muDoubleScalarSqrt(rt);
          if (b < 0.0) {
            rt = -rt;
          }
          rt = nrm / (b + rt);
        } else {
          rt = 0.0;
        }
        rt += (sqds + sm) * (sqds - sm);
        nrm = sqds * (e[ii] / scale);
        st.site = &ub_emlrtRSI;
        for (k = ii + 1; k <= scalarLB; k++) {
          st.site = &tb_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&rt, &nrm, &scale, &sn);
          if (k > ii + 1) {
            e[k - 2] = rt;
          }
          nrm = e[k - 1];
          rt = s[k - 1];
          sm = scale * rt + sn * nrm;
          e[k - 1] = scale * nrm - sn * rt;
          sqds = s[k];
          b = sn * sqds;
          sqds *= scale;
          st.site = &sb_emlrtRSI;
          scale = 0.0;
          sn = 0.0;
          drotg(&sm, &b, &scale, &sn);
          s[k - 1] = sm;
          nrm = e[k - 1];
          rt = scale * nrm + sn * sqds;
          sqds = -sn * nrm + scale * sqds;
          s[k] = sqds;
          nrm = sn * e[k];
          e[k] *= scale;
        }
        e[m] = rt;
        iter++;
        break;
      default:
        if (s[ii] < 0.0) {
          s[ii] = -s[ii];
        }
        qp1 = ii + 1;
        while ((ii + 1 < 6) && (s[ii] < s[qp1])) {
          rt = s[ii];
          s[ii] = s[qp1];
          s[qp1] = rt;
          ii = qp1;
          qp1++;
        }
        iter = 0;
        m--;
        break;
      }
    }
  }
  for (k = 0; k < 6; k++) {
    S[k] = s[k];
  }
  if (doscale) {
    xzlascl(cscale, anrm, S);
  }
}

/* End of code generation (xzsvdc.c) */
