/*
 * bitset.c
 *
 *  Created on: Jan 7, 2019
 *      Author: bulkodaw
 */

#include "../include/bitset.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

void bitmap_Init(bitmapS* bitmapa, const uint32_t n)
{
	bitmapa->bitLen = n;
	bitmapa->size = n / CHAR_BIT;
	bitmapa->arr = malloc(sizeof(*bitmapa->arr) * (bitmapa->size + 1));
	if(bitmapa->arr == NULL)
	{
		perror("Uninitialized array!");
		return;
	}
}

void bitmap_Setbit(bitmapS* bitmapa, uint32_t index, bool value)
{
	if(bitmapa->arr == NULL)
	{
		perror("Uninitialized array!");
		return;
	}
	if(index >= bitmapa->bitLen)
	{
		perror("Index is higher than amount of bits in array");
		return;
	}
	SET_BIT_VALUE(bitmapa->arr[index / CHAR_BIT], index % CHAR_BIT, value);
}

int bitmap_Getbit(bitmapS* bitmapa, uint32_t index)
{
	if(bitmapa->arr == NULL)
	{
		perror("Uninitialized array!");
		return -1;
	}
	if(index >= bitmapa->bitLen)
	{
		perror("Index is higher than amount of bits in array");
		return -1;
	}
	return GET_BIT(bitmapa->arr[index / CHAR_BIT], index % CHAR_BIT);
}

int bitmap_Clearbit(bitmapS* bitmapa, uint32_t index)
{
	if(index >= bitmapa->bitLen)
	{
		perror("Index is higher than amount of bits in array");
		return -1;
	}
	return CLEAR_BIT(bitmapa->arr[index / CHAR_BIT], index % CHAR_BIT);
}
/* ~(~0 << n)) - create mask. Work the same way as (1 << n) -1 */
unsigned getbits(unsigned variableX, unsigned position, unsigned ammountOfBits)
{
	if(ammountOfBits > position || ammountOfBits > sizeof(variableX) * CHAR_BIT)
	{
		perror("Beyond the limit of bits in variable");
		return UINT32_MAX;
	}
		return ((variableX >> (position + 1 - ammountOfBits)) & ((1u << ammountOfBits) - 1u));
}

unsigned setbits(unsigned variableX, unsigned position, unsigned ammountOfBits, unsigned variableY)
{
	if(ammountOfBits > position || ammountOfBits > sizeof(variableX) * CHAR_BIT)
	{
		perror("Beyond the limit of bits in variable");
		return UINT32_MAX;
	}
	return (variableX & ~(~((1u << ammountOfBits) - 1u) << (position + 1u - ammountOfBits))) |
			(variableY & ((1u << ammountOfBits) - 1u)) << (position + 1u - ammountOfBits);
}
