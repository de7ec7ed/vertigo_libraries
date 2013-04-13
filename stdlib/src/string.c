#include <config.h>
#include <defines.h>
#include <types.h>
#include <stdlib/string.h>

void * memcpy(void *destination, const void *source, size_t size) {

        u8_t *src;
        u8_t *dst;

        size_t i;

        src = (u8_t *)source;
        dst = (u8_t *)destination;

        for(i = 0; i < size; i++) {
                dst[i] = src[i];
        }

        return destination;
}

void * memset(void *pointer, size_t value, size_t size) {

        size_t i;
        u8_t *ptr;

        ptr = pointer;

        for(i = 0; i < size; i++) {
                ptr[i] = value;
        }

        return pointer;
}

int memcmp(const void * str1, const void * str2, size_t count) {

	register const unsigned char *s1 = (const unsigned char*)str1;
	register const unsigned char *s2 = (const unsigned char*)str2;

	while (count-- > 0) {
		if (*s1++ != *s2++) {
			return s1[-1] < s2[-1] ? -1 : 1;
		}
	}

  return 0;
}

size_t strlen(const char *str) {
	register const char *s;

	for (s = str; *s; ++s);
	return(s - str);
}

char * strcat(char *dest, const char *src) {
	char *ret = dest;

	for (; *dest; ++dest);

	while ((*dest++ = *src++) != '\0');

	return ret;
}

char * strncat(char *dest, const char *src, size_t n) {
    size_t dest_len = strlen(dest);
    size_t i;

    for (i = 0 ; i < n && src[i] != '\0' ; i++) {
    	dest[dest_len + i] = src[i];
    }

    dest[dest_len + i] = '\0';

    return dest;
}

char * strcpy(char *dest, const char *src) {
    char *s = dest;

    while ((*s++ = *src++) != 0);

    return (dest);
}

char * strncpy(char *dest, const char *src, size_t n) {
    size_t i;

    for(i = 0; i < n && src[i] != '\0'; i++) {
    	dest[i] = src[i];
    }

    for ( ; i < n; i++) {
    	dest[i] = '\0';
    }

    return dest;
}

void reverse(char *s) {
	char *j;
	int c;

	j = s + strlen(s) - 1;
	while(s < j) {
		c = *s;
		*s++ = *j;
		*j-- = c;
	}

	return;
}

void ltoa(long value, char *string, int radix) {
	char tmp[33];
	char *tp = tmp;
	int i;
	unsigned long v;
	int sign;
	char *sp;

	if (radix > 36 || radix <= 1) {
		return;
	}

	sign = (radix == 10 && value < 0);
	if (sign) {
		v = -value;
	}
	else {
		v = (unsigned long)value;
	}

	while (v || tp == tmp) {
		i = v % radix;
		v = v / radix;
		if (i < 10) {
			*tp++ = i + '0';
		}
		else {
			*tp++ = i + 'a' - 10;
		}
	}

	if (string == NULL) {
		return;
	}
	sp = string;

	if (sign) {
		*sp++ = '-';
	}
	while (tp > tmp) {
		*sp++ = *--tp;
	}

	*sp = 0;

	return;
}

void itoa(int value, char *string, int radix) {
	char tmp[33];
	char *tp = tmp;
	int i;
	unsigned v;
	int sign;
	char *sp;

	if (radix > 36 || radix <= 1) {
		return;
	}

	sign = (radix == 10 && value < 0);
	if (sign) {
		v = -value;
	}
	else {
		v = (unsigned)value;
	}
	while (v || tp == tmp) {
		i = v % radix;
		v = v / radix;
		if (i < 10) {
			*tp++ = i+'0';
		}
		else {
			*tp++ = i + 'a' - 10;
		}
	}

	if (string == NULL) {
		return;
	}
	sp = string;

	if (sign) {
		*sp++ = '-';
	}
	while (tp > tmp) {
		*sp++ = *--tp;
	}

	*sp = 0;

	return;
}

int atoi(char *s) {
	int sign, n;

	while(isspace(*s)) {
		++s;
	}

	sign = 1;

	if(*s == '-') {
		sign = -1;
	}
	else if(*s == '+') {
		++s;
	}

	n = 0;

	while(isdigit(*s)) {
		n = 10 * n + *s++ - '0';
	}

	return (sign * n);
}

int isspace(int c) {
	return (c <= ' ' && (c == ' ' || (c <= 13 && c >= 9)));
}

int isdigit(int c) {
	return (c<='9' && c>='0');
}
