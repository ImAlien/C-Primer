#include <bits/stdc++.h>

using namespace std;

class B{
    public:
        virtual int f1();
};

class D1:public B{

    public:
        int f1(int);
        virtual void f2();
};

class D2:public D1{

    public: 
        int f1(int);
        int f1();
        void f2();
};


int main()
{
  B b; D1 d1; D2 d2;
   B* pb = &b, *pd1 = &d1, *pd2 = &d2;
    pb->f1();
    pd1->f1();
    // error pd1->f1(42);
    pd2->f1();

    dynamic_cast<D2*>(pd2)->f1(23);

    D1* pd11 = &d1;
    //pd11->f1(); error;

   system("pause");
   return 0;
}
