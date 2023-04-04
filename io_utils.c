/*-
 * SPDX-License-Identifier: Unlicense
 *
 * This is free and unencumbered software released into the public domain.
 * 
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 * 
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 * 
 * For more information, please refer to <http://unlicense.org/>
 */

#include "io_utils.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Reallocate pointer to new location of specified size
 * @details
 * Memory is handled by caller
 * Address of pointer is swapped with a tmp pointer
 * @param ptr Address of pointer to reallocate
 * @param size Size of new address to allocate to
 */
static void self_realloc(void **ptr, size_t size);

static void
self_realloc(void **ptr, size_t size)
{
	void *res;

	res = realloc(*ptr, size);
	if (res == NULL)
		free(*ptr);

	*ptr = res;
}

char *
read_line(FILE *fp, size_t size)
{
	char *ret;
	size_t chunk, len;

	/* Start with a chunk of memory */
	chunk = size, len = 0;
	ret = malloc(chunk);
	if (ret == NULL)
		return NULL;

	/* Read until EOL or EOF */
	for (int ch; (ch = fgetc(fp)) != EOF && ch != '\n' && ch != '\r';
	    ret[len++] = ch) {
		/* Allocate more memory when needed */
		if (len == chunk) {
			/* Double each step for O(n) time */
			self_realloc((void **)&ret, chunk *= 2);
			if (ret == NULL)
				return NULL;
		}
	}
	ret[len++] = '\0';

	self_realloc((void **)&ret, len);
	return ret;
}
