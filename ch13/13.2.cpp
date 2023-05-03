#include <bits/stdc++.h>

using namespace std;

class HasPtr{

    public:
    HasPtr(const string&s = string()):ps(new string(s)),i(0){};
    HasPtr(const HasPtr& p):
    ps(new string(*p.ps)),i(p.i){};
    HasPtr& operator = (const HasPtr&);
    private:
    string *ps;
    int i;
};

HasPtr& 
HasPtr::operator=(const HasPtr& other){
    auto newp = new string(*other.ps);
    delete ps;// free old memory;

    ps = newp;

    i = other.i;
    
    return *this;

}

int main()
{
   
   system("pause");
   return 0;
}
