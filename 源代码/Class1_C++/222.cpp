#include <iostream>
using namespace std;
int main(){
	char u;
	cin>>u;
	if ((u>=97)&&(u<=122)){
		printf("%c",u-32);
	}
	else if ((u>=65)&&(u<=90)){
		printf("%c",u+32);
	}
	else{
		cout<<u;
	}
	return 0;
}

