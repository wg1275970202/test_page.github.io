//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: foo.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 24-May-2024 15:11:29
//

// Include Files
#include "foo.h"
#include "imbinarize.h"
#include "permute.h"
#include "rt_nonfinite.h"
#include <algorithm>
#include <cmath>
#include <cstring>

// Function Definitions
//
// Reformat the image data
//
// Arguments    : const unsigned char Icam[1687500]
//                unsigned char B[2250000]
// Return Type  : void
//
void foo(const unsigned char Icam[1687500], unsigned char B[2250000])
{
  static unsigned char b_tmp[2250000];
  static unsigned char b_Icam[1687500];
  static unsigned char tmp[562500];
  static bool bv[562500];
  coder::permute(Icam, b_Icam);
  //  Convert to gray image
  for (int i{0}; i < 562500; i++) {
    tmp[i] = static_cast<unsigned char>(std::round(
        (static_cast<double>(b_Icam[i]) * 0.29893602129377539 +
         static_cast<double>(b_Icam[i + 562500]) * 0.58704307445112125) +
        static_cast<double>(b_Icam[i + 1125000]) * 0.11402090425510336));
  }
  //  codegen ok
  coder::imbinarize(tmp, bv);
  for (int i{0}; i < 562500; i++) {
    tmp[i] = static_cast<unsigned char>(bv[i] * 255U);
  }
  for (int i{0}; i < 3; i++) {
    std::copy(&tmp[0], &tmp[562500], &b_Icam[i * 562500]);
  }
  std::copy(&b_Icam[0], &b_Icam[1687500], &b_tmp[0]);
  std::memset(&b_tmp[1687500], 0, 562500U * sizeof(unsigned char));
  coder::b_permute(b_tmp, B);
  //  Icam=[reshape(Icam,[3,N*N]); zeros(1,N*N,"uint8")];
  //  B=Icam(:);
}

//
// File trailer for foo.cpp
//
// [EOF]
//
