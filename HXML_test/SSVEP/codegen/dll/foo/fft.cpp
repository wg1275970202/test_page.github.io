//
// File: fft.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Aug-2024 01:31:17
//

// Include Files
#include "fft.h"
#include "FFTImplementationCallback.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const array<creal32_T, 1U> &x
//                float varargin_1
//                array<creal32_T, 1U> &y
// Return Type  : void
//
namespace coder {
void fft(const array<creal32_T, 1U> &x, float varargin_1,
         array<creal32_T, 1U> &y)
{
  array<creal32_T, 1U> b_fv;
  array<creal32_T, 1U> fv;
  array<creal32_T, 1U> wwc;
  array<float, 2U> costab;
  array<float, 2U> costab1q;
  array<float, 2U> sintab;
  array<float, 2U> sintabinv;
  int nd2;
  int nfft_tmp_tmp_tmp;
  nfft_tmp_tmp_tmp = static_cast<int>(varargin_1);
  if ((x.size(0) == 0) || (static_cast<int>(varargin_1) == 0)) {
    y.set_size(nfft_tmp_tmp_tmp);
    for (int i{0}; i < nfft_tmp_tmp_tmp; i++) {
      y[i].re = 0.0F;
      y[i].im = 0.0F;
    }
  } else {
    float nt_re;
    int N2blue;
    int i;
    int nInt2m1;
    int rt;
    bool useRadix2;
    useRadix2 = ((static_cast<int>(varargin_1) > 0) &&
                 ((static_cast<int>(varargin_1) &
                   (static_cast<int>(varargin_1) - 1)) == 0));
    N2blue = internal::fft::FFTImplementationCallback::get_algo_sizes(
        static_cast<int>(varargin_1), useRadix2, nd2);
    nt_re = 6.28318548F / static_cast<float>(nd2);
    rt = static_cast<int>(static_cast<unsigned int>(nd2) >> 1) >> 1;
    costab1q.set_size(1, rt + 1);
    costab1q[0] = 1.0F;
    nd2 = rt / 2 - 1;
    for (int k{0}; k <= nd2; k++) {
      costab1q[k + 1] = std::cos(nt_re * static_cast<float>(k + 1));
    }
    i = nd2 + 2;
    nInt2m1 = rt - 1;
    for (int k{i}; k <= nInt2m1; k++) {
      costab1q[k] = std::sin(nt_re * static_cast<float>(rt - k));
    }
    costab1q[rt] = 0.0F;
    if (!useRadix2) {
      rt = costab1q.size(1) - 1;
      nd2 = (costab1q.size(1) - 1) << 1;
      costab.set_size(1, nd2 + 1);
      sintab.set_size(1, nd2 + 1);
      costab[0] = 1.0F;
      sintab[0] = 0.0F;
      sintabinv.set_size(1, nd2 + 1);
      for (int k{0}; k < rt; k++) {
        sintabinv[k + 1] = costab1q[(rt - k) - 1];
      }
      i = costab1q.size(1);
      for (int k{i}; k <= nd2; k++) {
        sintabinv[k] = costab1q[k - rt];
      }
      for (int k{0}; k < rt; k++) {
        costab[k + 1] = costab1q[k + 1];
        sintab[k + 1] = -costab1q[(rt - k) - 1];
      }
      i = costab1q.size(1);
      for (int k{i}; k <= nd2; k++) {
        costab[k] = -costab1q[nd2 - k];
        sintab[k] = -costab1q[k - rt];
      }
    } else {
      rt = costab1q.size(1) - 1;
      nd2 = (costab1q.size(1) - 1) << 1;
      costab.set_size(1, nd2 + 1);
      sintab.set_size(1, nd2 + 1);
      costab[0] = 1.0F;
      sintab[0] = 0.0F;
      for (int k{0}; k < rt; k++) {
        costab[k + 1] = costab1q[k + 1];
        sintab[k + 1] = -costab1q[(rt - k) - 1];
      }
      i = costab1q.size(1);
      for (int k{i}; k <= nd2; k++) {
        costab[k] = -costab1q[nd2 - k];
        sintab[k] = -costab1q[k - rt];
      }
      sintabinv.set_size(1, 0);
    }
    if (useRadix2) {
      internal::fft::FFTImplementationCallback::r2br_r2dit_trig_impl(
          x, static_cast<int>(varargin_1), costab, sintab, y);
    } else {
      float b_re_tmp;
      float nt_im;
      float re_tmp;
      int nInt2;
      nInt2m1 =
          (static_cast<int>(varargin_1) + static_cast<int>(varargin_1)) - 1;
      wwc.set_size(nInt2m1);
      rt = 0;
      wwc[static_cast<int>(varargin_1) - 1].re = 1.0F;
      wwc[static_cast<int>(varargin_1) - 1].im = 0.0F;
      nInt2 = static_cast<int>(varargin_1) << 1;
      for (int k{0}; k <= nfft_tmp_tmp_tmp - 2; k++) {
        nd2 = ((k + 1) << 1) - 1;
        if (nInt2 - rt <= nd2) {
          rt += nd2 - nInt2;
        } else {
          rt += nd2;
        }
        nt_im = -3.14159274F * static_cast<float>(rt) /
                static_cast<float>(static_cast<int>(varargin_1));
        i = (static_cast<int>(varargin_1) - k) - 2;
        wwc[i].re = std::cos(nt_im);
        wwc[i].im = -std::sin(nt_im);
      }
      i = nInt2m1 - 1;
      for (int k{i}; k >= nfft_tmp_tmp_tmp; k--) {
        wwc[k] = wwc[(nInt2m1 - k) - 1];
      }
      y.set_size(nfft_tmp_tmp_tmp);
      if (static_cast<int>(varargin_1) > x.size(0)) {
        y.set_size(nfft_tmp_tmp_tmp);
        for (i = 0; i < nfft_tmp_tmp_tmp; i++) {
          y[i].re = 0.0F;
          y[i].im = 0.0F;
        }
      }
      nd2 = static_cast<int>(varargin_1);
      nInt2m1 = x.size(0);
      if (nd2 <= nInt2m1) {
        nInt2m1 = nd2;
      }
      i = static_cast<unsigned short>(nInt2m1);
      for (int k{0}; k < i; k++) {
        nd2 = (static_cast<int>(varargin_1) + k) - 1;
        nt_re = wwc[nd2].re;
        nt_im = wwc[nd2].im;
        re_tmp = x[k].im;
        b_re_tmp = x[k].re;
        y[k].re = nt_re * b_re_tmp + nt_im * re_tmp;
        y[k].im = nt_re * re_tmp - nt_im * b_re_tmp;
      }
      i = nInt2m1 + 1;
      for (int k{i}; k <= nfft_tmp_tmp_tmp; k++) {
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
        nt_re = fv[i].re;
        nt_im = b_fv[i].im;
        re_tmp = fv[i].im;
        b_re_tmp = b_fv[i].re;
        b_fv[i].re = nt_re * b_re_tmp - re_tmp * nt_im;
        b_fv[i].im = nt_re * nt_im + re_tmp * b_re_tmp;
      }
      internal::fft::FFTImplementationCallback::r2br_r2dit_trig_impl(
          b_fv, N2blue, costab, sintabinv, fv);
      if (fv.size(0) > 1) {
        nt_re = 1.0F / static_cast<float>(fv.size(0));
        nd2 = fv.size(0);
        for (i = 0; i < nd2; i++) {
          fv[i].re = nt_re * fv[i].re;
          fv[i].im = nt_re * fv[i].im;
        }
      }
      i = static_cast<int>(static_cast<float>(static_cast<int>(varargin_1)));
      nInt2m1 = wwc.size(0);
      for (int k{i}; k <= nInt2m1; k++) {
        re_tmp = wwc[k - 1].re;
        b_re_tmp = fv[k - 1].im;
        nt_re = wwc[k - 1].im;
        nt_im = fv[k - 1].re;
        nd2 = k - static_cast<int>(
                      static_cast<float>(static_cast<int>(varargin_1)));
        y[nd2].re = re_tmp * nt_im + nt_re * b_re_tmp;
        y[nd2].im = re_tmp * b_re_tmp - nt_re * nt_im;
      }
    }
  }
}

//
// Arguments    : const array<float, 1U> &x
//                float varargin_1
//                creal32_T y_data[]
// Return Type  : int
//
int fft(const array<float, 1U> &x, float varargin_1, creal32_T y_data[])
{
  array<creal32_T, 1U> b_wwc_data;
  array<creal32_T, 1U> b_y_data;
  array<creal32_T, 1U> d_y_data;
  array<creal32_T, 1U> r;
  array<creal32_T, 1U> y;
  array<float, 2U> costab;
  array<float, 2U> costab1q;
  array<float, 2U> sintab;
  array<float, 2U> sintabinv;
  creal32_T c_y_data[4000];
  creal32_T wwc_data[1999];
  int minNrowsNx;
  int nfft_tmp_tmp_tmp;
  int y_size;
  nfft_tmp_tmp_tmp = static_cast<int>(varargin_1);
  if ((x.size(0) == 0) || (static_cast<int>(varargin_1) == 0)) {
    y_size = static_cast<int>(varargin_1);
    if (nfft_tmp_tmp_tmp - 1 >= 0) {
      std::memset(&y_data[0], 0,
                  static_cast<unsigned int>(nfft_tmp_tmp_tmp) *
                      sizeof(creal32_T));
    }
  } else {
    float nt_im;
    int N2blue;
    int i;
    int i1;
    int nd2;
    bool useRadix2;
    useRadix2 = ((static_cast<int>(varargin_1) > 0) &&
                 ((static_cast<int>(varargin_1) &
                   (static_cast<int>(varargin_1) - 1)) == 0));
    N2blue = internal::fft::FFTImplementationCallback::get_algo_sizes(
        static_cast<int>(varargin_1), useRadix2, minNrowsNx);
    nt_im = 6.28318548F / static_cast<float>(minNrowsNx);
    minNrowsNx =
        static_cast<int>(static_cast<unsigned int>(minNrowsNx) >> 1) >> 1;
    costab1q.set_size(1, minNrowsNx + 1);
    costab1q[0] = 1.0F;
    nd2 = minNrowsNx / 2 - 1;
    for (int k{0}; k <= nd2; k++) {
      costab1q[k + 1] = std::cos(nt_im * static_cast<float>(k + 1));
    }
    i = nd2 + 2;
    i1 = minNrowsNx - 1;
    for (int k{i}; k <= i1; k++) {
      costab1q[k] = std::sin(nt_im * static_cast<float>(minNrowsNx - k));
    }
    costab1q[minNrowsNx] = 0.0F;
    if (!useRadix2) {
      minNrowsNx = costab1q.size(1) - 1;
      nd2 = (costab1q.size(1) - 1) << 1;
      costab.set_size(1, nd2 + 1);
      sintab.set_size(1, nd2 + 1);
      costab[0] = 1.0F;
      sintab[0] = 0.0F;
      sintabinv.set_size(1, nd2 + 1);
      for (int k{0}; k < minNrowsNx; k++) {
        sintabinv[k + 1] = costab1q[(minNrowsNx - k) - 1];
      }
      i = costab1q.size(1);
      for (int k{i}; k <= nd2; k++) {
        sintabinv[k] = costab1q[k - minNrowsNx];
      }
      for (int k{0}; k < minNrowsNx; k++) {
        costab[k + 1] = costab1q[k + 1];
        sintab[k + 1] = -costab1q[(minNrowsNx - k) - 1];
      }
      i = costab1q.size(1);
      for (int k{i}; k <= nd2; k++) {
        costab[k] = -costab1q[nd2 - k];
        sintab[k] = -costab1q[k - minNrowsNx];
      }
    } else {
      minNrowsNx = costab1q.size(1) - 1;
      nd2 = (costab1q.size(1) - 1) << 1;
      costab.set_size(1, nd2 + 1);
      sintab.set_size(1, nd2 + 1);
      costab[0] = 1.0F;
      sintab[0] = 0.0F;
      for (int k{0}; k < minNrowsNx; k++) {
        costab[k + 1] = costab1q[k + 1];
        sintab[k + 1] = -costab1q[(minNrowsNx - k) - 1];
      }
      i = costab1q.size(1);
      for (int k{i}; k <= nd2; k++) {
        costab[k] = -costab1q[nd2 - k];
        sintab[k] = -costab1q[k - minNrowsNx];
      }
      sintabinv.set_size(1, 0);
    }
    if (useRadix2) {
      int iv[2];
      y_size = static_cast<int>(varargin_1);
      if (static_cast<int>(varargin_1) > x.size(0)) {
        y_size = static_cast<int>(varargin_1);
        if (nfft_tmp_tmp_tmp - 1 >= 0) {
          std::memset(&y_data[0], 0,
                      static_cast<unsigned int>(nfft_tmp_tmp_tmp) *
                          sizeof(creal32_T));
        }
      }
      iv[0] = (*(int(*)[2])costab.size())[0];
      iv[1] = (*(int(*)[2])costab.size())[1];
      internal::fft::FFTImplementationCallback::doHalfLengthRadix2(
          x, y_data, y_size, static_cast<int>(varargin_1),
          (float *)costab.data(), iv, (float *)sintab.data());
    } else {
      int nInt2m1;
      i = static_cast<int>(varargin_1) & 1;
      if (i == 0) {
        int nInt2;
        int rt;
        minNrowsNx = static_cast<int>(
            static_cast<unsigned int>(static_cast<int>(varargin_1)) >> 1);
        nInt2m1 = (minNrowsNx + minNrowsNx) - 1;
        rt = 0;
        wwc_data[minNrowsNx - 1].re = 1.0F;
        wwc_data[minNrowsNx - 1].im = 0.0F;
        nInt2 = minNrowsNx << 1;
        i1 = static_cast<unsigned short>(minNrowsNx - 1);
        for (int k{0}; k < i1; k++) {
          nd2 = ((k + 1) << 1) - 1;
          if (nInt2 - rt <= nd2) {
            rt += nd2 - nInt2;
          } else {
            rt += nd2;
          }
          nt_im = -3.14159274F * static_cast<float>(rt) /
                  static_cast<float>(minNrowsNx);
          nd2 = (minNrowsNx - k) - 2;
          wwc_data[nd2].re = std::cos(nt_im);
          wwc_data[nd2].im = -std::sin(nt_im);
        }
        i1 = nInt2m1 - 1;
        for (int k{i1}; k >= minNrowsNx; k--) {
          wwc_data[k] = wwc_data[(nInt2m1 - k) - 1];
        }
      } else {
        int nInt2;
        int rt;
        nInt2m1 =
            (static_cast<int>(varargin_1) + static_cast<int>(varargin_1)) - 1;
        rt = 0;
        wwc_data[static_cast<int>(varargin_1) - 1].re = 1.0F;
        wwc_data[static_cast<int>(varargin_1) - 1].im = 0.0F;
        nInt2 = static_cast<int>(varargin_1) << 1;
        i1 = static_cast<unsigned short>(static_cast<int>(varargin_1) - 1);
        for (int k{0}; k < i1; k++) {
          nd2 = ((k + 1) << 1) - 1;
          if (nInt2 - rt <= nd2) {
            rt += nd2 - nInt2;
          } else {
            rt += nd2;
          }
          nt_im = -3.14159274F * static_cast<float>(rt) /
                  static_cast<float>(static_cast<int>(varargin_1));
          nd2 = (static_cast<int>(varargin_1) - k) - 2;
          wwc_data[nd2].re = std::cos(nt_im);
          wwc_data[nd2].im = -std::sin(nt_im);
        }
        i1 = nInt2m1 - 1;
        for (int k{i1}; k >= nfft_tmp_tmp_tmp; k--) {
          wwc_data[k] = wwc_data[(nInt2m1 - k) - 1];
        }
      }
      y_size = static_cast<int>(varargin_1);
      if (static_cast<int>(varargin_1) > x.size(0)) {
        y_size = static_cast<int>(varargin_1);
        if (nfft_tmp_tmp_tmp - 1 >= 0) {
          std::memset(&y_data[0], 0,
                      static_cast<unsigned int>(nfft_tmp_tmp_tmp) *
                          sizeof(creal32_T));
        }
      }
      if ((N2blue != 1) && (i == 0)) {
        int iv[2];
        iv[0] = (*(int(*)[2])costab.size())[0];
        iv[1] = (*(int(*)[2])costab.size())[1];
        internal::fft::FFTImplementationCallback::doHalfLengthBluestein(
            x, y_data, x.size(0), static_cast<int>(varargin_1), N2blue,
            wwc_data, nInt2m1, (float *)costab.data(), iv,
            (float *)sintab.data(), (float *)costab.data(),
            (float *)sintabinv.data());
      } else {
        float f;
        float f1;
        float f2;
        nd2 = static_cast<int>(varargin_1);
        minNrowsNx = x.size(0);
        if (nd2 <= minNrowsNx) {
          minNrowsNx = nd2;
        }
        i = static_cast<unsigned short>(minNrowsNx);
        for (int k{0}; k < i; k++) {
          nd2 = (static_cast<int>(varargin_1) + k) - 1;
          y_data[k].re = wwc_data[nd2].re * x[k];
          y_data[k].im = wwc_data[nd2].im * -x[k];
        }
        i = minNrowsNx + 1;
        if (i <= nfft_tmp_tmp_tmp) {
          std::memset(&y_data[i + -1], 0,
                      static_cast<unsigned int>((nfft_tmp_tmp_tmp - i) + 1) *
                          sizeof(creal32_T));
        }
        b_y_data.set(&y_data[0], y_size);
        internal::fft::FFTImplementationCallback::r2br_r2dit_trig_impl(
            b_y_data, N2blue, costab, sintab, y);
        b_wwc_data.set(&wwc_data[0], nInt2m1);
        internal::fft::FFTImplementationCallback::r2br_r2dit_trig_impl(
            b_wwc_data, N2blue, costab, sintab, r);
        nd2 = y.size(0);
        minNrowsNx = y.size(0);
        for (i = 0; i < minNrowsNx; i++) {
          nt_im = y[i].re;
          f = r[i].im;
          f1 = y[i].im;
          f2 = r[i].re;
          c_y_data[i].re = nt_im * f2 - f1 * f;
          c_y_data[i].im = nt_im * f + f1 * f2;
        }
        d_y_data.set(&c_y_data[0], nd2);
        internal::fft::FFTImplementationCallback::r2br_r2dit_trig_impl(
            d_y_data, N2blue, costab, sintabinv, y);
        if (y.size(0) > 1) {
          nt_im = 1.0F / static_cast<float>(y.size(0));
          minNrowsNx = y.size(0);
          for (i = 0; i < minNrowsNx; i++) {
            y[i].re = nt_im * y[i].re;
            y[i].im = nt_im * y[i].im;
          }
        }
        i = static_cast<int>(static_cast<float>(static_cast<int>(varargin_1)));
        for (int k{i}; k <= nInt2m1; k++) {
          nt_im = wwc_data[k - 1].re;
          f = y[k - 1].im;
          f1 = wwc_data[k - 1].im;
          f2 = y[k - 1].re;
          i1 = k - static_cast<int>(
                       static_cast<float>(static_cast<int>(varargin_1)));
          y_data[i1].re = nt_im * f2 + f1 * f;
          y_data[i1].im = nt_im * f - f1 * f2;
        }
      }
    }
  }
  return y_size;
}

} // namespace coder

//
// File trailer for fft.cpp
//
// [EOF]
//
