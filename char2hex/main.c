#include "char2hex.c"
#include <stdio.h>

int main() {

	char *src = "\x00\x1b";
	char dst[100] = {0};

	binary_to_hex(dst, src, 2, true);
	printf("%s\n", dst);

	return 0;
}
