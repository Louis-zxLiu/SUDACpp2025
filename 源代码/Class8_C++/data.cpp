#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

const double N=1.0;

// 1) 按行读取文件data.txt中的所有单词，返回二维vector，每行一个vector
vector <vector<string>> func1(){
    vector <vector<string>> ans;
    ifstream in ("c:\\data\\data.txt"); // 打开数据文件
    string line;
    while (getline(in, line)){
        vector<string> temp;
        stringstream ss(line);
        string word;
        while (ss >> word) {
            temp.push_back(word); // 提取每个单词
        }
        ans.push_back(temp); // 存储每行的单词
    }
    return ans;
}

// 2) 计算单词的重心值 = (所有字母的ascii码值之和) / 字母个数
// 传入string，返回double
// 这里假设单词不含空格
// N为比例系数，题目要求为1.0

double func2(string &s){
    int sum=0;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        sum+=s[i]; // 累加每个字符的ascii码
        cnt++;
    }
    return (N*sum/cnt); // 计算重心值
}

// 3) 找出每行中重心值最大的单词，输出到屏幕
// 单词与重心值之间用空格分隔，重心值保留3位小数
void func3(vector<string>& v0){
    string temp1="";
    double temp2=0.0;
    for (auto i=v0.begin();i<v0.end();i++){
        if (func2(*i)>temp2){
            temp1=*i;
            temp2=func2(*i);
        }
    }
    cout<<temp1<<' '<<fixed<<setprecision(3)<<temp2<<'\n';
}

// 4) 找出每行中重心值最大的单词，输出到文件wordValue.txt
// 输出格式同3），文件保存在C盘的data文件夹下
void func4(vector<string>& v0,ofstream& out){
    string temp1="";
    double temp2=0.0;
    for (auto i=v0.begin();i<v0.end();i++){
        if (func2(*i)>temp2){
            temp1=*i;
            temp2=func2(*i);
        }
    }
    out<<temp1<<' '<<fixed<<setprecision(3)<<temp2<<'\n';
}

int main(){
    // 读取所有单词
    vector <vector<string>> ans;
    ans = func1();
    // 打开输出文件（写模式，覆盖原有内容）
    ofstream out("c:\\data\\wordValue.txt");
    // 对每一行，分别输出到屏幕和文件
    for (auto i=ans.begin();i<ans.end();i++){
        func3(*i); // 输出到屏幕
        func4(*i,out); // 输出到文件
    }
    out.close(); // 关闭文件
}