#include <iostream>
#include <string>
using namespace std;

int a[100];

int main(){

    cout << &a[0] <<'\n';
    cout << &a[1] <<'\n';

    cout << &a[0] + 1 << '\n';

    return 0;
}