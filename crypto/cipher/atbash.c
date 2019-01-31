#include <string.h>

#include "../append/macro/consts.h"
#include "../append/types/char.h"

static uchar_t __alpha_atbash[MAX_LENGTH] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
static uchar_t __length_alpha_atbash = LEN_ALPHA;

static uchar_t _char_atbash (const uchar_t ch) {
	for (uchar_t *p = __alpha_atbash; *p != END_OF_STRING; ++p)
		if (*p == ch)
			return __alpha_atbash[__length_alpha_atbash - 1 - (p - __alpha_atbash)];
		
	return ch;
}

extern char set_alpha_atbash (const uchar_t * const alpha) {
	const size_t length = strlen(alpha);

	if (length >= MAX_LENGTH)
		return 1;

	__length_alpha_atbash = (uchar_t)length;
	strcpy(__alpha_atbash, alpha);

	return 0;
}

extern char atbash (
	uchar_t * to, 
	const uchar_t * from
) {
	while (*from != END_OF_STRING)
		*to++ = _char_atbash(*from++);
	
	*to = END_OF_STRING;
	
	return 0;
}
