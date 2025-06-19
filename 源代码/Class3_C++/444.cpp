#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int printOut(int n){
    cout.unsetf(ios::fixed);
    cout<<setw(10)<<right<<n<<endl;
    return 0;
}

int printOut(float n){
    cout.unsetf(ios::fixed);
    cout<<setprecision(4)<<fixed<<n<<endl;
    return 0;
}

int printOut(string n){
    cout.unsetf(ios::fixed);
    char ans=n[0];
    cout<<setw(3)<<right<<ans<<endl;
    return 0;
}

int main(){
    int n;float f;
    string s;
    cout<<"请输入整数";
    cin>>n;
    cout<<"请输入浮点数";
    cin>>f;
    cout<<"请输入字符串";
    cin>>s;
    printOut(n);
    printOut(f);
    printOut(s);    
    
}