//
// File: foo.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Aug-2024 01:31:17
//

// Include Files
#include "foo.h"
#include "eml_setop.h"
#include "log2.h"
#include "mrdivide_helper.h"
#include "periodogram.h"
#include "rt_nonfinite.h"
#include "string1.h"
#include "sum.h"
#include "coder_array.h"
#include "coder_bounded_array.h"
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

// Function Definitions
//
// input=[1,rand(1,30e3),12,0.1];
//  Precompute indices
//
// Arguments    : const float input[60000]
//                float Out[1013]
// Return Type  : void
//
void foo(const float input[60000], float Out[1013])
{
  static const double dv[100]{12.0,
                              12.1,
                              12.2,
                              12.3,
                              12.4,
                              12.5,
                              12.6,
                              12.7,
                              12.8,
                              12.9,
                              13.0,
                              13.1,
                              13.2,
                              13.3,
                              13.4,
                              13.5,
                              13.6,
                              13.7,
                              13.8,
                              13.9,
                              14.0,
                              14.1,
                              14.2,
                              14.3,
                              14.4,
                              14.5,
                              14.6,
                              14.7,
                              14.8,
                              14.9,
                              15.0,
                              15.1,
                              15.2,
                              15.3,
                              15.4,
                              15.5,
                              15.6,
                              15.7,
                              15.8,
                              15.9,
                              16.0,
                              16.1,
                              16.2,
                              16.3,
                              16.4,
                              16.5,
                              16.6,
                              16.7,
                              16.8,
                              16.9,
                              17.0,
                              17.1,
                              17.2,
                              17.3,
                              17.4,
                              17.5,
                              17.6,
                              17.7,
                              17.8,
                              17.9,
                              18.0,
                              18.1,
                              18.2,
                              18.3,
                              18.4,
                              18.5,
                              18.6,
                              18.7,
                              18.8,
                              18.9,
                              19.0,
                              19.1,
                              19.2,
                              19.3,
                              19.4,
                              19.5,
                              19.6,
                              19.7,
                              19.8,
                              19.9,
                              20.0,
                              20.1,
                              20.200000000000003,
                              20.3,
                              20.4,
                              20.5,
                              20.6,
                              20.700000000000003,
                              20.8,
                              20.9,
                              21.0,
                              21.1,
                              21.200000000000003,
                              21.3,
                              21.4,
                              21.5,
                              21.6,
                              21.700000000000003,
                              21.8,
                              21.9};
  static const signed char iv[14]{12, 22, 32, 42, 52, 58, 59,
                                  62, 66, 67, 72, 75, 83, 84};
  coder::rtString b_obj;
  coder::rtString c_obj;
  coder::rtString obj;
  coder::array<float, 2U> data;
  coder::array<float, 2U> r;
  double c_data[451];
  double S1_data[100];
  double d_tmp_data[100];
  double d;
  double p;
  float P_S0_data[1000];
  float f_tmp_data[1000];
  float F_temp[501];
  float Y[501];
  float B_range_data[451];
  float varargin_1[451];
  float Y_I[100];
  float ALL;
  float Alpha;
  float Beta;
  float Theta;
  float ex;
  int ia_data[451];
  int S1_size[2];
  int obj2Value_size[2];
  int tmp_size[2];
  int end_tmp;
  int idx;
  int k;
  int loop_ub;
  int trueCount;
  short b_tmp_data[451];
  short c_tmp_data[451];
  short tmp_data[451];
  signed char e_tmp_data[100];
  char varargin_1_data[27];
  char st[24];
  char b_obj2Value_data[23];
  char obj2Value_data[23];
  bool XX[100];
  bool x[100];
  bool b;
  bool exitg1;
  //  Extract parameters from input
  Theta = input[0] * 1000.0F + 1.0F;
  if (Theta < 2.0F) {
    end_tmp = 0;
    idx = 0;
  } else {
    end_tmp = 1;
    idx = static_cast<int>(Theta);
  }
  loop_ub = idx - end_tmp;
  data.set_size(1, loop_ub);
  for (idx = 0; idx < loop_ub; idx++) {
    data[idx] = input[end_tmp + idx];
  }
  //  Display parameters% Display parameters using sprintf
  //  fprintf('F1 = %.2f\n', F1)
  //  fprintf('df = %.2f\n', df)
  std::printf("%s\n", "duration");
  std::fflush(stdout);
  std::printf("%s\n", "data");
  std::fflush(stdout);
  coder::rtString::convertToString(input[30001], obj2Value_data,
                                   obj2Value_size);
  obj.Value.size[0] = 1;
  obj.Value.size[1] = obj2Value_size[1] + 3;
  obj.Value.data[0] = 'F';
  obj.Value.data[1] = '1';
  obj.Value.data[2] = '=';
  idx = obj2Value_size[1];
  if (idx - 1 >= 0) {
    std::copy(&obj2Value_data[0], &obj2Value_data[idx], &obj.Value.data[3]);
  }
  idx = obj.Value.size[1];
  std::copy(&obj.Value.data[0], &obj.Value.data[idx], &varargin_1_data[0]);
  varargin_1_data[obj.Value.size[1]] = '\x00';
  std::printf("%s\n", &varargin_1_data[0]);
  std::fflush(stdout);
  coder::rtString::convertToString(input[30002], obj2Value_data,
                                   obj2Value_size);
  b_obj.Value.size[0] = 1;
  b_obj.Value.size[1] = obj2Value_size[1] + 3;
  b_obj.Value.data[0] = 'd';
  b_obj.Value.data[1] = 'f';
  b_obj.Value.data[2] = '=';
  idx = obj2Value_size[1];
  if (idx - 1 >= 0) {
    std::copy(&obj2Value_data[0], &obj2Value_data[idx], &b_obj.Value.data[3]);
  }
  idx = b_obj.Value.size[1];
  std::copy(&b_obj.Value.data[0], &b_obj.Value.data[idx], &varargin_1_data[0]);
  varargin_1_data[b_obj.Value.size[1]] = '\x00';
  std::printf("%s\n", &varargin_1_data[0]);
  std::fflush(stdout);
  //  Define frequency range
  //  Compute periodogram
  coder::periodogram(data, Y, F_temp);
  if (!std::isnan(Y[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k <= 501)) {
      if (!std::isnan(Y[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    ex = Y[0];
  } else {
    ex = Y[idx - 1];
    end_tmp = idx + 1;
    for (k = end_tmp; k < 502; k++) {
      Theta = Y[k - 1];
      if (ex < Theta) {
        ex = Theta;
      }
    }
  }
  //  Ensure F_temp is a column vector for concatenation
  //  Display B1
  std::printf("%s\n", "B1 done");
  std::fflush(stdout);
  //
  //  Define XX
  std::memset(&XX[0], 0, 100U * sizeof(bool));
  for (end_tmp = 0; end_tmp < 14; end_tmp++) {
    XX[iv[end_tmp]] = true;
  }
  std::printf("%s\n", "B2 done 1");
  std::fflush(stdout);
  //  Compute additional metrics
  //  Define constants
  //  Compute periodogram
  coder::periodogram(data, Y_I);
  for (k = 0; k < 100; k++) {
    Y_I[k] = std::sqrt(Y_I[k]);
  }
  b = !std::isnan(Y_I[0]);
  if (b) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k <= 100)) {
      if (!std::isnan(Y_I[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    Alpha = Y_I[0];
  } else {
    Alpha = Y_I[idx - 1];
    end_tmp = idx + 1;
    for (k = end_tmp; k < 101; k++) {
      Theta = Y_I[k - 1];
      if (Alpha > Theta) {
        Alpha = Theta;
      }
    }
  }
  if (b) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k <= 100)) {
      if (!std::isnan(Y_I[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    ALL = Y_I[0];
  } else {
    ALL = Y_I[idx - 1];
    end_tmp = idx + 1;
    for (k = end_tmp; k < 101; k++) {
      Theta = Y_I[k - 1];
      if (ALL < Theta) {
        ALL = Theta;
      }
    }
  }
  Theta = (ALL + Alpha) / 2.0F;
  //  Compute MI
  for (end_tmp = 0; end_tmp < 100; end_tmp++) {
    x[end_tmp] = ((Y_I[end_tmp] > Theta) == XX[end_tmp]);
  }
  idx = x[0];
  for (k = 0; k < 99; k++) {
    idx += x[k + 1];
  }
  double pxy_idx_1;
  double pxy_tmp;
  //  Probability of not being transmitted correctly
  //  Helper function to compute Mutual Information
  p = static_cast<double>(idx) / 100.0;
  //  Joint probability distribution
  pxy_tmp = (1.0 - p) / 2.0;
  pxy_idx_1 = p / 2.0;
  //  Marginal probabilities
  //  Entropies
  d = pxy_tmp + p / 2.0;
  d *= coder::internal::scalar::b_log2(d + 1.0E-10);
  pxy_tmp *= coder::internal::scalar::b_log2(pxy_tmp + 1.0E-10);
  pxy_idx_1 *= coder::internal::scalar::b_log2(pxy_idx_1 + 1.0E-10);
  //  Mutual Information
  p = d + d;
  p = 100.0 * ((-p - p) - (-(((pxy_tmp + pxy_idx_1) + pxy_idx_1) + pxy_tmp)));
  //  Display MI
  if (p == 0.0) {
    idx = 1;
    b_obj2Value_data[0] = '0';
  } else if (std::isinf(p)) {
    if (p > 0.0) {
      idx = 3;
      b_obj2Value_data[0] = 'I';
      b_obj2Value_data[1] = 'n';
      b_obj2Value_data[2] = 'f';
    } else {
      idx = 4;
      b_obj2Value_data[0] = '-';
      b_obj2Value_data[1] = 'I';
      b_obj2Value_data[2] = 'n';
      b_obj2Value_data[3] = 'f';
    }
  } else {
    idx = std::snprintf(&st[0], 24, "%.16g", p);
    if (idx - 1 >= 0) {
      std::copy(&st[0], &st[idx], &b_obj2Value_data[0]);
    }
  }
  c_obj.Value.size[0] = 1;
  c_obj.Value.size[1] = idx + 3;
  c_obj.Value.data[0] = 'M';
  c_obj.Value.data[1] = 'I';
  c_obj.Value.data[2] = '=';
  if (idx - 1 >= 0) {
    std::copy(&b_obj2Value_data[0], &b_obj2Value_data[idx],
              &c_obj.Value.data[3]);
  }
  idx = c_obj.Value.size[1];
  std::copy(&c_obj.Value.data[0], &c_obj.Value.data[idx], &varargin_1_data[0]);
  varargin_1_data[c_obj.Value.size[1]] = '\x00';
  std::printf("%s\n", &varargin_1_data[0]);
  std::fflush(stdout);
  //  disp(MI)
  //  Alpha Beta Theta bands
  trueCount = 0;
  S1_size[0] = 1;
  idx = 0;
  for (k = 0; k < 100; k++) {
    if (XX[k]) {
      trueCount++;
      S1_data[idx] = dv[k];
      idx++;
    }
  }
  S1_size[1] = trueCount;
  std::printf("%s\n", "abc");
  std::fflush(stdout);
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  coder::b_periodogram(data, varargin_1);
  for (k = 0; k < 451; k++) {
    varargin_1[k] =
        std::sqrt(varargin_1[k] * static_cast<float>(loop_ub) * 1000.0F);
  }
  // 输入参数Fre_range固定
  k = coder::do_vectors(S1_data, S1_size, c_data, obj2Value_size, ia_data, idx);
  for (end_tmp = 0; end_tmp < k; end_tmp++) {
    B_range_data[end_tmp] =
        varargin_1[ia_data[end_tmp] - 1] / static_cast<float>(loop_ub) * 2.0F;
  }
  end_tmp = obj2Value_size[1] - 1;
  trueCount = 0;
  idx = 0;
  for (k = 0; k <= end_tmp; k++) {
    d = c_data[k];
    if ((d >= 4.0) && (d < 8.0)) {
      trueCount++;
      tmp_data[idx] = static_cast<short>(k);
      idx++;
    }
  }
  if (trueCount == 0) {
    Theta = 0.0F;
  } else {
    Theta = B_range_data[tmp_data[0]];
    for (k = 2; k <= trueCount; k++) {
      Theta += B_range_data[tmp_data[k - 1]];
    }
  }
  trueCount = 0;
  idx = 0;
  for (k = 0; k <= end_tmp; k++) {
    d = c_data[k];
    if ((d >= 8.0) && (d < 12.0)) {
      trueCount++;
      b_tmp_data[idx] = static_cast<short>(k);
      idx++;
    }
  }
  if (trueCount == 0) {
    Alpha = 0.0F;
  } else {
    Alpha = B_range_data[b_tmp_data[0]];
    for (k = 2; k <= trueCount; k++) {
      Alpha += B_range_data[b_tmp_data[k - 1]];
    }
  }
  trueCount = 0;
  idx = 0;
  for (k = 0; k <= end_tmp; k++) {
    d = c_data[k];
    if ((d >= 12.0) && (d < 35.0)) {
      trueCount++;
      c_tmp_data[idx] = static_cast<short>(k);
      idx++;
    }
  }
  if (trueCount == 0) {
    Beta = 0.0F;
  } else {
    Beta = B_range_data[c_tmp_data[0]];
    for (k = 2; k <= trueCount; k++) {
      Beta += B_range_data[c_tmp_data[k - 1]];
    }
  }
  ALL = (Alpha + Beta) + Theta;
  Theta /= ALL;
  Alpha /= ALL;
  Beta /= ALL;
  std::printf("%s\n", "abc");
  std::fflush(stdout);
  //  Indicator values
  //  Display Indicator_3band
  std::printf("%s\n", "Alpha Beta Theta");
  std::fflush(stdout);
  //  Compute SNR
  trueCount = 0;
  idx = 0;
  for (k = 0; k < 100; k++) {
    if (!XX[k]) {
      trueCount++;
      e_tmp_data[idx] = static_cast<signed char>(k);
      idx++;
    }
  }
  tmp_size[0] = 1;
  tmp_size[1] = trueCount;
  for (end_tmp = 0; end_tmp < trueCount; end_tmp++) {
    d_tmp_data[end_tmp] = dv[e_tmp_data[end_tmp]];
  }
  coder::periodogram(data, d_tmp_data, tmp_size, r);
  coder::sum(r, P_S0_data, obj2Value_size);
  coder::periodogram(data, S1_data, S1_size, r);
  std::printf("%s\n", "abc");
  std::fflush(stdout);
  //  % Compute approximate entropy
  //  approxEnt = approximateEntropy(data);
  //
  //  % Display approximate entropy
  //  disp("approxEnt")
  //  Indicators =[MI, Indicator_3band, SNR, approxEnt];
  std::printf("%s\n", "B2 done 2");
  std::fflush(stdout);
  //  Combine results
  std::printf("%s\n", "B2 done 3");
  std::fflush(stdout);
  //  Output the combined result
  for (end_tmp = 0; end_tmp < 501; end_tmp++) {
    Out[end_tmp] = F_temp[end_tmp];
    Out[end_tmp + 501] = Y[end_tmp] / ex;
  }
  Out[1002] = Theta;
  Out[1003] = Alpha;
  Out[1004] = Beta;
  Out[1005] = Theta / Alpha;
  Out[1006] = Theta / Beta;
  Out[1007] = Alpha / Beta;
  Theta += Alpha;
  Out[1008] = Theta / Beta;
  Out[1009] = Theta;
  Out[1010] = Theta + Beta;
  Out[1011] = static_cast<float>(p);
  coder::sum(r, f_tmp_data, tmp_size);
  Out[1012] =
      coder::internal::mrdiv(f_tmp_data, tmp_size, P_S0_data, obj2Value_size);
  //  Ensure concatenation aligns properly
  //
}

//
// File trailer for foo.cpp
//
// [EOF]
//
