/* This file is part of VERTIGO.
 *
 * (C) Copyright 2013, Siege Technologies <siegetechnologies.com>
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

#ifndef __STRING_H__
#define __STRING_H__

extern void * memcpy(void *destination, const void *source, size_t size);

extern void * memset(void *pointer, size_t value, size_t size);

extern size_t strlen(const char *str);

extern int memcmp(const void * str1, const void * str2, size_t count);

extern void reverse(char *s);

extern void itoa(int value, char *string, int radix);

extern int atoi(char *s);

extern int isspace(int c);

extern int isdigit(int c);

#endif //__STRING_H__
