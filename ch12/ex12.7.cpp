#include<bits/stdc++.h>

using namespace std;


shared_ptr< vector<int> > generator(int sz){
    return shared_ptr<vector<int>>(new vector<int>(sz));
}

void getValue(shared_ptr< vector<int> > v){
    int n = v->size();
    for(int i = 0; i < n; i ++){
        int a;
        cout << "please input &" << i+1 << " value :" << endl;
        cin >> a;
        (*v)[i] = a;
    }
}

void printValue(shared_ptr< vector<int> > v){
    for(auto i = v->begin(); i != v->end(); i ++){
        cout << *i << endl;
    }
}

int main(){

    auto a = generator(5);
    getValue(a);
    printValue(a);
}