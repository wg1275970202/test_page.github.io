//
// File: computeDFT.h
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Aug-2024 01:31:17
//

#ifndef COMPUTEDFT_H
#define COMPUTEDFT_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void b_computeDFTviaCZT(const array<float, 1U> &xin, creal32_T Xx[451]);

void computeDFTviaCZT(const array<float, 1U> &xin, creal32_T Xx[100]);

int computeDFTviaFFT(const array<float, 1U> &xin, double nx, float nfft,
                     float Fs, creal32_T Xx_data[], float f_data[],
                     int &f_size);

} // namespace coder

#endif
//
// File trailer for computeDFT.h
//
// [EOF]
//
