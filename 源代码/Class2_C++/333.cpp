#include <iostream>
using namespace std;
int main(){
    float price=200;
    int n,k;
    int money=0;
    bool jl=true;
    cin>>n>>k;
    for (int i=1;i<=20;i++){
        if (money>=price){
            cout<<i<<endl;
            jl=false;
            break;
        }
        money+=n;
        price*=(1+k/100.0);
    }
    if (jl){
        cout<<"Impossible"<<endl;
    }
}