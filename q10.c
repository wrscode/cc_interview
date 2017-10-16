/*
 * File name: q10.cpp
 * author: wrscode
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

    char buff[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77};

    char*  pChar  = buff;
    short* pShort = (short*)buff;
    int*   pInt   = (int* )buff;

    printf("*pChar:  %8x\n",  *pChar);
    printf("*pShort: %8x\n", *pShort);
    printf("*pInt:   %8x\n",   *pInt);

    pChar++;
    (*pShort)++;
    *(pInt++);

    printf("*pChar:  %8x\n",  *pChar);
    printf("*pShort: %8x\n", *pShort);
    printf("*pInt:   %8x\n",   *pInt);

	return EXIT_SUCCESS;
}
