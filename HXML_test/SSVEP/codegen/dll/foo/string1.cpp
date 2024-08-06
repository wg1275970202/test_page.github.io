//
// File: string1.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Aug-2024 01:31:17
//

// Include Files
#include "string1.h"
#include "rt_nonfinite.h"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

// Function Definitions
//
// Arguments    : float val
//                char str_data[]
//                int str_size[2]
// Return Type  : void
//
namespace coder {
void rtString::convertToString(float val, char str_data[], int str_size[2])
{
  char st[24];
  if (val == 0.0F) {
    str_size[0] = 1;
    str_size[1] = 1;
    str_data[0] = '0';
  } else if (std::isinf(val)) {
    if (val > 0.0F) {
      str_size[0] = 1;
      str_size[1] = 3;
      str_data[0] = 'I';
      str_data[1] = 'n';
      str_data[2] = 'f';
    } else {
      str_size[0] = 1;
      str_size[1] = 4;
      str_data[0] = '-';
      str_data[1] = 'I';
      str_data[2] = 'n';
      str_data[3] = 'f';
    }
  } else {
    int resCount;
    resCount = std::snprintf(&st[0], 24, "%.16g", val);
    str_size[0] = 1;
    str_size[1] = resCount;
    if (resCount - 1 >= 0) {
      std::copy(&st[0], &st[resCount], &str_data[0]);
    }
  }
}

} // namespace coder

//
// File trailer for string1.cpp
//
// [EOF]
//
