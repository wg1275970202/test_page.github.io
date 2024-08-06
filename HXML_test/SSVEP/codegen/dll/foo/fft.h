//
// File: fft.h
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Aug-2024 01:31:17
//

#ifndef FFT_H
#define FFT_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void fft(const array<creal32_T, 1U> &x, float varargin_1,
         array<creal32_T, 1U> &y);

int fft(const array<float, 1U> &x, float varargin_1, creal32_T y_data[]);

} // namespace coder

#endif
//
// File trailer for fft.h
//
// [EOF]
//
