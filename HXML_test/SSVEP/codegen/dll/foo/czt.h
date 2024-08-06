//
// File: czt.h
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 06-Aug-2024 01:31:17
//

#ifndef CZT_H
#define CZT_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void czt(const array<float, 1U> &x, const creal32_T w, const creal32_T a,
         creal32_T g[501]);

int czt(const array<float, 1U> &x, double k, const creal32_T w,
        const creal32_T a, creal32_T g_data[]);

} // namespace coder

#endif
//
// File trailer for czt.h
//
// [EOF]
//
