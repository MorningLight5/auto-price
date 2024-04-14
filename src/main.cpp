//
// File: main.cpp
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 09-Apr-2024 15:11:39
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
#include "FuzzyPrice.h"
#include <iostream>

// Function Declarations
static double argInit_real_T();

// Function Definitions
//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : int argc
//                char **argv
// Return Type  : int
//
int main(int argc, char * argv[])
{
  // The initialize function is being called automatically from your entry-point
  // function. So, a call to initialize is not included here. Invoke the
  // entry-point functions.
  // You can call entry-point functions multiple times.
  double priceRate_tmp;
  // Initialize function 'FuzzyPrice' input arguments.
  
  // Call the entry-point 'FuzzyPrice'.

  if (argc != 9) {
	  std::cout << "please input right number of args.\n";
	  return 1;
  }
  double parameter[8] = { 0.0 };
  for (int i = 0; i < 8; i++) {
	  parameter[i] = std::strtod(argv[i + 1], nullptr);
  }
  priceRate_tmp = FuzzyPrice(parameter[0], parameter[1], parameter[2], parameter[3], parameter[4], parameter[5], parameter[6], parameter[7]);

  // Terminate the application.
  // You do not need to do this more than one time.
  std::cout<<priceRate_tmp<< std::endl;

  return 0;
}

//
// Arguments    : void
// Return Type  : void
//


//
// File trailer for main.cpp
//
// [EOF]
//
