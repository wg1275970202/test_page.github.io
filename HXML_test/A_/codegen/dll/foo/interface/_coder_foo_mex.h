//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_foo_mex.h
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 24-May-2024 15:11:29
//

#ifndef _CODER_FOO_MEX_H
#define _CODER_FOO_MEX_H

// Include Files
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

// Function Declarations
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS();

void unsafe_foo_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                            const mxArray *prhs[1]);

#endif
//
// File trailer for _coder_foo_mex.h
//
// [EOF]
//
