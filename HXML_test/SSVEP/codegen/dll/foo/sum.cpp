//
// File: sum.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Aug-2024 01:31:17
//

// Include Files
#include "sum.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cstring>

// Function Definitions
//
// Arguments    : const array<float, 2U> &x
//                float y_data[]
//                int y_size[2]
// Return Type  : void
//
namespace coder {
void sum(const array<float, 2U> &x, float y_data[], int y_size[2])
{
  int vlen;
  vlen = x.size(0);
  if ((x.size(0) == 0) || (x.size(1) == 0)) {
    y_size[0] = 1;
    y_size[1] = static_cast<short>(x.size(1));
    vlen = static_cast<short>(x.size(1));
    if (vlen - 1 >= 0) {
      std::memset(&y_data[0], 0,
                  static_cast<unsigned int>(vlen) * sizeof(float));
    }
  } else {
    int i;
    i = x.size(1);
    y_size[0] = 1;
    y_size[1] = x.size(1);
    for (int xi{0}; xi < i; xi++) {
      int xpageoffset;
      xpageoffset = xi * x.size(0);
      y_data[xi] = x[xpageoffset];
      for (int k{2}; k <= vlen; k++) {
        y_data[xi] += x[(xpageoffset + k) - 1];
      }
    }
  }
}

} // namespace coder

//
// File trailer for sum.cpp
//
// [EOF]
//
