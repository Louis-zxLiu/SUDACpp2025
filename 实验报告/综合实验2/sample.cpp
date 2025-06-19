#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cmath>
#include <regex>
using namespace std;
vector<string> func1(string arr[], int n)
{
	vector<string> vec;
	// 正则表达式匹配数值（整数或浮点数）
    std::regex pattern(R"([+-]?\d+(\.\d*)?)");
    for (int i = 0; i < n; ++i) {
        if (std::regex_match(arr[i], pattern)) {
            vec.push_back(arr[i]);
        }
    }
	return vec;
}

vector<double> func2(const vector<string>& vec)
{
	vector<double> res;
	double sum=0,ave=0,cnt=0,sigma=0;
	for (auto i=vec.begin();i<vec.end();i++){
		sum+=stod(*i);
		cnt+=1;
	}
	ave=sum/cnt;
	sum=0;//节省内存 
	for (auto i=vec.begin();i<vec.end();i++){
		sum+=(ave-stod(*i))*(ave-stod(*i));
	}
	sigma=pow((sum)/(cnt-1),0.5);//计算sigma 
	for (auto i=vec.begin();i<vec.end();i++){
		if (stod(*i)<=sigma+ave && stod(*i)>=ave-sigma){
			res.push_back(stod(*i));
		}
	}
	return res;
}

int func3(const vector<double>& vec, unsigned int num)
{
	int res = 0;
	int cntrise=1,cntdown=1,cover=0,cnt=0;
	int check[vec.size()]={0};//记录每一段末尾，防止重复计数 
	for (auto i=vec.begin()+1;i<vec.end();i++){
		cnt++;
		if ((*i)>(*(i-1))){
			cntrise++;
			if (cntdown>=num){
				
				res=res+cntdown-check[cnt-cntdown];
				check[cnt-1]=1;

			}
			cntdown=1;
		}
		else if ((*i)<(*(i-1))){
			cntdown++;
			if (cntrise>=num){
				res=res+cntrise-check[cnt-cntrise];
				check[cnt-1]=1;
			}
			cntrise=1;
		}
		else {
			if (cntrise>=num){
				res=res+cntrise-check[cnt-cntrise];}
			if (cntdown>=num){
				res=res+cntdown-check[cnt-cntrise];}
			check[cnt-1]=1;
			cntdown=1;cntrise=1;
		}
	}
	if (cntrise>=num){
				res=res+cntrise-check[cnt-cntrise];}
	if (cntdown>=num){
				res=res+cntdown-check[cnt-cntrise];}

	return res;
}

string func4(const vector<double>& vec, unsigned int num)
{
	string res = "";
	int check[vec.size()]={0};//记录上下 
	for (int i=1;i<vec.size()-1;i++){
		if ((vec[i]!=vec[i+1] && vec[i]!=vec[i-1])&&(vec[i]-vec[i+1])/(vec[i]-vec[i-1])>0){
			check[i]=1;
			check[i-1]=1;
			check[i+1]=1;
		}
	}
	int t=0;string temp="";
	for (int j=0;j<vec.size();j++){
		
		if (check[j]){
			temp+=to_string(j);
			temp+=' ';
			t++;
		}
		else{
			if (t>=num){

				res+=temp;
				temp="";t=0;
			}		
		}
	}
	if (t>=num){//最后一段防止漏记 
		res+=temp;
	}

	return res;
}

int main()
{
	//输入数据
	//string arr[] = { "", "12.51", "ab.2", "13.52", "13..52",  "13.5.1", "14.54", "14.52", "12.53", "13.56", "0013.54", "010", "   ", "13.   5" };
	//string arr[]= {"35.26", "36.2.4", "35.42", "36.x15", "35.3 6", "35.98", "36.01", "39.99", "035.22", "35", " ", "35.01"};
	//string arr[]={"110.12", "110.15", "110..16", "110", "110.18", "130.25", "110.4 5", " ", "110.09", "110.09", "110.09", "110.13", "110.10"};
	//string arr[]={"237.2", "237.1", "236.9", "236.5", "236.1", "235..8", "235.5", "235", "234. 8", "2333", "234.1", "237.2", "236.3"};
	string arr[]={"555.3", "555.3", "555.3", "555.4", "555.5", "55.5.5", "555.5", " ", "555.5" "555.4", "555.3", "5555", "555.2", "555.1", "549.8", "550.6"};
	//调用函数func1
	vector<string> res1 = func1(arr, sizeof(arr) / sizeof(string));
	for (unsigned int i = 0; i < res1.size(); i++)
		cout << i << " " << res1[i] << endl;

	cout << "---------------------" << endl;

	//调用函数func2
	vector<double> res2 = func2(res1);
	for (unsigned int i = 0; i < res2.size(); i++)
		cout << i << " " << res2[i] << endl;

	cout << "---------------------" << endl;

	//调用函数func3
	unsigned int num3 = 3;
	int res3 = func3(res2, num3);
	cout << res3 << endl;

	cout << "---------------------" << endl;

	//调用函数func4
	unsigned int num4 = 3;
	string res4 = func4(res2, num4);
	cout << res4 << endl;
}
