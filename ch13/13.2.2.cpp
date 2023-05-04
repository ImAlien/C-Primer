#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class HasPtr{
    public:
        HasPtr(const string& s = string()):
        ps(new string(s)),i(0), use(new size_t(1)){}
        HasPtr(const HasPtr& p):ps(p.ps),i(p.i),use(p.use){++*use;}
        HasPtr& operator =(const HasPtr&);
        ~HasPtr();
    private:
        string *ps;
        int i;
        size_t* use;
};

HasPtr::~HasPtr(){
    if(--*use == 0){
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator=(const HasPtr &other){
    ++*other.use;
    // 右边先加，左边再减
    if(--*use ==0){
        delete ps;
        delete use;
    }
    ps = other.ps;
    i = other.i;
    use = other.use;
    return *this;
}

int main()
{
   std::cout << sizeof (size_t) << std::endl;
   system("pause");
   return 0;
}
