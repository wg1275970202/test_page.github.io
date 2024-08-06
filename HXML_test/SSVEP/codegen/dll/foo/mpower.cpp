//
// File: mpower.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Aug-2024 01:31:17
//

// Include Files
#include "mpower.h"
#include "foo_rtwutil.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include <cmath>
#include <cstring>

// Function Declarations
static float rt_atan2f_snf(float u0, float u1);

// Function Definitions
//
// Arguments    : float u0
//                float u1
// Return Type  : float
//
static float rt_atan2f_snf(float u0, float u1)
{
  float y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = rtNaNF;
  } else if (std::isinf(u0) && std::isinf(u1)) {
    int i;
    int i1;
    if (u0 > 0.0F) {
      i = 1;
    } else {
      i = -1;
    }
    if (u1 > 0.0F) {
      i1 = 1;
    } else {
      i1 = -1;
    }
    y = std::atan2(static_cast<float>(i), static_cast<float>(i1));
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = std::atan2(u0, u1);
  }
  return y;
}

//
// Arguments    : const creal32_T a
//                float b
// Return Type  : creal32_T
//
namespace coder {
creal32_T mpower(const creal32_T a, float b)
{
  creal32_T c;
  if ((a.im == 0.0F) && (a.re >= 0.0F)) {
    c.re = rt_powf_snf(a.re, b);
    c.im = 0.0F;
  } else if ((a.re == 0.0F) && (std::floor(b) == b)) {
    float r;
    float ytmp;
    signed char i;
    ytmp = rt_powf_snf(a.im, b);
    if (std::isinf(b)) {
      r = rtNaNF;
    } else if (b == 0.0F) {
      r = 0.0F;
    } else {
      r = std::fmod(b, 4.0F);
      if (r == 0.0F) {
        r = 0.0F;
      } else if (b < 0.0F) {
        r += 4.0F;
      }
    }
    if (r < 128.0F) {
      i = static_cast<signed char>(r);
    } else {
      i = 0;
    }
    if (i == 3) {
      c.re = 0.0F;
      c.im = -ytmp;
    } else if (i == 2) {
      c.re = -ytmp;
      c.im = 0.0F;
    } else if (i == 1) {
      c.re = 0.0F;
      c.im = ytmp;
    } else {
      c.re = ytmp;
      c.im = 0.0F;
    }
  } else if ((a.im == 0.0F) && std::isinf(b) && (std::abs(a.re) == 1.0F)) {
    c.re = 1.0F;
    c.im = 0.0F;
  } else {
    float b_im;
    float ytmp;
    if (a.im == 0.0F) {
      if (a.re < 0.0F) {
        ytmp = std::log(std::abs(a.re));
        b_im = 3.14159274F;
      } else {
        ytmp = std::log(a.re);
        b_im = 0.0F;
      }
    } else if ((std::abs(a.re) > 1.70141173E+38F) ||
               (std::abs(a.im) > 1.70141173E+38F)) {
      ytmp = std::log(rt_hypotf_snf(a.re / 2.0F, a.im / 2.0F)) + 0.693147182F;
      b_im = rt_atan2f_snf(a.im, a.re);
    } else {
      ytmp = std::log(rt_hypotf_snf(a.re, a.im));
      b_im = rt_atan2f_snf(a.im, a.re);
    }
    ytmp *= b;
    b_im *= b;
    if (ytmp == 0.0F) {
      c.re = std::cos(b_im);
      c.im = std::sin(b_im);
    } else if (b_im == 0.0F) {
      c.re = std::exp(ytmp);
      c.im = 0.0F;
    } else if (std::isinf(b_im) && std::isinf(ytmp) && (ytmp < 0.0F)) {
      c.re = 0.0F;
      c.im = 0.0F;
    } else {
      float r;
      r = std::exp(ytmp / 2.0F);
      c.re = r * (r * std::cos(b_im));
      c.im = r * (r * std::sin(b_im));
    }
  }
  return c;
}

//
// Arguments    : const creal32_T a
//                double b
// Return Type  : creal32_T
//
creal32_T mpower(const creal32_T a, double b)
{
  creal32_T c;
  if ((a.im == 0.0F) && (a.re >= 0.0F)) {
    c.re = rt_powf_snf(a.re, static_cast<float>(b));
    c.im = 0.0F;
  } else if ((a.re == 0.0F) && (b == b)) {
    double b_r;
    float r;
    signed char i;
    r = rt_powf_snf(a.im, static_cast<float>(b));
    b_r = std::fmod(b, 4.0);
    if (b_r == 0.0) {
      b_r = 0.0;
    } else {
      b_r += 4.0;
    }
    b_r = std::round(b_r);
    if (b_r < 128.0) {
      i = static_cast<signed char>(b_r);
    } else {
      i = 0;
    }
    if (i == 3) {
      c.re = 0.0F;
      c.im = -r;
    } else if (i == 2) {
      c.re = -r;
      c.im = 0.0F;
    } else if (i == 1) {
      c.re = 0.0F;
      c.im = r;
    } else {
      c.re = r;
      c.im = 0.0F;
    }
  } else {
    float b_im;
    float r;
    if (a.im == 0.0F) {
      if (a.re < 0.0F) {
        r = std::log(std::abs(a.re));
        b_im = 3.14159274F;
      } else {
        r = std::log(a.re);
        b_im = 0.0F;
      }
    } else if ((std::abs(a.re) > 1.70141173E+38F) ||
               (std::abs(a.im) > 1.70141173E+38F)) {
      r = std::log(rt_hypotf_snf(a.re / 2.0F, a.im / 2.0F)) + 0.693147182F;
      b_im = rt_atan2f_snf(a.im, a.re);
    } else {
      r = std::log(rt_hypotf_snf(a.re, a.im));
      b_im = rt_atan2f_snf(a.im, a.re);
    }
    r *= static_cast<float>(b);
    b_im *= static_cast<float>(b);
    if (r == 0.0F) {
      c.re = std::cos(b_im);
      c.im = std::sin(b_im);
    } else if (b_im == 0.0F) {
      c.re = std::exp(r);
      c.im = 0.0F;
    } else if (std::isinf(b_im) && std::isinf(r) && (r < 0.0F)) {
      c.re = 0.0F;
      c.im = 0.0F;
    } else {
      r = std::exp(r / 2.0F);
      c.re = r * (r * std::cos(b_im));
      c.im = r * (r * std::sin(b_im));
    }
  }
  return c;
}

} // namespace coder

//
// File trailer for mpower.cpp
//
// [EOF]
//
