/* if an error occurr hex_to_binary() return false and the dst content is undefined */

#include "char2hex.h"
#include <stdint.h>

// bool binary_to_hex(void *dst, const char *src, size_t src_len, bool uppercase) {
#if 0
bool binary_to_hex(void *dst, const char *src, size_t src_len, bool use_uppercase) {

	/* lookup table */
	static const char b16_uppercase[] = "0123456789ABCDEF";
	static const char b16_lowercase[] = "0123456789abcdef";

	register const char *const b16 = use_uppercase ? b16_uppercase : b16_lowercase;

	for (size_t i = 0; i < src_len; i++, dst += 2) {

		uint8_t ch = src[i];
		*((char *)dst)   = b16[ ch/16 %16 ];
		*((char *)dst+1) = b16[ ch%16 ];
	}

	return true;
}
#endif

// (0..20).each {|i| p i % 16 === i & 15 }
bool binary_to_hex(void *dst, const char *src, size_t src_len, bool use_uppercase) {

	/* lookup table */
	static const char b16_uppercase[] = "0123456789ABCDEF";
	static const char b16_lowercase[] = "0123456789abcdef";

	register const char *const b16 = use_uppercase ? b16_uppercase : b16_lowercase;
    	register char *out = (char *)dst;

	for (size_t i = 0; i < src_len; i++, out += 2) {
		uint8_t ch = src[i];
		out[0] = b16[ ch >> 4 ];
		out[1] = b16[ ch & 15 ];
	}

	return true;
}
