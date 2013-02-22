/* This file is part of VERTIGO.
 *
 * (C) Copyright 2013, Siege Technologies <http://www.siegetechnologies.com>
 *
 * VERTIGO is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * VERTIGO is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with VERTIGO. If not, see <http://www.gnu.org/licenses/>.
 *
 * Written by Kirk Swidowski <kirk@swidowski.com>
 */

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

size_t strlen(const char *str)
{
	register const char *s;

	for (s = str; *s; ++s);
	return(s - str);
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

// http://www.hackchina.com/en/r/60272/REVERSE.C__html
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


// http://www.hackchina.com/en/r/60272/ATOI.C__html
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

// http://www.hackchina.com/en/r/60272/ISSPACE.C__html
int isspace(int c) {
	return (c <= ' ' && (c == ' ' || (c <= 13 && c >= 9)));
}

// http://www.hackchina.com/en/r/60272/ISDIGIT.C__html
int isdigit(int c) {
	return (c<='9' && c>='0');
}
