//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: imbinarize.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 24-May-2024 15:11:29
//

// Include Files
#include "imbinarize.h"
#include "rt_nonfinite.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const unsigned char b_I[562500]
//                bool BW[562500]
// Return Type  : void
//
namespace coder {
void imbinarize(const unsigned char b_I[562500], bool BW[562500])
{
  double localBins1[256];
  double localBins2[256];
  double localBins3[256];
  double y[256];
  double d;
  double idx;
  double num_elems;
  double num_maxval;
  double p;
  int i;
  int k;
  std::memset(&y[0], 0, 256U * sizeof(double));
  std::memset(&localBins1[0], 0, 256U * sizeof(double));
  std::memset(&localBins2[0], 0, 256U * sizeof(double));
  std::memset(&localBins3[0], 0, 256U * sizeof(double));
  for (i = 0; i + 4 <= 562500; i += 4) {
    localBins1[b_I[i]]++;
    k = b_I[i + 1];
    localBins2[k]++;
    k = b_I[i + 2];
    localBins3[k]++;
    k = b_I[i + 3];
    y[k]++;
  }
  while (i + 1 <= 562500) {
    y[b_I[i]]++;
    i++;
  }
  num_elems = 0.0;
  for (i = 0; i < 256; i++) {
    d = ((y[i] + localBins1[i]) + localBins2[i]) + localBins3[i];
    y[i] = d;
    num_elems += d;
  }
  localBins1[0] = y[0] / num_elems;
  localBins2[0] = localBins1[0];
  for (k = 0; k < 255; k++) {
    p = y[k + 1] / num_elems;
    localBins1[k + 1] = localBins1[k] + p;
    localBins2[k + 1] = localBins2[k] + p * (static_cast<double>(k) + 2.0);
  }
  num_elems = rtMinusInf;
  idx = 0.0;
  num_maxval = 0.0;
  for (k = 0; k < 255; k++) {
    d = localBins1[k];
    p = localBins2[255] * d - localBins2[k];
    p = p * p / (d * (1.0 - d));
    if (p > num_elems) {
      num_elems = p;
      idx = static_cast<double>(k) + 1.0;
      num_maxval = 1.0;
    } else if (p == num_elems) {
      idx += static_cast<double>(k) + 1.0;
      num_maxval++;
    }
  }
  if (!std::isinf(num_elems)) {
    idx /= num_maxval;
    p = (idx - 1.0) / 255.0;
  } else {
    p = 0.0;
  }
  d = 255.0 * p;
  for (k = 0; k < 562500; k++) {
    BW[k] = (b_I[k] > d);
  }
}

} // namespace coder

//
// File trailer for imbinarize.cpp
//
// [EOF]
//
