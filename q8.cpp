//============================================================================
// Name        : cc_test.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <thread>
#include <sstream>
#include <vector>
#include <chrono>

using namespace std;


void foo(int num){

    this_thread::sleep_for(chrono::milliseconds(num));

    cout << num << endl;
}

int main() {

    std::vector<std::thread *> vth;

    std::vector<int> nums = {9,8,7,5,4,2,10};

    for(auto it = nums.begin(); it != nums.end(); ++it){
        vth.push_back(new std::thread(foo, *it));
    }

    for( auto ith = vth.begin(); ith != vth.end(); ++ith){
            (*ith)->join();
    }

	return 0;
}
