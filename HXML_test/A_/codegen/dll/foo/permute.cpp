//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: permute.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 24-May-2024 15:11:29
//

// Include Files
#include "permute.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : const unsigned char a[2250000]
//                unsigned char b[2250000]
// Return Type  : void
//
namespace coder {
void b_permute(const unsigned char a[2250000], unsigned char b[2250000])
{
  for (int k{0}; k < 4; k++) {
    for (int b_k{0}; b_k < 750; b_k++) {
      for (int c_k{0}; c_k < 750; c_k++) {
        b[(k + (b_k << 2)) + 3000 * c_k] = a[(c_k + 750 * b_k) + 562500 * k];
      }
    }
  }
}

//
// Arguments    : const unsigned char a[1687500]
//                unsigned char b[1687500]
// Return Type  : void
//
void permute(const unsigned char a[1687500], unsigned char b[1687500])
{
  for (int k{0}; k < 750; k++) {
    for (int b_k{0}; b_k < 750; b_k++) {
      int b_b_tmp;
      int b_tmp;
      b_tmp = 3 * b_k + 2250 * k;
      b_b_tmp = k + 750 * b_k;
      b[b_b_tmp] = a[b_tmp];
      b[b_b_tmp + 562500] = a[b_tmp + 1];
      b[b_b_tmp + 1125000] = a[b_tmp + 2];
    }
  }
}

} // namespace coder

//
// File trailer for permute.cpp
//
// [EOF]
//
