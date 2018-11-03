#ifndef __cplusplus
#include <stdbool.h>
#include <stddef.h>
#else
extern "C" {
#include <cstddef>
#endif

/* binary_to_hex() always return true, the size of dst is expected to be at least 2*src 
it dosn't add the null terminator obv */
bool binary_to_hex(void *dst, const char *src, size_t src_len, bool use_uppercase);

#ifdef __cplusplus
}  /* end of scope of extern "C" */
#endif
