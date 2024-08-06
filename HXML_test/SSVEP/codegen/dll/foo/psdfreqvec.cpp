//
// File: psdfreqvec.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Aug-2024 01:31:17
//

// Include Files
#include "psdfreqvec.h"
#include "rt_nonfinite.h"
#include <algorithm>
#include <cfloat>
#include <cmath>
#include <cstring>

// Function Declarations
static float rt_remf_snf(float u0, float u1);

// Function Definitions
//
// Arguments    : float u0
//                float u1
// Return Type  : float
//
static float rt_remf_snf(float u0, float u1)
{
  float y;
  if (std::isnan(u0) || std::isnan(u1) || std::isinf(u0)) {
    y = rtNaNF;
  } else if (std::isinf(u1)) {
    y = u0;
  } else if ((u1 != 0.0F) && (u1 != std::trunc(u1))) {
    float q;
    q = std::abs(u0 / u1);
    if (!(std::abs(q - std::floor(q + 0.5F)) > FLT_EPSILON * q)) {
      y = 0.0F * u0;
    } else {
      y = std::fmod(u0, u1);
    }
  } else {
    y = std::fmod(u0, u1);
  }
  return y;
}

//
// Arguments    : float varargin_2
//                float varargin_4
//                float w_data[]
// Return Type  : int
//
namespace coder {
int psdfreqvec(float varargin_2, float varargin_4, float w_data[])
{
  float w1_data[1000];
  float Fs1;
  float Nyq;
  float freq_res;
  float half_res;
  int loop_ub;
  int w_size;
  if (std::isnan(varargin_4)) {
    Fs1 = 6.28318548F;
  } else {
    Fs1 = varargin_4;
  }
  freq_res = Fs1 / varargin_2;
  if (std::isnan(varargin_2 - 1.0F)) {
    w_size = 1;
    w1_data[0] = rtNaNF;
  } else {
    w_size = static_cast<int>(varargin_2 - 1.0F) + 1;
    loop_ub = static_cast<int>(varargin_2 - 1.0F);
    for (int i{0}; i <= loop_ub; i++) {
      w1_data[i] = static_cast<float>(i);
    }
  }
  loop_ub = w_size - 1;
  for (int i{0}; i <= loop_ub; i++) {
    w1_data[i] *= freq_res;
  }
  Nyq = Fs1 / 2.0F;
  half_res = freq_res / 2.0F;
  if (rt_remf_snf(varargin_2, 2.0F) != 0.0F) {
    float halfNPTS;
    halfNPTS = (varargin_2 + 1.0F) / 2.0F;
    w1_data[static_cast<int>(halfNPTS) - 1] = Nyq - half_res;
    w1_data[static_cast<int>(halfNPTS)] = Nyq + half_res;
  } else {
    w1_data[static_cast<int>(varargin_2 / 2.0F + 1.0F) - 1] = Nyq;
  }
  w1_data[static_cast<int>(varargin_2) - 1] = Fs1 - freq_res;
  if (w_size - 1 >= 0) {
    std::copy(&w1_data[0], &w1_data[w_size], &w_data[0]);
  }
  return w_size;
}

} // namespace coder

//
// File trailer for psdfreqvec.cpp
//
// [EOF]
//
