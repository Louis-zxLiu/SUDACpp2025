#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int dis;
	cin>>dis;
	double t1,t2=50;
	t1=dis/1.2;
	t2+=dis/3.0;
	if (abs(t1-t2)<=1e-8){
		cout<<"一样快";
	}
	else if (t1<t2){
		cout<<"走路快";
	}
	else if (t1>t2){
		cout<<"骑车快";
	}
	return 0;
}