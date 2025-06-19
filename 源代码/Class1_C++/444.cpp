#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int h,r;
	cin>>h>>r;
	double pi=3.1415,v;
	v=pi*(r*r)*h;
	cout<<ceil(20000/v);
	return 0;
}