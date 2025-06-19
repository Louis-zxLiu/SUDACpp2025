#include <iostream>
#include <iomanip>
#include <cmath>
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
        
        // 加法运算符重载
        CCircle operator+(const CCircle& c) const {
            CCircle result;
            result.x = x;
            result.y = y;
            result.r = r + c.r;
            return result;
        }
        
        // 减法运算符重载
        CCircle operator-(const CCircle& c) const {
            CCircle result;
            result.x = x;
            result.y = y;
            double area_diff = fabs(pi*r*r - pi*c.r*c.r);
            result.r = sqrt(area_diff/pi);
            return result;
        }
        
        // 前置自增运算符
        CCircle& operator++() {
            ++r;
            return *this;
        }
        
        // 后置自增运算符
        CCircle operator++(int) {
            CCircle temp = *this;
            ++r;
            return temp;
        }
        
        // 前置自减运算符
        CCircle& operator--() {
            if(r > 0) --r;
            return *this;
        }
        
        // 后置自减运算符
        CCircle operator--(int) {
            CCircle temp = *this;
            if(r > 0) --r;
            return temp;
        }
        
        // 大于运算符
        bool operator>(const CCircle& c) const {
            return r*r > c.r*c.r;
        }
        
        // 小于运算符
        bool operator<(const CCircle& c) const {
            return r*r < c.r*c.r;
        }
        
        // 相等运算符
        bool operator==(const CCircle& c) const {
            return x == c.x && y == c.y && r == c.r;
        }
        
        // 不等运算符
        bool operator!=(const CCircle& c) const {
            return !(*this == c);
        }
        
        // 同心运算符
        bool operator&(const CCircle& c) const {
            return x == c.x && y == c.y;
        }
        
        // 位置关系运算符
        int operator|(const CCircle& c) const {
            double distance = sqrt(pow(x - c.x, 2) + pow(y - c.y, 2));
            double r_sum = r + c.r;
            double r_diff = fabs(r - c.r);
            
            if(distance <= r_diff) {
                return 0; // 包含关系
            } else if(distance < r_sum) {
                return 1; // 相交
            } else if(distance == r_sum) {
                return 2; // 相切
            } else {
                return 3; // 相离
            }
        }
        
        // 友元函数：输出流运算符重载
        friend ostream& operator<<(ostream& os, const CCircle& c);
};

// 输出流运算符重载定义
ostream& operator<<(ostream& os, const CCircle& c) {
    os << fixed << setprecision(3);
    os << "(" << c.x<<','<<c.y << ") ";
    os << c.r ;
    os << fixed << setprecision(3) << 2 * c.pi * c.r << " ";
    os << fixed << setprecision(3) << c.pi * c.r * c.r;
    return os;
}

int main()
{
	CCircle c1,c2,c3,c4;
	double x1,y1,x2,y2,r1,r2;
	int istate;
	cout<<"请输入圆心坐标和半径: "<<endl;
	cin>>x1>>y1>>r1;
	c1.set_xy(x1,y1);
	c1.set_r(r1);
	cout<<c1<<endl;
	cout<<"请输入圆心坐标和半径: "<<endl;
	cin>>x2>>y2>>r2;
	c2.set_xy(x2,y2);
	c2.set_r(r2);
	cout<<c2<<endl;

    c3=c1+c2;
    cout<<" 两圆相加: "<<c3<<endl;
    c4=c3-c2;
    cout<<" 两圆相减: "<<c4<<endl;
    ++c4;
    cout<<" C4前自增: "<<c4<<endl;
    cout<<" C4后自增: "<<c4++<<" C4自增后: "<<c4<<endl;
    --c4;
    cout<<" C4前自减: "<<c4<<endl;
    cout<<" C4后自减: "<<c4--<<" C4自减后: "<<c4<<endl;

    cout<<"c1: "<<c1<<" c2: "<<c2<<endl;
    if (c1>c2)
        cout<<"c1>c2"<<endl;
    else if (c1<c2)
        cout<<"c1<c2"<<endl;
    else
        cout<<"c1<>c2"<<endl;   // 表示无比较结果

    cout<<"c1: "<<c1<<" c4: "<<c4<<endl;
    if (c1==c4)
        cout<<"c1==c4"<<endl;
    else if (c1 != c4)
        cout<<"c1!=c4"<<endl;
    else
        cout<<"c1<>c4"<<endl;   // 表示无比较结果


    if (c1&c4)
        cout<<"c1与c4同心"<<endl;

    istate = c1|c2;
    switch(istate)
    {
    case 0:
        cout<<"c1包含c2"<<endl;
        break;
    case 1:
        cout<<"c1与c2相交"<<endl;
        break;
    case 2:
        cout<<"c1与c2相切"<<endl;
        break;
    case 3:
        cout<<"c1与c2相离"<<endl;
        break;
    default:
        cout<<"c1与c2位置判断错误"<<endl;
    }
    istate = c3|c1;
    switch(istate)
    {
    case 0:
        cout<<"c3包含c1"<<endl;
        break;
    case 1:
        cout<<"c3与c1相交"<<endl;
        break;
    case 2:
        cout<<"c3与c1相切"<<endl;
        break;
    case 3:
        cout<<"c3与c1相离"<<endl;
    default:
        cout<<"c3与c1位置判断错误"<<endl;
    }

	//system("pause");
	return 0;
}
