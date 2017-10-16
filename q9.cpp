/*
 * File name: q9.cpp
 * author: wrscode
 */

#include <iostream>
#include <string>
#include <array>

using namespace std;

std::string func(const std::string& InText) {

    std::array<bool, 256> SawChar;
    std::string OutText;

    SawChar.fill(false);

    for (auto it = InText.begin(); it != InText.end(); ++it) {

        if(!SawChar[*it]){
            OutText.push_back(*it);
            SawChar[*it] = true;
        }
    }

    return OutText;
}

int main() {
    cout << func("CCABCOBDDD") << endl;
    return 0;
}
