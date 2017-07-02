/*
 *  File name livelock.cpp
 *  Created on: Jul 2, 2017
 *
 *  g++ -std=c++0x -o throwExecptionFromDestructor throwExecptionFromDestructor.cpp
 */

#include <iostream>

using namespace std;

class Dst{

public:
    Dst(){
        std::cout << "Dst()" << std::endl;
    }
    ~Dst(){
        std::cout << "~Dst()" << std::endl;
        throw std::runtime_error("Exception form ~Dst");
    }
};

int main(){

    cout << "can u see line: " << __LINE__ << endl;

    Dst *ptr = new Dst;

    cout << "can u see line: " << __LINE__ << endl;

    try{
        delete ptr;
//    }catch (std::runtime_error &e) {
    }catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    cout << "can u see line: " << __LINE__ << endl;


    return 0;
}
