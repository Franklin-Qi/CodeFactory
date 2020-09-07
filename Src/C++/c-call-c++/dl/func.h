#ifndef CPPFUNCTIONS_H_
#define CPPFUNCTIONS_H_

#ifdef __cplusplus

int cpp_func(int input);

extern "C" {
#endif

int c_func(int input);

#ifdef __cplusplus
}
#endif
#endif /* CPPFUNCTIONS_H_ */
