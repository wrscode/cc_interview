#include <iostream>

using namespace std;


struct A{
   
    A(){
        cout << "A" << endl;
        foo();
    }

    ~A(){
        cout << "~A" << endl;
    }    
    
    virtual void foo(){
        cout << "A::foo" << endl;
    }
    
};

struct B : public A{
    B(){
        cout << "B" << endl;
    }

    ~B(){
        cout << "~B" << endl;
    }    
    
    virtual void foo(){
        cout << "B::foo" << endl;
    }
};

int main(){
  
    A *b = new B;
    b->foo();
    
    return 0;
}