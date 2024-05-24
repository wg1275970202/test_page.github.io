//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_foo_api.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 24-May-2024 15:11:29
//

// Include Files
#include "_coder_foo_api.h"
#include "_coder_foo_mex.h"

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal{nullptr};

emlrtContext emlrtContextGlobal{
    true,                                                 // bFirstTime
    false,                                                // bInitialized
    131643U,                                              // fVersionInfo
    nullptr,                                              // fErrorFunction
    "foo",                                                // fFunctionName
    nullptr,                                              // fRTCallStack
    false,                                                // bDebugMode
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, // fSigWrd
    nullptr                                               // fSigMem
};

// Function Declarations
static uint8_T (*b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[1687500];

static uint8_T (*emlrt_marshallIn(const emlrtStack &sp,
                                  const mxArray *b_nullptr,
                                  const char_T *identifier))[1687500];

static uint8_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId))[1687500];

static const mxArray *emlrt_marshallOut(const uint8_T u[2250000]);

// Function Definitions
//
// Arguments    : const emlrtStack &sp
//                const mxArray *src
//                const emlrtMsgIdentifier *msgId
// Return Type  : uint8_T (*)[1687500]
//
static uint8_T (*b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[1687500]
{
  static const int32_T dims[2]{1, 1687500};
  int32_T iv[2];
  uint8_T(*ret)[1687500];
  boolean_T bv[2]{false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "uint8", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret = (uint8_T(*)[1687500])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *b_nullptr
//                const char_T *identifier
// Return Type  : uint8_T (*)[1687500]
//
static uint8_T (*emlrt_marshallIn(const emlrtStack &sp,
                                  const mxArray *b_nullptr,
                                  const char_T *identifier))[1687500]
{
  emlrtMsgIdentifier thisId;
  uint8_T(*y)[1687500];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

//
// Arguments    : const emlrtStack &sp
//                const mxArray *u
//                const emlrtMsgIdentifier *parentId
// Return Type  : uint8_T (*)[1687500]
//
static uint8_T (*emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId))[1687500]
{
  uint8_T(*y)[1687500];
  y = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

//
// Arguments    : const uint8_T u[2250000]
// Return Type  : const mxArray *
//
static const mxArray *emlrt_marshallOut(const uint8_T u[2250000])
{
  static const int32_T i{0};
  static const int32_T i1{2250000};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxUINT8_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

//
// Arguments    : const mxArray *prhs
//                const mxArray **plhs
// Return Type  : void
//
void foo_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  uint8_T(*B)[2250000];
  uint8_T(*Icam)[1687500];
  st.tls = emlrtRootTLSGlobal;
  B = (uint8_T(*)[2250000])mxMalloc(sizeof(uint8_T[2250000]));
  // Marshall function inputs
  Icam = emlrt_marshallIn(st, emlrtAlias(prhs), "Icam");
  // Invoke the target function
  foo(*Icam, *B);
  // Marshall function outputs
  *plhs = emlrt_marshallOut(*B);
}

//
// Arguments    : void
// Return Type  : void
//
void foo_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  foo_xil_terminate();
  foo_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void foo_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

//
// Arguments    : void
// Return Type  : void
//
void foo_terminate()
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

//
// File trailer for _coder_foo_api.cpp
//
// [EOF]
//
