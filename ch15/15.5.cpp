#include <bits/stdc++.h>

using namespace std;

class B{
    public:
    B() = default;
};

class D: private B{
    
    public:
    using B::B;

    D() = default;
};


int main()
{
    B b;
    D d;
    // error
    //B* p = &d;

   system("pause");
   return 0;
}
