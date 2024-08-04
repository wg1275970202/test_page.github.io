//
// File: FFTImplementationCallback.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 04-Aug-2024 23:30:26
//

// Include Files
#include "FFTImplementationCallback.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : int nfft
//                bool useRadix2
//                int &nRows
// Return Type  : int
//
namespace coder {
namespace internal {
namespace fft {
int FFTImplementationCallback::get_algo_sizes(int nfft, bool useRadix2,
                                              int &nRows)
{
  int n2blue;
  n2blue = 1;
  if (useRadix2) {
    nRows = nfft;
  } else {
    if (nfft > 0) {
      int n;
      int pmax;
      n = (nfft + nfft) - 1;
      pmax = 31;
      if (n <= 1) {
        pmax = 0;
      } else {
        int pmin;
        bool exitg1;
        pmin = 0;
        exitg1 = false;
        while ((!exitg1) && (pmax - pmin > 1)) {
          int k;
          int pow2p;
          k = (pmin + pmax) >> 1;
          pow2p = 1 << k;
          if (pow2p == n) {
            pmax = k;
            exitg1 = true;
          } else if (pow2p > n) {
            pmax = k;
          } else {
            pmin = k;
          }
        }
      }
      n2blue = 1 << pmax;
    }
    nRows = n2blue;
  }
  return n2blue;
}

//
// Arguments    : const array<creal32_T, 1U> &x
//                int unsigned_nRows
//                const array<float, 2U> &costab
//                const array<float, 2U> &sintab
//                array<creal32_T, 1U> &y
// Return Type  : void
//
void FFTImplementationCallback::r2br_r2dit_trig_impl(
    const array<creal32_T, 1U> &x, int unsigned_nRows,
    const array<float, 2U> &costab, const array<float, 2U> &sintab,
    array<creal32_T, 1U> &y)
{
  float temp_im;
  float temp_re;
  float temp_re_tmp;
  float twid_re;
  int i;
  int iDelta;
  int iDelta2;
  int iheight;
  int ihi;
  int iy;
  int j;
  int ju;
  int k;
  int nRowsD2;
  y.set_size(unsigned_nRows);
  if (unsigned_nRows > x.size(0)) {
    y.set_size(unsigned_nRows);
    for (iy = 0; iy < unsigned_nRows; iy++) {
      y[iy].re = 0.0F;
      y[iy].im = 0.0F;
    }
  }
  j = x.size(0);
  if (j > unsigned_nRows) {
    j = unsigned_nRows;
  }
  ihi = unsigned_nRows - 2;
  nRowsD2 = static_cast<int>(static_cast<unsigned int>(unsigned_nRows) >> 1);
  k = nRowsD2 / 2;
  iy = 0;
  ju = 0;
  for (i = 0; i <= j - 2; i++) {
    bool tst;
    y[iy] = x[i];
    iy = unsigned_nRows;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }
    iy = ju;
  }
  if (j - 2 < 0) {
    j = 0;
  } else {
    j--;
  }
  y[iy] = x[j];
  if (unsigned_nRows > 1) {
    for (i = 0; i <= ihi; i += 2) {
      temp_re_tmp = y[i + 1].re;
      temp_im = y[i + 1].im;
      temp_re = y[i].re;
      twid_re = y[i].im;
      y[i + 1].re = temp_re - temp_re_tmp;
      y[i + 1].im = twid_re - temp_im;
      y[i].re = temp_re + temp_re_tmp;
      y[i].im = twid_re + temp_im;
    }
  }
  iDelta = 2;
  iDelta2 = 4;
  iheight = ((k - 1) << 2) + 1;
  while (k > 0) {
    for (i = 0; i < iheight; i += iDelta2) {
      iy = i + iDelta;
      temp_re = y[iy].re;
      temp_im = y[iy].im;
      y[iy].re = y[i].re - temp_re;
      y[iy].im = y[i].im - temp_im;
      y[i].re = y[i].re + temp_re;
      y[i].im = y[i].im + temp_im;
    }
    iy = 1;
    for (j = k; j < nRowsD2; j += k) {
      float twid_im;
      twid_re = costab[j];
      twid_im = sintab[j];
      i = iy;
      ihi = iy + iheight;
      while (i < ihi) {
        ju = i + iDelta;
        temp_re_tmp = y[ju].im;
        temp_im = y[ju].re;
        temp_re = twid_re * temp_im - twid_im * temp_re_tmp;
        temp_im = twid_re * temp_re_tmp + twid_im * temp_im;
        y[ju].re = y[i].re - temp_re;
        y[ju].im = y[i].im - temp_im;
        y[i].re = y[i].re + temp_re;
        y[i].im = y[i].im + temp_im;
        i += iDelta2;
      }
      iy++;
    }
    k /= 2;
    iDelta = iDelta2;
    iDelta2 += iDelta2;
    iheight -= iDelta;
  }
}

} // namespace fft
} // namespace internal
} // namespace coder

//
// File trailer for FFTImplementationCallback.cpp
//
// [EOF]
//
