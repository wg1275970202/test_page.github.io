//
// File: _coder_foo_api.h
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Aug-2024 13:53:25
//

#ifndef _CODER_FOO_API_H
#define _CODER_FOO_API_H

// Include Files
#include "foo_spec.h"
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <algorithm>
#include <cstring>

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

// Function Declarations
void foo(real32_T input[30000], real32_T duration, real32_T B[200]);

void foo_api(const mxArray *const prhs[2], const mxArray **plhs);

void foo_atexit();

void foo_initialize();

void foo_terminate();

void foo_xil_shutdown();

void foo_xil_terminate();

#endif
//
// File trailer for _coder_foo_api.h
//
// [EOF]
//
