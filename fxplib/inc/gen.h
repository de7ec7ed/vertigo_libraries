#ifndef __FXPLIB_GEN_H__
#define __FXPLIB_GEN_H__

#ifdef __C__

extern void * gen_get_base();
extern void * gen_add_base(void *address);
extern void * gen_subtract_base(void *address);

#endif //__C__

#ifdef __ASSEMBLY__

.extern gen_get_base

#endif //__ASSEMBLY__

#endif //__FXPLIB_GEN_H__
