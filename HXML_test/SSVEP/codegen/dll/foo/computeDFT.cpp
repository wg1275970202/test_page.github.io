//
// File: computeDFT.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Aug-2024 01:31:17
//

// Include Files
#include "computeDFT.h"
#include "fft.h"
#include "foo_data.h"
#include "foo_rtwutil.h"
#include "ifft.h"
#include "mpower.h"
#include "psdfreqvec.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const array<float, 1U> &xin
//                creal32_T Xx[451]
// Return Type  : void
//
namespace coder {
void b_computeDFTviaCZT(const array<float, 1U> &xin, creal32_T Xx[451])
{
  static const creal32_T fc{
      0.999999821F,    // re
      -0.000628318463F // im
  };
  array<creal32_T, 2U> aa;
  array<creal32_T, 1U> fv;
  array<creal32_T, 1U> fy;
  array<creal32_T, 1U> r;
  array<creal32_T, 1U> ww;
  array<creal32_T, 1U> x1;
  array<creal32_T, 1U> y;
  creal32_T fc1;
  float br;
  float brm;
  float initVal;
  float nfft;
  float sgnbr;
  int eint;
  int i;
  int m;
  int maxDim;
  x1.set_size(xin.size(0));
  maxDim = xin.size(0);
  for (i = 0; i < maxDim; i++) {
    x1[i].re = xin[i];
    x1[i].im = 0.0F;
  }
  m = x1.size(0);
  initVal = std::frexp(static_cast<float>(x1.size(0) + 450), &eint);
  if (initVal == 0.5F) {
    eint--;
  }
  nfft = rt_powf_snf(2.0F, static_cast<float>(eint));
  maxDim =
      static_cast<int>(std::fmax(
          450.0F, static_cast<float>(static_cast<double>(x1.size(0)) - 1.0))) +
      x1.size(0);
  ww.set_size(maxDim);
  initVal = static_cast<float>(-static_cast<double>(x1.size(0))) + 1.0F;
  for (eint = 0; eint < maxDim; eint++) {
    ww[eint] = mpower(fc, initVal * initVal / 2.0F);
    initVal++;
  }
  aa.set_size(1, x1.size(0));
  aa[0] = ww[x1.size(0) - 1];
  i = x1.size(0);
  if (i - 2 >= 0) {
    fc1.re = 1.0F;
    fc1.im = 0.0F;
  }
  for (eint = 0; eint <= i - 2; eint++) {
    creal32_T fc2;
    fc2 = mpower(fc1, -(static_cast<double>(eint) + 1.0));
    maxDim = m + eint;
    br = ww[maxDim].im;
    brm = ww[maxDim].re;
    aa[eint + 1].re = fc2.re * brm - fc2.im * br;
    aa[eint + 1].im = fc2.re * br + fc2.im * brm;
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
  r.set_size(x1.size(0) + 450);
  for (i = 0; i <= maxDim + 449; i++) {
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
  for (maxDim = 0; maxDim < 451; maxDim++) {
    initVal = static_cast<float>(m + maxDim);
    br = fv[static_cast<int>(initVal) - 1].re;
    brm = ww[static_cast<int>(initVal) - 1].im;
    sgnbr = fv[static_cast<int>(initVal) - 1].im;
    initVal = ww[static_cast<int>(initVal) - 1].re;
    Xx[maxDim].re = br * initVal - sgnbr * brm;
    Xx[maxDim].im = br * brm + sgnbr * initVal;
  }
}

//
// Arguments    : const array<float, 1U> &xin
//                creal32_T Xx[100]
// Return Type  : void
//
void computeDFTviaCZT(const array<float, 1U> &xin, creal32_T Xx[100])
{
  static const creal32_T fc{
      0.999999821F,    // re
      -0.000628318463F // im
  };
  static const creal32_T fc2{
      0.997158885F, // re
      0.0753268F    // im
  };
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
  x1.set_size(xin.size(0));
  maxDim = xin.size(0);
  for (i = 0; i < maxDim; i++) {
    x1[i].re = xin[i];
    x1[i].im = 0.0F;
  }
  m = x1.size(0);
  initVal = std::frexp(static_cast<float>(x1.size(0) + 99), &eint);
  if (initVal == 0.5F) {
    eint--;
  }
  nfft = rt_powf_snf(2.0F, static_cast<float>(eint));
  maxDim =
      static_cast<int>(std::fmax(
          99.0F, static_cast<float>(static_cast<double>(x1.size(0)) - 1.0))) +
      x1.size(0);
  ww.set_size(maxDim);
  initVal = static_cast<float>(-static_cast<double>(x1.size(0))) + 1.0F;
  for (eint = 0; eint < maxDim; eint++) {
    ww[eint] = mpower(fc, initVal * initVal / 2.0F);
    initVal++;
  }
  aa.set_size(1, x1.size(0));
  aa[0] = ww[x1.size(0) - 1];
  i = x1.size(0);
  for (eint = 0; eint <= i - 2; eint++) {
    creal32_T fc1;
    fc1 = mpower(fc2, -(static_cast<double>(eint) + 1.0));
    maxDim = m + eint;
    br = ww[maxDim].im;
    brm = ww[maxDim].re;
    aa[eint + 1].re = fc1.re * brm - fc1.im * br;
    aa[eint + 1].im = fc1.re * br + fc1.im * brm;
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
  r.set_size(x1.size(0) + 99);
  for (i = 0; i <= maxDim + 98; i++) {
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
  for (maxDim = 0; maxDim < 100; maxDim++) {
    initVal = static_cast<float>(m + maxDim);
    br = fv[static_cast<int>(initVal) - 1].re;
    brm = ww[static_cast<int>(initVal) - 1].im;
    sgnbr = fv[static_cast<int>(initVal) - 1].im;
    initVal = ww[static_cast<int>(initVal) - 1].re;
    Xx[maxDim].re = br * initVal - sgnbr * brm;
    Xx[maxDim].im = br * brm + sgnbr * initVal;
  }
}

//
// Arguments    : const array<float, 1U> &xin
//                double nx
//                float nfft
//                float Fs
//                creal32_T Xx_data[]
//                float f_data[]
//                int &f_size
// Return Type  : int
//
int computeDFTviaFFT(const array<float, 1U> &xin, double nx, float nfft,
                     float Fs, creal32_T Xx_data[], float f_data[], int &f_size)
{
  array<float, 2U> wrappedData;
  array<float, 1U> xw;
  int Xx_size;
  if (nx > nfft) {
    int b_remainder;
    int i;
    int loop_ub;
    int remainder_tmp;
    loop_ub = static_cast<int>(nfft);
    xw.set_size(static_cast<int>(nfft));
    for (i = 0; i < loop_ub; i++) {
      xw[i] = 0.0F;
    }
    if (xin.size(0) == 1) {
      wrappedData.set_size(1, static_cast<int>(nfft));
      for (i = 0; i < loop_ub; i++) {
        wrappedData[i] = 0.0F;
      }
    } else {
      wrappedData.set_size(static_cast<int>(nfft), 1);
      for (i = 0; i < loop_ub; i++) {
        wrappedData[i] = 0.0F;
      }
    }
    if (static_cast<unsigned short>(static_cast<int>(nfft)) == 0U) {
      i = MAX_int32_T;
    } else {
      i = static_cast<int>(static_cast<unsigned int>(xin.size(0)) /
                           static_cast<unsigned short>(static_cast<int>(nfft)));
    }
    remainder_tmp = i * static_cast<int>(nfft);
    b_remainder = (xin.size(0) - remainder_tmp) - 1;
    for (int k{0}; k <= b_remainder; k++) {
      wrappedData[k] = xin[remainder_tmp + k];
    }
    remainder_tmp = b_remainder + 2;
    for (int k{remainder_tmp}; k <= loop_ub; k++) {
      wrappedData[k - 1] = 0.0F;
    }
    i = static_cast<unsigned short>(i);
    for (int j{0}; j < i; j++) {
      b_remainder = j * static_cast<int>(nfft);
      remainder_tmp = static_cast<unsigned short>(static_cast<int>(nfft));
      for (int k{0}; k < remainder_tmp; k++) {
        wrappedData[k] = wrappedData[k] + xin[b_remainder + k];
      }
    }
    for (i = 0; i < loop_ub; i++) {
      xw[i] = wrappedData[i];
    }
  } else {
    int loop_ub;
    xw.set_size(xin.size(0));
    loop_ub = xin.size(0);
    for (int i{0}; i < loop_ub; i++) {
      xw[i] = xin[i];
    }
  }
  Xx_size = fft(xw, nfft, Xx_data);
  f_size = psdfreqvec(nfft, Fs, f_data);
  return Xx_size;
}

} // namespace coder

//
// File trailer for computeDFT.cpp
//
// [EOF]
//
