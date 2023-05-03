#include <bits/stdc++.h>

using namespace std;

class A{
    public:
    A() = default;
    virtual void print(){
        cout << "A" << endl;
    }
};
class B: public A{
    public:
    B() = default;
    void print(){
        cout << "B" << endl;
    }
};
int main(){

    A* a = new A();
    a->print();
    
    B* b = dynamic_cast<B*>(a);
    cout << b << endl;

    A& a_ref = *a;
    try{
        B& b_ref = dynamic_cast<B&>(a_ref);
        cout << b << endl;
    }
    catch (bad_cast e){
        cout << e.what() << endl;
    }
    getchar();
}