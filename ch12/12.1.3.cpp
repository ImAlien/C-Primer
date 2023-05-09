#include<bits/stdc++.h>

using namespace std;

void process(shared_ptr<int> p){
    cout << p.use_count() << endl;
}
void process2(shared_ptr<int>& p){
    cout << p.use_count() << endl;
}

int main(){
    shared_ptr<int> p = make_shared<int>(3);
    process(p);
    process2(p);
}