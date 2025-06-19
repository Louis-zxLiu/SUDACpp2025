#include <iostream>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	float ave;
	ave=(a+b+c)/3;
	printf("%-8.4f",ave);
	cout<<endl;
	int ma,mi;
	ma=max(a,b);
	mi=min(a,b);
	if (ma>=c){
		printf("%6d",ma);
		cout<<endl;
	}
	else{
		printf("%6d",c);
		cout<<endl;
	}
	if (mi<=c){
		printf("%6d",mi);
		cout<<endl;
	}
	else{
		printf("%6d",c);
		cout<<endl;
	}
}