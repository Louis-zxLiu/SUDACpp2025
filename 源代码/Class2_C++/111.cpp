#include <iostream>
using namespace std;
int main(){
    char a,b,c,d,e;
    for (int i=32;i<=121;i+=5){
        a=i;
        b=i+1;
        c=i+2;
        d=i+3;
        e=i+4;
        cout<<a<<b<<c<<d<<e<<endl;  
    }
    return 0;


}