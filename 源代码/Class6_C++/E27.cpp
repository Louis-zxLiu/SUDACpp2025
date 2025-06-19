#include <iostream>
#include <cmath>
using namespace std;

class CPoint
{
	int m_x; //点的X坐标
	int m_y;	//点的Y坐标º
public:
	CPoint()
	{
		m_x=0;
		m_y=0;
	}
    CPoint (int x,int y)
	{
		m_x=x;
		m_y=y;
	}
	int getx()
	{
		return m_x;
	}
	int gety()
	{
		return m_y;
	}
	void showPoint()
	{
		cout<<"("<<this->m_x<<","<<this->m_y<<")"<<endl;
	}
};

class CLine
{
	CPoint m_point1;
	CPoint m_point2;
public:
	CLine()
	{
		// 默认构造函数，使用CPoint的默认构造函数初始化两个点
	}
	
	CLine(int x1, int y1, int x2, int y2)
	{
		m_point1 = CPoint(x1, y1);
		m_point2 = CPoint(x2, y2);
	}
	
	void ShowLine()
	{
		cout << "Point 1 is:";
		m_point1.showPoint();
		cout << "Point 2 is:";
		m_point2.showPoint();
	}
	
	double distance()
	{
		int dx = m_point2.getx() - m_point1.getx();
		int dy = m_point2.gety() - m_point1.gety();
		return sqrt(dx*dx + dy*dy);
	}
};

int main()
{
	CLine line1;
	line1.ShowLine();
	cout<<"Length="<<line1.distance()<<endl;

	CLine line2(1,1,5,5);
	line2.ShowLine();
	cout<<"Length="<<line2.distance()<<endl;
}
