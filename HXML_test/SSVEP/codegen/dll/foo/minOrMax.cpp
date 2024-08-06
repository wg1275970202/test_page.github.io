//
// File: minOrMax.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Aug-2024 01:31:17
//

// Include Files
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <cstring>

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
    while ((!exitg1) && (k <= 501)) {
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

//
// Arguments    : const float x_data[]
//                int x_size
// Return Type  : float
//
float maximum(const float x_data[], int x_size)
{
  float ex;
  if (x_size <= 2) {
    if (x_size == 1) {
      ex = x_data[0];
    } else {
      ex = x_data[x_size - 1];
      if ((!(x_data[0] < ex)) && ((!std::isnan(x_data[0])) || std::isnan(ex))) {
        ex = x_data[0];
      }
    }
  } else {
    int idx;
    int k;
    if (!std::isnan(x_data[0])) {
      idx = 1;
    } else {
      bool exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= x_size)) {
        if (!std::isnan(x_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = x_data[0];
    } else {
      ex = x_data[idx - 1];
      idx++;
      for (k = idx; k <= x_size; k++) {
        float f;
        f = x_data[k - 1];
        if (ex < f) {
          ex = f;
        }
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
