#include <bits/stdc++.h>

using namespace std;

int main(){
    int* p = new int(45);
    int* q = p;
    delete p;
     delete q;
}