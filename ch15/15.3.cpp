#include <bits/stdc++.h>

using namespace std;

struct B{
    virtual void f1(int) const;
    virtual void f2();
    void f3();
};

struct  D1 : B
{
    void f1(int) const override;
    //void f2(int) override;
    
    /* data */
};

struct D2:B{
    void f1(int) const final;
};

struct D3: D2{
    void f2();
    // error void f1(int) const;  

};


int main()
{
   
   system("pause");
   return 0;
}
