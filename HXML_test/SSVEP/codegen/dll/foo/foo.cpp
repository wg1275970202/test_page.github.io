//
// File: foo.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 04-Aug-2024 01:01:56
//

// Include Files
#include "foo.h"
#include "computeDFT.h"
#include "foo_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const float input[30000]
//                float duration
//                float B[402]
// Return Type  : void
//
void foo(const float input[30000], float duration, float B[402])
{
  static const float a[201]{
      0.0F,   0.00025F, 0.0005F, 0.00075F, 0.001F, 0.00125F, 0.0015F, 0.00175F,
      0.002F, 0.00225F, 0.0025F, 0.00275F, 0.003F, 0.00325F, 0.0035F, 0.00375F,
      0.004F, 0.00425F, 0.0045F, 0.00475F, 0.005F, 0.00525F, 0.0055F, 0.00575F,
      0.006F, 0.00625F, 0.0065F, 0.00675F, 0.007F, 0.00725F, 0.0075F, 0.00775F,
      0.008F, 0.00825F, 0.0085F, 0.00875F, 0.009F, 0.00925F, 0.0095F, 0.00975F,
      0.01F,  0.01025F, 0.0105F, 0.01075F, 0.011F, 0.01125F, 0.0115F, 0.01175F,
      0.012F, 0.01225F, 0.0125F, 0.01275F, 0.013F, 0.01325F, 0.0135F, 0.01375F,
      0.014F, 0.01425F, 0.0145F, 0.01475F, 0.015F, 0.01525F, 0.0155F, 0.01575F,
      0.016F, 0.01625F, 0.0165F, 0.01675F, 0.017F, 0.01725F, 0.0175F, 0.01775F,
      0.018F, 0.01825F, 0.0185F, 0.01875F, 0.019F, 0.01925F, 0.0195F, 0.01975F,
      0.02F,  0.02025F, 0.0205F, 0.02075F, 0.021F, 0.02125F, 0.0215F, 0.02175F,
      0.022F, 0.02225F, 0.0225F, 0.02275F, 0.023F, 0.02325F, 0.0235F, 0.02375F,
      0.024F, 0.02425F, 0.0245F, 0.02475F, 0.025F, 0.02525F, 0.0255F, 0.02575F,
      0.026F, 0.02625F, 0.0265F, 0.02675F, 0.027F, 0.02725F, 0.0275F, 0.02775F,
      0.028F, 0.02825F, 0.0285F, 0.02875F, 0.029F, 0.02925F, 0.0295F, 0.02975F,
      0.03F,  0.03025F, 0.0305F, 0.03075F, 0.031F, 0.03125F, 0.0315F, 0.03175F,
      0.032F, 0.03225F, 0.0325F, 0.03275F, 0.033F, 0.03325F, 0.0335F, 0.03375F,
      0.034F, 0.03425F, 0.0345F, 0.03475F, 0.035F, 0.03525F, 0.0355F, 0.03575F,
      0.036F, 0.03625F, 0.0365F, 0.03675F, 0.037F, 0.03725F, 0.0375F, 0.03775F,
      0.038F, 0.03825F, 0.0385F, 0.03875F, 0.039F, 0.03925F, 0.0395F, 0.03975F,
      0.04F,  0.04025F, 0.0405F, 0.04075F, 0.041F, 0.04125F, 0.0415F, 0.04175F,
      0.042F, 0.04225F, 0.0425F, 0.04275F, 0.043F, 0.04325F, 0.0435F, 0.04375F,
      0.044F, 0.04425F, 0.0445F, 0.04475F, 0.045F, 0.04525F, 0.0455F, 0.04575F,
      0.046F, 0.04625F, 0.0465F, 0.04675F, 0.047F, 0.04725F, 0.0475F, 0.04775F,
      0.048F, 0.04825F, 0.0485F, 0.04875F, 0.049F, 0.04925F, 0.0495F, 0.04975F,
      0.05F};
  coder::array<float, 1U> xw;
  creal32_T b_y1[201];
  double f;
  float b_k[201];
  float x_data[201];
  float cos2TwidFactor;
  float s0;
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
  f = std::frexp((static_cast<double>(xw.size(0)) + 201.0) - 1.0, &eint);
  if (f == 0.5) {
    eint--;
  }
  f = std::frexp(static_cast<double>(eint), &b_eint);
  if (f == 0.5) {
    f = static_cast<double>(b_eint) - 1.0;
  } else {
    f = std::log(f) / 0.69314718055994529 + static_cast<double>(b_eint);
  }
  if (80.0 * f < 201.0) {
    coder::computeDFTviaCZT(xw, b_y1);
  } else {
    len = xw.size(0);
    for (eint = 0; eint < 201; eint++) {
      float complexConstant_im;
      float complexConstant_re;
      float phaseCorrection_im;
      float phaseCorrection_re;
      twiddleFactor = 6.28318548F * (a[eint] * static_cast<float>(xw.size(0))) /
                      static_cast<float>(len);
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
      twiddleFactor = 0.0F;
      s2 = 0.0F;
      for (b_eint = 0; b_eint <= len - 2; b_eint++) {
        s0 = (xw[b_eint] + cos2TwidFactor * twiddleFactor) - s2;
        s2 = twiddleFactor;
        twiddleFactor = s0;
      }
      cos2TwidFactor = ((xw[len - 1] + cos2TwidFactor * twiddleFactor) - s2) -
                       twiddleFactor * complexConstant_re;
      s2 = 0.0F - twiddleFactor * complexConstant_im;
      b_y1[eint].re =
          cos2TwidFactor * phaseCorrection_re - s2 * phaseCorrection_im;
      b_y1[eint].im =
          cos2TwidFactor * phaseCorrection_im + s2 * phaseCorrection_re;
    }
  }
  for (len = 0; len < 201; len++) {
    twiddleFactor = b_y1[len].re;
    cos2TwidFactor = b_y1[len].im;
    s0 = twiddleFactor * twiddleFactor - cos2TwidFactor * -cos2TwidFactor;
    cos2TwidFactor =
        twiddleFactor * -cos2TwidFactor + cos2TwidFactor * twiddleFactor;
    if (cos2TwidFactor == 0.0F) {
      s2 = s0 / static_cast<float>(static_cast<short>(n));
    } else if (s0 == 0.0F) {
      s2 = 0.0F;
    } else {
      s2 = s0 / static_cast<float>(static_cast<short>(n));
    }
    b_k[len] = s2 / 1000.0F;
    if (cos2TwidFactor == 0.0F) {
      s2 = s0 / static_cast<float>(static_cast<short>(n));
    } else if (s0 == 0.0F) {
      s2 = 0.0F;
    } else {
      s2 = s0 / static_cast<float>(static_cast<short>(n));
    }
    x_data[len] = s2 / 1000.0F;
  }
  if (!std::isnan(x_data[0])) {
    len = 1;
  } else {
    bool exitg1;
    len = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 202)) {
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
    for (k = len; k < 202; k++) {
      s2 = b_k[k - 1];
      if (twiddleFactor < s2) {
        twiddleFactor = s2;
      }
    }
  }
  for (len = 0; len < 201; len++) {
    B[len] = 0.25F * static_cast<float>(len);
    B[len + 201] = b_k[len] / twiddleFactor;
  }
}

//
// File trailer for foo.cpp
//
// [EOF]
//
