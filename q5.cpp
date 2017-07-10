#include <iostream>

using namespace std;

int x = 0;


struct A{

    A(){
        cout << "A" << endl;
        
        if(x++ == 0){
            throw exception();
        }
    }
    
    ~A(){
        cout << "~A" << endl;
    }
};

struct B{
    
    B(){
        cout << "B" << endl;
    }

    ~B(){
        cout << "~B" << endl;
    }
    
    A a;
};


void foo(){
    static B b;
}

int main(){  
    try{
        foo();
    }catch(exception &e){
        cout << "e" << endl;
        foo();
    }
}