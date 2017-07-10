#include <iostream>

using namespace std;


struct A{
   
    A(){
        cout << "A";
    }
};

struct B{
   
    B(){
        cout << "B";
    }
};

struct C{
   
    C(){
        cout << "C";
    }
};

struct D{
   
    D(){
        cout << "D";
    }
};

struct E : public D{
   
    E(){
        cout << "E";
    }
    
    A a;
    B b;
};

int main(){
  
    E e;
        
    return 0;
}