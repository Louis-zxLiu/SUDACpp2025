#include <iostream>
#include <iomanip>
using namespace std;

class CComplex
{
	double m_real;
	double m_image;
public:
	void setValue(double real,double image){ // 设置复数的实部和虚部
        m_real=real;
        m_image=image;
}
    friend ostream& operator<<(ostream& os,const CComplex& c){
        os<<c.m_real<<'+'<<c.m_image<<"*i";
        return os;
    }
    CComplex operator+(const CComplex& c) const{
        CComplex result;
        result.m_real=m_real+c.m_real;
        result.m_image=m_image+c.m_image;
        return result;
    }
    CComplex operator+(int c) const{
        CComplex result;
        result.m_real=m_real+c;
        result.m_image=m_image;
        return result;
    }
    // 前置自增运算符
    CComplex& operator++() {
        ++m_real;
        ++m_image;
        return *this;
    }
    // 后置自增运算符
    CComplex operator++(int) {
        CComplex temp = *this;
        ++m_image;++m_real;
        return temp;
    }
};


int main()
{
	double x1,y1,x2,y2;
	CComplex c1,c2,c3;

	cout<<"输入四个实数:"<<endl;
	cin>>x1>>y1>>x2>>y2;
	c1.setValue(x1,y1);
	c2.setValue(x2,y2);
	cout<<"复数c1: "<<c1<<endl;
	cout<<"复数c2: "<<c2<<endl;
	c3=c1+c2;
	cout<<"c1+c2: "<<c3<<endl;
	cout<<"c1+x2: "<<c1+x2<<endl;
	cout<<"++c2: "<<++c2<<endl;
	cout<<"c2++: "<<c2++<<endl;
	cout<<"c2: "<<c2<<endl;

	//system("pause");
	return 0;
}
