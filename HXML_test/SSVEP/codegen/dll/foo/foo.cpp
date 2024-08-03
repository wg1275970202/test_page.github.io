//
// File: foo.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Aug-2024 13:53:25
//

// Include Files
#include "foo.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const float input[30000]
//                float duration
//                float B[200]
// Return Type  : void
//
void foo(const float input[30000], float duration, float B[200])
{
  static const float a[100]{
      0.0F,   0.001F, 0.002F, 0.003F, 0.004F, 0.005F, 0.006F, 0.007F, 0.008F,
      0.009F, 0.01F,  0.011F, 0.012F, 0.013F, 0.014F, 0.015F, 0.016F, 0.017F,
      0.018F, 0.019F, 0.02F,  0.021F, 0.022F, 0.023F, 0.024F, 0.025F, 0.026F,
      0.027F, 0.028F, 0.029F, 0.03F,  0.031F, 0.032F, 0.033F, 0.034F, 0.035F,
      0.036F, 0.037F, 0.038F, 0.039F, 0.04F,  0.041F, 0.042F, 0.043F, 0.044F,
      0.045F, 0.046F, 0.047F, 0.048F, 0.049F, 0.05F,  0.051F, 0.052F, 0.053F,
      0.054F, 0.055F, 0.056F, 0.057F, 0.058F, 0.059F, 0.06F,  0.061F, 0.062F,
      0.063F, 0.064F, 0.065F, 0.066F, 0.067F, 0.068F, 0.069F, 0.07F,  0.071F,
      0.072F, 0.073F, 0.074F, 0.075F, 0.076F, 0.077F, 0.078F, 0.079F, 0.08F,
      0.081F, 0.082F, 0.083F, 0.084F, 0.085F, 0.086F, 0.087F, 0.088F, 0.089F,
      0.09F,  0.091F, 0.092F, 0.093F, 0.094F, 0.095F, 0.096F, 0.097F, 0.098F,
      0.099F};
  coder::array<float, 1U> xw;
  double f;
  float b_k[100];
  float x_data[100];
  float s2;
  float twiddleFactor;
  int b_eint;
  int eint;
  int k;
  int len;
  int n;
  s2 = duration * 1000.0F;
  if (s2 < 1.0F) {
    n = 0;
  } else {
    n = static_cast<int>(s2);
  }
  xw.set_size(static_cast<int>(static_cast<short>(n)));
  if (static_cast<short>(n) != 0) {
    len = static_cast<short>(n) - 1;
    for (k = 0; k <= len; k++) {
      xw[k] = input[k];
    }
  }
  f = std::frexp((static_cast<double>(xw.size(0)) + 100.0) - 1.0, &eint);
  if (f == 0.5) {
    eint--;
  }
  std::frexp(static_cast<double>(eint), &b_eint);
  len = xw.size(0);
  for (eint = 0; eint < 100; eint++) {
    float complexConstant_im;
    float complexConstant_re;
    float cos2TwidFactor;
    float phaseCorrection_im;
    float phaseCorrection_re;
    float s1;
    s2 = a[eint] * static_cast<float>(xw.size(0));
    b_k[eint] = s2;
    twiddleFactor = 6.28318548F * s2 / static_cast<float>(len);
    cos2TwidFactor = 2.0F * std::cos(twiddleFactor);
    phaseCorrection_re = twiddleFactor * 0.0F;
    if (phaseCorrection_re == 0.0F) {
      complexConstant_re = std::cos(-twiddleFactor);
      complexConstant_im = std::sin(-twiddleFactor);
    } else if (-twiddleFactor == 0.0F) {
      complexConstant_re = rtNaNF;
      complexConstant_im = 0.0F;
    } else {
      complexConstant_re = rtNaNF;
      complexConstant_im = rtNaNF;
    }
    phaseCorrection_re *= static_cast<float>(len) - 1.0F;
    phaseCorrection_im = (static_cast<float>(len) - 1.0F) * -twiddleFactor;
    if (phaseCorrection_re == 0.0F) {
      phaseCorrection_re = std::cos(phaseCorrection_im);
      phaseCorrection_im = std::sin(phaseCorrection_im);
    } else if (phaseCorrection_im == 0.0F) {
      phaseCorrection_re = rtNaNF;
      phaseCorrection_im = 0.0F;
    } else {
      phaseCorrection_re = rtNaNF;
      phaseCorrection_im = rtNaNF;
    }
    s1 = 0.0F;
    s2 = 0.0F;
    for (b_eint = 0; b_eint <= len - 2; b_eint++) {
      twiddleFactor = (xw[b_eint] + cos2TwidFactor * s1) - s2;
      s2 = s1;
      s1 = twiddleFactor;
    }
    cos2TwidFactor =
        ((xw[len - 1] + cos2TwidFactor * s1) - s2) - s1 * complexConstant_re;
    s2 = 0.0F - s1 * complexConstant_im;
    complexConstant_re =
        cos2TwidFactor * phaseCorrection_re - s2 * phaseCorrection_im;
    s2 = cos2TwidFactor * phaseCorrection_im + s2 * phaseCorrection_re;
    cos2TwidFactor = complexConstant_re * complexConstant_re - s2 * -s2;
    twiddleFactor = complexConstant_re * -s2 + s2 * complexConstant_re;
    if (twiddleFactor == 0.0F) {
      complexConstant_re =
          cos2TwidFactor / static_cast<float>(static_cast<short>(n));
    } else if (cos2TwidFactor == 0.0F) {
      complexConstant_re = 0.0F;
    } else {
      complexConstant_re =
          cos2TwidFactor / static_cast<float>(static_cast<short>(n));
    }
    b_k[eint] = complexConstant_re / 1000.0F;
    if (twiddleFactor == 0.0F) {
      complexConstant_re =
          cos2TwidFactor / static_cast<float>(static_cast<short>(n));
    } else if (cos2TwidFactor == 0.0F) {
      complexConstant_re = 0.0F;
    } else {
      complexConstant_re =
          cos2TwidFactor / static_cast<float>(static_cast<short>(n));
    }
    x_data[eint] = complexConstant_re / 1000.0F;
  }
  if (!std::isnan(x_data[0])) {
    len = 1;
  } else {
    bool exitg1;
    len = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 101)) {
      if (!std::isnan(x_data[k - 1])) {
        len = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (len == 0) {
    twiddleFactor = b_k[0];
  } else {
    twiddleFactor = b_k[len - 1];
    len++;
    for (k = len; k < 101; k++) {
      s2 = b_k[k - 1];
      if (twiddleFactor < s2) {
        twiddleFactor = s2;
      }
    }
  }
  for (len = 0; len < 100; len++) {
    B[len] = static_cast<float>(len);
    B[len + 100] = b_k[len] / twiddleFactor;
  }
}

//
// File trailer for foo.cpp
//
// [EOF]
//
