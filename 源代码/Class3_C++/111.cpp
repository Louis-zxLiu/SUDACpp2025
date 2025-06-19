#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int x){
    int d;
    d=ceil(pow(x,0.5));
    if (x==1) return false;
    if (x==2) return true;
    if (x%2==0) return false;
    for (int i=3;i<=d;i+=2){
        if (x%i==0) return false;
    }
    return true;
}
int main(){
    int cnt=0;
    for (int i=1;i<=1000;i++){
        if (isprime(i)) {
            cout<<i<<" ";
            cnt++;}
        if (cnt==8){
            cout<<endl;
            cnt=0;
        }
        
    }
}