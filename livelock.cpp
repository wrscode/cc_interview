/*
 *  File name livelock.cpp
 *  Created on: Jul 2, 2017
 *
 *  g++ -std=c++0x -o livelock livelock.cpp -livelock
 */

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

class Spoon;

/* ----------------------------------------------------------------------------------------------------------------- */
class Diner{
public:

    Diner(string name);
    ~Diner();

    string &getName();
    bool isHungry();
    void eatWith(Spoon *spoon, Diner *spouse);

private:
    string name_;
    bool isHungry_;
};

/* ----------------------------------------------------------------------------------------------------------------- */
class Spoon{

public:
    Spoon(Diner *owner);
    ~Spoon();

    Diner *getOwner();
    void setOwner(Diner *owner); //s
    void use(); //s

private:
    Diner *owner_;
    mutex mt_;
};


Spoon::Spoon(Diner *owner): owner_(owner){
}

Spoon::~Spoon(){
}

Diner *Spoon::getOwner(){
    return owner_;
}

void Spoon::setOwner(Diner *owner){
    mt_.lock();
    owner_ = owner;
    mt_.unlock();

}

void Spoon::use(){
    mt_.lock();
    cout << owner_->getName() << "has eaten!" << endl;
    mt_.unlock();
}

/* ----------------------------------------------------------------------------------------------------------------- */
Diner::Diner(string name) : name_(name), isHungry_(true){
}

Diner::~Diner(){
}

string &Diner::getName(){
    return name_;
}

bool Diner::isHungry(){
    return isHungry_;
}

void Diner::eatWith(Spoon *spoon, Diner *spouse){

    while(isHungry_){
        // Don't have the spoon, so wait patiently for spouse.
        if(spoon->getOwner() != this){
            this_thread::sleep_for(chrono::milliseconds(1000));
            continue;
        }

        // If spouse is hungry, insist upon passing the spoon.
        if(spouse->isHungry()){
            cout << name_ << "\t: You eat first my darling " << spouse->getName() << endl;
            spoon->setOwner(spouse);
            continue;
        }

        // Spouse wasn't hungry, so finally eat
        spoon->use();
        isHungry_ = false;
        cout << name_ << "\t: I am stuffed, my darling " << spouse->getName() << endl;
        spoon->setOwner(spouse);
    }
}

/* ----------------------------------------------------------------------------------------------------------------- */
int main(){

    Diner *husband = new Diner("Bob");
    Diner *wife = new Diner("Alice");

    Spoon *sp = new Spoon(husband);

    thread th0(&Diner::eatWith, husband, sp, wife);
    thread th1(&Diner::eatWith, wife, sp, husband);

    th0.join();
    th1.join();

    return 0;
}
