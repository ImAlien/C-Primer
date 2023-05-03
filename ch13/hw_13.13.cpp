#include <bits/stdc++.h>

using namespace std;

struct X
{
    X() {cout << "X()" << endl;}
    X(const X&) {cout << "X(const X&)"<< endl;}
    X& operator=(const X&){cout << "X=" << endl;return *this;}
    ~X(){}

    /* data */
};

void f1(X x){
}

X f2(X& x){
    return x;
}

int main()
{
   cout << sizeof(X) << endl;
   X x1;
   X x2(x1);
   X x3 = x2;
   X x4;
   x4 = x3;
   
   f1(x2);

   X x5 = f2(x3);
   system("pause");
   return 0;
}
