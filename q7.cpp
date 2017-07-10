#include <iostream>

using namespace std;

struct A{
    virtual void foo(int a = 10){
        cout << a << endl;
    }
    
};

struct B : public A{
    virtual void foo(int a = 20){
        cout << a << endl;
    }    
};

int main(){
    A *b = new B;
    b->foo();
}
