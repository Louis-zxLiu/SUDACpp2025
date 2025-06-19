#include <iostream>

int gcd(int a, int b){
    if (b==0) return a;
    return gcd(b, a%b);
}
int lcd(int a, int b){
    return a*b/gcd(a, b);
}

int main(){
    int a, b;
    std::cin>>a>>b;
    std::cout<<gcd(a, b)<<std::endl;
    std::cout<<lcd(a, b)<<std::endl;
    return 0;
}