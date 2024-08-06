//
// File: mrdivide_helper.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Aug-2024 01:31:17
//

// Include Files
#include "mrdivide_helper.h"
#include "foo_rtwutil.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include <algorithm>
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const float A_data[]
//                const int A_size[2]
//                const float B_data[]
//                const int B_size[2]
// Return Type  : float
//
namespace coder {
namespace internal {
float mrdiv(const float A_data[], const int A_size[2], const float B_data[],
            const int B_size[2])
{
  float b_A_data[1000];
  float b_B_data[1000];
  float Y;
  if ((A_size[1] == 0) || (B_size[1] == 0)) {
    Y = 0.0F;
  } else if (B_size[1] == 1) {
    Y = A_data[0] / B_data[0];
  } else {
    float tau_data;
    float wj;
    int b_A_size;
    int knt;
    b_A_size = B_size[1];
    knt = B_size[1];
    std::copy(&B_data[0], &B_data[knt], &b_A_data[0]);
    knt = A_size[1];
    std::copy(&A_data[0], &A_data[knt], &b_B_data[0]);
    tau_data = 0.0F;
    for (int i{0}; i < 1; i++) {
      float atmp;
      atmp = b_A_data[0];
      tau_data = 0.0F;
      wj = blas::xnrm2(b_A_size - 1, b_A_data);
      if (wj != 0.0F) {
        float beta1;
        beta1 = rt_hypotf_snf(b_A_data[0], wj);
        if (b_A_data[0] >= 0.0F) {
          beta1 = -beta1;
        }
        if (std::abs(beta1) < 9.86076132E-32F) {
          knt = 0;
          do {
            knt++;
            for (int k{2}; k <= b_A_size; k++) {
              b_A_data[k - 1] *= 1.01412048E+31F;
            }
            beta1 *= 1.01412048E+31F;
            atmp *= 1.01412048E+31F;
          } while ((std::abs(beta1) < 9.86076132E-32F) && (knt < 20));
          beta1 = rt_hypotf_snf(atmp, blas::xnrm2(b_A_size - 1, b_A_data));
          if (atmp >= 0.0F) {
            beta1 = -beta1;
          }
          tau_data = (beta1 - atmp) / beta1;
          wj = 1.0F / (atmp - beta1);
          for (int k{2}; k <= b_A_size; k++) {
            b_A_data[k - 1] *= wj;
          }
          for (int k{0}; k < knt; k++) {
            beta1 *= 9.86076132E-32F;
          }
          atmp = beta1;
        } else {
          tau_data = (beta1 - b_A_data[0]) / beta1;
          wj = 1.0F / (b_A_data[0] - beta1);
          for (int k{2}; k <= b_A_size; k++) {
            b_A_data[k - 1] *= wj;
          }
          atmp = beta1;
        }
      }
      b_A_data[0] = atmp;
    }
    knt = 0;
    wj = std::abs(b_A_data[0]);
    if (!(wj <= std::fmin(0.000345266977F,
                          1.1920929E-6F * static_cast<float>(B_size[1])) *
                    wj)) {
      knt = 1;
    }
    Y = 0.0F;
    if (tau_data != 0.0F) {
      wj = b_B_data[0];
      for (int i{2}; i <= b_A_size; i++) {
        wj += b_A_data[i - 1] * b_B_data[i - 1];
      }
      wj *= tau_data;
      if (wj != 0.0F) {
        b_B_data[0] -= wj;
        for (int i{2}; i <= b_A_size; i++) {
          b_B_data[i - 1] -= b_A_data[i - 1] * wj;
        }
      }
    }
    for (int i{0}; i < knt; i++) {
      Y = b_B_data[0];
    }
    for (b_A_size = knt; b_A_size >= 1; b_A_size--) {
      Y /= b_A_data[0];
    }
  }
  return Y;
}

} // namespace internal
} // namespace coder

//
// File trailer for mrdivide_helper.cpp
//
// [EOF]
//
