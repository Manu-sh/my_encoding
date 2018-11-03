#include "hex2char.h"
#include <stdint.h>

/* if an error occurr hex_to_binary() return false and the dst content is undefined (memory can overlap) */
bool hex_to_binary(void *dst, const char *src, size_t src_len) {

	/* 256 to avoid overflow with things like: "\xf\xf" */

#define EHEX -241
	static const int16_t tab[256] = {

		[  0] = EHEX,	[  1] = EHEX,	[  2] = EHEX,	[  3] = EHEX,
		[  4] = EHEX,	[  5] = EHEX,	[  6] = EHEX,	[  7] = EHEX,
		[  8] = EHEX,	[  9] = EHEX,	[ 10] = EHEX,	[ 11] = EHEX,
		[ 12] = EHEX,	[ 13] = EHEX,	[ 14] = EHEX,	[ 15] = EHEX,
		[ 16] = EHEX,	[ 17] = EHEX,	[ 18] = EHEX,	[ 19] = EHEX,
		[ 20] = EHEX,	[ 21] = EHEX,	[ 22] = EHEX,	[ 23] = EHEX,
		[ 24] = EHEX,	[ 25] = EHEX,	[ 26] = EHEX,	[ 27] = EHEX,
		[ 28] = EHEX,	[ 29] = EHEX,	[ 30] = EHEX,	[ 31] = EHEX,
		[ 32] = EHEX,	[ 33] = EHEX,	[ 34] = EHEX,	[ 35] = EHEX,
		[ 36] = EHEX,	[ 37] = EHEX,	[ 38] = EHEX,	[ 39] = EHEX,
		[ 40] = EHEX,	[ 41] = EHEX,	[ 42] = EHEX,	[ 43] = EHEX,
		[ 44] = EHEX,	[ 45] = EHEX,	[ 46] = EHEX,	[ 47] = EHEX,
		['0'] =    0,	['1'] =    1,	['2'] =    2,	['3'] =    3,
		['4'] =    4,	['5'] =    5,	['6'] =    6,	['7'] =    7,
		['8'] =    8,	['9'] =    9,	[ 58] = EHEX,	[ 59] = EHEX,
		[ 60] = EHEX,	[ 61] = EHEX,	[ 62] = EHEX,	[ 63] = EHEX,
		[ 64] = EHEX,	['A'] =   10,	['B'] =   11,	['C'] =   12,
		['D'] =   13,	['E'] =   14,	['F'] =   15,	[ 71] = EHEX,
		[ 72] = EHEX,	[ 73] = EHEX,	[ 74] = EHEX,	[ 75] = EHEX,
		[ 76] = EHEX,	[ 77] = EHEX,	[ 78] = EHEX,	[ 79] = EHEX,
		[ 80] = EHEX,	[ 81] = EHEX,	[ 82] = EHEX,	[ 83] = EHEX,
		[ 84] = EHEX,	[ 85] = EHEX,	[ 86] = EHEX,	[ 87] = EHEX,
		[ 88] = EHEX,	[ 89] = EHEX,	[ 90] = EHEX,	[ 91] = EHEX,
		[ 92] = EHEX,	[ 93] = EHEX,	[ 94] = EHEX,	[ 95] = EHEX,
		[ 96] = EHEX,	['a'] =   10,	['b'] =   11,	['c'] =   12,
		['d'] =   13,	['e'] =   14,	['f'] =   15,	[103] = EHEX,
		[104] = EHEX,	[105] = EHEX,	[106] = EHEX,	[107] = EHEX,
		[108] = EHEX,	[109] = EHEX,	[110] = EHEX,	[111] = EHEX,
		[112] = EHEX,	[113] = EHEX,	[114] = EHEX,	[115] = EHEX,
		[116] = EHEX,	[117] = EHEX,	[118] = EHEX,	[119] = EHEX,
		[120] = EHEX,	[121] = EHEX,	[122] = EHEX,	[123] = EHEX,
		[124] = EHEX,	[125] = EHEX,	[126] = EHEX,	[127] = EHEX,
		[128] = EHEX,	[129] = EHEX,	[130] = EHEX,	[131] = EHEX,
		[132] = EHEX,	[133] = EHEX,	[134] = EHEX,	[135] = EHEX,
		[136] = EHEX,	[137] = EHEX,	[138] = EHEX,	[139] = EHEX,
		[140] = EHEX,	[141] = EHEX,	[142] = EHEX,	[143] = EHEX,
		[144] = EHEX,	[145] = EHEX,	[146] = EHEX,	[147] = EHEX,
		[148] = EHEX,	[149] = EHEX,	[150] = EHEX,	[151] = EHEX,
		[152] = EHEX,	[153] = EHEX,	[154] = EHEX,	[155] = EHEX,
		[156] = EHEX,	[157] = EHEX,	[158] = EHEX,	[159] = EHEX,
		[160] = EHEX,	[161] = EHEX,	[162] = EHEX,	[163] = EHEX,
		[164] = EHEX,	[165] = EHEX,	[166] = EHEX,	[167] = EHEX,
		[168] = EHEX,	[169] = EHEX,	[170] = EHEX,	[171] = EHEX,
		[172] = EHEX,	[173] = EHEX,	[174] = EHEX,	[175] = EHEX,
		[176] = EHEX,	[177] = EHEX,	[178] = EHEX,	[179] = EHEX,
		[180] = EHEX,	[181] = EHEX,	[182] = EHEX,	[183] = EHEX,
		[184] = EHEX,	[185] = EHEX,	[186] = EHEX,	[187] = EHEX,
		[188] = EHEX,	[189] = EHEX,	[190] = EHEX,	[191] = EHEX,
		[192] = EHEX,	[193] = EHEX,	[194] = EHEX,	[195] = EHEX,
		[196] = EHEX,	[197] = EHEX,	[198] = EHEX,	[199] = EHEX,
		[200] = EHEX,	[201] = EHEX,	[202] = EHEX,	[203] = EHEX,
		[204] = EHEX,	[205] = EHEX,	[206] = EHEX,	[207] = EHEX,
		[208] = EHEX,	[209] = EHEX,	[210] = EHEX,	[211] = EHEX,
		[212] = EHEX,	[213] = EHEX,	[214] = EHEX,	[215] = EHEX,
		[216] = EHEX,	[217] = EHEX,	[218] = EHEX,	[219] = EHEX,
		[220] = EHEX,	[221] = EHEX,	[222] = EHEX,	[223] = EHEX,
		[224] = EHEX,	[225] = EHEX,	[226] = EHEX,	[227] = EHEX,
		[228] = EHEX,	[229] = EHEX,	[230] = EHEX,	[231] = EHEX,
		[232] = EHEX,	[233] = EHEX,	[234] = EHEX,	[235] = EHEX,
		[236] = EHEX,	[237] = EHEX,	[238] = EHEX,	[239] = EHEX,
		[240] = EHEX,	[241] = EHEX,	[242] = EHEX,	[243] = EHEX,
		[244] = EHEX,	[245] = EHEX,	[246] = EHEX,	[247] = EHEX,
		[248] = EHEX,	[249] = EHEX,	[250] = EHEX,	[251] = EHEX,
		[252] = EHEX,	[253] = EHEX,	[254] = EHEX,	[255] = EHEX

	};
#undef EHEX

	if (src_len == 0 || src_len%2 != 0)
		return false;

	/* TODO si può migliorare ulteriormente usando un valore sentinella (EHEX) posto in src_len-2 visto che si avanza di i += 2
        ma una soluzione di questo tipo impedisce di continuare a usare const char * visto che si deve modificare l'ultimo
        carattere */

	for (size_t i = 0; i < src_len; i += 2) {
		int16_t ch = (tab[((const uint8_t *)src)[i]] << 4) + tab[((const uint8_t *)src)[i+1]];
		if (ch < 0) return false;
		((uint8_t *)dst)[i/2] = (uint8_t)ch;
	}

	return true;
}
