//
// File: FFTImplementationCallback.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Aug-2024 01:31:17
//

// Include Files
#include "FFTImplementationCallback.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const array<float, 1U> &x
//                creal32_T y_data[]
//                int nrowsx
//                int nRows
//                int nfft
//                const creal32_T wwc_data[]
//                int wwc_size
//                const float costab_data[]
//                const int costab_size[2]
//                const float sintab_data[]
//                const float costabinv_data[]
//                const float sintabinv_data[]
// Return Type  : void
//
namespace coder {
namespace internal {
namespace fft {
void FFTImplementationCallback::doHalfLengthBluestein(
    const array<float, 1U> &x, creal32_T y_data[], int nrowsx, int nRows,
    int nfft, const creal32_T wwc_data[], int wwc_size,
    const float costab_data[], const int costab_size[2],
    const float sintab_data[], const float costabinv_data[],
    const float sintabinv_data[])
{
  array<creal32_T, 1U> b_fy_data;
  array<creal32_T, 1U> b_wwc_data;
  array<creal32_T, 1U> r;
  array<creal32_T, 1U> y;
  array<float, 2U> b_hcostab_data;
  array<float, 2U> b_hcostabinv_data;
  array<float, 2U> b_hsintab_data;
  array<float, 2U> b_hsintabinv_data;
  array<float, 2U> costab;
  array<float, 2U> costab1q;
  array<float, 2U> sintab;
  creal32_T fy_data[2000];
  creal32_T reconVar1_data[500];
  creal32_T reconVar2_data[500];
  creal32_T ytmp_data[500];
  cuint8_T b_y_data[1000];
  double z_tmp;
  float hcostab_data[1000];
  float hcostabinv_data[1000];
  float hsintab_data[1000];
  float hsintabinv_data[1000];
  float temp_im;
  float temp_re;
  float temp_re_tmp;
  float twid_im;
  float twid_re;
  int wrapIndex_data[500];
  int b_i;
  int hnRows;
  int hszCostab;
  int i;
  int iDelta;
  int iDelta2;
  int iheight;
  int j;
  int ju;
  int k;
  int k1;
  int nRowsD2;
  int nd2;
  bool tst;
  hnRows = static_cast<int>(static_cast<unsigned int>(nRows) >> 1);
  if (hnRows > nrowsx) {
    if (hnRows - 1 >= 0) {
      std::memset(&b_y_data[0], 0,
                  static_cast<unsigned int>(hnRows) * sizeof(cuint8_T));
    }
  }
  for (i = 0; i < hnRows; i++) {
    ytmp_data[i].re = 0.0F;
    ytmp_data[i].im = b_y_data[i].im;
  }
  if ((x.size(0) & 1) == 0) {
    tst = true;
    ju = x.size(0);
  } else if (x.size(0) >= nRows) {
    tst = true;
    ju = nRows;
  } else {
    tst = false;
    ju = x.size(0) - 1;
  }
  if (ju > nRows) {
    ju = nRows;
  }
  nd2 = nRows << 1;
  temp_im = 6.28318548F / static_cast<float>(nd2);
  iDelta2 = static_cast<int>(static_cast<unsigned int>(nd2) >> 1) >> 1;
  costab1q.set_size(1, iDelta2 + 1);
  costab1q[0] = 1.0F;
  nd2 = iDelta2 / 2 - 1;
  for (k = 0; k <= nd2; k++) {
    costab1q[k + 1] = std::cos(temp_im * static_cast<float>(k + 1));
  }
  i = nd2 + 2;
  j = iDelta2 - 1;
  for (k = i; k <= j; k++) {
    costab1q[k] = std::sin(temp_im * static_cast<float>(iDelta2 - k));
  }
  costab1q[iDelta2] = 0.0F;
  iDelta2 = costab1q.size(1) - 1;
  nd2 = (costab1q.size(1) - 1) << 1;
  costab.set_size(1, nd2 + 1);
  sintab.set_size(1, nd2 + 1);
  costab[0] = 1.0F;
  sintab[0] = 0.0F;
  for (k = 0; k < iDelta2; k++) {
    costab[k + 1] = costab1q[k + 1];
    sintab[k + 1] = -costab1q[(iDelta2 - k) - 1];
  }
  i = costab1q.size(1);
  for (k = i; k <= nd2; k++) {
    costab[k] = -costab1q[nd2 - k];
    sintab[k] = -costab1q[k - iDelta2];
  }
  hszCostab = static_cast<int>(static_cast<unsigned int>(costab_size[1]) >> 1);
  for (b_i = 0; b_i < hszCostab; b_i++) {
    nd2 = ((b_i + 1) << 1) - 2;
    hcostab_data[b_i] = costab_data[nd2];
    hsintab_data[b_i] = sintab_data[nd2];
    hcostabinv_data[b_i] = costabinv_data[nd2];
    hsintabinv_data[b_i] = sintabinv_data[nd2];
  }
  i = static_cast<unsigned short>(hnRows);
  for (b_i = 0; b_i < i; b_i++) {
    j = b_i << 1;
    temp_im = sintab[j];
    temp_re = costab[j];
    reconVar1_data[b_i].re = temp_im + 1.0F;
    reconVar1_data[b_i].im = -temp_re;
    reconVar2_data[b_i].re = 1.0F - temp_im;
    reconVar2_data[b_i].im = temp_re;
  }
  for (b_i = 0; b_i < i; b_i++) {
    if (b_i + 1 != 1) {
      wrapIndex_data[b_i] = (hnRows - b_i) + 1;
    } else {
      wrapIndex_data[0] = 1;
    }
  }
  z_tmp = static_cast<double>(ju) / 2.0;
  j = static_cast<unsigned short>(static_cast<int>(z_tmp));
  for (k1 = 0; k1 < j; k1++) {
    temp_re = wwc_data[(hnRows + k1) - 1].re;
    temp_im = wwc_data[(hnRows + k1) - 1].im;
    nd2 = k1 << 1;
    twid_re = x[nd2];
    twid_im = x[nd2 + 1];
    ytmp_data[k1].re = temp_re * twid_re + temp_im * twid_im;
    ytmp_data[k1].im = temp_re * twid_im - temp_im * twid_re;
  }
  if (!tst) {
    temp_re = wwc_data[(hnRows + static_cast<int>(z_tmp)) - 1].re;
    temp_im = wwc_data[(hnRows + static_cast<int>(z_tmp)) - 1].im;
    if (static_cast<unsigned short>(static_cast<int>(z_tmp)) - 1 < 0) {
      iDelta2 = 0;
    } else {
      iDelta2 = static_cast<unsigned short>(static_cast<int>(z_tmp)) << 1;
    }
    twid_re = x[iDelta2];
    ytmp_data[static_cast<int>(static_cast<double>(ju) / 2.0)].re =
        temp_re * twid_re + temp_im * 0.0F;
    ytmp_data[static_cast<int>(static_cast<double>(ju) / 2.0)].im =
        temp_re * 0.0F - temp_im * twid_re;
    if (static_cast<int>(z_tmp) + 2 <= hnRows) {
      j = static_cast<int>(z_tmp) + 2;
      if (j <= hnRows) {
        std::memset(&ytmp_data[j + -1], 0,
                    static_cast<unsigned int>((hnRows - j) + 1) *
                        sizeof(creal32_T));
      }
    }
  } else if (static_cast<int>(z_tmp) + 1 <= hnRows) {
    j = static_cast<int>(z_tmp) + 1;
    if (j <= hnRows) {
      std::memset(&ytmp_data[j + -1], 0,
                  static_cast<unsigned int>((hnRows - j) + 1) *
                      sizeof(creal32_T));
    }
  }
  z_tmp = static_cast<double>(nfft) / 2.0;
  nd2 = static_cast<int>(z_tmp);
  y.set_size(nd2);
  if (static_cast<int>(z_tmp) > hnRows) {
    y.set_size(nd2);
    for (j = 0; j < nd2; j++) {
      y[j].re = 0.0F;
      y[j].im = 0.0F;
    }
  }
  iDelta = y.size(0);
  nd2 = y.size(0);
  for (j = 0; j < nd2; j++) {
    fy_data[j] = y[j];
  }
  j = static_cast<int>(z_tmp);
  if (hnRows <= j) {
    j = hnRows;
  }
  k1 = static_cast<int>(z_tmp) - 2;
  nRowsD2 =
      static_cast<int>(static_cast<unsigned int>(static_cast<int>(z_tmp)) >> 1);
  k = nRowsD2 / 2;
  nd2 = 0;
  ju = 0;
  for (b_i = 0; b_i <= j - 2; b_i++) {
    fy_data[nd2] = ytmp_data[b_i];
    iDelta2 = static_cast<int>(z_tmp);
    tst = true;
    while (tst) {
      iDelta2 >>= 1;
      ju ^= iDelta2;
      tst = ((ju & iDelta2) == 0);
    }
    nd2 = ju;
  }
  if (j - 2 < 0) {
    iDelta2 = 0;
  } else {
    iDelta2 = j - 1;
  }
  fy_data[nd2] = ytmp_data[iDelta2];
  y.set_size(iDelta);
  for (j = 0; j < iDelta; j++) {
    y[j] = fy_data[j];
  }
  if (static_cast<int>(z_tmp) > 1) {
    for (b_i = 0; b_i <= k1; b_i += 2) {
      temp_re_tmp = y[b_i + 1].re;
      temp_re = y[b_i + 1].im;
      temp_im = y[b_i].re;
      twid_re = y[b_i].im;
      y[b_i + 1].re = temp_im - temp_re_tmp;
      y[b_i + 1].im = twid_re - temp_re;
      y[b_i].re = temp_im + temp_re_tmp;
      y[b_i].im = twid_re + temp_re;
    }
  }
  iDelta = 2;
  iDelta2 = 4;
  iheight = ((k - 1) << 2) + 1;
  while (k > 0) {
    for (b_i = 0; b_i < iheight; b_i += iDelta2) {
      nd2 = b_i + iDelta;
      temp_re = y[nd2].re;
      temp_im = y[nd2].im;
      y[nd2].re = y[b_i].re - temp_re;
      y[nd2].im = y[b_i].im - temp_im;
      y[b_i].re = y[b_i].re + temp_re;
      y[b_i].im = y[b_i].im + temp_im;
    }
    nd2 = 1;
    for (j = k; j < nRowsD2; j += k) {
      twid_re = hcostab_data[j];
      twid_im = hsintab_data[j];
      b_i = nd2;
      ju = nd2 + iheight;
      while (b_i < ju) {
        k1 = b_i + iDelta;
        temp_re_tmp = y[k1].im;
        temp_im = y[k1].re;
        temp_re = twid_re * temp_im - twid_im * temp_re_tmp;
        temp_im = twid_re * temp_re_tmp + twid_im * temp_im;
        y[k1].re = y[b_i].re - temp_re;
        y[k1].im = y[b_i].im - temp_im;
        y[b_i].re = y[b_i].re + temp_re;
        y[b_i].im = y[b_i].im + temp_im;
        b_i += iDelta2;
      }
      nd2++;
    }
    k /= 2;
    iDelta = iDelta2;
    iDelta2 += iDelta2;
    iheight -= iDelta;
  }
  b_wwc_data.set((creal32_T *)&wwc_data[0], wwc_size);
  b_hcostab_data.set(&hcostab_data[0], 1, hszCostab);
  b_hsintab_data.set(&hsintab_data[0], 1, hszCostab);
  FFTImplementationCallback::r2br_r2dit_trig_impl(
      b_wwc_data, static_cast<int>(z_tmp), b_hcostab_data, b_hsintab_data, r);
  iDelta = y.size(0);
  nd2 = y.size(0);
  for (j = 0; j < nd2; j++) {
    temp_im = y[j].re;
    temp_re = r[j].im;
    twid_re = y[j].im;
    twid_im = r[j].re;
    fy_data[j].re = temp_im * twid_im - twid_re * temp_re;
    fy_data[j].im = temp_im * temp_re + twid_re * twid_im;
  }
  b_fy_data.set(&fy_data[0], iDelta);
  b_hcostabinv_data.set(&hcostabinv_data[0], 1, hszCostab);
  b_hsintabinv_data.set(&hsintabinv_data[0], 1, hszCostab);
  FFTImplementationCallback::r2br_r2dit_trig_impl(
      b_fy_data, static_cast<int>(z_tmp), b_hcostabinv_data, b_hsintabinv_data,
      y);
  if (y.size(0) > 1) {
    temp_im = 1.0F / static_cast<float>(y.size(0));
    nd2 = y.size(0);
    for (j = 0; j < nd2; j++) {
      y[j].re = temp_im * y[j].re;
      y[j].im = temp_im * y[j].im;
    }
  }
  j = static_cast<int>(static_cast<float>(hnRows));
  for (k = j; k <= wwc_size; k++) {
    temp_im = wwc_data[k - 1].re;
    temp_re = y[k - 1].im;
    twid_re = wwc_data[k - 1].im;
    twid_im = y[k - 1].re;
    ytmp_data[k - static_cast<int>(static_cast<float>(hnRows))].re =
        temp_im * twid_im + twid_re * temp_re;
    ytmp_data[k - static_cast<int>(static_cast<float>(hnRows))].im =
        temp_im * temp_re - twid_re * twid_im;
  }
  for (b_i = 0; b_i < i; b_i++) {
    float b_ytmp_re_tmp;
    float ytmp_im_tmp;
    float ytmp_re_tmp;
    j = wrapIndex_data[b_i];
    temp_im = ytmp_data[b_i].re;
    temp_re = reconVar1_data[b_i].im;
    twid_re = ytmp_data[b_i].im;
    twid_im = reconVar1_data[b_i].re;
    temp_re_tmp = ytmp_data[j - 1].re;
    ytmp_im_tmp = -ytmp_data[j - 1].im;
    ytmp_re_tmp = reconVar2_data[b_i].im;
    b_ytmp_re_tmp = reconVar2_data[b_i].re;
    y_data[b_i].re =
        0.5F * ((temp_im * twid_im - twid_re * temp_re) +
                (temp_re_tmp * b_ytmp_re_tmp - ytmp_im_tmp * ytmp_re_tmp));
    y_data[b_i].im =
        0.5F * ((temp_im * temp_re + twid_re * twid_im) +
                (temp_re_tmp * ytmp_re_tmp + ytmp_im_tmp * b_ytmp_re_tmp));
    y_data[hnRows + b_i].re =
        0.5F * ((temp_im * b_ytmp_re_tmp - twid_re * ytmp_re_tmp) +
                (temp_re_tmp * twid_im - ytmp_im_tmp * temp_re));
    y_data[hnRows + b_i].im =
        0.5F * ((temp_im * ytmp_re_tmp + twid_re * b_ytmp_re_tmp) +
                (temp_re_tmp * temp_re + ytmp_im_tmp * twid_im));
  }
}

//
// Arguments    : const array<float, 1U> &x
//                creal32_T y_data[]
//                int &y_size
//                int unsigned_nRows
//                const float costab_data[]
//                const int costab_size[2]
//                const float sintab_data[]
// Return Type  : void
//
void FFTImplementationCallback::doHalfLengthRadix2(
    const array<float, 1U> &x, creal32_T y_data[], int &y_size,
    int unsigned_nRows, const float costab_data[], const int costab_size[2],
    const float sintab_data[])
{
  array<creal32_T, 1U> y;
  creal32_T reconVar1_data[500];
  creal32_T reconVar2_data[500];
  double d;
  double z;
  float hcostab_data[1000];
  float hsintab_data[1000];
  float b_y_re_tmp;
  float c_y_re_tmp;
  float d_y_re_tmp;
  float temp2_im;
  float temp2_re;
  float temp_im;
  float temp_im_tmp;
  float temp_re;
  float temp_re_tmp;
  float y_re_tmp;
  int bitrevIndex_data[500];
  int wrapIndex_data[500];
  int b_i;
  int hszCostab;
  int i;
  int iDelta;
  int iheight;
  int iy;
  int ju;
  int k;
  int nRows;
  int nRowsD2;
  int u0;
  bool tst;
  nRows = static_cast<int>(static_cast<unsigned int>(unsigned_nRows) >> 1);
  u0 = y_size;
  if (u0 > nRows) {
    u0 = nRows;
  }
  iheight = nRows - 2;
  nRowsD2 = nRows / 2;
  k = nRowsD2 / 2;
  hszCostab = static_cast<int>(static_cast<unsigned int>(costab_size[1]) >> 1);
  for (i = 0; i < hszCostab; i++) {
    iy = ((i + 1) << 1) - 2;
    hcostab_data[i] = costab_data[iy];
    hsintab_data[i] = sintab_data[iy];
  }
  b_i = static_cast<unsigned short>(nRows);
  for (i = 0; i < b_i; i++) {
    temp_im = sintab_data[i];
    temp_re = costab_data[i];
    reconVar1_data[i].re = temp_im + 1.0F;
    reconVar1_data[i].im = -temp_re;
    reconVar2_data[i].re = 1.0F - temp_im;
    reconVar2_data[i].im = temp_re;
    if (i + 1 != 1) {
      wrapIndex_data[i] = (nRows - i) + 1;
    } else {
      wrapIndex_data[0] = 1;
    }
  }
  z = static_cast<double>(unsigned_nRows) / 2.0;
  ju = 0;
  iy = 1;
  hszCostab = static_cast<int>(z);
  if (hszCostab - 1 >= 0) {
    std::memset(&bitrevIndex_data[0], 0,
                static_cast<unsigned int>(hszCostab) * sizeof(int));
  }
  b_i = static_cast<unsigned short>(u0 - 1);
  for (iDelta = 0; iDelta < b_i; iDelta++) {
    bitrevIndex_data[iDelta] = iy;
    hszCostab = static_cast<int>(z);
    tst = true;
    while (tst) {
      hszCostab >>= 1;
      ju ^= hszCostab;
      tst = ((ju & hszCostab) == 0);
    }
    iy = ju + 1;
  }
  bitrevIndex_data[u0 - 1] = iy;
  if ((x.size(0) & 1) == 0) {
    tst = true;
    u0 = x.size(0);
  } else if (x.size(0) >= unsigned_nRows) {
    tst = true;
    u0 = unsigned_nRows;
  } else {
    tst = false;
    u0 = x.size(0) - 1;
  }
  if (u0 > unsigned_nRows) {
    u0 = unsigned_nRows;
  }
  d = static_cast<double>(u0) / 2.0;
  b_i = static_cast<unsigned short>(static_cast<int>(d));
  for (i = 0; i < b_i; i++) {
    iy = i << 1;
    hszCostab = bitrevIndex_data[i];
    y_data[hszCostab - 1].re = x[iy];
    y_data[hszCostab - 1].im = x[iy + 1];
  }
  if (!tst) {
    b_i = bitrevIndex_data[static_cast<int>(d)] - 1;
    if (static_cast<unsigned short>(static_cast<int>(d)) - 1 < 0) {
      u0 = 0;
    } else {
      u0 = static_cast<unsigned short>(static_cast<int>(d)) << 1;
    }
    y_data[b_i].re = x[u0];
    y_data[b_i].im = 0.0F;
  }
  y.set_size(y_size);
  for (b_i = 0; b_i < y_size; b_i++) {
    y[b_i] = y_data[b_i];
  }
  if (nRows > 1) {
    for (i = 0; i <= iheight; i += 2) {
      temp_re_tmp = y[i + 1].re;
      temp_im_tmp = y[i + 1].im;
      temp_re = y[i].re;
      temp_im = y[i].im;
      y[i + 1].re = temp_re - temp_re_tmp;
      y[i + 1].im = temp_im - temp_im_tmp;
      y[i].re = temp_re + temp_re_tmp;
      y[i].im = temp_im + temp_im_tmp;
    }
  }
  iDelta = 2;
  nRows = 4;
  iheight = ((k - 1) << 2) + 1;
  while (k > 0) {
    for (i = 0; i < iheight; i += nRows) {
      hszCostab = i + iDelta;
      temp_re = y[hszCostab].re;
      temp_im = y[hszCostab].im;
      y[hszCostab].re = y[i].re - temp_re;
      y[hszCostab].im = y[i].im - temp_im;
      y[i].re = y[i].re + temp_re;
      y[i].im = y[i].im + temp_im;
    }
    hszCostab = 1;
    for (iy = k; iy < nRowsD2; iy += k) {
      temp2_re = hcostab_data[iy];
      temp2_im = hsintab_data[iy];
      i = hszCostab;
      ju = hszCostab + iheight;
      while (i < ju) {
        u0 = i + iDelta;
        temp_re_tmp = y[u0].im;
        y_re_tmp = y[u0].re;
        temp_re = temp2_re * y_re_tmp - temp2_im * temp_re_tmp;
        temp_im = temp2_re * temp_re_tmp + temp2_im * y_re_tmp;
        y[u0].re = y[i].re - temp_re;
        y[u0].im = y[i].im - temp_im;
        y[i].re = y[i].re + temp_re;
        y[i].im = y[i].im + temp_im;
        i += nRows;
      }
      hszCostab++;
    }
    k /= 2;
    iDelta = nRows;
    nRows += nRows;
    iheight -= iDelta;
  }
  y_size = y.size(0);
  hszCostab = y.size(0);
  for (b_i = 0; b_i < hszCostab; b_i++) {
    y_data[b_i] = y[b_i];
  }
  hszCostab =
      static_cast<int>(static_cast<unsigned int>(static_cast<int>(z)) >> 1);
  y_re_tmp = y[0].re * reconVar1_data[0].re;
  temp_re = y[0].re * reconVar1_data[0].im;
  b_y_re_tmp = y[0].re * reconVar2_data[0].re;
  temp_im = y[0].re * reconVar2_data[0].im;
  y_data[0].re = 0.5F * ((y_re_tmp - y[0].im * reconVar1_data[0].im) +
                         (b_y_re_tmp - -y[0].im * reconVar2_data[0].im));
  y_data[0].im = 0.5F * ((temp_re + y[0].im * reconVar1_data[0].re) +
                         (temp_im + -y[0].im * reconVar2_data[0].re));
  y_data[static_cast<int>(z)].re =
      0.5F * ((b_y_re_tmp - y[0].im * reconVar2_data[0].im) +
              (y_re_tmp - -y[0].im * reconVar1_data[0].im));
  y_data[static_cast<int>(z)].im =
      0.5F * ((temp_im + y[0].im * reconVar2_data[0].re) +
              (temp_re + -y[0].im * reconVar1_data[0].re));
  for (i = 2; i <= hszCostab; i++) {
    float temp2_im_tmp;
    temp_re_tmp = y_data[i - 1].re;
    temp_im_tmp = y_data[i - 1].im;
    b_i = wrapIndex_data[i - 1];
    temp2_im = y_data[b_i - 1].re;
    temp2_im_tmp = y_data[b_i - 1].im;
    y_re_tmp = reconVar1_data[i - 1].im;
    b_y_re_tmp = reconVar1_data[i - 1].re;
    c_y_re_tmp = reconVar2_data[i - 1].im;
    d_y_re_tmp = reconVar2_data[i - 1].re;
    y_data[i - 1].re =
        0.5F * ((temp_re_tmp * b_y_re_tmp - temp_im_tmp * y_re_tmp) +
                (temp2_im * d_y_re_tmp - -temp2_im_tmp * c_y_re_tmp));
    y_data[i - 1].im =
        0.5F * ((temp_re_tmp * y_re_tmp + temp_im_tmp * b_y_re_tmp) +
                (temp2_im * c_y_re_tmp + -temp2_im_tmp * d_y_re_tmp));
    iy = (static_cast<int>(z) + i) - 1;
    y_data[iy].re =
        0.5F * ((temp_re_tmp * d_y_re_tmp - temp_im_tmp * c_y_re_tmp) +
                (temp2_im * b_y_re_tmp - -temp2_im_tmp * y_re_tmp));
    y_data[iy].im =
        0.5F * ((temp_re_tmp * c_y_re_tmp + temp_im_tmp * d_y_re_tmp) +
                (temp2_im * y_re_tmp + -temp2_im_tmp * b_y_re_tmp));
    temp_im = reconVar1_data[b_i - 1].im;
    temp_re = reconVar1_data[b_i - 1].re;
    y_re_tmp = reconVar2_data[b_i - 1].im;
    temp2_re = reconVar2_data[b_i - 1].re;
    y_data[b_i - 1].re =
        0.5F * ((temp2_im * temp_re - temp2_im_tmp * temp_im) +
                (temp_re_tmp * temp2_re - -temp_im_tmp * y_re_tmp));
    y_data[b_i - 1].im =
        0.5F * ((temp2_im * temp_im + temp2_im_tmp * temp_re) +
                (temp_re_tmp * y_re_tmp + -temp_im_tmp * temp2_re));
    b_i = (b_i + static_cast<int>(z)) - 1;
    y_data[b_i].re = 0.5F * ((temp2_im * temp2_re - temp2_im_tmp * y_re_tmp) +
                             (temp_re_tmp * temp_re - -temp_im_tmp * temp_im));
    y_data[b_i].im = 0.5F * ((temp2_im * y_re_tmp + temp2_im_tmp * temp2_re) +
                             (temp_re_tmp * temp_im + -temp_im_tmp * temp_re));
  }
  temp_re_tmp = y_data[hszCostab].re;
  temp_im_tmp = y_data[hszCostab].im;
  y_re_tmp = reconVar1_data[hszCostab].im;
  b_y_re_tmp = reconVar1_data[hszCostab].re;
  c_y_re_tmp = temp_re_tmp * b_y_re_tmp;
  temp_re = temp_re_tmp * y_re_tmp;
  d_y_re_tmp = reconVar2_data[hszCostab].im;
  temp2_re = reconVar2_data[hszCostab].re;
  temp2_im = temp_re_tmp * temp2_re;
  temp_im = temp_re_tmp * d_y_re_tmp;
  y_data[hszCostab].re = 0.5F * ((c_y_re_tmp - temp_im_tmp * y_re_tmp) +
                                 (temp2_im - -temp_im_tmp * d_y_re_tmp));
  y_data[hszCostab].im = 0.5F * ((temp_re + temp_im_tmp * b_y_re_tmp) +
                                 (temp_im + -temp_im_tmp * temp2_re));
  b_i = static_cast<int>(z) + hszCostab;
  y_data[b_i].re = 0.5F * ((temp2_im - temp_im_tmp * d_y_re_tmp) +
                           (c_y_re_tmp - -temp_im_tmp * y_re_tmp));
  y_data[b_i].im = 0.5F * ((temp_im + temp_im_tmp * temp2_re) +
                           (temp_re + -temp_im_tmp * b_y_re_tmp));
}

//
// Arguments    : int nfft
//                bool useRadix2
//                int &nRows
// Return Type  : int
//
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
