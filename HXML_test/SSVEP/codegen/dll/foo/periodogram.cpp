//
// File: periodogram.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Aug-2024 01:31:17
//

// Include Files
#include "periodogram.h"
#include "computeDFT.h"
#include "czt.h"
#include "foo_data.h"
#include "log2.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <algorithm>
#include <cmath>
#include <cstring>

// Function Declarations
namespace coder {
static double periodogram_options(const double varargin_1_data[],
                                  const int varargin_1_size[2],
                                  double options_nfft_data[],
                                  int options_nfft_size[2],
                                  char options_range[8]);

}

// Function Definitions
//
// Arguments    : const double varargin_1_data[]
//                const int varargin_1_size[2]
//                double options_nfft_data[]
//                int options_nfft_size[2]
//                char options_range[8]
// Return Type  : double
//
namespace coder {
static double periodogram_options(const double varargin_1_data[],
                                  const int varargin_1_size[2],
                                  double options_nfft_data[],
                                  int options_nfft_size[2],
                                  char options_range[8])
{
  static const char varargin_3[8]{'t', 'w', 'o', 's', 'i', 'd', 'e', 'd'};
  double nfftph_data[100];
  double options1_nfft_data[100];
  double options_Fs;
  int loop_ub;
  int options1_nfft_size_idx_1;
  bool x[2];
  bool exitg1;
  bool y;
  options1_nfft_size_idx_1 = varargin_1_size[1];
  loop_ub = varargin_1_size[1];
  if (loop_ub - 1 >= 0) {
    std::copy(&nfftph_data[0], &nfftph_data[loop_ub], &options1_nfft_data[0]);
  }
  x[0] = true;
  x[1] = (varargin_1_size[1] <= 1);
  y = false;
  loop_ub = 0;
  exitg1 = false;
  while ((!exitg1) && (loop_ub < 2)) {
    if (x[loop_ub]) {
      y = true;
      exitg1 = true;
    } else {
      loop_ub++;
    }
  }
  if (y) {
    if (varargin_1_size[1] != 0) {
      loop_ub = static_cast<signed char>(varargin_1_size[1]);
      std::copy(&varargin_1_data[0], &varargin_1_data[loop_ub],
                &nfftph_data[0]);
      options1_nfft_size_idx_1 = static_cast<signed char>(varargin_1_size[1]);
      std::copy(&nfftph_data[0], &nfftph_data[loop_ub], &options1_nfft_data[0]);
    }
    options_nfft_size[0] = 1;
    options_nfft_size[1] = options1_nfft_size_idx_1;
    if (options1_nfft_size_idx_1 - 1 >= 0) {
      std::copy(&options1_nfft_data[0],
                &options1_nfft_data[options1_nfft_size_idx_1],
                &options_nfft_data[0]);
    }
    options_Fs = 1000.0;
    for (loop_ub = 0; loop_ub < 8; loop_ub++) {
      options_range[loop_ub] = varargin_3[loop_ub];
    }
  }
  if (varargin_1_size[1] > 1) {
    for (loop_ub = 0; loop_ub < 8; loop_ub++) {
      options_range[loop_ub] = varargin_3[loop_ub];
    }
  }
  return options_Fs;
}

//
// Arguments    : const array<float, 2U> &x
//                float Px[451]
// Return Type  : void
//
void b_periodogram(const array<float, 2U> &x, float Px[451])
{
  static const float a[451]{0.0F,           0.000100000005F, 0.000200000009F,
                            0.0003F,        0.000400000019F, 0.0005F,
                            0.0006F,        0.0007F,         0.000800000038F,
                            0.0009F,        0.001F,          0.0011F,
                            0.0012F,        0.0013F,         0.0014F,
                            0.0015F,        0.00160000008F,  0.0017F,
                            0.0018F,        0.0019F,         0.002F,
                            0.0021F,        0.0022F,         0.0023F,
                            0.0024F,        0.0025F,         0.0026F,
                            0.0027F,        0.0028F,         0.0029000002F,
                            0.003F,         0.00309999986F,  0.00320000015F,
                            0.0033F,        0.0034F,         0.0035F,
                            0.0036F,        0.0037F,         0.0038F,
                            0.00390000013F, 0.004F,          0.0041F,
                            0.0042F,        0.0043F,         0.0044F,
                            0.0045F,        0.0046F,         0.0047F,
                            0.0048F,        0.0049F,         0.005F,
                            0.00509999972F, 0.0052F,         0.00530000031F,
                            0.0054F,        0.0055F,         0.0056F,
                            0.00569999963F, 0.00580000039F,  0.0059F,
                            0.006F,         0.0061F,         0.00619999971F,
                            0.0063F,        0.0064000003F,   0.0065F,
                            0.0066F,        0.0067F,         0.0068F,
                            0.0069F,        0.007F,          0.0071F,
                            0.0072F,        0.0073F,         0.0074F,
                            0.0075F,        0.0076F,         0.0077F,
                            0.00780000025F, 0.00790000055F,  0.008F,
                            0.0081F,        0.0082F,         0.0083F,
                            0.0084F,        0.0085F,         0.0086F,
                            0.0087F,        0.0088F,         0.0089F,
                            0.009F,         0.0091F,         0.0092F,
                            0.0093F,        0.0094F,         0.0095F,
                            0.0096F,        0.00969999935F,  0.0098F,
                            0.0099F,        0.01F,           0.0101000005F,
                            0.0101999994F,  0.0103F,         0.0104F,
                            0.0105F,        0.0106000006F,   0.0106999995F,
                            0.0108F,        0.0108999992F,   0.011F,
                            0.0111000007F,  0.0112F,         0.0113F,
                            0.0113999993F,  0.0115F,         0.0116000008F,
                            0.0117F,        0.0118F,         0.0118999993F,
                            0.012F,         0.0121F,         0.0122F,
                            0.0123000005F,  0.0123999994F,   0.0125F,
                            0.0126F,        0.0127F,         0.0128000006F,
                            0.0128999995F,  0.013F,          0.0131F,
                            0.0132F,        0.0133F,         0.0134F,
                            0.0135F,        0.0136F,         0.0137F,
                            0.0138F,        0.0139F,         0.014F,
                            0.0141F,        0.0142F,         0.0143F,
                            0.0144F,        0.0145F,         0.0146F,
                            0.0147F,        0.0148F,         0.0149F,
                            0.015F,         0.0151F,         0.0152F,
                            0.0153F,        0.0154F,         0.0155F,
                            0.0156000005F,  0.0157F,         0.0158000011F,
                            0.0158999991F,  0.016F,          0.0161F,
                            0.0162F,        0.0162999984F,   0.0164F,
                            0.0165F,        0.0166F,         0.0167000014F,
                            0.0168F,        0.0169F,         0.017F,
                            0.0171F,        0.0172F,         0.0172999986F,
                            0.0174F,        0.0175F,         0.0176F,
                            0.0177000016F,  0.0178F,         0.0179F,
                            0.018F,         0.0181F,         0.0182F,
                            0.0182999987F,  0.0184F,         0.0185F,
                            0.0186F,        0.0187F,         0.0188F,
                            0.0189F,        0.019F,          0.0191000011F,
                            0.0192F,        0.0192999989F,   0.0193999987F,
                            0.0195F,        0.0196F,         0.0197F,
                            0.0198F,        0.0199F,         0.02F,
                            0.0201000012F,  0.0202000011F,   0.020299999F,
                            0.0203999989F,  0.0205F,         0.0206F,
                            0.0207F,        0.0208F,         0.0209F,
                            0.021F,         0.0211F,         0.0212000012F,
                            0.0213F,        0.021399999F,    0.0215F,
                            0.0216F,        0.0217F,         0.0217999984F,
                            0.0219F,        0.022F,          0.0221F,
                            0.0222000014F,  0.0223F,         0.0224F,
                            0.0225F,        0.0226F,         0.0227F,
                            0.0227999985F,  0.0229F,         0.023F,
                            0.0231F,        0.0232000016F,   0.0233F,
                            0.0234F,        0.0235F,         0.0236F,
                            0.0237F,        0.0237999987F,   0.0239F,
                            0.024F,         0.0241F,         0.0242F,
                            0.0243F,        0.0244F,         0.0245F,
                            0.0246000011F,  0.0247F,         0.0247999988F,
                            0.0249F,        0.025F,          0.0251F,
                            0.0252F,        0.0253F,         0.0254F,
                            0.0255F,        0.0256000012F,   0.025700001F,
                            0.025799999F,   0.0258999988F,   0.026F,
                            0.0261F,        0.0262F,         0.0263F,
                            0.0264F,        0.0265F,         0.0266F,
                            0.0267000012F,  0.0268F,         0.026899999F,
                            0.027F,         0.0271F,         0.0272F,
                            0.0272999983F,  0.0274F,         0.0275F,
                            0.0276F,        0.0277000014F,   0.0278F,
                            0.0279F,        0.028F,          0.0281F,
                            0.0282F,        0.0282999985F,   0.0284F,
                            0.0285F,        0.0286F,         0.0287000015F,
                            0.0288F,        0.0289F,         0.029F,
                            0.0291F,        0.0292F,         0.0292999987F,
                            0.0294F,        0.0295F,         0.0296F,
                            0.0297F,        0.0298F,         0.0299F,
                            0.03F,          0.030100001F,    0.0302F,
                            0.0302999988F,  0.0304F,         0.0305F,
                            0.0306F,        0.0307F,         0.0308F,
                            0.0309F,        0.031F,          0.0311000012F,
                            0.031200001F,   0.0313F,         0.0314F,
                            0.0315F,        0.0316000022F,   0.0317F,
                            0.0317999981F,  0.0319F,         0.032F,
                            0.0321F,        0.0322F,         0.0323F,
                            0.0324F,        0.0325F,         0.0325999968F,
                            0.0327000022F,  0.0328F,         0.0329F,
                            0.033F,         0.0330999978F,   0.0332F,
                            0.0332999974F,  0.0334000029F,   0.0335F,
                            0.0336F,        0.0337F,         0.0338F,
                            0.0339F,        0.034F,          0.0341F,
                            0.0342F,        0.0343F,         0.0344F,
                            0.0345F,        0.0345999971F,   0.0347000025F,
                            0.0348F,        0.0349000022F,   0.035F,
                            0.0350999981F,  0.0352F,         0.0352999978F,
                            0.0354000032F,  0.0355F,         0.0356F,
                            0.0357F,        0.0358F,         0.0359F,
                            0.036F,         0.0361F,         0.0362F,
                            0.0363F,        0.0364F,         0.0365F,
                            0.0365999974F,  0.0367F,         0.0368F,
                            0.0369000025F,  0.037F,          0.0371F,
                            0.0372F,        0.0372999981F,   0.0374F,
                            0.0375F,        0.0376F,         0.0377F,
                            0.0378F,        0.0379F,         0.038F,
                            0.0380999967F,  0.0382000022F,   0.0383F,
                            0.0384F,        0.0385F,         0.0385999978F,
                            0.0387F,        0.0387999974F,   0.0389000028F,
                            0.039F,         0.0391F,         0.0392F,
                            0.0393F,        0.0394F,         0.0395F,
                            0.0396F,        0.0397F,         0.0398F,
                            0.0399F,        0.04F,           0.0400999971F,
                            0.0402000025F,  0.0403F,         0.0404000022F,
                            0.0405F,        0.0405999981F,   0.0407F,
                            0.0407999977F,  0.0409000032F,   0.041F,
                            0.0411F,        0.0412F,         0.0413F,
                            0.0414F,        0.0415F,         0.0416F,
                            0.0417F,        0.0418F,         0.0419F,
                            0.042F,         0.0420999974F,   0.0422F,
                            0.0423F,        0.0424000025F,   0.0425F,
                            0.0426F,        0.0427F,         0.0427999981F,
                            0.0429F,        0.043F,          0.0431F,
                            0.0432F,        0.0433F,         0.0434F,
                            0.0435F,        0.0435999967F,   0.0437000021F,
                            0.0438F,        0.0439F,         0.044F,
                            0.0440999977F,  0.0442F,         0.0442999974F,
                            0.0444000028F,  0.0445F,         0.0446F,
                            0.0447F,        0.0448F,         0.0449F,
                            0.045F};
  array<float, 1U> b_x;
  array<float, 1U> r;
  array<float, 1U> xw;
  creal32_T b_y1[451];
  double f;
  float cos2TwidFactor;
  float s2;
  float twiddleFactor;
  int acoef;
  int eint;
  int i;
  int loop_ub;
  unsigned short csz_idx_0;
  acoef = x.size(1);
  r.set_size(x.size(1));
  loop_ub = x.size(1);
  for (i = 0; i < loop_ub; i++) {
    r[i] = 1.0F;
  }
  b_x = x.reshape(acoef);
  if (r.size(0) == 1) {
    csz_idx_0 = static_cast<unsigned short>(b_x.size(0));
  } else if (b_x.size(0) == 1) {
    csz_idx_0 = static_cast<unsigned short>(r.size(0));
  } else if (b_x.size(0) == r.size(0)) {
    csz_idx_0 = static_cast<unsigned short>(b_x.size(0));
  } else if (r.size(0) < b_x.size(0)) {
    csz_idx_0 = static_cast<unsigned short>(r.size(0));
  } else {
    csz_idx_0 = static_cast<unsigned short>(b_x.size(0));
  }
  xw.set_size(static_cast<int>(csz_idx_0));
  if (csz_idx_0 != 0) {
    acoef = (b_x.size(0) != 1);
    i = csz_idx_0 - 1;
    for (loop_ub = 0; loop_ub <= i; loop_ub++) {
      xw[loop_ub] = b_x[acoef * loop_ub];
    }
  }
  f = std::frexp((static_cast<double>(xw.size(0)) + 451.0) - 1.0, &eint);
  if (f == 0.5) {
    eint--;
  }
  if (80.0 * internal::scalar::b_log2(static_cast<double>(eint)) < 451.0) {
    b_computeDFTviaCZT(xw, b_y1);
  } else {
    acoef = xw.size(0);
    for (loop_ub = 0; loop_ub < 451; loop_ub++) {
      float complexConstant_im;
      float complexConstant_re;
      float phaseCorrection_im;
      float phaseCorrection_re;
      float s1;
      twiddleFactor = 6.28318548F *
                      (a[loop_ub] * static_cast<float>(xw.size(0))) /
                      static_cast<float>(acoef);
      cos2TwidFactor = 2.0F * std::cos(twiddleFactor);
      phaseCorrection_re = twiddleFactor * 0.0F;
      if (phaseCorrection_re == 0.0F) {
        complexConstant_re = std::cos(-twiddleFactor);
        complexConstant_im = std::sin(-twiddleFactor);
      } else if (-twiddleFactor == 0.0F) {
        complexConstant_re = rtNaNF;
        complexConstant_im = 0.0F;
      } else {
        complexConstant_re = rtNaNF;
        complexConstant_im = rtNaNF;
      }
      phaseCorrection_re *=
          static_cast<float>(static_cast<double>(acoef) - 1.0);
      phaseCorrection_im =
          static_cast<float>(static_cast<double>(acoef) - 1.0) * -twiddleFactor;
      if (phaseCorrection_re == 0.0F) {
        phaseCorrection_re = std::cos(phaseCorrection_im);
        phaseCorrection_im = std::sin(phaseCorrection_im);
      } else if (phaseCorrection_im == 0.0F) {
        phaseCorrection_re = rtNaNF;
        phaseCorrection_im = 0.0F;
      } else {
        phaseCorrection_re = rtNaNF;
        phaseCorrection_im = rtNaNF;
      }
      s1 = 0.0F;
      s2 = 0.0F;
      for (eint = 0; eint <= acoef - 2; eint++) {
        twiddleFactor = (xw[eint] + cos2TwidFactor * s1) - s2;
        s2 = s1;
        s1 = twiddleFactor;
      }
      cos2TwidFactor = ((xw[acoef - 1] + cos2TwidFactor * s1) - s2) -
                       s1 * complexConstant_re;
      s2 = 0.0F - s1 * complexConstant_im;
      b_y1[loop_ub].re =
          cos2TwidFactor * phaseCorrection_re - s2 * phaseCorrection_im;
      b_y1[loop_ub].im =
          cos2TwidFactor * phaseCorrection_im + s2 * phaseCorrection_re;
    }
  }
  for (i = 0; i < 451; i++) {
    twiddleFactor = b_y1[i].re;
    cos2TwidFactor = b_y1[i].im;
    s2 = twiddleFactor * twiddleFactor - cos2TwidFactor * -cos2TwidFactor;
    if (twiddleFactor * -cos2TwidFactor + cos2TwidFactor * twiddleFactor ==
        0.0F) {
      s2 /= static_cast<float>(x.size(1));
    } else if (s2 == 0.0F) {
      s2 = 0.0F;
    } else {
      s2 /= static_cast<float>(x.size(1));
    }
    Px[i] = s2 / 1000.0F;
  }
}

//
// Arguments    : const array<float, 2U> &x
//                float Px[501]
//                float w[501]
// Return Type  : void
//
void periodogram(const array<float, 2U> &x, float Px[501], float w[501])
{
  static const float a[501]{0.0F,           0.000100000005F, 0.000200000009F,
                            0.0003F,        0.000400000019F, 0.0005F,
                            0.0006F,        0.0007F,         0.000800000038F,
                            0.0009F,        0.001F,          0.0011F,
                            0.0012F,        0.0013F,         0.0014F,
                            0.0015F,        0.00160000008F,  0.0017F,
                            0.0018F,        0.0019F,         0.002F,
                            0.0021F,        0.0022F,         0.0023F,
                            0.0024F,        0.0025F,         0.0026F,
                            0.0027F,        0.0028F,         0.0029000002F,
                            0.003F,         0.00309999986F,  0.00320000015F,
                            0.0033F,        0.0034F,         0.0035F,
                            0.0036F,        0.0037F,         0.0038F,
                            0.00390000013F, 0.004F,          0.0041F,
                            0.0042F,        0.0043F,         0.0044F,
                            0.0045F,        0.0046F,         0.0047F,
                            0.0048F,        0.0049F,         0.005F,
                            0.00509999972F, 0.0052F,         0.00530000031F,
                            0.0054F,        0.0055F,         0.0056F,
                            0.00569999963F, 0.00580000039F,  0.0059F,
                            0.006F,         0.0061F,         0.00619999971F,
                            0.0063F,        0.0064000003F,   0.0065F,
                            0.0066F,        0.0067F,         0.0068F,
                            0.0069F,        0.007F,          0.0071F,
                            0.0072F,        0.0073F,         0.0074F,
                            0.0075F,        0.0076F,         0.0077F,
                            0.00780000025F, 0.00790000055F,  0.008F,
                            0.0081F,        0.0082F,         0.0083F,
                            0.0084F,        0.0085F,         0.0086F,
                            0.0087F,        0.0088F,         0.0089F,
                            0.009F,         0.0091F,         0.0092F,
                            0.0093F,        0.0094F,         0.0095F,
                            0.0096F,        0.00969999935F,  0.0098F,
                            0.0099F,        0.01F,           0.0101000005F,
                            0.0101999994F,  0.0103F,         0.0104F,
                            0.0105F,        0.0106000006F,   0.0106999995F,
                            0.0108F,        0.0108999992F,   0.011F,
                            0.0111000007F,  0.0112F,         0.0113F,
                            0.0113999993F,  0.0115F,         0.0116000008F,
                            0.0117F,        0.0118F,         0.0118999993F,
                            0.012F,         0.0121F,         0.0122F,
                            0.0123000005F,  0.0123999994F,   0.0125F,
                            0.0126F,        0.0127F,         0.0128000006F,
                            0.0128999995F,  0.013F,          0.0131F,
                            0.0132F,        0.0133F,         0.0134F,
                            0.0135F,        0.0136F,         0.0137F,
                            0.0138F,        0.0139F,         0.014F,
                            0.0141F,        0.0142F,         0.0143F,
                            0.0144F,        0.0145F,         0.0146F,
                            0.0147F,        0.0148F,         0.0149F,
                            0.015F,         0.0151F,         0.0152F,
                            0.0153F,        0.0154F,         0.0155F,
                            0.0156000005F,  0.0157F,         0.0158000011F,
                            0.0158999991F,  0.016F,          0.0161F,
                            0.0162F,        0.0162999984F,   0.0164F,
                            0.0165F,        0.0166F,         0.0167000014F,
                            0.0168F,        0.0169F,         0.017F,
                            0.0171F,        0.0172F,         0.0172999986F,
                            0.0174F,        0.0175F,         0.0176F,
                            0.0177000016F,  0.0178F,         0.0179F,
                            0.018F,         0.0181F,         0.0182F,
                            0.0182999987F,  0.0184F,         0.0185F,
                            0.0186F,        0.0187F,         0.0188F,
                            0.0189F,        0.019F,          0.0191000011F,
                            0.0192F,        0.0192999989F,   0.0193999987F,
                            0.0195F,        0.0196F,         0.0197F,
                            0.0198F,        0.0199F,         0.02F,
                            0.0201000012F,  0.0202000011F,   0.020299999F,
                            0.0203999989F,  0.0205F,         0.0206F,
                            0.0207F,        0.0208F,         0.0209F,
                            0.021F,         0.0211F,         0.0212000012F,
                            0.0213F,        0.021399999F,    0.0215F,
                            0.0216F,        0.0217F,         0.0217999984F,
                            0.0219F,        0.022F,          0.0221F,
                            0.0222000014F,  0.0223F,         0.0224F,
                            0.0225F,        0.0226F,         0.0227F,
                            0.0227999985F,  0.0229F,         0.023F,
                            0.0231F,        0.0232000016F,   0.0233F,
                            0.0234F,        0.0235F,         0.0236F,
                            0.0237F,        0.0237999987F,   0.0239F,
                            0.024F,         0.0241F,         0.0242F,
                            0.0243F,        0.0244F,         0.0245F,
                            0.0246000011F,  0.0247F,         0.0247999988F,
                            0.0249F,        0.025F,          0.0251F,
                            0.0252F,        0.0253F,         0.0254F,
                            0.0255F,        0.0256000012F,   0.025700001F,
                            0.025799999F,   0.0258999988F,   0.026F,
                            0.0261F,        0.0262F,         0.0263F,
                            0.0264F,        0.0265F,         0.0266F,
                            0.0267000012F,  0.0268F,         0.026899999F,
                            0.027F,         0.0271F,         0.0272F,
                            0.0272999983F,  0.0274F,         0.0275F,
                            0.0276F,        0.0277000014F,   0.0278F,
                            0.0279F,        0.028F,          0.0281F,
                            0.0282F,        0.0282999985F,   0.0284F,
                            0.0285F,        0.0286F,         0.0287000015F,
                            0.0288F,        0.0289F,         0.029F,
                            0.0291F,        0.0292F,         0.0292999987F,
                            0.0294F,        0.0295F,         0.0296F,
                            0.0297F,        0.0298F,         0.0299F,
                            0.03F,          0.030100001F,    0.0302F,
                            0.0302999988F,  0.0304F,         0.0305F,
                            0.0306F,        0.0307F,         0.0308F,
                            0.0309F,        0.031F,          0.0311000012F,
                            0.031200001F,   0.0313F,         0.0314F,
                            0.0315F,        0.0316000022F,   0.0317F,
                            0.0317999981F,  0.0319F,         0.032F,
                            0.0321F,        0.0322F,         0.0323F,
                            0.0324F,        0.0325F,         0.0325999968F,
                            0.0327000022F,  0.0328F,         0.0329F,
                            0.033F,         0.0330999978F,   0.0332F,
                            0.0332999974F,  0.0334000029F,   0.0335F,
                            0.0336F,        0.0337F,         0.0338F,
                            0.0339F,        0.034F,          0.0341F,
                            0.0342F,        0.0343F,         0.0344F,
                            0.0345F,        0.0345999971F,   0.0347000025F,
                            0.0348F,        0.0349000022F,   0.035F,
                            0.0350999981F,  0.0352F,         0.0352999978F,
                            0.0354000032F,  0.0355F,         0.0356F,
                            0.0357F,        0.0358F,         0.0359F,
                            0.036F,         0.0361F,         0.0362F,
                            0.0363F,        0.0364F,         0.0365F,
                            0.0365999974F,  0.0367F,         0.0368F,
                            0.0369000025F,  0.037F,          0.0371F,
                            0.0372F,        0.0372999981F,   0.0374F,
                            0.0375F,        0.0376F,         0.0377F,
                            0.0378F,        0.0379F,         0.038F,
                            0.0380999967F,  0.0382000022F,   0.0383F,
                            0.0384F,        0.0385F,         0.0385999978F,
                            0.0387F,        0.0387999974F,   0.0389000028F,
                            0.039F,         0.0391F,         0.0392F,
                            0.0393F,        0.0394F,         0.0395F,
                            0.0396F,        0.0397F,         0.0398F,
                            0.0399F,        0.04F,           0.0400999971F,
                            0.0402000025F,  0.0403F,         0.0404000022F,
                            0.0405F,        0.0405999981F,   0.0407F,
                            0.0407999977F,  0.0409000032F,   0.041F,
                            0.0411F,        0.0412F,         0.0413F,
                            0.0414F,        0.0415F,         0.0416F,
                            0.0417F,        0.0418F,         0.0419F,
                            0.042F,         0.0420999974F,   0.0422F,
                            0.0423F,        0.0424000025F,   0.0425F,
                            0.0426F,        0.0427F,         0.0427999981F,
                            0.0429F,        0.043F,          0.0431F,
                            0.0432F,        0.0433F,         0.0434F,
                            0.0435F,        0.0435999967F,   0.0437000021F,
                            0.0438F,        0.0439F,         0.044F,
                            0.0440999977F,  0.0442F,         0.0442999974F,
                            0.0444000028F,  0.0445F,         0.0446F,
                            0.0447F,        0.0448F,         0.0449F,
                            0.045F,         0.0451F,         0.0452F,
                            0.0453F,        0.0454F,         0.0455F,
                            0.045599997F,   0.0457000025F,   0.0458F,
                            0.0459000021F,  0.046F,          0.0460999981F,
                            0.0462F,        0.0462999977F,   0.0464000031F,
                            0.0465F,        0.0466F,         0.0467F,
                            0.0468F,        0.0469F,         0.047F,
                            0.0471F,        0.0472F,         0.0473F,
                            0.0474F,        0.0475F,         0.0475999974F,
                            0.0477F,        0.0478F,         0.0479000024F,
                            0.048F,         0.0481F,         0.0482F,
                            0.048299998F,   0.0484F,         0.0485F,
                            0.0486F,        0.0487F,         0.0488F,
                            0.0489F,        0.049F,          0.0490999967F,
                            0.0492000021F,  0.0493F,         0.0494F,
                            0.0495F,        0.0495999977F,   0.0497F,
                            0.0498F,        0.0499000028F,   0.05F};
  static const float f[501]{
      0.0F,  0.1F,  0.2F,  0.3F,  0.4F,  0.5F,  0.6F,  0.7F,  0.8F,  0.9F,
      1.0F,  1.1F,  1.2F,  1.3F,  1.4F,  1.5F,  1.6F,  1.7F,  1.8F,  1.9F,
      2.0F,  2.1F,  2.2F,  2.3F,  2.4F,  2.5F,  2.6F,  2.7F,  2.8F,  2.9F,
      3.0F,  3.1F,  3.2F,  3.3F,  3.4F,  3.5F,  3.6F,  3.7F,  3.8F,  3.9F,
      4.0F,  4.1F,  4.2F,  4.3F,  4.4F,  4.5F,  4.6F,  4.7F,  4.8F,  4.9F,
      5.0F,  5.1F,  5.2F,  5.3F,  5.4F,  5.5F,  5.6F,  5.7F,  5.8F,  5.9F,
      6.0F,  6.1F,  6.2F,  6.3F,  6.4F,  6.5F,  6.6F,  6.7F,  6.8F,  6.9F,
      7.0F,  7.1F,  7.2F,  7.3F,  7.4F,  7.5F,  7.6F,  7.7F,  7.8F,  7.9F,
      8.0F,  8.1F,  8.2F,  8.3F,  8.4F,  8.5F,  8.6F,  8.7F,  8.8F,  8.9F,
      9.0F,  9.1F,  9.2F,  9.3F,  9.4F,  9.5F,  9.6F,  9.7F,  9.8F,  9.9F,
      10.0F, 10.1F, 10.2F, 10.3F, 10.4F, 10.5F, 10.6F, 10.7F, 10.8F, 10.9F,
      11.0F, 11.1F, 11.2F, 11.3F, 11.4F, 11.5F, 11.6F, 11.7F, 11.8F, 11.9F,
      12.0F, 12.1F, 12.2F, 12.3F, 12.4F, 12.5F, 12.6F, 12.7F, 12.8F, 12.9F,
      13.0F, 13.1F, 13.2F, 13.3F, 13.4F, 13.5F, 13.6F, 13.7F, 13.8F, 13.9F,
      14.0F, 14.1F, 14.2F, 14.3F, 14.4F, 14.5F, 14.6F, 14.7F, 14.8F, 14.9F,
      15.0F, 15.1F, 15.2F, 15.3F, 15.4F, 15.5F, 15.6F, 15.7F, 15.8F, 15.9F,
      16.0F, 16.1F, 16.2F, 16.3F, 16.4F, 16.5F, 16.6F, 16.7F, 16.8F, 16.9F,
      17.0F, 17.1F, 17.2F, 17.3F, 17.4F, 17.5F, 17.6F, 17.7F, 17.8F, 17.9F,
      18.0F, 18.1F, 18.2F, 18.3F, 18.4F, 18.5F, 18.6F, 18.7F, 18.8F, 18.9F,
      19.0F, 19.1F, 19.2F, 19.3F, 19.4F, 19.5F, 19.6F, 19.7F, 19.8F, 19.9F,
      20.0F, 20.1F, 20.2F, 20.3F, 20.4F, 20.5F, 20.6F, 20.7F, 20.8F, 20.9F,
      21.0F, 21.1F, 21.2F, 21.3F, 21.4F, 21.5F, 21.6F, 21.7F, 21.8F, 21.9F,
      22.0F, 22.1F, 22.2F, 22.3F, 22.4F, 22.5F, 22.6F, 22.7F, 22.8F, 22.9F,
      23.0F, 23.1F, 23.2F, 23.3F, 23.4F, 23.5F, 23.6F, 23.7F, 23.8F, 23.9F,
      24.0F, 24.1F, 24.2F, 24.3F, 24.4F, 24.5F, 24.6F, 24.7F, 24.8F, 24.9F,
      25.0F, 25.1F, 25.2F, 25.3F, 25.4F, 25.5F, 25.6F, 25.7F, 25.8F, 25.9F,
      26.0F, 26.1F, 26.2F, 26.3F, 26.4F, 26.5F, 26.6F, 26.7F, 26.8F, 26.9F,
      27.0F, 27.1F, 27.2F, 27.3F, 27.4F, 27.5F, 27.6F, 27.7F, 27.8F, 27.9F,
      28.0F, 28.1F, 28.2F, 28.3F, 28.4F, 28.5F, 28.6F, 28.7F, 28.8F, 28.9F,
      29.0F, 29.1F, 29.2F, 29.3F, 29.4F, 29.5F, 29.6F, 29.7F, 29.8F, 29.9F,
      30.0F, 30.1F, 30.2F, 30.3F, 30.4F, 30.5F, 30.6F, 30.7F, 30.8F, 30.9F,
      31.0F, 31.1F, 31.2F, 31.3F, 31.4F, 31.5F, 31.6F, 31.7F, 31.8F, 31.9F,
      32.0F, 32.1F, 32.2F, 32.3F, 32.4F, 32.5F, 32.6F, 32.7F, 32.8F, 32.9F,
      33.0F, 33.1F, 33.2F, 33.3F, 33.4F, 33.5F, 33.6F, 33.7F, 33.8F, 33.9F,
      34.0F, 34.1F, 34.2F, 34.3F, 34.4F, 34.5F, 34.6F, 34.7F, 34.8F, 34.9F,
      35.0F, 35.1F, 35.2F, 35.3F, 35.4F, 35.5F, 35.6F, 35.7F, 35.8F, 35.9F,
      36.0F, 36.1F, 36.2F, 36.3F, 36.4F, 36.5F, 36.6F, 36.7F, 36.8F, 36.9F,
      37.0F, 37.1F, 37.2F, 37.3F, 37.4F, 37.5F, 37.6F, 37.7F, 37.8F, 37.9F,
      38.0F, 38.1F, 38.2F, 38.3F, 38.4F, 38.5F, 38.6F, 38.7F, 38.8F, 38.9F,
      39.0F, 39.1F, 39.2F, 39.3F, 39.4F, 39.5F, 39.6F, 39.7F, 39.8F, 39.9F,
      40.0F, 40.1F, 40.2F, 40.3F, 40.4F, 40.5F, 40.6F, 40.7F, 40.8F, 40.9F,
      41.0F, 41.1F, 41.2F, 41.3F, 41.4F, 41.5F, 41.6F, 41.7F, 41.8F, 41.9F,
      42.0F, 42.1F, 42.2F, 42.3F, 42.4F, 42.5F, 42.6F, 42.7F, 42.8F, 42.9F,
      43.0F, 43.1F, 43.2F, 43.3F, 43.4F, 43.5F, 43.6F, 43.7F, 43.8F, 43.9F,
      44.0F, 44.1F, 44.2F, 44.3F, 44.4F, 44.5F, 44.6F, 44.7F, 44.8F, 44.9F,
      45.0F, 45.1F, 45.2F, 45.3F, 45.4F, 45.5F, 45.6F, 45.7F, 45.8F, 45.9F,
      46.0F, 46.1F, 46.2F, 46.3F, 46.4F, 46.5F, 46.6F, 46.7F, 46.8F, 46.9F,
      47.0F, 47.1F, 47.2F, 47.3F, 47.4F, 47.5F, 47.6F, 47.7F, 47.8F, 47.9F,
      48.0F, 48.1F, 48.2F, 48.3F, 48.4F, 48.5F, 48.6F, 48.7F, 48.8F, 48.9F,
      49.0F, 49.1F, 49.2F, 49.3F, 49.4F, 49.5F, 49.6F, 49.7F, 49.8F, 49.9F,
      50.0F};
  static const float fv[501]{
      0.0F,  0.1F,  0.2F,  0.3F,  0.4F,  0.5F,  0.6F,  0.7F,  0.8F,  0.9F,
      1.0F,  1.1F,  1.2F,  1.3F,  1.4F,  1.5F,  1.6F,  1.7F,  1.8F,  1.9F,
      2.0F,  2.1F,  2.2F,  2.3F,  2.4F,  2.5F,  2.6F,  2.7F,  2.8F,  2.9F,
      3.0F,  3.1F,  3.2F,  3.3F,  3.4F,  3.5F,  3.6F,  3.7F,  3.8F,  3.9F,
      4.0F,  4.1F,  4.2F,  4.3F,  4.4F,  4.5F,  4.6F,  4.7F,  4.8F,  4.9F,
      5.0F,  5.1F,  5.2F,  5.3F,  5.4F,  5.5F,  5.6F,  5.7F,  5.8F,  5.9F,
      6.0F,  6.1F,  6.2F,  6.3F,  6.4F,  6.5F,  6.6F,  6.7F,  6.8F,  6.9F,
      7.0F,  7.1F,  7.2F,  7.3F,  7.4F,  7.5F,  7.6F,  7.7F,  7.8F,  7.9F,
      8.0F,  8.1F,  8.2F,  8.3F,  8.4F,  8.5F,  8.6F,  8.7F,  8.8F,  8.9F,
      9.0F,  9.1F,  9.2F,  9.3F,  9.4F,  9.5F,  9.6F,  9.7F,  9.8F,  9.9F,
      10.0F, 10.1F, 10.2F, 10.3F, 10.4F, 10.5F, 10.6F, 10.7F, 10.8F, 10.9F,
      11.0F, 11.1F, 11.2F, 11.3F, 11.4F, 11.5F, 11.6F, 11.7F, 11.8F, 11.9F,
      12.0F, 12.1F, 12.2F, 12.3F, 12.4F, 12.5F, 12.6F, 12.7F, 12.8F, 12.9F,
      13.0F, 13.1F, 13.2F, 13.3F, 13.4F, 13.5F, 13.6F, 13.7F, 13.8F, 13.9F,
      14.0F, 14.1F, 14.2F, 14.3F, 14.4F, 14.5F, 14.6F, 14.7F, 14.8F, 14.9F,
      15.0F, 15.1F, 15.2F, 15.3F, 15.4F, 15.5F, 15.6F, 15.7F, 15.8F, 15.9F,
      16.0F, 16.1F, 16.2F, 16.3F, 16.4F, 16.5F, 16.6F, 16.7F, 16.8F, 16.9F,
      17.0F, 17.1F, 17.2F, 17.3F, 17.4F, 17.5F, 17.6F, 17.7F, 17.8F, 17.9F,
      18.0F, 18.1F, 18.2F, 18.3F, 18.4F, 18.5F, 18.6F, 18.7F, 18.8F, 18.9F,
      19.0F, 19.1F, 19.2F, 19.3F, 19.4F, 19.5F, 19.6F, 19.7F, 19.8F, 19.9F,
      20.0F, 20.1F, 20.2F, 20.3F, 20.4F, 20.5F, 20.6F, 20.7F, 20.8F, 20.9F,
      21.0F, 21.1F, 21.2F, 21.3F, 21.4F, 21.5F, 21.6F, 21.7F, 21.8F, 21.9F,
      22.0F, 22.1F, 22.2F, 22.3F, 22.4F, 22.5F, 22.6F, 22.7F, 22.8F, 22.9F,
      23.0F, 23.1F, 23.2F, 23.3F, 23.4F, 23.5F, 23.6F, 23.7F, 23.8F, 23.9F,
      24.0F, 24.1F, 24.2F, 24.3F, 24.4F, 24.5F, 24.6F, 24.7F, 24.8F, 24.9F,
      25.0F, 25.1F, 25.2F, 25.3F, 25.4F, 25.5F, 25.6F, 25.7F, 25.8F, 25.9F,
      26.0F, 26.1F, 26.2F, 26.3F, 26.4F, 26.5F, 26.6F, 26.7F, 26.8F, 26.9F,
      27.0F, 27.1F, 27.2F, 27.3F, 27.4F, 27.5F, 27.6F, 27.7F, 27.8F, 27.9F,
      28.0F, 28.1F, 28.2F, 28.3F, 28.4F, 28.5F, 28.6F, 28.7F, 28.8F, 28.9F,
      29.0F, 29.1F, 29.2F, 29.3F, 29.4F, 29.5F, 29.6F, 29.7F, 29.8F, 29.9F,
      30.0F, 30.1F, 30.2F, 30.3F, 30.4F, 30.5F, 30.6F, 30.7F, 30.8F, 30.9F,
      31.0F, 31.1F, 31.2F, 31.3F, 31.4F, 31.5F, 31.6F, 31.7F, 31.8F, 31.9F,
      32.0F, 32.1F, 32.2F, 32.3F, 32.4F, 32.5F, 32.6F, 32.7F, 32.8F, 32.9F,
      33.0F, 33.1F, 33.2F, 33.3F, 33.4F, 33.5F, 33.6F, 33.7F, 33.8F, 33.9F,
      34.0F, 34.1F, 34.2F, 34.3F, 34.4F, 34.5F, 34.6F, 34.7F, 34.8F, 34.9F,
      35.0F, 35.1F, 35.2F, 35.3F, 35.4F, 35.5F, 35.6F, 35.7F, 35.8F, 35.9F,
      36.0F, 36.1F, 36.2F, 36.3F, 36.4F, 36.5F, 36.6F, 36.7F, 36.8F, 36.9F,
      37.0F, 37.1F, 37.2F, 37.3F, 37.4F, 37.5F, 37.6F, 37.7F, 37.8F, 37.9F,
      38.0F, 38.1F, 38.2F, 38.3F, 38.4F, 38.5F, 38.6F, 38.7F, 38.8F, 38.9F,
      39.0F, 39.1F, 39.2F, 39.3F, 39.4F, 39.5F, 39.6F, 39.7F, 39.8F, 39.9F,
      40.0F, 40.1F, 40.2F, 40.3F, 40.4F, 40.5F, 40.6F, 40.7F, 40.8F, 40.9F,
      41.0F, 41.1F, 41.2F, 41.3F, 41.4F, 41.5F, 41.6F, 41.7F, 41.8F, 41.9F,
      42.0F, 42.1F, 42.2F, 42.3F, 42.4F, 42.5F, 42.6F, 42.7F, 42.8F, 42.9F,
      43.0F, 43.1F, 43.2F, 43.3F, 43.4F, 43.5F, 43.6F, 43.7F, 43.8F, 43.9F,
      44.0F, 44.1F, 44.2F, 44.3F, 44.4F, 44.5F, 44.6F, 44.7F, 44.8F, 44.9F,
      45.0F, 45.1F, 45.2F, 45.3F, 45.4F, 45.5F, 45.6F, 45.7F, 45.8F, 45.9F,
      46.0F, 46.1F, 46.2F, 46.3F, 46.4F, 46.5F, 46.6F, 46.7F, 46.8F, 46.9F,
      47.0F, 47.1F, 47.2F, 47.3F, 47.4F, 47.5F, 47.6F, 47.7F, 47.8F, 47.9F,
      48.0F, 48.1F, 48.2F, 48.3F, 48.4F, 48.5F, 48.6F, 48.7F, 48.8F, 48.9F,
      49.0F, 49.1F, 49.2F, 49.3F, 49.4F, 49.5F, 49.6F, 49.7F, 49.8F, 49.9F,
      50.0F};
  array<float, 1U> b_x;
  array<float, 1U> r;
  array<float, 1U> xw;
  creal32_T b_y1[501];
  double b_f;
  float errorMatrix[501];
  float y[501];
  float maxFreq;
  float s0;
  float s1;
  int acoef;
  int eint;
  int ind;
  int loop_ub;
  unsigned short csz_idx_0;
  std::copy(&fv[0], &fv[501], &w[0]);
  acoef = x.size(1);
  r.set_size(x.size(1));
  loop_ub = x.size(1);
  for (ind = 0; ind < loop_ub; ind++) {
    r[ind] = 1.0F;
  }
  b_x = x.reshape(acoef);
  if (r.size(0) == 1) {
    csz_idx_0 = static_cast<unsigned short>(b_x.size(0));
  } else if (b_x.size(0) == 1) {
    csz_idx_0 = static_cast<unsigned short>(r.size(0));
  } else if (b_x.size(0) == r.size(0)) {
    csz_idx_0 = static_cast<unsigned short>(b_x.size(0));
  } else if (r.size(0) < b_x.size(0)) {
    csz_idx_0 = static_cast<unsigned short>(r.size(0));
  } else {
    csz_idx_0 = static_cast<unsigned short>(b_x.size(0));
  }
  xw.set_size(static_cast<int>(csz_idx_0));
  if (csz_idx_0 != 0) {
    acoef = (b_x.size(0) != 1);
    ind = csz_idx_0 - 1;
    for (loop_ub = 0; loop_ub <= ind; loop_ub++) {
      xw[loop_ub] = b_x[acoef * loop_ub];
    }
  }
  y[500] = 50.0F;
  y[0] = 0.0F;
  for (loop_ub = 0; loop_ub < 499; loop_ub++) {
    y[loop_ub + 1] = (static_cast<float>(loop_ub) + 1.0F) * 0.1F;
  }
  std::copy(&f[0], &f[501], &errorMatrix[0]);
  maxFreq = internal::maximum(errorMatrix);
  for (acoef = 0; acoef < 501; acoef++) {
    errorMatrix[acoef] = std::abs(f[acoef] - y[acoef]) / maxFreq;
  }
  b_f = std::frexp((static_cast<double>(xw.size(0)) + 501.0) - 1.0, &eint);
  if (b_f == 0.5) {
    eint--;
  }
  if ((internal::maximum(errorMatrix) < 3.57627869E-7F) &&
      (80.0 * internal::scalar::b_log2(static_cast<double>(eint)) < 501.0)) {
    creal32_T complexConstant;
    creal32_T phaseCorrection;
    phaseCorrection.re = 1.0F;
    phaseCorrection.im = 0.0F;
    complexConstant.re = 0.999999821F;
    complexConstant.im = -0.000628318463F;
    czt(xw, complexConstant, phaseCorrection, b_y1);
  } else {
    creal32_T phaseCorrection;
    acoef = xw.size(0);
    for (loop_ub = 0; loop_ub < 501; loop_ub++) {
      creal32_T complexConstant;
      float cos2TwidFactor;
      maxFreq = 6.28318548F * (a[loop_ub] * static_cast<float>(xw.size(0))) /
                static_cast<float>(acoef);
      cos2TwidFactor = 2.0F * std::cos(maxFreq);
      phaseCorrection.re = maxFreq * 0.0F;
      if (phaseCorrection.re == 0.0F) {
        complexConstant.re = std::cos(-maxFreq);
        complexConstant.im = std::sin(-maxFreq);
      } else if (-maxFreq == 0.0F) {
        complexConstant.re = rtNaNF;
        complexConstant.im = 0.0F;
      } else {
        complexConstant.re = rtNaNF;
        complexConstant.im = rtNaNF;
      }
      phaseCorrection.re *=
          static_cast<float>(static_cast<double>(acoef) - 1.0);
      maxFreq = static_cast<float>(static_cast<double>(acoef) - 1.0) * -maxFreq;
      if (phaseCorrection.re == 0.0F) {
        phaseCorrection.re = std::cos(maxFreq);
        phaseCorrection.im = std::sin(maxFreq);
      } else if (maxFreq == 0.0F) {
        phaseCorrection.re = rtNaNF;
        phaseCorrection.im = 0.0F;
      } else {
        phaseCorrection.re = rtNaNF;
        phaseCorrection.im = rtNaNF;
      }
      s1 = 0.0F;
      maxFreq = 0.0F;
      for (ind = 0; ind <= acoef - 2; ind++) {
        s0 = (xw[ind] + cos2TwidFactor * s1) - maxFreq;
        maxFreq = s1;
        s1 = s0;
      }
      s0 = ((xw[acoef - 1] + cos2TwidFactor * s1) - maxFreq) -
           s1 * complexConstant.re;
      maxFreq = 0.0F - s1 * complexConstant.im;
      b_y1[loop_ub].re = s0 * phaseCorrection.re - maxFreq * phaseCorrection.im;
      b_y1[loop_ub].im = s0 * phaseCorrection.im + maxFreq * phaseCorrection.re;
    }
  }
  for (ind = 0; ind < 501; ind++) {
    s0 = b_y1[ind].re;
    s1 = b_y1[ind].im;
    maxFreq = s0 * s0 - s1 * -s1;
    if (s0 * -s1 + s1 * s0 == 0.0F) {
      maxFreq /= static_cast<float>(x.size(1));
    } else if (maxFreq == 0.0F) {
      maxFreq = 0.0F;
    } else {
      maxFreq /= static_cast<float>(x.size(1));
    }
    Px[ind] = maxFreq / 1000.0F;
  }
}

//
// Arguments    : const array<float, 2U> &x
//                float Px[100]
// Return Type  : void
//
void periodogram(const array<float, 2U> &x, float Px[100])
{
  static const float a[100]{
      0.012F,  0.0121F,       0.0122F,       0.0123000005F, 0.0123999994F,
      0.0125F, 0.0126F,       0.0127F,       0.0128000006F, 0.0128999995F,
      0.013F,  0.0131F,       0.0132F,       0.0133F,       0.0134F,
      0.0135F, 0.0136F,       0.0137F,       0.0138F,       0.0139F,
      0.014F,  0.0141F,       0.0142F,       0.0143F,       0.0144F,
      0.0145F, 0.0146F,       0.0147F,       0.0148F,       0.0149F,
      0.015F,  0.0151F,       0.0152F,       0.0153F,       0.0154F,
      0.0155F, 0.0156000005F, 0.0157F,       0.0158000011F, 0.0158999991F,
      0.016F,  0.0161F,       0.0162F,       0.0162999984F, 0.0164F,
      0.0165F, 0.0166F,       0.0167000014F, 0.0168F,       0.0169F,
      0.017F,  0.0171F,       0.0172F,       0.0172999986F, 0.0174F,
      0.0175F, 0.0176F,       0.0177000016F, 0.0178F,       0.0179F,
      0.018F,  0.0181F,       0.0182F,       0.0182999987F, 0.0184F,
      0.0185F, 0.0186F,       0.0187F,       0.0188F,       0.0189F,
      0.019F,  0.0191000011F, 0.0192F,       0.0192999989F, 0.0193999987F,
      0.0195F, 0.0196F,       0.0197F,       0.0198F,       0.0199F,
      0.02F,   0.0201000012F, 0.0202000011F, 0.020299999F,  0.0203999989F,
      0.0205F, 0.0206F,       0.0207F,       0.0208F,       0.0209F,
      0.021F,  0.0211F,       0.0212000012F, 0.0213F,       0.021399999F,
      0.0215F, 0.0216F,       0.0217F,       0.0217999984F, 0.0219F};
  array<float, 1U> b_x;
  array<float, 1U> r;
  array<float, 1U> xw;
  creal32_T b_y1[100];
  double f;
  float cos2TwidFactor;
  float s2;
  float twiddleFactor;
  int acoef;
  int eint;
  int i;
  int loop_ub;
  unsigned short csz_idx_0;
  acoef = x.size(1);
  r.set_size(x.size(1));
  loop_ub = x.size(1);
  for (i = 0; i < loop_ub; i++) {
    r[i] = 1.0F;
  }
  b_x = x.reshape(acoef);
  if (r.size(0) == 1) {
    csz_idx_0 = static_cast<unsigned short>(b_x.size(0));
  } else if (b_x.size(0) == 1) {
    csz_idx_0 = static_cast<unsigned short>(r.size(0));
  } else if (b_x.size(0) == r.size(0)) {
    csz_idx_0 = static_cast<unsigned short>(b_x.size(0));
  } else if (r.size(0) < b_x.size(0)) {
    csz_idx_0 = static_cast<unsigned short>(r.size(0));
  } else {
    csz_idx_0 = static_cast<unsigned short>(b_x.size(0));
  }
  xw.set_size(static_cast<int>(csz_idx_0));
  if (csz_idx_0 != 0) {
    acoef = (b_x.size(0) != 1);
    i = csz_idx_0 - 1;
    for (loop_ub = 0; loop_ub <= i; loop_ub++) {
      xw[loop_ub] = b_x[acoef * loop_ub];
    }
  }
  f = std::frexp((static_cast<double>(xw.size(0)) + 100.0) - 1.0, &eint);
  if (f == 0.5) {
    eint--;
  }
  if (80.0 * internal::scalar::b_log2(static_cast<double>(eint)) < 100.0) {
    computeDFTviaCZT(xw, b_y1);
  } else {
    acoef = xw.size(0);
    for (loop_ub = 0; loop_ub < 100; loop_ub++) {
      float complexConstant_im;
      float complexConstant_re;
      float phaseCorrection_im;
      float phaseCorrection_re;
      float s1;
      twiddleFactor = 6.28318548F *
                      (a[loop_ub] * static_cast<float>(xw.size(0))) /
                      static_cast<float>(acoef);
      cos2TwidFactor = 2.0F * std::cos(twiddleFactor);
      phaseCorrection_re = twiddleFactor * 0.0F;
      if (phaseCorrection_re == 0.0F) {
        complexConstant_re = std::cos(-twiddleFactor);
        complexConstant_im = std::sin(-twiddleFactor);
      } else if (-twiddleFactor == 0.0F) {
        complexConstant_re = rtNaNF;
        complexConstant_im = 0.0F;
      } else {
        complexConstant_re = rtNaNF;
        complexConstant_im = rtNaNF;
      }
      phaseCorrection_re *=
          static_cast<float>(static_cast<double>(acoef) - 1.0);
      phaseCorrection_im =
          static_cast<float>(static_cast<double>(acoef) - 1.0) * -twiddleFactor;
      if (phaseCorrection_re == 0.0F) {
        phaseCorrection_re = std::cos(phaseCorrection_im);
        phaseCorrection_im = std::sin(phaseCorrection_im);
      } else if (phaseCorrection_im == 0.0F) {
        phaseCorrection_re = rtNaNF;
        phaseCorrection_im = 0.0F;
      } else {
        phaseCorrection_re = rtNaNF;
        phaseCorrection_im = rtNaNF;
      }
      s1 = 0.0F;
      s2 = 0.0F;
      for (eint = 0; eint <= acoef - 2; eint++) {
        twiddleFactor = (xw[eint] + cos2TwidFactor * s1) - s2;
        s2 = s1;
        s1 = twiddleFactor;
      }
      cos2TwidFactor = ((xw[acoef - 1] + cos2TwidFactor * s1) - s2) -
                       s1 * complexConstant_re;
      s2 = 0.0F - s1 * complexConstant_im;
      b_y1[loop_ub].re =
          cos2TwidFactor * phaseCorrection_re - s2 * phaseCorrection_im;
      b_y1[loop_ub].im =
          cos2TwidFactor * phaseCorrection_im + s2 * phaseCorrection_re;
    }
  }
  for (i = 0; i < 100; i++) {
    twiddleFactor = b_y1[i].re;
    cos2TwidFactor = b_y1[i].im;
    s2 = twiddleFactor * twiddleFactor - cos2TwidFactor * -cos2TwidFactor;
    if (twiddleFactor * -cos2TwidFactor + cos2TwidFactor * twiddleFactor ==
        0.0F) {
      s2 /= static_cast<float>(x.size(1));
    } else if (s2 == 0.0F) {
      s2 = 0.0F;
    } else {
      s2 /= static_cast<float>(x.size(1));
    }
    Px[i] = s2 / 1000.0F;
  }
}

//
// Arguments    : const array<float, 2U> &x
//                const double varargin_2_data[]
//                const int varargin_2_size[2]
//                array<float, 2U> &Px
// Return Type  : void
//
void periodogram(const array<float, 2U> &x, const double varargin_2_data[],
                 const int varargin_2_size[2], array<float, 2U> &Px)
{
  static const char b_b[8]{'o', 'n', 'e', 's', 'i', 'd', 'e', 'd'};
  array<float, 1U> b_x;
  array<float, 1U> r;
  array<float, 1U> xw;
  creal32_T Px1_data[1000];
  creal32_T Xx_data[100];
  creal32_T phaseCorrection;
  double options_nfft_data[100];
  double options_Fs;
  float Sxx_data[1000];
  float nfft_data[100];
  float cos2TwidFactor;
  float delta1;
  float s0;
  float s1;
  int options_nfft_size[2];
  int acoef;
  int eint;
  int i;
  int k;
  int loop_ub;
  int nfft_size_idx_1;
  unsigned short csz_idx_0;
  char options_range[8];
  bool b;
  options_Fs =
      periodogram_options(varargin_2_data, varargin_2_size, options_nfft_data,
                          options_nfft_size, options_range);
  nfft_size_idx_1 = options_nfft_size[1];
  loop_ub = options_nfft_size[1];
  for (i = 0; i < loop_ub; i++) {
    nfft_data[i] = static_cast<float>(options_nfft_data[i]);
  }
  s1 = static_cast<float>(options_Fs);
  b = std::isnan(static_cast<float>(options_Fs));
  if (b) {
    s1 = 6.28318548F;
  }
  acoef = x.size(1);
  r.set_size(x.size(1));
  loop_ub = x.size(1);
  for (i = 0; i < loop_ub; i++) {
    r[i] = 1.0F;
  }
  b_x = x.reshape(acoef);
  if (r.size(0) == 1) {
    csz_idx_0 = static_cast<unsigned short>(b_x.size(0));
  } else if (b_x.size(0) == 1) {
    csz_idx_0 = static_cast<unsigned short>(r.size(0));
  } else if (b_x.size(0) == r.size(0)) {
    csz_idx_0 = static_cast<unsigned short>(b_x.size(0));
  } else if (r.size(0) < b_x.size(0)) {
    csz_idx_0 = static_cast<unsigned short>(r.size(0));
  } else {
    csz_idx_0 = static_cast<unsigned short>(b_x.size(0));
  }
  xw.set_size(static_cast<int>(csz_idx_0));
  if (csz_idx_0 != 0) {
    acoef = (b_x.size(0) != 1);
    i = csz_idx_0 - 1;
    for (k = 0; k <= i; k++) {
      xw[k] = b_x[acoef * k];
    }
  }
  if (options_nfft_size[1] == 1) {
    acoef = computeDFTviaFFT(xw, static_cast<double>(xw.size(0)), nfft_data[0],
                             s1, Px1_data, Sxx_data, k);
  } else {
    double f;
    float approx_data[100];
    float errorMatrix_data[100];
    float varargin_1_data[100];
    if (options_nfft_size[1] >= 1) {
      delta1 = nfft_data[options_nfft_size[1] - 1];
      errorMatrix_data[options_nfft_size[1] - 1] = delta1;
      if (options_nfft_size[1] >= 2) {
        errorMatrix_data[0] = nfft_data[0];
        if (options_nfft_size[1] >= 3) {
          delta1 = (delta1 - nfft_data[0]) /
                   (static_cast<float>(options_nfft_size[1]) - 1.0F);
          for (k = 0; k <= nfft_size_idx_1 - 3; k++) {
            errorMatrix_data[k + 1] =
                nfft_data[0] + (static_cast<float>(k) + 1.0F) * delta1;
          }
        }
      }
    }
    for (k = 0; k < nfft_size_idx_1; k++) {
      approx_data[k] = errorMatrix_data[k];
      varargin_1_data[k] = std::abs(nfft_data[k]);
    }
    delta1 = internal::maximum(varargin_1_data, options_nfft_size[1]);
    for (acoef = 0; acoef < nfft_size_idx_1; acoef++) {
      errorMatrix_data[acoef] =
          std::abs(nfft_data[acoef] - approx_data[acoef]) / delta1;
    }
    f = std::frexp(
        std::abs(static_cast<double>(xw.size(0) + options_nfft_size[1]) - 1.0),
        &eint);
    if (f == 0.5) {
      eint--;
    }
    if ((internal::maximum(errorMatrix_data, options_nfft_size[1]) <
         3.57627869E-7F) &&
        (options_nfft_size[1] >
         80.0 * internal::scalar::b_log2(static_cast<double>(eint)))) {
      creal32_T complexConstant;
      s0 = 0.0F * nfft_data[0];
      cos2TwidFactor = 6.28318548F * nfft_data[0];
      if (cos2TwidFactor == 0.0F) {
        phaseCorrection.re = s0 / s1;
        phaseCorrection.im = 0.0F;
      } else if (s0 == 0.0F) {
        phaseCorrection.re = 0.0F;
        phaseCorrection.im = cos2TwidFactor / s1;
      } else {
        phaseCorrection.re = rtNaNF;
        phaseCorrection.im = cos2TwidFactor / s1;
      }
      if (phaseCorrection.re == 0.0F) {
        delta1 = phaseCorrection.im;
        phaseCorrection.re = std::cos(delta1);
        phaseCorrection.im = std::sin(delta1);
      } else if (phaseCorrection.im == 0.0F) {
        phaseCorrection.re = rtNaNF;
        phaseCorrection.im = 0.0F;
      } else {
        phaseCorrection.re = rtNaNF;
        phaseCorrection.im = rtNaNF;
      }
      delta1 = nfft_data[0] - nfft_data[options_nfft_size[1] - 1];
      s0 = 0.0F * delta1;
      cos2TwidFactor = 6.28318548F * delta1;
      delta1 = (static_cast<float>(options_nfft_size[1]) - 1.0F) * s1;
      if (cos2TwidFactor == 0.0F) {
        complexConstant.re = s0 / delta1;
        complexConstant.im = 0.0F;
      } else if (s0 == 0.0F) {
        complexConstant.re = 0.0F;
        complexConstant.im = cos2TwidFactor / delta1;
      } else {
        complexConstant.re = rtNaNF;
        complexConstant.im = cos2TwidFactor / delta1;
      }
      if (complexConstant.re == 0.0F) {
        delta1 = complexConstant.im;
        complexConstant.re = std::cos(delta1);
        complexConstant.im = std::sin(delta1);
      } else if (complexConstant.im == 0.0F) {
        complexConstant.re = rtNaNF;
        complexConstant.im = 0.0F;
      } else {
        complexConstant.re = rtNaNF;
        complexConstant.im = rtNaNF;
      }
      acoef = czt(xw, static_cast<double>(options_nfft_size[1]),
                  complexConstant, phaseCorrection, Xx_data);
      if (acoef - 1 >= 0) {
        std::copy(&Xx_data[0], &Xx_data[acoef], &Px1_data[0]);
      }
    } else {
      for (i = 0; i < nfft_size_idx_1; i++) {
        delta1 = nfft_data[i];
        cos2TwidFactor = delta1;
        if (std::isnan(delta1) || std::isnan(s1) || std::isinf(delta1)) {
          cos2TwidFactor = rtNaNF;
        } else if (!std::isinf(s1)) {
          bool rEQ0;
          cos2TwidFactor = std::fmod(delta1, s1);
          rEQ0 = (cos2TwidFactor == 0.0F);
          if ((!rEQ0) && (s1 > std::floor(s1))) {
            delta1 /= s1;
            rEQ0 = !(std::abs(delta1 - std::floor(delta1 + 0.5F)) >
                     1.1920929E-7F * delta1);
          }
          if (rEQ0) {
            cos2TwidFactor = s1 * 0.0F;
          }
        }
        approx_data[i] = cos2TwidFactor / s1 * static_cast<float>(xw.size(0));
      }
      acoef = xw.size(0);
      for (k = 0; k < nfft_size_idx_1; k++) {
        creal32_T complexConstant;
        delta1 = 6.28318548F * approx_data[k] / static_cast<float>(acoef);
        cos2TwidFactor = 2.0F * std::cos(delta1);
        phaseCorrection.re = delta1 * 0.0F;
        if (phaseCorrection.re == 0.0F) {
          complexConstant.re = std::cos(-delta1);
          complexConstant.im = std::sin(-delta1);
        } else if (-delta1 == 0.0F) {
          complexConstant.re = rtNaNF;
          complexConstant.im = 0.0F;
        } else {
          complexConstant.re = rtNaNF;
          complexConstant.im = rtNaNF;
        }
        phaseCorrection.re *=
            static_cast<float>(static_cast<double>(acoef) - 1.0);
        delta1 = static_cast<float>(static_cast<double>(acoef) - 1.0) * -delta1;
        if (phaseCorrection.re == 0.0F) {
          phaseCorrection.re = std::cos(delta1);
          phaseCorrection.im = std::sin(delta1);
        } else if (delta1 == 0.0F) {
          phaseCorrection.re = rtNaNF;
          phaseCorrection.im = 0.0F;
        } else {
          phaseCorrection.re = rtNaNF;
          phaseCorrection.im = rtNaNF;
        }
        s1 = 0.0F;
        delta1 = 0.0F;
        for (loop_ub = 0; loop_ub <= acoef - 2; loop_ub++) {
          s0 = (xw[loop_ub] + cos2TwidFactor * s1) - delta1;
          delta1 = s1;
          s1 = s0;
        }
        cos2TwidFactor = ((xw[acoef - 1] + cos2TwidFactor * s1) - delta1) -
                         s1 * complexConstant.re;
        delta1 = 0.0F - s1 * complexConstant.im;
        Xx_data[k].re =
            cos2TwidFactor * phaseCorrection.re - delta1 * phaseCorrection.im;
        Xx_data[k].im =
            cos2TwidFactor * phaseCorrection.im + delta1 * phaseCorrection.re;
      }
      acoef = options_nfft_size[1];
      if (nfft_size_idx_1 - 1 >= 0) {
        std::copy(&Xx_data[0], &Xx_data[nfft_size_idx_1], &Px1_data[0]);
      }
    }
  }
  k = acoef;
  for (i = 0; i < acoef; i++) {
    delta1 = Px1_data[i].re;
    cos2TwidFactor = Px1_data[i].im;
    s0 = delta1 * delta1 - cos2TwidFactor * -cos2TwidFactor;
    if (delta1 * -cos2TwidFactor + cos2TwidFactor * delta1 == 0.0F) {
      s0 /= static_cast<float>(x.size(1));
    } else if (s0 == 0.0F) {
      s0 = 0.0F;
    } else {
      s0 /= static_cast<float>(x.size(1));
    }
    Sxx_data[i] = s0;
  }
  acoef = std::memcmp(&options_range[0], &b_b[0], 8);
  if ((acoef == 0) && (options_nfft_size[1] == 1)) {
    if (std::isnan(nfft_data[0]) || std::isinf(nfft_data[0])) {
      cos2TwidFactor = rtNaNF;
    } else {
      cos2TwidFactor = std::fmod(nfft_data[0], 2.0F);
      if (cos2TwidFactor == 0.0F) {
        cos2TwidFactor = 0.0F;
      }
    }
    if (!(cos2TwidFactor == 1.0F)) {
      float Sxx_unscaled_data[501];
      float select_data[501];
      nfft_data[0] = nfft_data[0] / 2.0F + 1.0F;
      if (std::isnan(nfft_data[0])) {
        acoef = 1;
        select_data[0] = rtNaNF;
      } else {
        acoef = static_cast<int>(nfft_data[0] - 1.0) + 1;
        loop_ub = static_cast<int>(nfft_data[0] - 1.0);
        for (i = 0; i <= loop_ub; i++) {
          select_data[i] = static_cast<float>(static_cast<double>(i) + 1.0);
        }
      }
      for (i = 0; i < acoef; i++) {
        Sxx_unscaled_data[i] = Sxx_data[static_cast<int>(select_data[i]) - 1];
      }
      if (acoef - 1 < 2) {
        i = 0;
        eint = 1;
      } else {
        i = 1;
        eint = acoef;
      }
      delta1 = Sxx_data[static_cast<int>(select_data[0]) - 1];
      cos2TwidFactor = Sxx_data[static_cast<int>(select_data[acoef - 1]) - 1];
      loop_ub = eint - i;
      k = loop_ub + 1;
      Sxx_data[0] = delta1;
      for (eint = 0; eint <= loop_ub - 2; eint++) {
        Sxx_data[eint + 1] = 2.0F * Sxx_unscaled_data[i + eint];
      }
      Sxx_data[loop_ub] = cos2TwidFactor;
    } else {
      float Sxx_unscaled_data[501];
      float select_data[501];
      nfft_data[0] = (nfft_data[0] + 1.0F) / 2.0F;
      if (std::isnan(nfft_data[0])) {
        acoef = 1;
        select_data[0] = rtNaNF;
      } else {
        acoef = static_cast<int>(nfft_data[0] - 1.0) + 1;
        loop_ub = static_cast<int>(nfft_data[0] - 1.0);
        for (i = 0; i <= loop_ub; i++) {
          select_data[i] = static_cast<float>(static_cast<double>(i) + 1.0);
        }
      }
      for (i = 0; i < acoef; i++) {
        Sxx_unscaled_data[i] = Sxx_data[static_cast<int>(select_data[i]) - 1];
      }
      if (acoef < 2) {
        i = 0;
        acoef = 0;
      } else {
        i = 1;
      }
      delta1 = Sxx_data[static_cast<int>(select_data[0]) - 1];
      loop_ub = acoef - i;
      k = loop_ub + 1;
      Sxx_data[0] = delta1;
      for (eint = 0; eint < loop_ub; eint++) {
        Sxx_data[eint + 1] = 2.0F * Sxx_unscaled_data[i + eint];
      }
    }
  }
  if (!b) {
    for (i = 0; i < k; i++) {
      Sxx_data[i] /= static_cast<float>(options_Fs);
    }
  } else {
    for (i = 0; i < k; i++) {
      Sxx_data[i] /= 6.28318548F;
    }
  }
  for (i = 0; i < k; i++) {
    Px1_data[i].re = Sxx_data[i];
    Px1_data[i].im = 0.0F;
  }
  if (options_nfft_size[1] > 1) {
    Px.set_size(1, k);
    for (i = 0; i < k; i++) {
      Px[Px.size(0) * i] = Px1_data[i].re;
    }
  } else {
    Px.set_size(k, 1);
    for (i = 0; i < k; i++) {
      Px[i] = Px1_data[i].re;
    }
  }
}

} // namespace coder

//
// File trailer for periodogram.cpp
//
// [EOF]
//
