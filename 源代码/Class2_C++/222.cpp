#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a,n,ans=0;
    cin>>a>>n;
    int sum=a;
    for (int i=1;i<=n;i++){
        ans+=sum;
        sum+=a*(pow(10,(i-1)));
    }
    cout<<sum<<endl;
    return 0;
}

