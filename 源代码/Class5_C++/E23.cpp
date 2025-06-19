#include <iostream>
#include <iomanip>
using namespace std;

class CColumn{
    private:
        double x,y,r,h;
        double pi=3.14159;
    public:
        void SetXY(double x1,double y1){
            x=x1;y=y1;
        }
        void SetR(double r1){
            r=r1;
        }
        void SetH(double h1){
            h=h1;
        }
        double GetBottomCirclum(){
            return 2*pi*r;
        }
        double GetBottomArea(){
            return pi*r*r;
        }
        double GetSideArea(){
            return h*pi*2*r;
        }
        double GetVolume(){
            return pi*r*r*h;
        }
};

int main()
{
	CColumn c1;
	double x,y,r1,r2,h1,h2;
	cout<<"输入圆心坐标、半径和高"<<endl;
	cin>>x>>y>>r1>>h1;
	c1.SetXY(x,y);
	c1.SetR(r1);
	c1.SetH(h1);
	cout<<"圆柱的底面周长、底面积、侧面积和体积："<<endl;
	cout<<fixed<<setprecision(3)<<c1.GetBottomCirclum()<<" "
		<<c1.GetBottomArea()<<" "
		<<c1.GetSideArea()<<" "
		<<c1.GetVolume()<<endl;
    cout<<"输入底圆半径和高:"<<endl;
	cin>>r2>>h2;
	c1.SetR(r2);
	c1.SetH(h2);
	cout<<"圆柱的底面周长、底面积、侧面积和体积："<<endl;
	cout<<fixed<<setprecision(3)<<c1.GetBottomCirclum()<<" "
		<<c1.GetBottomArea()<<" "
		<<c1.GetSideArea()<<" "
		<<c1.GetVolume()<<endl;

	//system("pause");
	return 0;
}
