#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string re(string s){
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    string s;
    cin>>s;
    string ans=re(s);
    cout << atoi(ans.c_str());
    return 0;
}