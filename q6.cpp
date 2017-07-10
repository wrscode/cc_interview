#include <iostream>
#include <utility>

using namespace std;

int y(int& x) {
    return 1;
}

int y(int&& x) {
    return 2;
}

template<class T>
int f(T&& t) {
    return(y(t));
}

template<class T>
int g(T&& t) {
    return(y(std::move(t))); 
}

template<class T>
int h(T&& t) {
    return(y(std::forward<T>(t)));
}

int main(){
  
    int i = 10;
    
    cout << f(i) << " - " << f(20) << endl;
    cout << g(i) << " - " << g(20) << endl;
    cout << h(i) << " - " << h(20) << endl;
   
    return 0;    
}