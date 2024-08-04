//
// File: czt.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 04-Aug-2024 23:30:26
//

// Include Files
#include "czt.h"
#include "fft.h"
#include "foo_data.h"
#include "ifft.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "rt_defines.h"
#include <cmath>

// Function Declarations
static float rt_atan2f_snf(float u0, float u1);

static float rt_hypotf_snf(float u0, float u1);

static float rt_powf_snf(float u0, float u1);

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
// Arguments    : float u0
//                float u1
// Return Type  : float
//
static float rt_hypotf_snf(float u0, float u1)
{
  float a;
  float b;
  float y;
  a = std::abs(u0);
  b = std::abs(u1);
  if (a < b) {
    a /= b;
    y = b * std::sqrt(a * a + 1.0F);
  } else if (a > b) {
    b /= a;
    y = a * std::sqrt(b * b + 1.0F);
  } else if (std::isnan(b)) {
    y = rtNaNF;
  } else {
    y = a * 1.41421354F;
  }
  return y;
}

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
// Arguments    : const array<float, 1U> &x
//                const creal32_T w
//                const creal32_T a
//                creal32_T g[501]
// Return Type  : void
//
namespace coder {
void czt(const array<float, 1U> &x, const creal32_T w, const creal32_T a,
         creal32_T g[501])
{
  array<creal32_T, 2U> aa;
  array<creal32_T, 1U> b_r;
  array<creal32_T, 1U> fv;
  array<creal32_T, 1U> fy;
  array<creal32_T, 1U> ww;
  array<creal32_T, 1U> x1;
  array<creal32_T, 1U> y;
  float ai;
  float ar;
  float b;
  float initVal;
  float nfft;
  float r;
  float y_re;
  float ytmp;
  int eint;
  int i;
  int m;
  int maxDim;
  x1.set_size(x.size(0));
  maxDim = x.size(0);
  for (i = 0; i < maxDim; i++) {
    x1[i].re = x[i];
    x1[i].im = 0.0F;
  }
  m = x1.size(0);
  initVal = std::frexp((static_cast<float>(x1.size(0)) + 501.0F) - 1.0F, &eint);
  if (initVal == 0.5F) {
    eint--;
  }
  nfft = rt_powf_snf(2.0F, static_cast<float>(eint));
  maxDim =
      static_cast<int>(std::fmax(
          500.0F, static_cast<float>(static_cast<double>(x1.size(0)) - 1.0))) +
      x1.size(0);
  ww.set_size(maxDim);
  initVal = static_cast<float>(-static_cast<double>(x1.size(0))) + 1.0F;
  ar = w.re;
  ai = w.im;
  for (eint = 0; eint < maxDim; eint++) {
    b = initVal * initVal / 2.0F;
    if ((ai == 0.0F) && (ar >= 0.0F)) {
      ww[eint].re = rt_powf_snf(ar, b);
      ww[eint].im = 0.0F;
    } else if ((ar == 0.0F) && (std::floor(b) == b)) {
      signed char i1;
      ytmp = rt_powf_snf(ai, b);
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
        i1 = static_cast<signed char>(r);
      } else {
        i1 = 0;
      }
      if (i1 == 3) {
        ww[eint].re = 0.0F;
        ww[eint].im = -ytmp;
      } else if (i1 == 2) {
        ww[eint].re = -ytmp;
        ww[eint].im = 0.0F;
      } else if (i1 == 1) {
        ww[eint].re = 0.0F;
        ww[eint].im = ytmp;
      } else {
        ww[eint].re = ytmp;
        ww[eint].im = 0.0F;
      }
    } else if ((ai == 0.0F) && std::isinf(b) && (std::abs(ar) == 1.0F)) {
      ww[eint].re = 1.0F;
      ww[eint].im = 0.0F;
    } else {
      if (w.im == 0.0F) {
        if (w.re < 0.0F) {
          y_re = std::log(std::abs(w.re));
          ytmp = 3.14159274F;
        } else {
          y_re = std::log(w.re);
          ytmp = 0.0F;
        }
      } else if ((std::abs(w.re) > 1.70141173E+38F) ||
                 (std::abs(w.im) > 1.70141173E+38F)) {
        y_re = std::log(rt_hypotf_snf(w.re / 2.0F, w.im / 2.0F)) + 0.693147182F;
        ytmp = rt_atan2f_snf(w.im, w.re);
      } else {
        y_re = std::log(rt_hypotf_snf(w.re, w.im));
        ytmp = rt_atan2f_snf(w.im, w.re);
      }
      y_re *= b;
      ytmp *= b;
      if (y_re == 0.0F) {
        ww[eint].re = std::cos(ytmp);
        ww[eint].im = std::sin(ytmp);
      } else if (ytmp == 0.0F) {
        ww[eint].re = std::exp(y_re);
        ww[eint].im = 0.0F;
      } else if (std::isinf(ytmp) && std::isinf(y_re) && (y_re < 0.0F)) {
        ww[eint].re = 0.0F;
        ww[eint].im = 0.0F;
      } else {
        r = std::exp(y_re / 2.0F);
        ww[eint].re = r * (r * std::cos(ytmp));
        ww[eint].im = r * (r * std::sin(ytmp));
      }
    }
    initVal++;
  }
  aa.set_size(1, x1.size(0));
  aa[0] = ww[x1.size(0) - 1];
  i = x1.size(0);
  for (eint = 0; eint <= i - 2; eint++) {
    if ((a.im == 0.0F) && (a.re >= 0.0F)) {
      y_re = rt_powf_snf(
          a.re, static_cast<float>(-(static_cast<double>(eint) + 1.0)));
      ytmp = 0.0F;
    } else if (a.re == 0.0F) {
      ytmp = rt_powf_snf(
          a.im, static_cast<float>(-(static_cast<double>(eint) + 1.0)));
      maxDim =
          static_cast<int>(std::fmod(-(static_cast<double>(eint) + 1.0), 4.0));
      if (maxDim == 0) {
        maxDim = -4;
      }
      if (maxDim + 4 == 3) {
        y_re = 0.0F;
        ytmp = -ytmp;
      } else if (maxDim + 4 == 2) {
        y_re = -ytmp;
        ytmp = 0.0F;
      } else if (maxDim + 4 == 1) {
        y_re = 0.0F;
      } else {
        y_re = ytmp;
        ytmp = 0.0F;
      }
    } else {
      if (a.im == 0.0F) {
        if (a.re < 0.0F) {
          y_re = std::log(std::abs(a.re));
          ytmp = 3.14159274F;
        } else {
          y_re = std::log(a.re);
          ytmp = 0.0F;
        }
      } else if ((std::abs(a.re) > 1.70141173E+38F) ||
                 (std::abs(a.im) > 1.70141173E+38F)) {
        y_re = std::log(rt_hypotf_snf(a.re / 2.0F, a.im / 2.0F)) + 0.693147182F;
        ytmp = rt_atan2f_snf(a.im, a.re);
      } else {
        y_re = std::log(rt_hypotf_snf(a.re, a.im));
        ytmp = rt_atan2f_snf(a.im, a.re);
      }
      y_re *= static_cast<float>(-(static_cast<double>(eint) + 1.0));
      ytmp *= static_cast<float>(-(static_cast<double>(eint) + 1.0));
      if (y_re == 0.0F) {
        y_re = std::cos(ytmp);
        ytmp = std::sin(ytmp);
      } else if (ytmp == 0.0F) {
        y_re = std::exp(y_re);
        ytmp = 0.0F;
      } else if (std::isinf(ytmp) && std::isinf(y_re) && (y_re < 0.0F)) {
        y_re = 0.0F;
        ytmp = 0.0F;
      } else {
        r = std::exp(y_re / 2.0F);
        y_re = r * (r * std::cos(ytmp));
        ytmp = r * (r * std::sin(ytmp));
      }
    }
    maxDim = m + eint;
    ar = ww[maxDim].im;
    b = ww[maxDim].re;
    aa[eint + 1].re = y_re * b - ytmp * ar;
    aa[eint + 1].im = y_re * ar + ytmp * b;
  }
  y.set_size(x1.size(0));
  i = x1.size(0);
  for (maxDim = 0; maxDim < i; maxDim++) {
    ar = x1[maxDim].re;
    b = aa[maxDim].im;
    ai = x1[maxDim].im;
    initVal = aa[maxDim].re;
    y[maxDim].re = ar * initVal - ai * b;
    y[maxDim].im = ar * b + ai * initVal;
  }
  fft(y, nfft, fy);
  maxDim = x1.size(0);
  b_r.set_size(x1.size(0) + 500);
  for (i = 0; i <= maxDim + 499; i++) {
    ai = ww[i].re;
    b = ww[i].im;
    if (b == 0.0F) {
      b_r[i].re = 1.0F / ai;
      b_r[i].im = 0.0F;
    } else if (ai == 0.0F) {
      b_r[i].re = 0.0F;
      b_r[i].im = -(1.0F / b);
    } else {
      r = std::abs(ai);
      initVal = std::abs(b);
      if (r > initVal) {
        r = b / ai;
        initVal = ai + r * b;
        b_r[i].re = (r * 0.0F + 1.0F) / initVal;
        b_r[i].im = (0.0F - r) / initVal;
      } else if (initVal == r) {
        if (ai > 0.0F) {
          ar = 0.5F;
        } else {
          ar = -0.5F;
        }
        if (b > 0.0F) {
          initVal = 0.5F;
        } else {
          initVal = -0.5F;
        }
        b_r[i].re = (ar + 0.0F * initVal) / r;
        b_r[i].im = (0.0F * ar - initVal) / r;
      } else {
        r = ai / b;
        initVal = b + r * ai;
        b_r[i].re = r / initVal;
        b_r[i].im = (r * 0.0F - 1.0F) / initVal;
      }
    }
  }
  fft(b_r, nfft, fv);
  i = static_cast<int>(nfft);
  for (maxDim = 0; maxDim < i; maxDim++) {
    initVal = fy[maxDim].re;
    r = fv[maxDim].im;
    ar = fy[maxDim].im;
    ai = fv[maxDim].re;
    fy[maxDim].re = initVal * ai - ar * r;
    fy[maxDim].im = initVal * r + ar * ai;
  }
  ifft(fy, fv);
  for (maxDim = 0; maxDim < 501; maxDim++) {
    initVal = static_cast<float>(m + maxDim);
    ar = fv[static_cast<int>(initVal) - 1].re;
    b = ww[static_cast<int>(initVal) - 1].im;
    ai = fv[static_cast<int>(initVal) - 1].im;
    initVal = ww[static_cast<int>(initVal) - 1].re;
    g[maxDim].re = ar * initVal - ai * b;
    g[maxDim].im = ar * b + ai * initVal;
  }
}

} // namespace coder

//
// File trailer for czt.cpp
//
// [EOF]
//
