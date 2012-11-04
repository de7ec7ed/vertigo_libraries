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
