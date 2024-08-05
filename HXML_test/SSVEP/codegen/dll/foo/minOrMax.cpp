//
// File: minOrMax.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 05-Aug-2024 10:41:23
//

// Include Files
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const float x[501]
// Return Type  : float
//
namespace coder {
namespace internal {
float maximum(const float x[501])
{
  float ex;
  int idx;
  int k;
  if (!std::isnan(x[0])) {
    idx = 1;
  } else {
    bool exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 502)) {
      if (!std::isnan(x[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    ex = x[0];
  } else {
    ex = x[idx - 1];
    idx++;
    for (k = idx; k < 502; k++) {
      float f;
      f = x[k - 1];
      if (ex < f) {
        ex = f;
      }
    }
  }
  return ex;
}

} // namespace internal
} // namespace coder

//
// File trailer for minOrMax.cpp
//
// [EOF]
//
