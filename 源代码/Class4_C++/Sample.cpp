#include<iostream>
using namespace std;
#include<vector>

vector<int> func1(int m, int n) //每一位分别计算，降低时间复杂度
{
	vector<int> vec;
	for (int len=2;len<5;len++){
		for (int s=1;s<=10-len;s++){
			int num=0;
			int d=s;
			for (int i=0;i<len;i++){
				num=num*10+d;
				d+=1;}
				if (num>=m&&num<=n){
					vec.push_back(num);
				}
		}
	}
	return vec;
}

vector<int> func2(vector<int> vec)   //试除法&开方降低时间复杂度
{
	vector<int> res;
	for (unsigned int i = 0; i < vec.size(); i++){
		int ans=0;int temp=vec[i];
		for (int i=2;i*i<=temp;i++){
			if (temp%i==0){
				ans+=1;
				while (temp%i==0){//除去所有因子
					temp/=i;				
				}
			}
		}
		if (temp!=1) ans++;//仍有质因子
		res.push_back(ans);
	}
	return res;
}

vector<int> func3(vector<int> vec1, vector<int> vec2)
{
	vector<int> res;
	for (int i=0;i<vec1.size();i++){
		int a=vec1[i],b=vec2[i],left=0,time=0,step=1;
		if (b==1){//无法跳跃
			res.push_back(-1);
			continue;
		}
		while (left<a){
			time++;
			left=left+b-step;
			step++;
			if (step>b){
				step=1;
			}
			if (left+b>=a){//只跳跃不回头
				time++;
				break;
			}
		}
		res.push_back(time);
	}
	return res;
}

int main()
{
	int m = 100, n = 500;
	//func1的调用
	vector<int> v1 = func1(m, n);
	
	//func2的调用
	vector<int> v2 = func2(v1);

	//func3的调用
	vector<int> v3 = func3(v1, v2);
	for (unsigned int i = 0; i < v3.size(); i++)
		cout << v1[i] << " " << v2[i] << " " << v3[i] << " " << endl;
}
