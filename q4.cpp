#include <iostream>

using namespace std;

int main(){
  
    int x = 0;
    int a = 10;
    int b = 20;

    cout << "x: " << x << " a: " << a << " b: " << b << endl;
    
    x = a,b;
    
    cout << "x: " << x << " a: " << a << " b: " << b << endl;
    
    return 0;
}