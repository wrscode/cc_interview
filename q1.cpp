#include <iostream>

using namespace std;


struct GeneralException{
    virtual void print() { cout << "G"; };
};

struct SpecificException : public GeneralException{
    virtual void print() { cout << "S"; };
};

void func(){
    throw SpecificException();
}

int main(){
  
    try{
        func();
    }catch(GeneralException e){
//    }catch(GeneralException &e){
//    }catch(GeneralException *e){
            e.print();
    }
    
    return 0;
}