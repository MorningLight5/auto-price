//
// File: trimf.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 09-Apr-2024 15:11:39
//

// Include Files
#include "trimf.h"

// Function Definitions
//
// Arguments    : double x
//                const double params[3]
// Return Type  : double
//
namespace coder {
namespace fuzzy {
namespace internal {
namespace codegen {
double trimf(double x, const double params[3])
{
  double y;
  y = 0.0;
  if ((params[0] != params[1]) && (params[0] < x) && (x < params[1])) {
    y = (x - params[0]) * (1.0 / (params[1] - params[0]));
  }
  if ((params[1] != params[2]) && (params[1] < x) && (x < params[2])) {
    y = (params[2] - x) * (1.0 / (params[2] - params[1]));
  }
  if (x == params[1]) {
    y = 1.0;
  }
  return y;
}

} // namespace codegen
} // namespace internal
} // namespace fuzzy
} // namespace coder

//
// File trailer for trimf.cpp
//
// [EOF]
//
