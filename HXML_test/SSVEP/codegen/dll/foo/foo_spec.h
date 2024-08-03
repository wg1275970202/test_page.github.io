//
// File: foo_spec.h
//
// MATLAB Coder version            : 23.2
// C/C++ source code generated on  : 03-Aug-2024 13:56:33
//

#ifndef FOO_SPEC_H
#define FOO_SPEC_H

// Include Files
#ifdef FOO_XIL_BUILD
#if defined(_WIN32) || defined(__LCC__)
#define FOO_DLL_EXPORT __declspec(dllimport)
#else
#define FOO_DLL_EXPORT __attribute__((visibility("default")))
#endif
#elif defined(BUILDING_FOO)
#if defined(_WIN32) || defined(__LCC__)
#define FOO_DLL_EXPORT __declspec(dllexport)
#else
#define FOO_DLL_EXPORT __attribute__((visibility("default")))
#endif
#else
#define FOO_DLL_EXPORT
#endif

#endif
//
// File trailer for foo_spec.h
//
// [EOF]
//
