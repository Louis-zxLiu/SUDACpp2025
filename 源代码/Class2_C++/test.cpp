#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int a;float b;
    cin>>a>>b;
    cout<<sizeof(a)<<endl;
    cout<<typeid(b).name()<<endl;
    cout<<hex<<a<<endl;
    
    cout.unsetf(ios::hex);

    cout<<scientific<<b<<endl;
    
    cout.unsetf(ios::scientific);

    const double pi=3.14;
    double ans;
    ans=pi*(a+b);
    cout<<right<<setfill('$')<<setw(20)<<ans<<endl;
    cout<<111<<endl;
}
