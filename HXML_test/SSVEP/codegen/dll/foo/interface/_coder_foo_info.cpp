//
// File: _coder_foo_info.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Aug-2024 01:31:17
//

// Include Files
#include "_coder_foo_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

// Function Declarations
static const mxArray *emlrtMexFcnResolvedFunctionsInfo();

// Function Definitions
//
// Arguments    : void
// Return Type  : const mxArray *
//
static const mxArray *emlrtMexFcnResolvedFunctionsInfo()
{
  const mxArray *nameCaptureInfo;
  const char_T *data[5]{
      "789c6360f4f465646060e063808015dc109a17ca1780d24c0ca8005d9e114d1d23aa7206"
      "560616147d30f97e289d9c9f57925a5102e1e425e6a6c275a6e4e766"
      "e625e695845416a43214a516e7e794a5a68065d2327352433273538391397e205eae1b92"
      "149c039202b19d335293b3834b73198a328a112ecc41e6c0c363010e",
      "ffb210191e9638c243004d3eda35d6c52ac63db324a33429a63cddd0c8dcd4d2dcc0c8c0"
      "482f1d2ca697991fe311e1eb135f925a5c12131c1ce61a1093969faf"
      "978be6de040addcb8cd3bd1099b4d23caadac786d33e884c71665e7a4eea10898fd23ca2"
      "e3839f48f7a2d308f51c607afaf35b8cf4b44fc79de3233ded838181",
      "b2af028779c4a637311cf609a0c90786993b9a7946b81bfb46169915797bba875b5a1ab9"
      "21dc1140c01e42ee60c0c1a797f90b70e81facf9b68042f7e20a1f01"
      "343a29b3a438a42831af3837b3a4a42435855ee56a4a7e691272b9ba8242fbdc70da872a"
      "4f4efca0871128b2e8551e74d3b97cddb8c6b49f9ef6c1c0702f5f3d",
      "3cbcd3cdbc0dca42f333f322cd232a5c934a428b9d877ef90a00498dae62", ""};
  nameCaptureInfo = nullptr;
  emlrtNameCaptureMxArrayR2016a(&data[0], 3008U, &nameCaptureInfo);
  return nameCaptureInfo;
}

//
// Arguments    : void
// Return Type  : mxArray *
//
mxArray *emlrtMexFcnProperties()
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[9]{"Version",
                                 "ResolvedFunctions",
                                 "Checksum",
                                 "EntryPoints",
                                 "CoverageInfo",
                                 "IsPolymorphic",
                                 "PropertyList",
                                 "UUID",
                                 "ClassEntryPointIsHandle"};
  const char_T *epFieldName[8]{
      "Name",     "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "FullPath", "TimeStamp",      "Constructor",     "Visible"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 8, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("foo"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "FullPath",
      emlrtMxCreateString(
          "D:\\Github\\wg1275970202.github.io\\HXML_test\\SSVEP\\foo.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739470.0403125));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("23.2.0.2409890 (R2023b) Update 3"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("TJ1058QZi4FcGkLkaWt4NB"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

//
// File trailer for _coder_foo_info.cpp
//
// [EOF]
//
