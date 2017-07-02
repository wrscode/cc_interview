/*
 *  File name livelock.cpp
 *  Created on: Jul 2, 2017
 *
 *  g++ -std=c++0x -o threadsEditGlobalVariable threadsEditGlobalVariable.cpp -lpthread
 */

#include <iostream>
#include <thread>
#include <mutex>

#include <vector>
#include <string>

using namespace std;

const unsigned howManyThreads = 10;
const unsigned incLimit = 10000;

unsigned incGlobal = 0;

void funcWithoutMutex(){
    for (unsigned inc = 0; inc < incLimit; ++inc) {
        ++incGlobal;
    }
}

mutex mt;

void funcWithMutex(){
    for (unsigned inc = 0; inc < incLimit; ++inc) {
        mt.lock();
        ++incGlobal;
        mt.unlock();
    }
}

void benchmark(string message, void (*thFunc)()){

    vector<thread *>ths;

    incGlobal = 0;

    for(unsigned idx = 0 ; idx < howManyThreads; ++idx){
        ths.push_back(new thread(thFunc));
    }

    for(auto t : ths){
        t->join();
    }

    ths.clear();

    cout << message << " - supouse result: " << (howManyThreads * incLimit) << " calculete: " << incGlobal << endl;
}

int main(){
    benchmark("Run function without mutex", funcWithoutMutex);
    benchmark("Run function with mutex", funcWithMutex);
}














