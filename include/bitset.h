/*
 * bitset.h
 *
 *  Created on: Jan 7, 2019
 *      Author: bulkodaw
 */

#ifndef INCLUDE_BITSET_H_
#define INCLUDE_BITSET_H_

/* Includes ---------------------------------------------------------*/
#include <inttypes.h>
#include <stdbool.h>
/* Macros ---------------------------------------------------------*/
#define BIT(k) (1U << (unsigned)(k))
#define GET_BIT(n, k) (((n) & (typeof(n))(BIT(k))) >> (typeof(n))k)
#define SET_BIT(n, k)   ((n) |= ((typeof(n))BIT(k)))
#define CLEAR_BIT(n, k) ((n) &= ((typeof(n))~BIT(k)))

#define SET_BIT_VALUE(n, k, val)	\
	if((val)) 						\
		SET_BIT(n, k); 				\
	else 							\
		CLEAR_BIT(n, k);			\

/* Enums ---------------------------------------------------------*/

/* Struct and Union ---------------------------------------------------------*/
typedef struct bitmap
{
	uint32_t bitLen;
	uint32_t size;
	uint8_t* arr;
}bitmapS;

/* Functions ---------------------------------------------------------*/
void bitmap_Init(bitmapS* bitmapa, const uint32_t n);
void bitmap_Setbit(bitmapS* bitmapa, uint32_t index, bool value);
int bitmap_Getbit(bitmapS* bitmapa, uint32_t index);
int bitmap_Clearbit(bitmapS* bitmapa, uint32_t index);

unsigned getbits(unsigned variableX, unsigned position, unsigned ammountOfBits);
unsigned setbits(unsigned variableX, unsigned position, unsigned ammountOfBits, unsigned variableY);

#endif /* INCLUDE_BITSET_H_ */
