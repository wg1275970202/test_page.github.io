//
// File: ifft.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 05-Aug-2024 10:41:23
//

// Include Files
#include "ifft.h"
#include "FFTImplementationCallback.h"
#include "foo_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
//
// Arguments    : const array<creal32_T, 1U> &x
//                array<creal32_T, 1U> &y
// Return Type  : void
//
namespace coder {
void ifft(const array<creal32_T, 1U> &x, array<creal32_T, 1U> &y)
{
  array<creal32_T, 1U> b_fv;
  array<creal32_T, 1U> fv;
  array<creal32_T, 1U> wwc;
  array<float, 2U> costab;
  array<float, 2U> costab1q;
  array<float, 2U> sintab;
  array<float, 2U> sintabinv;
  int nd2;
  int nfft;
  nfft = x.size(0);
  if (x.size(0) == 0) {
    y.set_size(0);
  } else {
    float nt_im;
    int N2blue;
    int i;
    int nInt2;
    int rt;
    bool useRadix2;
    useRadix2 = ((x.size(0) & (x.size(0) - 1)) == 0);
    N2blue = internal::fft::FFTImplementationCallback::get_algo_sizes(
        x.size(0), useRadix2, nd2);
    nt_im = 6.28318548F / static_cast<float>(nd2);
    nInt2 = static_cast<int>(static_cast<unsigned int>(nd2) >> 1) >> 1;
    costab1q.set_size(1, nInt2 + 1);
    costab1q[0] = 1.0F;
    nd2 = nInt2 / 2 - 1;
    for (int k{0}; k <= nd2; k++) {
      costab1q[k + 1] = std::cos(nt_im * static_cast<float>(k + 1));
    }
    i = nd2 + 2;
    rt = nInt2 - 1;
    for (int k{i}; k <= rt; k++) {
      costab1q[k] = std::sin(nt_im * static_cast<float>(nInt2 - k));
    }
    costab1q[nInt2] = 0.0F;
    if (!useRadix2) {
      nInt2 = costab1q.size(1) - 1;
      nd2 = (costab1q.size(1) - 1) << 1;
      costab.set_size(1, nd2 + 1);
      sintab.set_size(1, nd2 + 1);
      costab[0] = 1.0F;
      sintab[0] = 0.0F;
      sintabinv.set_size(1, nd2 + 1);
      for (int k{0}; k < nInt2; k++) {
        sintabinv[k + 1] = costab1q[(nInt2 - k) - 1];
      }
      i = costab1q.size(1);
      for (int k{i}; k <= nd2; k++) {
        sintabinv[k] = costab1q[k - nInt2];
      }
      for (int k{0}; k < nInt2; k++) {
        costab[k + 1] = costab1q[k + 1];
        sintab[k + 1] = -costab1q[(nInt2 - k) - 1];
      }
      i = costab1q.size(1);
      for (int k{i}; k <= nd2; k++) {
        costab[k] = -costab1q[nd2 - k];
        sintab[k] = -costab1q[k - nInt2];
      }
    } else {
      nInt2 = costab1q.size(1) - 1;
      nd2 = (costab1q.size(1) - 1) << 1;
      costab.set_size(1, nd2 + 1);
      sintab.set_size(1, nd2 + 1);
      costab[0] = 1.0F;
      sintab[0] = 0.0F;
      for (int k{0}; k < nInt2; k++) {
        costab[k + 1] = costab1q[k + 1];
        sintab[k + 1] = costab1q[(nInt2 - k) - 1];
      }
      i = costab1q.size(1);
      for (int k{i}; k <= nd2; k++) {
        costab[k] = -costab1q[nd2 - k];
        sintab[k] = costab1q[k - nInt2];
      }
      sintabinv.set_size(1, 0);
    }
    if (useRadix2) {
      internal::fft::FFTImplementationCallback::r2br_r2dit_trig_impl(
          x, x.size(0), costab, sintab, y);
      if (y.size(0) > 1) {
        nt_im = 1.0F / static_cast<float>(y.size(0));
        nd2 = y.size(0);
        for (i = 0; i < nd2; i++) {
          y[i].re = nt_im * y[i].re;
          y[i].im = nt_im * y[i].im;
        }
      }
    } else {
      float b_re_tmp;
      float c_re_tmp;
      float nt_re;
      float re_tmp;
      nd2 = (x.size(0) + x.size(0)) - 1;
      wwc.set_size(nd2);
      rt = 0;
      wwc[x.size(0) - 1].re = 1.0F;
      wwc[x.size(0) - 1].im = 0.0F;
      nInt2 = x.size(0) << 1;
      i = x.size(0);
      for (int k{0}; k <= i - 2; k++) {
        int b_y;
        b_y = ((k + 1) << 1) - 1;
        if (nInt2 - rt <= b_y) {
          rt += b_y - nInt2;
        } else {
          rt += b_y;
        }
        nt_im = 3.14159274F * static_cast<float>(rt) /
                static_cast<float>(x.size(0));
        wwc[(x.size(0) - k) - 2].re = std::cos(nt_im);
        wwc[(x.size(0) - k) - 2].im = -std::sin(nt_im);
      }
      i = nd2 - 1;
      for (int k{i}; k >= nfft; k--) {
        wwc[k] = wwc[(nd2 - k) - 1];
      }
      y.set_size(x.size(0));
      nd2 = x.size(0);
      for (int k{0}; k < nd2; k++) {
        nt_re = wwc[(nfft + k) - 1].re;
        nt_im = wwc[(nfft + k) - 1].im;
        re_tmp = x[k].im;
        b_re_tmp = x[k].re;
        y[k].re = nt_re * b_re_tmp + nt_im * re_tmp;
        y[k].im = nt_re * re_tmp - nt_im * b_re_tmp;
      }
      i = x.size(0) + 1;
      for (int k{i}; k <= nfft; k++) {
        y[k - 1].re = 0.0F;
        y[k - 1].im = 0.0F;
      }
      internal::fft::FFTImplementationCallback::r2br_r2dit_trig_impl(
          y, N2blue, costab, sintab, fv);
      internal::fft::FFTImplementationCallback::r2br_r2dit_trig_impl(
          wwc, N2blue, costab, sintab, b_fv);
      b_fv.set_size(fv.size(0));
      nd2 = fv.size(0);
      for (i = 0; i < nd2; i++) {
        nt_im = fv[i].re;
        re_tmp = b_fv[i].im;
        b_re_tmp = fv[i].im;
        c_re_tmp = b_fv[i].re;
        b_fv[i].re = nt_im * c_re_tmp - b_re_tmp * re_tmp;
        b_fv[i].im = nt_im * re_tmp + b_re_tmp * c_re_tmp;
      }
      internal::fft::FFTImplementationCallback::r2br_r2dit_trig_impl(
          b_fv, N2blue, costab, sintabinv, fv);
      if (fv.size(0) > 1) {
        nt_im = 1.0F / static_cast<float>(fv.size(0));
        nd2 = fv.size(0);
        for (i = 0; i < nd2; i++) {
          fv[i].re = nt_im * fv[i].re;
          fv[i].im = nt_im * fv[i].im;
        }
      }
      nt_re = static_cast<float>(x.size(0));
      i = static_cast<int>(static_cast<float>(x.size(0)));
      rt = wwc.size(0);
      for (int k{i}; k <= rt; k++) {
        float ar;
        nt_im = wwc[k - 1].re;
        re_tmp = fv[k - 1].im;
        b_re_tmp = wwc[k - 1].im;
        c_re_tmp = fv[k - 1].re;
        ar = nt_im * c_re_tmp + b_re_tmp * re_tmp;
        nt_im = nt_im * re_tmp - b_re_tmp * c_re_tmp;
        if (nt_im == 0.0F) {
          nd2 = k - i;
          y[nd2].re = ar / nt_re;
          y[nd2].im = 0.0F;
        } else if (ar == 0.0F) {
          nd2 = k - i;
          y[nd2].re = 0.0F;
          y[nd2].im = nt_im / nt_re;
        } else {
          nd2 = k - i;
          y[nd2].re = ar / nt_re;
          y[nd2].im = nt_im / nt_re;
        }
      }
    }
  }
}

} // namespace coder

//
// File trailer for ifft.cpp
//
// [EOF]
//
