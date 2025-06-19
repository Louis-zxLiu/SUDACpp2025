#include <iostream>
#include <iomanip>
using namespace std;

class CCircle
{
    private:
    double x,y,r;
        double pi=3.14159;
    public:
        void set_xy(double x1,double y1){
            x=x1;y=y1;
        }
        void set_r(double r1){
            r=r1;
        }
        double get_circlum(){
            return 2*pi*r;
        }
        double get_area(){
            return pi*r*r;
        }
};

int main()
{
	CCircle c1;
	double x,y,r1,r2;
    cout<<"输入圆心坐标和半径"<<endl;
	cin>>x>>y>>r1;
	c1.set_xy(x,y);
	c1.set_r(r1);
	cout<<"圆周长和面积: "<<fixed<<setprecision(3)<<c1.get_circlum()<<" "<<c1.get_area()<<endl;
	cout<<"输入新的半径:"<<endl;
	cin>>r2;
	c1.set_r(r2);
	cout<<"圆周长和面积: "<<fixed<<setprecision(3)<<c1.get_circlum()<<" "<<c1.get_area()<<endl;

	system("pause");
	return 0;
}
