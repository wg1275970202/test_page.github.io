//
// File: string1.h
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Aug-2024 01:31:17
//

#ifndef STRING1_H
#define STRING1_H

// Include Files
#include "rtwtypes.h"
#include "coder_bounded_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
class rtString {
public:
  static void convertToString(float val, char str_data[], int str_size[2]);
  bounded_array<char, 26U, 2U> Value;
};

} // namespace coder

#endif
//
// File trailer for string1.h
//
// [EOF]
//
