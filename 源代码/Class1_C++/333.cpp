#include <iostream>
#include <string>
using namespace std;
int main(){
	int m,d;
	cin>>m>>d;
	int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int ans=0;
	for (int i=m;i--;i>=1){
		ans+=month[i];
	}
	ans+=d;
	ans-=1;
	string week[]={"星期六","星期日","星期一","星期二","星期三","星期四","星期五"};
	cout<<week[ans%7];

}