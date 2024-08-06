//
// File: czt.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Aug-2024 01:31:17
//

// Include Files
#include "czt.h"
#include "fft.h"
#include "foo_data.h"
#include "foo_rtwutil.h"
#include "ifft.h"
#include "mpower.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Definitions
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
  array<creal32_T, 1U> fv;
  array<creal32_T, 1U> fy;
  array<creal32_T, 1U> r;
  array<creal32_T, 1U> ww;
  array<creal32_T, 1U> x1;
  array<creal32_T, 1U> y;
  float br;
  float brm;
  float initVal;
  float nfft;
  float sgnbr;
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
  initVal = std::frexp(static_cast<float>(x1.size(0) + 500), &eint);
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
  for (eint = 0; eint < maxDim; eint++) {
    ww[eint] = mpower(w, initVal * initVal / 2.0F);
    initVal++;
  }
  aa.set_size(1, x1.size(0));
  aa[0] = ww[x1.size(0) - 1];
  i = x1.size(0);
  for (eint = 0; eint <= i - 2; eint++) {
    creal32_T fc;
    fc = mpower(a, -(static_cast<double>(eint) + 1.0));
    maxDim = m + eint;
    br = ww[maxDim].im;
    brm = ww[maxDim].re;
    aa[eint + 1].re = fc.re * brm - fc.im * br;
    aa[eint + 1].im = fc.re * br + fc.im * brm;
  }
  y.set_size(x1.size(0));
  i = x1.size(0);
  for (maxDim = 0; maxDim < i; maxDim++) {
    br = x1[maxDim].re;
    brm = aa[maxDim].im;
    sgnbr = x1[maxDim].im;
    initVal = aa[maxDim].re;
    y[maxDim].re = br * initVal - sgnbr * brm;
    y[maxDim].im = br * brm + sgnbr * initVal;
  }
  fft(y, nfft, fy);
  maxDim = x1.size(0);
  r.set_size(x1.size(0) + 500);
  for (i = 0; i <= maxDim + 499; i++) {
    float bi;
    br = ww[i].re;
    bi = ww[i].im;
    if (bi == 0.0F) {
      r[i].re = 1.0F / br;
      r[i].im = 0.0F;
    } else if (br == 0.0F) {
      r[i].re = 0.0F;
      r[i].im = -(1.0F / bi);
    } else {
      brm = std::abs(br);
      initVal = std::abs(bi);
      if (brm > initVal) {
        brm = bi / br;
        initVal = br + brm * bi;
        r[i].re = (brm * 0.0F + 1.0F) / initVal;
        r[i].im = (0.0F - brm) / initVal;
      } else if (initVal == brm) {
        if (br > 0.0F) {
          sgnbr = 0.5F;
        } else {
          sgnbr = -0.5F;
        }
        if (bi > 0.0F) {
          initVal = 0.5F;
        } else {
          initVal = -0.5F;
        }
        r[i].re = (sgnbr + 0.0F * initVal) / brm;
        r[i].im = (0.0F * sgnbr - initVal) / brm;
      } else {
        brm = br / bi;
        initVal = bi + brm * br;
        r[i].re = brm / initVal;
        r[i].im = (brm * 0.0F - 1.0F) / initVal;
      }
    }
  }
  fft(r, nfft, fv);
  i = static_cast<int>(nfft);
  for (maxDim = 0; maxDim < i; maxDim++) {
    initVal = fy[maxDim].re;
    brm = fv[maxDim].im;
    sgnbr = fy[maxDim].im;
    br = fv[maxDim].re;
    fy[maxDim].re = initVal * br - sgnbr * brm;
    fy[maxDim].im = initVal * brm + sgnbr * br;
  }
  ifft(fy, fv);
  for (maxDim = 0; maxDim < 501; maxDim++) {
    initVal = static_cast<float>(m + maxDim);
    br = fv[static_cast<int>(initVal) - 1].re;
    brm = ww[static_cast<int>(initVal) - 1].im;
    sgnbr = fv[static_cast<int>(initVal) - 1].im;
    initVal = ww[static_cast<int>(initVal) - 1].re;
    g[maxDim].re = br * initVal - sgnbr * brm;
    g[maxDim].im = br * brm + sgnbr * initVal;
  }
}

//
// Arguments    : const array<float, 1U> &x
//                double k
//                const creal32_T w
//                const creal32_T a
//                creal32_T g_data[]
// Return Type  : int
//
int czt(const array<float, 1U> &x, double k, const creal32_T w,
        const creal32_T a, creal32_T g_data[])
{
  array<creal32_T, 2U> aa;
  array<creal32_T, 1U> fv;
  array<creal32_T, 1U> fy;
  array<creal32_T, 1U> r;
  array<creal32_T, 1U> ww;
  array<creal32_T, 1U> x1;
  array<creal32_T, 1U> y;
  float absn;
  float absn_tmp;
  float bi;
  float br;
  float f;
  float nfft;
  int eint;
  int g_size;
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
  absn_tmp = (static_cast<float>(x1.size(0)) + static_cast<float>(k)) - 1.0F;
  absn = std::abs(absn_tmp);
  if ((!std::isinf(absn)) && (!std::isnan(absn))) {
    f = std::frexp(absn, &eint);
    absn = static_cast<float>(eint);
    if (f == 0.5F) {
      absn = static_cast<float>(eint) - 1.0F;
    }
  }
  nfft = rt_powf_snf(2.0F, absn);
  maxDim = static_cast<int>(
      std::fmax(static_cast<float>(k) - 1.0F,
                static_cast<float>(static_cast<double>(x1.size(0)) - 1.0)) -
      static_cast<float>(-static_cast<double>(x1.size(0)) + 1.0));
  ww.set_size(maxDim + 1);
  absn = static_cast<float>(-static_cast<double>(x1.size(0))) + 1.0F;
  for (eint = 0; eint <= maxDim; eint++) {
    ww[eint] = mpower(w, absn * absn / 2.0F);
    absn++;
  }
  aa.set_size(1, x1.size(0));
  aa[0] = ww[x1.size(0) - 1];
  i = x1.size(0);
  for (eint = 0; eint <= i - 2; eint++) {
    creal32_T fc;
    fc = mpower(a, -(static_cast<double>(eint) + 1.0));
    maxDim = m + eint;
    f = ww[maxDim].im;
    br = ww[maxDim].re;
    aa[eint + 1].re = fc.re * br - fc.im * f;
    aa[eint + 1].im = fc.re * f + fc.im * br;
  }
  y.set_size(x1.size(0));
  i = x1.size(0);
  for (maxDim = 0; maxDim < i; maxDim++) {
    f = x1[maxDim].re;
    br = aa[maxDim].im;
    bi = x1[maxDim].im;
    absn = aa[maxDim].re;
    y[maxDim].re = f * absn - bi * br;
    y[maxDim].im = f * br + bi * absn;
  }
  fft(y, nfft, fy);
  f = (static_cast<float>(k) - 1.0F) + static_cast<float>(x1.size(0));
  if (f < 1.0F) {
    maxDim = 0;
  } else {
    maxDim = static_cast<int>(f);
  }
  r.set_size(maxDim);
  for (i = 0; i < maxDim; i++) {
    br = ww[i].re;
    bi = ww[i].im;
    if (bi == 0.0F) {
      r[i].re = 1.0F / br;
      r[i].im = 0.0F;
    } else if (br == 0.0F) {
      r[i].re = 0.0F;
      r[i].im = -(1.0F / bi);
    } else {
      float brm;
      brm = std::abs(br);
      absn = std::abs(bi);
      if (brm > absn) {
        f = bi / br;
        absn = br + f * bi;
        r[i].re = (f * 0.0F + 1.0F) / absn;
        r[i].im = (0.0F - f) / absn;
      } else if (absn == brm) {
        if (br > 0.0F) {
          f = 0.5F;
        } else {
          f = -0.5F;
        }
        if (bi > 0.0F) {
          absn = 0.5F;
        } else {
          absn = -0.5F;
        }
        r[i].re = (f + 0.0F * absn) / brm;
        r[i].im = (0.0F * f - absn) / brm;
      } else {
        f = br / bi;
        absn = bi + f * br;
        r[i].re = f / absn;
        r[i].im = (f * 0.0F - 1.0F) / absn;
      }
    }
  }
  fft(r, nfft, fv);
  i = static_cast<int>(nfft);
  for (maxDim = 0; maxDim < i; maxDim++) {
    absn = fy[static_cast<int>(static_cast<float>(maxDim) + 1.0F) - 1].re;
    f = fv[static_cast<int>(static_cast<float>(maxDim) + 1.0F) - 1].im;
    br = fy[static_cast<int>(static_cast<float>(maxDim) + 1.0F) - 1].im;
    bi = fv[static_cast<int>(static_cast<float>(maxDim) + 1.0F) - 1].re;
    fy[static_cast<int>(static_cast<float>(maxDim) + 1.0F) - 1].re =
        absn * bi - br * f;
    fy[static_cast<int>(static_cast<float>(maxDim) + 1.0F) - 1].im =
        absn * f + br * bi;
  }
  ifft(fy, fv);
  g_size = static_cast<int>(static_cast<float>(k));
  i = static_cast<int>(absn_tmp + (1.0F - static_cast<float>(x1.size(0))));
  for (maxDim = 0; maxDim < i; maxDim++) {
    absn = static_cast<float>(m) + static_cast<float>(maxDim);
    f = fv[static_cast<int>(absn) - 1].re;
    br = ww[static_cast<int>(absn) - 1].im;
    bi = fv[static_cast<int>(absn) - 1].im;
    absn = ww[static_cast<int>(absn) - 1].re;
    g_data[maxDim].re = f * absn - bi * br;
    g_data[maxDim].im = f * br + bi * absn;
  }
  return g_size;
}

} // namespace coder

//
// File trailer for czt.cpp
//
// [EOF]
//
