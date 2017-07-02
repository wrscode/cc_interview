/*
 *  File name deadlock.cpp
 *  Created on: Jul 2, 2017
 *
 *  g++ -std=c++0x -o deadlock deadlock.cpp -lpthread
 */

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtA;
mutex mtB;

void funcA(){
    cout << "funcA: lock mtA" << endl;
    mtA.lock();

    cout << "funcA: lock mtB" << endl;
    mtB.lock();

    cout << "funcA: lock mtB" << endl;
    mtB.unlock();

    cout << "funcA: lock mtA" << endl;
    mtA.unlock();
}

void funcB(){
    cout << "funcB: lock mtA" << endl;
    mtB.lock();

    cout << "funcB: lock mtB" << endl;
    mtA.lock();

    cout << "funcB: lock mtB" << endl;
    mtA.unlock();

    cout << "funcB: lock mtA" << endl;
    mtB.unlock();
}

int main() {

    thread thA(funcA);
    thread thB(funcB);

    thA.join();
    thB.join();


	return 0;
}
