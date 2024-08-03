//
// File: foo.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Aug-2024 13:00:50
//

// Include Files
#include "foo.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const double input[96000]
//                double B[200]
// Return Type  : void
//
void foo(const double input[96000], double B[200])
{
  double xw[2000];
  double b_k[100];
  double x_data[100];
  double s0_re;
  double s2_re;
  int idx;
  int k;
  for (k = 0; k < 2000; k++) {
    xw[k] = input[48 * k];
  }
  for (k = 0; k < 100; k++) {
    double cos2TwidFactor;
    double phaseCorrection_im;
    double phaseCorrection_re;
    double s1_re;
    double twiddleFactor;
    if (k == 0) {
      phaseCorrection_re = 0.0;
    } else {
      phaseCorrection_re = (static_cast<double>(k) + 1.0) - 1.0;
    }
    twiddleFactor =
        6.2831853071795862 * (phaseCorrection_re / 1000.0 * 2000.0) / 2000.0;
    cos2TwidFactor = 2.0 * std::cos(twiddleFactor);
    phaseCorrection_im = 1999.0 * -twiddleFactor;
    phaseCorrection_re = std::cos(phaseCorrection_im);
    phaseCorrection_im = std::sin(phaseCorrection_im);
    s1_re = 0.0;
    s2_re = 0.0;
    for (idx = 0; idx < 1999; idx++) {
      s0_re = (xw[idx] + cos2TwidFactor * s1_re) - s2_re;
      s2_re = s1_re;
      s1_re = s0_re;
    }
    s0_re = s1_re * std::sin(-twiddleFactor);
    s2_re = ((xw[1999] + cos2TwidFactor * s1_re) - s2_re) -
            s1_re * std::cos(-twiddleFactor);
    twiddleFactor =
        s2_re * phaseCorrection_re - (0.0 - s0_re) * phaseCorrection_im;
    s2_re = s2_re * phaseCorrection_im + (0.0 - s0_re) * phaseCorrection_re;
    s1_re = twiddleFactor * twiddleFactor - s2_re * -s2_re;
    s0_re = twiddleFactor * -s2_re + s2_re * twiddleFactor;
    if (s0_re == 0.0) {
      twiddleFactor = s1_re / 2000.0;
    } else if (s1_re == 0.0) {
      twiddleFactor = 0.0;
    } else {
      twiddleFactor = s1_re / 2000.0;
    }
    b_k[k] = twiddleFactor / 1000.0;
    if (s0_re == 0.0) {
      twiddleFactor = s1_re / 2000.0;
    } else if (s1_re == 0.0) {
      twiddleFactor = 0.0;
    } else {
      twiddleFactor = s1_re / 2000.0;
    }
    x_data[k] = twiddleFactor / 1000.0;
  }
  if (!std::isnan(x_data[0])) {
    idx = 1;
  } else {
    bool exitg1;
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 101)) {
      if (!std::isnan(x_data[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    s2_re = b_k[0];
  } else {
    s2_re = b_k[idx - 1];
    idx++;
    for (k = idx; k < 101; k++) {
      s0_re = b_k[k - 1];
      if (s2_re < s0_re) {
        s2_re = s0_re;
      }
    }
  }
  for (idx = 0; idx < 100; idx++) {
    B[idx] = idx;
    B[idx + 100] = b_k[idx] / s2_re;
  }
}

//
// File trailer for foo.cpp
//
// [EOF]
//
