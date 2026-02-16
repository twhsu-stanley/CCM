/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_RiemannEnergy1_info.c
 *
 * Code generation for function 'RiemannEnergy1'
 *
 */

/* Include files */
#include "_coder_RiemannEnergy1_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[4] = {
      "789cc553dd4ec230182d06893728575efb041a122f8c576a838809c638221a6b66d77d48"
      "637fb06c0a4fa18fe12369e263f8003a3636466c2021e277737672d2"
      "9ed3d30e151acd0242681dc573508ab19cf04a822b283fd37ac182e35945c5dcbab1fe92"
      "20d32a804110134525a42b7d2db9a22a680d7b800cf4b578027fa474",
      "b8801697e04c92b388c9e309292591147de32eb0072794c874fb59423149d23ede2ce72d"
      "ced907b6f45199d26f6ab7789f1ce2ab86b385b50f04e326614cba7d"
      "a0867549d48fd1c215f4d9d54a7005e48283a44ad51498fb61755be672df2d98bb64cd1d"
      "2b6db7c35475797ebe0e3d0199dfeb827e3b56bfbcfeebbdf40455d4",
      "3c86d4271202c31989ebf8b983597d6ccc99cff61f95d1da08dbf5cf91b42cbfd2d7fbc7"
      "32fdc6f35f7e03cb7ef3beaf4d8b5f654a0f6b27de293897dc1bc275"
      "6fcf61471d6fb79ee5389fe1332b07b2f0bfdeff1b4fc668cb",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 1624U, &nameCaptureInfo);
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
                emlrtMxCreateString("RiemannEnergy1"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(7.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString(
          "C:\\ACXIS "
          "Code\\CCM\\ccm_search\\control_law_online\\RiemannEnergy1.m"));
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
                emlrtMxCreateString("gPJ6X7iaJ5Z0w7x5wj3ipC"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_RiemannEnergy1_info.c) */
