#ifndef __cplusplus
#include <stdbool.h>
#include <stddef.h>
#else
extern "C" {
#include <cstddef>
#endif

/* if an error occurr hex_to_binary() return false and the dst content is undefined (memory can overlap) */
bool hex_to_binary(void *dst, const char *src, size_t src_len);

#ifdef __cplusplus
}  /* end of scope of extern "C" */
#endif
