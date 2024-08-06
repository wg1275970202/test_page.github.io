//
// File: xnrm2.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Aug-2024 01:31:17
//

// Include Files
#include "xnrm2.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : int n
//                const float x_data[]
// Return Type  : float
//
namespace coder {
namespace internal {
namespace blas {
float xnrm2(int n, const float x_data[])
{
  float y;
  y = 0.0F;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x_data[1]);
    } else {
      float scale;
      int kend;
      scale = 1.29246971E-26F;
      kend = n + 1;
      for (int k{2}; k <= kend; k++) {
        float absxk;
        absxk = std::abs(x_data[k - 1]);
        if (absxk > scale) {
          float t;
          t = scale / absxk;
          y = y * t * t + 1.0F;
          scale = absxk;
        } else {
          float t;
          t = absxk / scale;
          y += t * t;
        }
      }
      y = scale * std::sqrt(y);
    }
  }
  return y;
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xnrm2.cpp
//
// [EOF]
//
