#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    int d=0;
    d=pow(n*2,0.5);
    int ans=0;
    for (int i=1;i<=d;i++){
        ans+=i*i;
    }
    ans+=(n-d*(d+1)/2)*(d+1);
    cout<<ans<<endl;
    return 0;  
}