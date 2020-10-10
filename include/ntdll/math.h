#ifndef NTDLL_MATH_H
#define NTDLL_MATH_H

#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllimport) int abs(int i);
__declspec(dllimport) long labs(long n);
__declspec(dllimport) double atan(double d);
__declspec(dllimport) double ceil(double d);
__declspec(dllimport) double cos(double d);
__declspec(dllimport) double fabs(double d);
__declspec(dllimport) double floor(double d);
__declspec(dllimport) double log(double d);
__declspec(dllimport) double pow(double x, double y);
__declspec(dllimport) double sin(double d);
__declspec(dllimport) double sqrt(double d);
__declspec(dllimport) double tan(double d);

#ifdef __cplusplus
}
#endif

#endif
