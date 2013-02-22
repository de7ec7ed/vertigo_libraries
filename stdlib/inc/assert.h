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

#ifndef __ASSERT_H__
#define __ASSERT_H__

// DBG_LOG_STATEMENT is located in gen.h under dbglib
#ifndef DBG_LOG_STATEMENT
#define DBG_LOG_STATEMENT(a, b, c, d)
#endif //DBG_LOG_STATEMENT

#define ASSERT(a, b, c, d, e, f) \
	if(!(a)) { DBG_LOG_STATEMENT(c, d, e, f); goto b; }

#define ASSERT_NOT_NULL(a, b, c, d, e, f) \
	if((void *)a == NULL) { DBG_LOG_STATEMENT(c, d, e, f); goto b; }

#define ASSERT_NULL(a, b, c, d, e, f) \
		if((void *)a != NULL) { DBG_LOG_STATEMENT(c, d, e, f); goto b; }

#define ASSERT_SUCCESS(a, b, c, d, e, f) \
		if((size_t)a != SUCCESS) { DBG_LOG_STATEMENT(c, d, e, f); goto b; }

#define ASSERT_FAILURE(a, b, c, d, e, f) \
		if((size_t)a != FAILURE) { DBG_LOG_STATEMENT(c, d, e, f); goto b; }

#define ASSERT_TRUE(a, b, c, d, e, f) \
		if((size_t)a == FALSE) { DBG_LOG_STATEMENT(c, d, e, f); goto b; }

#define ASSERT_FALSE(a, b, c, d, e, f) \
		if((size_t)a != FALSE) { DBG_LOG_STATEMENT(c, d, e, f); goto b; }

#define ASSERT_EQUAL(a, b, c, d, e, f, g) \
		if((size_t)a != (size_t)b) { DBG_LOG_STATEMENT(d, e, f, g); goto c; }

#define ASSERT_NOT_EQUAL(a, b, c, d, e, f, g) \
		if((size_t)a == (size_t)b) { DBG_LOG_STATEMENT(d, e, f, g); goto c; }

#endif //__ASSERT_H__
