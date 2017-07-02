/*
 * File name: bigLittleEndian.cpp
 * Created on: Jul 2, 2017
 */

#include <iostream>

using namespace std;

int main() {

    char cT[2] = {(char)0x00, (char)0xFF};
    unsigned short *pST = reinterpret_cast<unsigned short *>(cT);


    if((*pST) == static_cast<unsigned short>(0xFF00)){
        std::cout << "little endian\n" << std::endl;
    }else{
        std::cout << "big endian\n" << std::endl;
    }

    return 0;
}
