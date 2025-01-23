#include <iostream>
#include <cstring>
#include <utility>
using namespace std;

int main() {
    string str = "hello";
    int start = 0;
    int end = str.length() - 1;
    while(start < end) {
        swap(str[start++], str[end--]);
    }
    cout<<str;
    return 0;
}