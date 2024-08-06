//
// File: FFTImplementationCallback.h
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Aug-2024 01:31:17
//

#ifndef FFTIMPLEMENTATIONCALLBACK_H
#define FFTIMPLEMENTATIONCALLBACK_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace internal {
namespace fft {
class FFTImplementationCallback {
public:
  static int get_algo_sizes(int nfft, bool useRadix2, int &nRows);
  static void r2br_r2dit_trig_impl(const array<creal32_T, 1U> &x,
                                   int unsigned_nRows,
                                   const array<float, 2U> &costab,
                                   const array<float, 2U> &sintab,
                                   array<creal32_T, 1U> &y);
  static void doHalfLengthRadix2(const array<float, 1U> &x, creal32_T y_data[],
                                 int &y_size, int unsigned_nRows,
                                 const float costab_data[],
                                 const int costab_size[2],
                                 const float sintab_data[]);
  static void doHalfLengthBluestein(const array<float, 1U> &x,
                                    creal32_T y_data[], int nrowsx, int nRows,
                                    int nfft, const creal32_T wwc_data[],
                                    int wwc_size, const float costab_data[],
                                    const int costab_size[2],
                                    const float sintab_data[],
                                    const float costabinv_data[],
                                    const float sintabinv_data[]);
};

} // namespace fft
} // namespace internal
} // namespace coder

#endif
//
// File trailer for FFTImplementationCallback.h
//
// [EOF]
//
