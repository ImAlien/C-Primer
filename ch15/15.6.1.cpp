#include <bits/stdc++.h>

using namespace std;

struct  B
{
    B(): mem(0){};
    public:
    int mem;
    /* data */
};

struct D:B{
    D(int i):mem(i){};

    public:
        int mem;
};

int main()
{
   cout << sizeof(B) << endl;
   cout << sizeof(D) << endl;
   D d(2);
   cout << d.mem << d.B::mem << endl;
   
   system("pause");
   return 0;
}
