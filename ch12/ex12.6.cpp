#include<bits/stdc++.h>

using namespace std;


vector<int>* generator(int sz){
    return new vector<int>(sz);
}

void getValue(vector<int>* v){
    int n = v->size();
    for(int i = 0; i < n; i ++){
        int a;
        cout << "please input &" << i+1 << " value :" << endl;
        cin >> a;
        (*v)[i] = a;
    }
}

void printValue(vector<int>* v){
    for(auto i = v->begin(); i != v->end(); i ++){
        cout << *i << endl;
    }
}

int main(){

    vector<int>* a = generator(5);
    getValue(a);
    printValue(a);
    delete a;
}