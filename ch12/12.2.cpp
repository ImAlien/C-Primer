#include<bits/stdc++.h>

using namespace std;



int main(){
    int* p = new int[4]{0,1,2,3};
    cout <<  (*p) << *(p+1) << *(p+2) << *(p+3) << endl;
    cout << sizeof(p); 
    delete[] p;
}