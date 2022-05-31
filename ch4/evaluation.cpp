#include <iostream>

using namespace std;

int f(){
    cout << "f" << endl;
    return 1;
}
int g(){
    cout << "g" << endl;
    return 2;
}
int h(){
    cout << "h" << endl;
    return 1;
}
int j(){
    cout << "j" << endl;
    return 1;
}
int main(){
    int a = f() + g()*h() + j();
    system("pause");
}