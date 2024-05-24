//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_foo_api.h
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 24-May-2024 15:11:29
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
void foo(uint8_T Icam[1687500], uint8_T B[2250000]);

void foo_api(const mxArray *prhs, const mxArray **plhs);

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
