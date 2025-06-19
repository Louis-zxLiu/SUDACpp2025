#include <iostream>
using namespace std;
int main(){
    for (int cock=0;cock<20;cock++){
        for (int hen=0;hen<34;hen++){
            int res;
            res=100-cock-hen;
            if (res%3!=0){
                continue;
            }
            else{
                if ((res/3+cock*5+hen*3)==100){
                    cout<<"鸡翁，鸡母，鸡雏分别为"<<cock<<","<<hen<<','<<res<<endlS;
                }
            }
        }
    }
}