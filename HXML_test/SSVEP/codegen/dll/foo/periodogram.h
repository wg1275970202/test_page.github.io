//
// File: periodogram.h
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Aug-2024 01:31:17
//

#ifndef PERIODOGRAM_H
#define PERIODOGRAM_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void b_periodogram(const array<float, 2U> &x, float Px[451]);

void periodogram(const array<float, 2U> &x, float Px[501], float w[501]);

void periodogram(const array<float, 2U> &x, float Px[100]);

void periodogram(const array<float, 2U> &x, const double varargin_2_data[],
                 const int varargin_2_size[2], array<float, 2U> &Px);

} // namespace coder

#endif
//
// File trailer for periodogram.h
//
// [EOF]
//
