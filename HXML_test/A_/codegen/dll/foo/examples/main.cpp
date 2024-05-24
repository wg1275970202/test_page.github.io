//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 24-May-2024 15:11:29
//

/*************************************************************************/
/* This automatically generated example C++ main file shows how to call  */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

// Include Files
#include "main.h"
#include "foo.h"
#include "foo_terminate.h"
#include "rt_nonfinite.h"

// Function Declarations
static void argInit_1x1687500_uint8_T(unsigned char result[1687500]);

static unsigned char argInit_uint8_T();

// Function Definitions
//
// Arguments    : unsigned char result[1687500]
// Return Type  : void
//
static void argInit_1x1687500_uint8_T(unsigned char result[1687500])
{
  // Loop over the array to initialize each element.
  for (int idx1{0}; idx1 < 1687500; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_uint8_T();
  }
}

//
// Arguments    : void
// Return Type  : unsigned char
//
static unsigned char argInit_uint8_T()
{
  return 0U;
}

//
// Arguments    : int argc
//                char **argv
// Return Type  : int
//
int main(int, char **)
{
  // The initialize function is being called automatically from your entry-point
  // function. So, a call to initialize is not included here. Invoke the
  // entry-point functions.
  // You can call entry-point functions multiple times.
  main_foo();
  // Terminate the application.
  // You do not need to do this more than one time.
  foo_terminate();
  return 0;
}

//
// Arguments    : void
// Return Type  : void
//
void main_foo()
{
  static unsigned char B[2250000];
  static unsigned char uv[1687500];
  // Initialize function 'foo' input arguments.
  // Initialize function input argument 'Icam'.
  // Call the entry-point 'foo'.
  argInit_1x1687500_uint8_T(uv);
  foo(uv, B);
}

//
// File trailer for main.cpp
//
// [EOF]
//
