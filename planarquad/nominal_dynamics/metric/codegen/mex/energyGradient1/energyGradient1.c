/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * energyGradient1.c
 *
 * Code generation for function 'energyGradient1'
 *
 */

/* Include files */
#include "energyGradient1.h"
#include "W_fcn1.h"
#include "assertValidSizeArg.h"
#include "dW_dxi_fcn1.h"
#include "energyGradient1_data.h"
#include "energyGradient1_emxutil.h"
#include "energyGradient1_types.h"
#include "mldivide.h"
#include "mtimes.h"
#include "norm.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emxArray_real_T *c_pre;

static boolean_T c_pre_not_empty;

static emxArray_real_T *g_pre;

static emlrtRSInfo
    emlrtRSI =
        {
            16,                /* lineNo */
            "energyGradient1", /* fcnName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pathName
                                                                            */
};

static emlrtRSInfo
    b_emlrtRSI =
        {
            17,                /* lineNo */
            "energyGradient1", /* fcnName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pathName
                                                                            */
};

static emlrtRSInfo
    c_emlrtRSI =
        {
            18,                /* lineNo */
            "energyGradient1", /* fcnName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pathName
                                                                            */
};

static emlrtRSInfo
    d_emlrtRSI =
        {
            19,                /* lineNo */
            "energyGradient1", /* fcnName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pathName
                                                                            */
};

static emlrtRSInfo
    e_emlrtRSI =
        {
            28,                /* lineNo */
            "energyGradient1", /* fcnName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pathName
                                                                            */
};

static emlrtRSInfo
    f_emlrtRSI =
        {
            30,                /* lineNo */
            "energyGradient1", /* fcnName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pathName
                                                                            */
};

static emlrtRSInfo
    g_emlrtRSI =
        {
            33,                /* lineNo */
            "energyGradient1", /* fcnName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pathName
                                                                            */
};

static emlrtRSInfo
    h_emlrtRSI =
        {
            35,                /* lineNo */
            "energyGradient1", /* fcnName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pathName
                                                                            */
};

static emlrtRSInfo i_emlrtRSI = {
    51,                  /* lineNo */
    "reshapeSizeChecks", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    113,               /* lineNo */
    "computeDimsData", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pathName */
};

static emlrtRSInfo t_emlrtRSI =
    {
        94,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" /* pathName */
};

static emlrtRSInfo u_emlrtRSI =
    {
        69,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" /* pathName */
};

static emlrtRSInfo kc_emlrtRSI = {
    41,    /* lineNo */
    "cat", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" /* pathName
                                                                          */
};

static emlrtRSInfo lc_emlrtRSI = {
    65,         /* lineNo */
    "cat_impl", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" /* pathName
                                                                          */
};

static emlrtRTEInfo emlrtRTEI =
    {
        133,                   /* lineNo */
        23,                    /* colNo */
        "dynamic_size_checks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" /* pName */
};

static emlrtRTEInfo b_emlrtRTEI =
    {
        138,                   /* lineNo */
        23,                    /* colNo */
        "dynamic_size_checks", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    225,                   /* lineNo */
    27,                    /* colNo */
    "check_non_axis_size", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m" /* pName
                                                                          */
};

static emlrtRTEInfo d_emlrtRTEI = {
    87,                  /* lineNo */
    23,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    85,                  /* lineNo */
    23,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    80,                  /* lineNo */
    13,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

static emlrtECInfo
    emlrtECI =
        {
            -1,                /* nDims */
            35,                /* lineNo */
            9,                 /* colNo */
            "energyGradient1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pName
                                                                            */
};

static emlrtECInfo
    b_emlrtECI =
        {
            2,                 /* nDims */
            35,                /* lineNo */
            34,                /* colNo */
            "energyGradient1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pName
                                                                            */
};

static emlrtECInfo
    c_emlrtECI =
        {
            2,                 /* nDims */
            35,                /* lineNo */
            72,                /* colNo */
            "energyGradient1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pName
                                                                            */
};

static emlrtECInfo
    d_emlrtECI =
        {
            1,                 /* nDims */
            35,                /* lineNo */
            72,                /* colNo */
            "energyGradient1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pName
                                                                            */
};

static emlrtBCInfo emlrtBCI =
    {
        1,                 /* iFirst */
        3,                 /* iLast */
        35,                /* lineNo */
        146,               /* colNo */
        "T",               /* aName */
        "energyGradient1", /* fName */
        "C:\\ACXIS "
        "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m", /* pName
                                                                         */
        0 /* checkKind */
};

static emlrtDCInfo emlrtDCI =
    {
        35,                /* lineNo */
        146,               /* colNo */
        "energyGradient1", /* fName */
        "C:\\ACXIS "
        "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m", /* pName
                                                                         */
        1 /* checkKind */
};

static emlrtDCInfo b_emlrtDCI =
    {
        35,                /* lineNo */
        114,               /* colNo */
        "energyGradient1", /* fName */
        "C:\\ACXIS "
        "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m", /* pName
                                                                         */
        1 /* checkKind */
};

static emlrtDCInfo c_emlrtDCI =
    {
        35,                /* lineNo */
        110,               /* colNo */
        "energyGradient1", /* fName */
        "C:\\ACXIS "
        "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m", /* pName
                                                                         */
        1 /* checkKind */
};

static emlrtDCInfo d_emlrtDCI =
    {
        35,                /* lineNo */
        110,               /* colNo */
        "energyGradient1", /* fName */
        "C:\\ACXIS "
        "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m", /* pName
                                                                         */
        4 /* checkKind */
};

static emlrtBCInfo b_emlrtBCI =
    {
        1,                 /* iFirst */
        3,                 /* iLast */
        35,                /* lineNo */
        96,                /* colNo */
        "T_dot",           /* aName */
        "energyGradient1", /* fName */
        "C:\\ACXIS "
        "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m", /* pName
                                                                         */
        0 /* checkKind */
};

static emlrtDCInfo e_emlrtDCI =
    {
        35,                /* lineNo */
        96,                /* colNo */
        "energyGradient1", /* fName */
        "C:\\ACXIS "
        "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m", /* pName
                                                                         */
        1 /* checkKind */
};

static emlrtDCInfo f_emlrtDCI =
    {
        35,                /* lineNo */
        83,                /* colNo */
        "energyGradient1", /* fName */
        "C:\\ACXIS "
        "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m", /* pName
                                                                         */
        1 /* checkKind */
};

static emlrtDCInfo g_emlrtDCI =
    {
        35,                /* lineNo */
        83,                /* colNo */
        "energyGradient1", /* fName */
        "C:\\ACXIS "
        "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m", /* pName
                                                                         */
        4 /* checkKind */
};

static emlrtRTEInfo
    g_emlrtRTEI =
        {
            32,                /* lineNo */
            13,                /* colNo */
            "energyGradient1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pName
                                                                            */
};

static emlrtBCInfo c_emlrtBCI =
    {
        1,                 /* iFirst */
        9,                 /* iLast */
        28,                /* lineNo */
        33,                /* colNo */
        "gamma",           /* aName */
        "energyGradient1", /* fName */
        "C:\\ACXIS "
        "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m", /* pName
                                                                         */
        0 /* checkKind */
};

static emlrtRTEInfo
    h_emlrtRTEI =
        {
            24,                /* lineNo */
            9,                 /* colNo */
            "energyGradient1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pName
                                                                            */
};

static emlrtDCInfo h_emlrtDCI =
    {
        20,                /* lineNo */
        13,                /* colNo */
        "energyGradient1", /* fName */
        "C:\\ACXIS "
        "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m", /* pName
                                                                         */
        1 /* checkKind */
};

static emlrtDCInfo i_emlrtDCI =
    {
        20,                /* lineNo */
        13,                /* colNo */
        "energyGradient1", /* fName */
        "C:\\ACXIS "
        "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m", /* pName
                                                                         */
        4 /* checkKind */
};

static emlrtECInfo
    e_emlrtECI =
        {
            2,                 /* nDims */
            17,                /* lineNo */
            9,                 /* colNo */
            "energyGradient1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pName
                                                                            */
};

static emlrtECInfo
    f_emlrtECI =
        {
            1,                 /* nDims */
            17,                /* lineNo */
            9,                 /* colNo */
            "energyGradient1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pName
                                                                            */
};

static emlrtDCInfo j_emlrtDCI =
    {
        7,                 /* lineNo */
        21,                /* colNo */
        "energyGradient1", /* fName */
        "C:\\ACXIS "
        "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m", /* pName
                                                                         */
        1 /* checkKind */
};

static emlrtDCInfo k_emlrtDCI =
    {
        7,                 /* lineNo */
        21,                /* colNo */
        "energyGradient1", /* fName */
        "C:\\ACXIS "
        "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m", /* pName
                                                                         */
        4 /* checkKind */
};

static emlrtDCInfo l_emlrtDCI =
    {
        6,                 /* lineNo */
        21,                /* colNo */
        "energyGradient1", /* fName */
        "C:\\ACXIS "
        "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m", /* pName
                                                                         */
        1 /* checkKind */
};

static emlrtDCInfo m_emlrtDCI =
    {
        6,                 /* lineNo */
        21,                /* colNo */
        "energyGradient1", /* fName */
        "C:\\ACXIS "
        "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m", /* pName
                                                                         */
        4 /* checkKind */
};

static emlrtDCInfo n_emlrtDCI =
    {
        6,                 /* lineNo */
        19,                /* colNo */
        "energyGradient1", /* fName */
        "C:\\ACXIS "
        "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m", /* pName
                                                                         */
        1 /* checkKind */
};

static emlrtDCInfo o_emlrtDCI =
    {
        6,                 /* lineNo */
        19,                /* colNo */
        "energyGradient1", /* fName */
        "C:\\ACXIS "
        "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m", /* pName
                                                                         */
        4 /* checkKind */
};

static emlrtDCInfo p_emlrtDCI =
    {
        35,                /* lineNo */
        36,                /* colNo */
        "energyGradient1", /* fName */
        "C:\\ACXIS "
        "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m", /* pName
                                                                         */
        1 /* checkKind */
};

static emlrtBCInfo d_emlrtBCI =
    {
        -1,                /* iFirst */
        -1,                /* iLast */
        35,                /* lineNo */
        36,                /* colNo */
        "g",               /* aName */
        "energyGradient1", /* fName */
        "C:\\ACXIS "
        "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m", /* pName
                                                                         */
        0 /* checkKind */
};

static emlrtBCInfo e_emlrtBCI =
    {
        -1,                /* iFirst */
        -1,                /* iLast */
        35,                /* lineNo */
        11,                /* colNo */
        "g",               /* aName */
        "energyGradient1", /* fName */
        "C:\\ACXIS "
        "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m", /* pName
                                                                         */
        0 /* checkKind */
};

static emlrtRTEInfo
    p_emlrtRTEI =
        {
            4,                 /* lineNo */
            12,                /* colNo */
            "energyGradient1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pName
                                                                            */
};

static emlrtRTEInfo
    q_emlrtRTEI =
        {
            4,                 /* lineNo */
            18,                /* colNo */
            "energyGradient1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pName
                                                                            */
};

static emlrtRTEInfo
    r_emlrtRTEI =
        {
            6,                 /* lineNo */
            5,                 /* colNo */
            "energyGradient1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pName
                                                                            */
};

static emlrtRTEInfo
    s_emlrtRTEI =
        {
            7,                 /* lineNo */
            5,                 /* colNo */
            "energyGradient1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pName
                                                                            */
};

static emlrtRTEInfo
    t_emlrtRTEI =
        {
            17,                /* lineNo */
            9,                 /* colNo */
            "energyGradient1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pName
                                                                            */
};

static emlrtRTEInfo
    u_emlrtRTEI =
        {
            41,                /* lineNo */
            5,                 /* colNo */
            "energyGradient1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pName
                                                                            */
};

static emlrtRTEInfo
    v_emlrtRTEI =
        {
            20,                /* lineNo */
            1,                 /* colNo */
            "energyGradient1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pName
                                                                            */
};

static emlrtRTEInfo
    w_emlrtRTEI =
        {
            38,                /* lineNo */
            5,                 /* colNo */
            "energyGradient1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pName
                                                                            */
};

static emlrtRTEInfo
    x_emlrtRTEI =
        {
            39,                /* lineNo */
            5,                 /* colNo */
            "energyGradient1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pName
                                                                            */
};

static emlrtRTEInfo
    y_emlrtRTEI =
        {
            35,                /* lineNo */
            72,                /* colNo */
            "energyGradient1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pName
                                                                            */
};

static emlrtRTEInfo ab_emlrtRTEI =
    {
        28,      /* lineNo */
        9,       /* colNo */
        "colon", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pName
                                                                          */
};

static emlrtRTEInfo
    bb_emlrtRTEI =
        {
            35,                /* lineNo */
            36,                /* colNo */
            "energyGradient1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pName
                                                                            */
};

static emlrtRTEInfo
    cb_emlrtRTEI =
        {
            35,                /* lineNo */
            11,                /* colNo */
            "energyGradient1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pName
                                                                            */
};

static emlrtRTEInfo
    db_emlrtRTEI =
        {
            35,                /* lineNo */
            34,                /* colNo */
            "energyGradient1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pName
                                                                            */
};

static emlrtRTEInfo
    eb_emlrtRTEI =
        {
            35,                /* lineNo */
            9,                 /* colNo */
            "energyGradient1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pName
                                                                            */
};

static emlrtRTEInfo
    fb_emlrtRTEI =
        {
            35,                /* lineNo */
            49,                /* colNo */
            "energyGradient1", /* fName */
            "C:\\ACXIS "
            "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m" /* pName
                                                                            */
};

/* Function Declarations */
static void binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                             const emxArray_real_T *in2,
                             const emxArray_real_T *in3,
                             const real_T in4_data[],
                             const int32_T in4_size[2]);

static void minus(real_T in1_data[], int32_T in1_size[2],
                  const emxArray_real_T *in2);

/* Function Definitions */
static void binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                             const emxArray_real_T *in2,
                             const emxArray_real_T *in3,
                             const real_T in4_data[], const int32_T in4_size[2])
{
  const real_T *in2_data;
  const real_T *in3_data;
  real_T *in1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in3_data = in3->data;
  in2_data = in2->data;
  i = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  emxEnsureCapacity_real_T(sp, in1, i, &db_emlrtRTEI);
  if (in4_size[1] == 1) {
    loop_ub = in3->size[1];
  } else {
    loop_ub = in4_size[1];
  }
  i = in1->size[0] * in1->size[1];
  in1->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &db_emlrtRTEI);
  in1_data = in1->data;
  stride_0_1 = (in3->size[1] != 1);
  stride_1_1 = (in4_size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = in2_data[(int32_T)in3_data[i * stride_0_1] - 1] +
                  in4_data[i * stride_1_1];
  }
}

static void minus(real_T in1_data[], int32_T in1_size[2],
                  const emxArray_real_T *in2)
{
  real_T b_in2_data[18];
  const real_T *in2_data;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_1;
  in2_data = in2->data;
  if (in1_size[1] == 1) {
    loop_ub = in2->size[1];
  } else {
    loop_ub = in1_size[1];
  }
  stride_0_0 = (in2->size[0] != 1);
  stride_0_1 = (in2->size[1] != 1);
  stride_1_1 = (in1_size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      b_in2_data[i1 + 6 * i] =
          in2_data[i1 * stride_0_0 + in2->size[0] * aux_0_1] -
          in1_data[i1 + 6 * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  in1_size[0] = 6;
  in1_size[1] = loop_ub;
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      stride_0_0 = i1 + 6 * i;
      in1_data[stride_0_0] = b_in2_data[stride_0_0];
    }
  }
}

void energyGradient1(const emlrtStack *sp, const real_T c[18], real_T n,
                     real_T D, real_T N, const real_T T[27],
                     const real_T T_dot[27], const real_T w[9],
                     emxArray_real_T *g)
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_int32_T *r1;
  emxArray_real_T *b_c;
  emxArray_real_T *r;
  emxArray_real_T *r2;
  emxArray_real_T *y;
  real_T c_data[324];
  real_T gamma_data[162];
  real_T gamma_s_data[162];
  real_T b_data[18];
  real_T M_x_gamma_sk_data[6];
  real_T b_W_fcn_eval[6];
  real_T T_dot_data[3];
  real_T dv[2];
  real_T alpha1;
  real_T b_w;
  real_T beta1;
  real_T *b_c_data;
  real_T *c_pre_data;
  real_T *g_data;
  real_T *g_pre_data;
  int32_T T_dot_size[2];
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T d_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T k;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  int32_T sizes_idx_0;
  int32_T sizes_tmp;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T *r5;
  char_T TRANSA1;
  char_T TRANSB1;
  boolean_T out;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  g_pre_data = g_pre->data;
  c_pre_data = c_pre->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*  Compute the gradient of the Riemann Energy under the pseudospectral method
   */
  /*  for code generation */
  if (!c_pre_not_empty) {
    /*  adding this may make the gradient calculatioin inaccurate */
    if (!(n >= 0.0)) {
      emlrtNonNegativeCheckR2012b(n, &o_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (n != (int32_T)muDoubleScalarFloor(n)) {
      emlrtIntegerCheckR2012b(n, &n_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (!(D + 1.0 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(D + 1.0, &m_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (D + 1.0 != (int32_T)muDoubleScalarFloor(D + 1.0)) {
      emlrtIntegerCheckR2012b(D + 1.0, &l_emlrtDCI, (emlrtConstCTX)sp);
    }
    i = c_pre->size[0] * c_pre->size[1];
    c_pre->size[0] = (int32_T)n;
    c_pre->size[1] = (int32_T)(D + 1.0);
    emxEnsureCapacity_real_T(sp, c_pre, i, &r_emlrtRTEI);
    c_pre_data = c_pre->data;
    loop_ub_tmp = (int32_T)n * (int32_T)(D + 1.0);
    for (i = 0; i < loop_ub_tmp; i++) {
      c_pre_data[i] = 0.0;
    }
    c_pre_not_empty = ((c_pre->size[0] != 0) && (c_pre->size[1] != 0));
    alpha1 = (D + 1.0) * n;
    if (!(alpha1 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(alpha1, &k_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (alpha1 != (int32_T)muDoubleScalarFloor(alpha1)) {
      emlrtIntegerCheckR2012b(alpha1, &j_emlrtDCI, (emlrtConstCTX)sp);
    }
    i = g_pre->size[0] * g_pre->size[1];
    g_pre->size[0] = 1;
    loop_ub_tmp = (int32_T)alpha1;
    g_pre->size[1] = (int32_T)alpha1;
    emxEnsureCapacity_real_T(sp, g_pre, i, &s_emlrtRTEI);
    g_pre_data = g_pre->data;
    for (i = 0; i < loop_ub_tmp; i++) {
      g_pre_data[i] = 0.0;
    }
  }
  /*      gamma = zeros(n,N+1); */
  /*      gamma_s = zeros(n,N+1); */
  /*      for i = 1:n    */
  /*         gamma(i,:) = c((i-1)*(D+1)+1:i*(D+1),:)'*T;       % gamma(i) is
   * 1*(N+1); the ith elment of gamma on all the (N+1) nodes */
  /*         gamma_s(i,:) = c((i-1)*(D+1)+1:i*(D+1),:)'*T_dot; */
  /*      end  */
  st.site = &emlrtRSI;
  b_st.site = &i_emlrtRSI;
  c_st.site = &j_emlrtRSI;
  assertValidSizeArg(&c_st, D + 1.0);
  c_st.site = &j_emlrtRSI;
  assertValidSizeArg(&c_st, n);
  if ((int32_T)(D + 1.0) > 18) {
    emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if ((int32_T)n > 18) {
    emlrtErrorWithMessageIdR2018a(&st, &f_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  out = ((int32_T)(D + 1.0) >= 0);
  if ((!out) || ((int32_T)n < 0)) {
    out = false;
  }
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &e_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  if ((int32_T)(D + 1.0) * (int32_T)n != 18) {
    emlrtErrorWithMessageIdR2018a(
        &st, &d_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  i1 = (int32_T)(D + 1.0);
  sizes_tmp = (int32_T)n;
  T_dot_size[0] = (int32_T)n;
  T_dot_size[1] = (int32_T)(D + 1.0);
  for (i = 0; i < i1; i++) {
    for (i2 = 0; i2 < sizes_tmp; i2++) {
      c_data[i2 + (int32_T)n * i] = c[i + (int32_T)(D + 1.0) * i2];
    }
  }
  /*  the ith row corresponds to the ith element */
  if (((int32_T)n != c_pre->size[0]) &&
      (((int32_T)n != 1) && (c_pre->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b((int32_T)n, c_pre->size[0], &f_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if (((int32_T)(D + 1.0) != c_pre->size[1]) &&
      (((int32_T)(D + 1.0) != 1) && (c_pre->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b((int32_T)(D + 1.0), c_pre->size[1], &e_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &b_c, 2, &t_emlrtRTEI, true);
  if (c_pre->size[0] == 1) {
    loop_ub = (int32_T)n;
  } else {
    loop_ub = c_pre->size[0];
  }
  i = b_c->size[0] * b_c->size[1];
  b_c->size[0] = loop_ub;
  if (c_pre->size[1] == 1) {
    i1 = (int32_T)(D + 1.0);
  } else {
    i1 = c_pre->size[1];
  }
  b_c->size[1] = i1;
  emxEnsureCapacity_real_T(sp, b_c, i, &t_emlrtRTEI);
  b_c_data = b_c->data;
  sizes_idx_0 = ((int32_T)n != 1);
  stride_0_1 = ((int32_T)(D + 1.0) != 1);
  loop_ub_tmp = (c_pre->size[0] != 1);
  stride_1_1 = (c_pre->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < i1; i++) {
    for (i2 = 0; i2 < loop_ub; i2++) {
      b_c_data[i2 + b_c->size[0] * i] =
          c_data[i2 * sizes_idx_0 + (int32_T)n * aux_0_1] -
          c_pre_data[i2 * loop_ub_tmp + c_pre->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  st.site = &b_emlrtRSI;
  if (b_norm(&st, b_c) > 1.0E-5) {
    int32_T gamma_s_size[2];
    int32_T gamma_size[2];
    st.site = &c_emlrtRSI;
    b_st.site = &u_emlrtRSI;
    if ((int32_T)(D + 1.0) != 3) {
      if (((int32_T)n == 1) && ((int32_T)(D + 1.0) == 1)) {
        emlrtErrorWithMessageIdR2018a(
            &b_st, &emlrtRTEI, "Coder:toolbox:mtimes_noDynamicScalarExpansion",
            "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI, "MATLAB:innerdim",
                                      "MATLAB:innerdim", 0);
      }
    }
    b_st.site = &t_emlrtRSI;
    mtimes(c_data, T_dot_size, T, gamma_data, gamma_size);
    st.site = &d_emlrtRSI;
    b_st.site = &u_emlrtRSI;
    b_st.site = &t_emlrtRSI;
    mtimes(c_data, T_dot_size, T_dot, gamma_s_data, gamma_s_size);
    alpha1 = (D + 1.0) * n;
    if (!(alpha1 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(alpha1, &i_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (alpha1 != (int32_T)muDoubleScalarFloor(alpha1)) {
      emlrtIntegerCheckR2012b(alpha1, &h_emlrtDCI, (emlrtConstCTX)sp);
    }
    i = g->size[0] * g->size[1];
    g->size[0] = 1;
    loop_ub_tmp = (int32_T)alpha1;
    g->size[1] = (int32_T)alpha1;
    emxEnsureCapacity_real_T(sp, g, i, &v_emlrtRTEI);
    g_data = g->data;
    for (i = 0; i < loop_ub_tmp; i++) {
      g_data[i] = 0.0;
    }
    /*      M_x_gamma_s = zeros(n,N+1); */
    /*  vectorized format */
    i = (int32_T)(N + 1.0);
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, N + 1.0, mxDOUBLE_CLASS,
                                  (int32_T)(N + 1.0), &h_emlrtRTEI,
                                  (emlrtConstCTX)sp);
    emxInit_real_T(sp, &r, 2, &y_emlrtRTEI, true);
    emxInit_int32_T(sp, &r1, &eb_emlrtRTEI);
    emxInit_real_T(sp, &r2, 2, &eb_emlrtRTEI, true);
    emxInit_real_T(sp, &y, 2, &fb_emlrtRTEI, true);
    for (k = 0; k < i; k++) {
      real_T W_fcn_eval[36];
      real_T b_gamma_data[18];
      /*      if norm(gamma(:,k))> 10 */
      /*          disp('gamma norm is out of range'); */
      /*      end */
      if (((int32_T)((uint32_T)k + 1U) < 1) ||
          ((int32_T)((uint32_T)k + 1U) > 9)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)k + 1U), 1, 9,
                                      &c_emlrtBCI, (emlrtConstCTX)sp);
      }
      loop_ub_tmp = gamma_size[0];
      for (i2 = 0; i2 < loop_ub_tmp; i2++) {
        b_gamma_data[i2] = gamma_data[i2 + gamma_size[0] * k];
      }
      st.site = &e_emlrtRSI;
      W_fcn1(&st, b_gamma_data, gamma_size[0], W_fcn_eval);
      /*          M_x_gamma_sk = (W_fcn(gamma(:,k))\gamma_s(:,k)); */
      stride_0_1 = gamma_s_size[0];
      for (i2 = 0; i2 < stride_0_1; i2++) {
        b_gamma_data[i2] = gamma_s_data[i2 + gamma_s_size[0] * k];
      }
      st.site = &f_emlrtRSI;
      mldivide(&st, W_fcn_eval, b_gamma_data, gamma_s_size[0],
               M_x_gamma_sk_data);
      /*          coder.extrinsic('dW_fcn'); */
      emlrtForLoopVectorCheckR2021a(1.0, 1.0, n, mxDOUBLE_CLASS, (int32_T)n,
                                    &g_emlrtRTEI, (emlrtConstCTX)sp);
      if ((int32_T)n - 1 >= 0) {
        b_loop_ub = gamma_size[0];
        if (D + 1.0 < 1.0) {
          c_loop_ub = 0;
          d_loop_ub = 0;
        } else {
          i2 = (int32_T)muDoubleScalarFloor(D + 1.0);
          if (D + 1.0 != i2) {
            emlrtIntegerCheckR2012b(D + 1.0, &e_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)(D + 1.0) < 1) || ((int32_T)(D + 1.0) > 3)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(D + 1.0), 1, 3, &b_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          c_loop_ub = (int32_T)(D + 1.0);
          if (D + 1.0 != i2) {
            emlrtIntegerCheckR2012b(D + 1.0, &emlrtDCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)(D + 1.0) < 1) || ((int32_T)(D + 1.0) > 3)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(D + 1.0), 1, 3, &emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          d_loop_ub = (int32_T)(D + 1.0);
        }
        b_w = w[k];
      }
      if (sizes_tmp - 1 >= 0) {
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          b_gamma_data[i2] = gamma_data[i2 + gamma_size[0] * k];
        }
      }
      for (aux_1_1 = 0; aux_1_1 < sizes_tmp; aux_1_1++) {
        __m128d r3;
        __m128d r4;
        int8_T input_sizes_idx_0;
        boolean_T empty_non_axis_sizes;
        st.site = &g_emlrtRSI;
        dW_dxi_fcn1(&st, (real_T)aux_1_1 + 1.0, b_gamma_data, loop_ub_tmp,
                    W_fcn_eval);
        /*              dW_dxi = dW_fcn{i}(gamma(:,k));  */
        st.site = &h_emlrtRSI;
        if (!(D + 1.0 >= 0.0)) {
          emlrtNonNegativeCheckR2012b(D + 1.0, &g_emlrtDCI, &st);
        }
        if (D + 1.0 != (int32_T)muDoubleScalarFloor(D + 1.0)) {
          emlrtIntegerCheckR2012b(D + 1.0, &f_emlrtDCI, &st);
        }
        alpha1 = n - ((real_T)aux_1_1 + 1.0);
        if (!(alpha1 >= 0.0)) {
          emlrtNonNegativeCheckR2012b(alpha1, &d_emlrtDCI, &st);
        }
        if (alpha1 != (int32_T)muDoubleScalarFloor(alpha1)) {
          emlrtIntegerCheckR2012b(alpha1, &c_emlrtDCI, &st);
        }
        if (D + 1.0 != (int32_T)muDoubleScalarFloor(D + 1.0)) {
          emlrtIntegerCheckR2012b(D + 1.0, &b_emlrtDCI, &st);
        }
        b_st.site = &kc_emlrtRSI;
        out = ((aux_1_1 != 0) && ((int32_T)(D + 1.0) != 0));
        if (out) {
          i1 = (int32_T)(D + 1.0);
        } else if (c_loop_ub != 0) {
          i1 = c_loop_ub;
        } else if (((int32_T)alpha1 != 0) && ((int32_T)(D + 1.0) != 0)) {
          i1 = (int32_T)(D + 1.0);
        } else {
          i1 = (int32_T)(D + 1.0);
          i1 = muIntScalarMax_sint32(i1, 0);
          if ((int32_T)(D + 1.0) > i1) {
            i1 = (int32_T)(D + 1.0);
          }
        }
        c_st.site = &lc_emlrtRSI;
        if (((int32_T)(D + 1.0) != i1) &&
            ((aux_1_1 != 0) && ((int32_T)(D + 1.0) != 0))) {
          emlrtErrorWithMessageIdR2018a(
              &c_st, &c_emlrtRTEI, "MATLAB:catenate:matrixDimensionMismatch",
              "MATLAB:catenate:matrixDimensionMismatch", 0);
        }
        if ((c_loop_ub != i1) && (c_loop_ub != 0)) {
          emlrtErrorWithMessageIdR2018a(
              &c_st, &c_emlrtRTEI, "MATLAB:catenate:matrixDimensionMismatch",
              "MATLAB:catenate:matrixDimensionMismatch", 0);
        }
        if (((int32_T)(D + 1.0) != i1) &&
            (((int32_T)alpha1 != 0) && ((int32_T)(D + 1.0) != 0))) {
          emlrtErrorWithMessageIdR2018a(
              &c_st, &c_emlrtRTEI, "MATLAB:catenate:matrixDimensionMismatch",
              "MATLAB:catenate:matrixDimensionMismatch", 0);
        }
        empty_non_axis_sizes = (i1 == 0);
        if (empty_non_axis_sizes || out) {
          loop_ub = aux_1_1;
        } else {
          loop_ub = 0;
        }
        if (empty_non_axis_sizes || (c_loop_ub != 0)) {
          input_sizes_idx_0 = 1;
        } else {
          input_sizes_idx_0 = 0;
        }
        if (empty_non_axis_sizes ||
            (((int32_T)alpha1 != 0) && ((int32_T)(D + 1.0) != 0))) {
          sizes_idx_0 = (int32_T)alpha1;
        } else {
          sizes_idx_0 = 0;
        }
        if (c_loop_ub - 1 >= 0) {
          memcpy(&T_dot_data[0], &T_dot[k * 3],
                 (uint32_T)c_loop_ub * sizeof(real_T));
        }
        stride_0_1 = input_sizes_idx_0;
        i2 = (loop_ub + input_sizes_idx_0) + sizes_idx_0;
        aux_0_1 = r->size[0] * r->size[1];
        r->size[0] = i2;
        r->size[1] = i1;
        emxEnsureCapacity_real_T(sp, r, aux_0_1, &y_emlrtRTEI);
        b_c_data = r->data;
        for (aux_0_1 = 0; aux_0_1 < i1; aux_0_1++) {
          for (stride_1_1 = 0; stride_1_1 < loop_ub; stride_1_1++) {
            b_c_data[stride_1_1 + r->size[0] * aux_0_1] = 0.0;
          }
        }
        for (aux_0_1 = 0; aux_0_1 < i1; aux_0_1++) {
          for (stride_1_1 = 0; stride_1_1 < stride_0_1; stride_1_1++) {
            b_c_data[loop_ub + r->size[0] * aux_0_1] =
                T_dot_data[input_sizes_idx_0 * aux_0_1] * 2.0;
          }
        }
        for (aux_0_1 = 0; aux_0_1 < i1; aux_0_1++) {
          for (stride_1_1 = 0; stride_1_1 < sizes_idx_0; stride_1_1++) {
            b_c_data[((stride_1_1 + loop_ub) + input_sizes_idx_0) +
                     r->size[0] * aux_0_1] = 0.0;
          }
        }
        if ((i2 != 6) && (i2 != 1)) {
          emlrtDimSizeImpxCheckR2021b(i2, 6, &d_emlrtECI, (emlrtConstCTX)sp);
        }
        for (i2 = 0; i2 < 6; i2++) {
          alpha1 = 0.0;
          for (aux_0_1 = 0; aux_0_1 < 6; aux_0_1++) {
            alpha1 += W_fcn_eval[i2 + 6 * aux_0_1] * M_x_gamma_sk_data[aux_0_1];
          }
          b_W_fcn_eval[i2] = alpha1;
        }
        T_dot_size[0] = 6;
        T_dot_size[1] = d_loop_ub;
        for (i2 = 0; i2 < d_loop_ub; i2++) {
          r3 = _mm_loadu_pd(&b_W_fcn_eval[0]);
          r4 = _mm_set1_pd(T[i2 + 3 * k]);
          _mm_storeu_pd(&b_data[6 * i2], _mm_mul_pd(r3, r4));
          r3 = _mm_loadu_pd(&b_W_fcn_eval[2]);
          _mm_storeu_pd(&b_data[6 * i2 + 2], _mm_mul_pd(r3, r4));
          r3 = _mm_loadu_pd(&b_W_fcn_eval[4]);
          _mm_storeu_pd(&b_data[6 * i2 + 4], _mm_mul_pd(r3, r4));
        }
        if ((r->size[1] != d_loop_ub) &&
            ((r->size[1] != 1) && (d_loop_ub != 1))) {
          emlrtDimSizeImpxCheckR2021b(r->size[1], d_loop_ub, &c_emlrtECI,
                                      (emlrtConstCTX)sp);
        }
        if (muDoubleScalarIsNaN(D + 1.0)) {
          i2 = y->size[0] * y->size[1];
          y->size[0] = 1;
          y->size[1] = 1;
          emxEnsureCapacity_real_T(sp, y, i2, &ab_emlrtRTEI);
          g_pre_data = y->data;
          g_pre_data[0] = rtNaN;
        } else if (D + 1.0 < 1.0) {
          y->size[1] = 0;
        } else {
          i2 = y->size[0] * y->size[1];
          y->size[0] = 1;
          y->size[1] = (int32_T)((D + 1.0) - 1.0) + 1;
          emxEnsureCapacity_real_T(sp, y, i2, &ab_emlrtRTEI);
          g_pre_data = y->data;
          loop_ub = (int32_T)((D + 1.0) - 1.0);
          for (i2 = 0; i2 <= loop_ub; i2++) {
            g_pre_data[i2] = (real_T)i2 + 1.0;
          }
        }
        i2 = y->size[0] * y->size[1];
        y->size[0] = 1;
        emxEnsureCapacity_real_T(sp, y, i2, &bb_emlrtRTEI);
        g_pre_data = y->data;
        beta1 = (((real_T)aux_1_1 + 1.0) - 1.0) * (D + 1.0);
        loop_ub = y->size[1] - 1;
        i1 = (y->size[1] / 2) << 1;
        sizes_idx_0 = i1 - 2;
        for (i2 = 0; i2 <= sizes_idx_0; i2 += 2) {
          r3 = _mm_loadu_pd(&g_pre_data[i2]);
          _mm_storeu_pd(&dv[0], _mm_add_pd(_mm_set1_pd(beta1), r3));
          if (dv[0] != (int32_T)muDoubleScalarFloor(dv[0])) {
            emlrtIntegerCheckR2012b(dv[0], &p_emlrtDCI, (emlrtConstCTX)sp);
          }
          if (dv[1] != (int32_T)muDoubleScalarFloor(dv[1])) {
            emlrtIntegerCheckR2012b(dv[1], &p_emlrtDCI, (emlrtConstCTX)sp);
          }
          r3 = _mm_loadu_pd(&dv[0]);
          _mm_storeu_pd(&g_pre_data[i2], r3);
        }
        for (i2 = i1; i2 <= loop_ub; i2++) {
          alpha1 = beta1 + g_pre_data[i2];
          if (alpha1 != (int32_T)muDoubleScalarFloor(alpha1)) {
            emlrtIntegerCheckR2012b(alpha1, &p_emlrtDCI, (emlrtConstCTX)sp);
          }
          g_pre_data[i2] = alpha1;
        }
        stride_0_1 = y->size[1];
        for (i2 = 0; i2 < stride_0_1; i2++) {
          aux_0_1 = (int32_T)g_pre_data[i2];
          if ((aux_0_1 < 1) || (aux_0_1 > g->size[1])) {
            emlrtDynamicBoundsCheckR2012b(aux_0_1, 1, g->size[1], &d_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
        }
        st.site = &h_emlrtRSI;
        if ((r->size[0] == 6) && (r->size[1] == d_loop_ub)) {
          loop_ub = 6 * r->size[1];
          T_dot_size[1] = r->size[1];
          i1 = (loop_ub / 2) << 1;
          sizes_idx_0 = i1 - 2;
          for (i2 = 0; i2 <= sizes_idx_0; i2 += 2) {
            r3 = _mm_loadu_pd(&b_c_data[i2]);
            r4 = _mm_loadu_pd(&b_data[i2]);
            _mm_storeu_pd(&b_data[i2], _mm_sub_pd(r3, r4));
          }
          for (i2 = i1; i2 < loop_ub; i2++) {
            b_data[i2] = b_c_data[i2] - b_data[i2];
          }
        } else {
          minus(b_data, T_dot_size, r);
        }
        b_st.site = &t_emlrtRSI;
        if (T_dot_size[1] == 0) {
          i2 = 0;
          T_dot_size[1] = 0;
        } else {
          TRANSB1 = 'N';
          TRANSA1 = 'T';
          alpha1 = 1.0;
          beta1 = 0.0;
          m_t = (ptrdiff_t)1;
          n_t = (ptrdiff_t)T_dot_size[1];
          k_t = (ptrdiff_t)6;
          lda_t = (ptrdiff_t)6;
          ldb_t = (ptrdiff_t)6;
          ldc_t = (ptrdiff_t)1;
          i2 = T_dot_size[1];
          dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1,
                &M_x_gamma_sk_data[0], &lda_t, &b_data[0], &ldb_t, &beta1,
                &T_dot_data[0], &ldc_t);
        }
        loop_ub = i2 - 1;
        i1 = (i2 / 2) << 1;
        sizes_idx_0 = i1 - 2;
        for (i2 = 0; i2 <= sizes_idx_0; i2 += 2) {
          r3 = _mm_loadu_pd(&T_dot_data[0]);
          _mm_storeu_pd(&T_dot_data[0], _mm_mul_pd(r3, _mm_set1_pd(b_w)));
        }
        for (i2 = i1; i2 <= loop_ub; i2++) {
          T_dot_data[i2] *= b_w;
        }
        if ((y->size[1] != T_dot_size[1]) &&
            ((y->size[1] != 1) && (T_dot_size[1] != 1))) {
          emlrtDimSizeImpxCheckR2021b(y->size[1], T_dot_size[1], &b_emlrtECI,
                                      (emlrtConstCTX)sp);
        }
        i2 = r1->size[0] * r1->size[1];
        r1->size[0] = 1;
        r1->size[1] = y->size[1];
        emxEnsureCapacity_int32_T(sp, r1, i2, &cb_emlrtRTEI);
        r5 = r1->data;
        for (i2 = 0; i2 < stride_0_1; i2++) {
          aux_0_1 = (int32_T)g_pre_data[i2];
          if ((aux_0_1 < 1) || (aux_0_1 > g->size[1])) {
            emlrtDynamicBoundsCheckR2012b(aux_0_1, 1, g->size[1], &e_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          r5[i2] = aux_0_1;
        }
        if (y->size[1] == T_dot_size[1]) {
          i2 = r2->size[0] * r2->size[1];
          r2->size[0] = 1;
          r2->size[1] = y->size[1];
          emxEnsureCapacity_real_T(sp, r2, i2, &db_emlrtRTEI);
          b_c_data = r2->data;
          for (i2 = 0; i2 < stride_0_1; i2++) {
            b_c_data[i2] = g_data[(int32_T)g_pre_data[i2] - 1] + T_dot_data[i2];
          }
        } else {
          st.site = &h_emlrtRSI;
          binary_expand_op(&st, r2, g, y, T_dot_data, T_dot_size);
          b_c_data = r2->data;
        }
        if (r1->size[1] != r2->size[1]) {
          emlrtSubAssignSizeCheck1dR2017a(r1->size[1], r2->size[1], &emlrtECI,
                                          (emlrtConstCTX)sp);
        }
        loop_ub = r2->size[1] - 1;
        for (i2 = 0; i2 <= loop_ub; i2++) {
          g_data[r5[i2] - 1] = b_c_data[i2];
        }
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtConstCTX)sp);
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    emxFree_real_T(sp, &y);
    emxFree_real_T(sp, &r2);
    emxFree_int32_T(sp, &r1);
    emxFree_real_T(sp, &r);
    i = c_pre->size[0] * c_pre->size[1];
    c_pre->size[0] = (int32_T)n;
    c_pre->size[1] = 3;
    emxEnsureCapacity_real_T(sp, c_pre, i, &w_emlrtRTEI);
    c_pre_data = c_pre->data;
    loop_ub_tmp = (int32_T)n * 3;
    for (i = 0; i < loop_ub_tmp; i++) {
      c_pre_data[i] = c_data[i];
    }
    c_pre_not_empty = ((c_pre->size[0] != 0) && (c_pre->size[1] != 0));
    i = g_pre->size[0] * g_pre->size[1];
    g_pre->size[0] = 1;
    loop_ub = g->size[1];
    g_pre->size[1] = g->size[1];
    emxEnsureCapacity_real_T(sp, g_pre, i, &x_emlrtRTEI);
    g_pre_data = g_pre->data;
    for (i = 0; i < loop_ub; i++) {
      g_pre_data[i] = g_data[i];
    }
  } else {
    i = g->size[0] * g->size[1];
    g->size[0] = 1;
    loop_ub = g_pre->size[1];
    g->size[1] = g_pre->size[1];
    emxEnsureCapacity_real_T(sp, g, i, &u_emlrtRTEI);
    g_data = g->data;
    for (i = 0; i < loop_ub; i++) {
      g_data[i] = g_pre_data[i];
    }
  }
  emxFree_real_T(sp, &b_c);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void energyGradient1_emx_free(const emlrtStack *sp)
{
  emxFree_real_T(sp, &c_pre);
  emxFree_real_T(sp, &g_pre);
}

void energyGradient1_emx_init(const emlrtStack *sp)
{
  emxInit_real_T(sp, &c_pre, 2, &p_emlrtRTEI, false);
  emxInit_real_T(sp, &g_pre, 2, &q_emlrtRTEI, false);
}

void energyGradient1_init(void)
{
  c_pre_not_empty = false;
}

/* End of code generation (energyGradient1.c) */
