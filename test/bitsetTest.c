/*
 * bitsetTest.c
 *
 *  Created on: Jan 7, 2019
 *      Author: bulkodaw
 */
#include "../include/bitset.h"
#include <criterion/criterion.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <limits.h>
#include <math.h>

Test(BIT, BIT_MOVE_BY_SHIFT)
{
	for (uint8_t var = 0; var < sizeof(uint32_t) * CHAR_BIT; ++var)
	{
		cr_expect_eq(BIT(var), pow(2,var), "This function fail.");
	}
}

Test(BIT, GET_BIT)
{
	/*Create uint16_t variable */
	uint16_t varTest = 23198;
	/*Binary value of 23198 = 0101 1010 1001 1110*/
	uint16_t varTestArray[sizeof(uint16_t) * CHAR_BIT];
	varTestArray[0] = 0;
	varTestArray[1] = 1;
	varTestArray[2] = 1;
	varTestArray[3] = 1;
	varTestArray[4] = 1;
	varTestArray[5] = 0;
	varTestArray[6] = 0;
	varTestArray[7] = 1;
	varTestArray[8] = 0;
	varTestArray[9] = 1;
	varTestArray[10] = 0;
	varTestArray[11] = 1;
	varTestArray[12] = 1;
	varTestArray[13] = 0;
	varTestArray[14] = 1;
	varTestArray[15] = 0;

	for (uint8_t var = 0; var < sizeof(uint16_t) * CHAR_BIT; ++var)
	{
		cr_expect_eq(GET_BIT(varTest, var), varTestArray[var], "This function fail in %d round.", var);
	}
}

Test(BIT, SET_BIT)
{
	/*Create uint16_t variable */
	unsigned varTest = 23198;
	/*Binary value of 23198 = 0101 1010 1001 1110*/

	const unsigned expectedValueAfterSetBitArray[sizeof(uint16_t) * CHAR_BIT] = {23199, 23199, 23199,
			23199, 23199, 23231, 23295, 23295, 23551, 23551, 24575, 24575, 24575, 32767, 32767,
			65535};
	for (uint8_t var = 0; var < sizeof(uint16_t) * CHAR_BIT; ++var)
	{
		cr_expect_eq(SET_BIT(varTest, var), expectedValueAfterSetBitArray[var], "This function fail in %d round.", var);
	}
}

Test(BIT, CLEAR_BIT)
{
	unsigned varTest = 23198;
	/*Binary value of 23198 = 0101 1010 1001 1110*/

	const unsigned expectedValueAfterSetBitArray[sizeof(uint16_t) * CHAR_BIT] = {23198, 23196, 23192,
			23184, 23168, 23168, 23168, 23040, 23040, 22528, 22528, 20480, 16384, 16384, 0,
			0};
	for (uint8_t var = 0; var < sizeof(uint16_t) * CHAR_BIT; ++var)
	{
		cr_expect_eq(CLEAR_BIT(varTest, var), expectedValueAfterSetBitArray[var], "This function fail in %d round.", var);
	}
}

Test(BIT, SET_BIT_VALUE_0)
{
	unsigned varTest = 23198;
	/*Binary value of 23198 = 0101 1010 1001 1110*/

	const unsigned expectedValueAfterSetBitArray_0[sizeof(uint16_t) * CHAR_BIT] = {23198, 23196, 23192,
			23184, 23168, 23168, 23168, 23040, 23040, 22528, 22528, 20480, 16384, 16384, 0,
			0};

	for (uint8_t var = 0; var < sizeof(uint16_t) * CHAR_BIT; ++var)
	{
		SET_BIT_VALUE(varTest, var, 0);
		cr_expect_eq(varTest, expectedValueAfterSetBitArray_0[var], "SET_BIT_VALUE for 0 function fail in %d round.", var);
	}

	varTest = 23198;
	const unsigned expectedValueAfterSetBitArray_1[sizeof(uint16_t) * CHAR_BIT] = {23199, 23199, 23199,
			23199, 23199, 23231, 23295, 23295, 23551, 23551, 24575, 24575, 24575, 32767, 32767,
			65535};
	for (uint8_t var = 0; var < sizeof(uint16_t) * CHAR_BIT; ++var)
	{
		SET_BIT_VALUE(varTest, var, 1);
		cr_expect_eq(varTest, expectedValueAfterSetBitArray_1[var], "SET_BIT_VALUE for 1 function fail in %d round.", var);
	}
}

Test(BIT, BITMAP_INIT)
{
	bitmapS test;
	for (uint32_t counter = 0; counter < UINT16_MAX; counter++)
	{
		uint32_t size = counter / CHAR_BIT;
		bitmap_Init(&test, counter);
		cr_expect_eq(test.bitLen, counter, "test.bitLen fail in %u round.", counter);
		cr_expect_eq(test.size, size, "test.size fail in %u round.", counter);
	}
}

Test(BIT, BITMAP_SETBIT)
{
	bitmapS test;
	uint32_t size = 0;
	bitmap_Init(&test, UINT16_MAX);
	const unsigned expectedValueAfterSetBitArray[CHAR_BIT] = {1, 3, 7, 15, 31, 63, 127, 255 };
	for (uint32_t counter = 0; counter < UINT16_MAX; counter++)
	{
		bitmap_Setbit(&test, counter, true);
		if(counter % CHAR_BIT == 0 && counter != 0)
			size++;
		cr_expect_eq(test.arr[size], expectedValueAfterSetBitArray[counter % CHAR_BIT], "test.arr[size] fail in %u round.", counter);
	}
}

Test(BIT, BITMAP_GETBIT)
{
	bitmapS test;
	bitmap_Init(&test, UINT16_MAX);
	for (uint32_t counter = 0; counter < UINT16_MAX; counter++)
	{
		if(counter & 0x01)
			bitmap_Setbit(&test, counter, true);
		else
			bitmap_Setbit(&test, counter, false);
	}
	for (uint32_t counter = 0; counter < UINT16_MAX; counter++)
	{
		if(counter & 0x01)
			cr_expect_eq(bitmap_Getbit(&test, counter), true, "test.arr[size] fail in %u round.", counter);
		else
			cr_expect_eq(bitmap_Getbit(&test, counter), false, "test.arr[size] fail in %u round.", counter);
	}
}

Test(BIT, getbits)
{
}

Test(BIT, setbits)
{
}
