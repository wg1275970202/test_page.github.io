//
// File: computeDFT.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 04-Aug-2024 01:01:56
//

// Include Files
#include "computeDFT.h"
#include "fft.h"
#include "foo_data.h"
#include "ifft.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
static float rt_powf_snf(float u0, float u1);

// Function Definitions
//
// Arguments    : float u0
//                float u1
// Return Type  : float
//
static float rt_powf_snf(float u0, float u1)
{
  float y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = rtNaNF;
  } else {
    float f;
    float f1;
    f = std::abs(u0);
    f1 = std::abs(u1);
    if (std::isinf(u1)) {
      if (f == 1.0F) {
        y = 1.0F;
      } else if (f > 1.0F) {
        if (u1 > 0.0F) {
          y = rtInfF;
        } else {
          y = 0.0F;
        }
      } else if (u1 > 0.0F) {
        y = 0.0F;
      } else {
        y = rtInfF;
      }
    } else if (f1 == 0.0F) {
      y = 1.0F;
    } else if (f1 == 1.0F) {
      if (u1 > 0.0F) {
        y = u0;
      } else {
        y = 1.0F / u0;
      }
    } else if (u1 == 2.0F) {
      y = u0 * u0;
    } else if ((u1 == 0.5F) && (u0 >= 0.0F)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0F) && (u1 > std::floor(u1))) {
      y = rtNaNF;
    } else {
      y = std::pow(u0, u1);
    }
  }
  return y;
}

//
// Arguments    : const array<float, 1U> &xin
//                creal32_T Xx[201]
// Return Type  : void
//
namespace coder {
void computeDFTviaCZT(const array<float, 1U> &xin, creal32_T Xx[201])
{
  array<creal32_T, 2U> aa;
  array<creal32_T, 1U> b_r;
  array<creal32_T, 1U> fv;
  array<creal32_T, 1U> fy;
  array<creal32_T, 1U> ww;
  array<creal32_T, 1U> x1;
  array<creal32_T, 1U> y;
  float initVal;
  float r;
  float y_im;
  float y_re;
  int i;
  int loop_ub;
  int m;
  int maxDim;
  int nfft;
  x1.set_size(xin.size(0));
  loop_ub = xin.size(0);
  for (i = 0; i < loop_ub; i++) {
    x1[i].re = xin[i];
    x1[i].im = 0.0F;
  }
  m = x1.size(0);
  r = std::frexp((static_cast<float>(x1.size(0)) + 201.0F) - 1.0F, &maxDim);
  if (r == 0.5F) {
    maxDim--;
  }
  nfft = static_cast<int>(rt_powf_snf(2.0F, static_cast<float>(maxDim)));
  maxDim = static_cast<int>(
               std::fmax(200.0F, static_cast<float>(x1.size(0)) - 1.0F)) +
           x1.size(0);
  ww.set_size(maxDim);
  initVal = -static_cast<float>(x1.size(0)) + 1.0F;
  for (loop_ub = 0; loop_ub < maxDim; loop_ub++) {
    r = initVal * initVal / 2.0F;
    y_re = r * -5.96046448E-8F;
    y_im = r * -0.00157079636F;
    if (y_re == 0.0F) {
      ww[loop_ub].re = std::cos(y_im);
      ww[loop_ub].im = std::sin(y_im);
    } else if (y_im == 0.0F) {
      ww[loop_ub].re = std::exp(y_re);
      ww[loop_ub].im = 0.0F;
    } else if (std::isinf(y_im) && std::isinf(y_re) && (y_re < 0.0F)) {
      ww[loop_ub].re = 0.0F;
      ww[loop_ub].im = 0.0F;
    } else {
      r = std::exp(y_re / 2.0F);
      ww[loop_ub].re = r * (r * std::cos(y_im));
      ww[loop_ub].im = r * (r * std::sin(y_im));
    }
    initVal++;
  }
  aa.set_size(1, x1.size(0));
  aa[0] = ww[x1.size(0) - 1];
  i = x1.size(0);
  for (loop_ub = 0; loop_ub <= i - 2; loop_ub++) {
    maxDim = m + loop_ub;
    r = ww[maxDim].im;
    y_re = ww[maxDim].re;
    aa[loop_ub + 1].re = y_re - 0.0F * r;
    aa[loop_ub + 1].im = r + 0.0F * y_re;
  }
  y.set_size(x1.size(0));
  i = x1.size(0);
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    r = x1[loop_ub].re;
    y_re = aa[loop_ub].im;
    y_im = x1[loop_ub].im;
    initVal = aa[loop_ub].re;
    y[loop_ub].re = r * initVal - y_im * y_re;
    y[loop_ub].im = r * y_re + y_im * initVal;
  }
  fft(y, static_cast<float>(nfft), fy);
  loop_ub = x1.size(0);
  b_r.set_size(x1.size(0) + 200);
  for (i = 0; i <= loop_ub + 199; i++) {
    y_im = ww[i].re;
    initVal = ww[i].im;
    if (initVal == 0.0F) {
      b_r[i].re = 1.0F / y_im;
      b_r[i].im = 0.0F;
    } else if (y_im == 0.0F) {
      b_r[i].re = 0.0F;
      b_r[i].im = -(1.0F / initVal);
    } else {
      float brm;
      brm = std::abs(y_im);
      r = std::abs(initVal);
      if (brm > r) {
        y_re = initVal / y_im;
        r = y_im + y_re * initVal;
        b_r[i].re = (y_re * 0.0F + 1.0F) / r;
        b_r[i].im = (0.0F - y_re) / r;
      } else if (r == brm) {
        if (y_im > 0.0F) {
          y_re = 0.5F;
        } else {
          y_re = -0.5F;
        }
        if (initVal > 0.0F) {
          r = 0.5F;
        } else {
          r = -0.5F;
        }
        b_r[i].re = (y_re + 0.0F * r) / brm;
        b_r[i].im = (0.0F * y_re - r) / brm;
      } else {
        y_re = y_im / initVal;
        r = initVal + y_re * y_im;
        b_r[i].re = y_re / r;
        b_r[i].im = (y_re * 0.0F - 1.0F) / r;
      }
    }
  }
  fft(b_r, static_cast<float>(nfft), fv);
  for (loop_ub = 0; loop_ub < nfft; loop_ub++) {
    r = fy[loop_ub].re;
    y_re = fv[loop_ub].im;
    y_im = fy[loop_ub].im;
    initVal = fv[loop_ub].re;
    fy[loop_ub].re = r * initVal - y_im * y_re;
    fy[loop_ub].im = r * y_re + y_im * initVal;
  }
  ifft(fy, fv);
  for (loop_ub = 0; loop_ub < 201; loop_ub++) {
    maxDim = (m + loop_ub) - 1;
    r = fv[maxDim].re;
    y_re = ww[maxDim].im;
    y_im = fv[maxDim].im;
    initVal = ww[maxDim].re;
    Xx[loop_ub].re = r * initVal - y_im * y_re;
    Xx[loop_ub].im = r * y_re + y_im * initVal;
  }
}

} // namespace coder

//
// File trailer for computeDFT.cpp
//
// [EOF]
//
