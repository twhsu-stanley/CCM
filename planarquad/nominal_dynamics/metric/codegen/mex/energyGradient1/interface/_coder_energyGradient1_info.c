/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_energyGradient1_info.c
 *
 * Code generation for function 'energyGradient1'
 *
 */

/* Include files */
#include "_coder_energyGradient1_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[6] = {
      "789ced57cb6ed340149da05290aa4236852d5fd0d2872260076ee3a4b456c155138291f1"
      "63528fea19bb13db7590f806bae8a29fc087b0ea17f0fa0b58b0248e"
      "9dc4b618d928952b47b99bebab63cf39bed73ef6804a73bf0200b807c2f8b312e6e5a8ae"
      "46f91648461aaf447921558fe276842ca7f04f51d62ce240df090ba2",
      "6038be52b730220a710efb360414f62cd383fa10e922131e220cc578210415aec7a07111"
      "40c1316740ed447431a0466fa2d08c17e37e7c66dcef024806ab1fdb"
      "8c7e5453f8db9d77dc33e939d76e8a8f384b8712c7ed4b9a86e51e54a86648417fa865ca"
      "a672265bc444044a90407adce7a9a223489cf5551cd7fd7e4add8b4c",
      "dd21d292bb1a592f8e4fb75cd58413bef329f9d6987c49fc9f73b14d8528f4d455740943"
      "87224d0adb311841563feee7d497ce93f3ef0e738bff39848ae25bfc"
      "fdf55b917ca3b8293e9fb15edee7eb0183af9ac2dd9d86ba0bc523a4f6e11bfb89a8bde8"
      "aa5bfc44c741064f960ec0a88b5abfacfe694fa97b2943f708d75bb2",
      "eea3c84cc1cdf9e9e5947c5b4cbe249ed34f636dc9f75d2babafbebefaf5a348be5194d5"
      "5757187cd514dec5755eedf1828fec5ad3262f05c1dedd03b3e3ab65"
      "7f5ff3eabcc3d4192201b16da0d2fe873e66f225f1ff98c3a01dab7856fdf2e3f78773bf"
      "04d7ff1ffa6a43109e5a67aeef614a6a1d5ed8306b47f5b95f96cd2f",
      "33fd6b40ecf9f37d7b6c0e9e3fc3fbf68b2f5773bf04d7ef9727b483f68c0f8dfe6947dd"
      "f4dafa71dbd86c6c97df2fff02dce22f11",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 5648U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[9] = {"Version",
                                    "ResolvedFunctions",
                                    "Checksum",
                                    "EntryPoints",
                                    "CoverageInfo",
                                    "IsPolymorphic",
                                    "PropertyList",
                                    "UUID",
                                    "ClassEntryPointIsHandle"};
  const char_T *epFieldName[8] = {
      "QualifiedName",    "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "ResolvedFilePath", "TimeStamp",      "Constructor",     "Visible"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 8, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 7);
  emlrtSetField(xEntryPoints, 0, "QualifiedName",
                emlrtMxCreateString("energyGradient1"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(7.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString(
          "C:\\ACXIS "
          "Code\\CCM\\ccm_search\\control_law_online\\energyGradient1.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739872.71615740738));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("24.2.0.2712019 (R2024b)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("cC4ZeP4LI5DGJni0jHMFXB"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_energyGradient1_info.c) */
