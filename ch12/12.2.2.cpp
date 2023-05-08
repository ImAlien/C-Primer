#include <bits/stdc++.h>

using namespace std;



void test2(){
    allocator<string> a;
    cout << "test2 begin" << endl;
    vector<string> data = {"1","2","3","4","5"};
   auto p = a.allocate(data.size() * 2);

   auto q = uninitialized_copy(data.begin(), data.end(), p);

   uninitialized_fill(q, q+5, "fill");

    for(auto i = p; i < (p + data.size() * 2); i ++){
        cout << *i << endl;
    }
}
int main()
{
   
   allocator<string> a;
   string* p = a.allocate(5);
   string *q = p;
   a.construct(q++, 10, 'c');
   a.construct(q++);
   a.construct(q++, "test");
   cout << *(p+2) << endl;
   while(q != p) a.destroy(--q);
   a.deallocate(p, 5);


   test2();
   system("pause");
   return 0;
}
