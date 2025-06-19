#include <iostream>
#include <cmath>
using namespace std;

class CTime
{
	int m_hour,m_mintue,m_second;
public:
	CTime(int hour=0,int minute=0,int second=0);
	//如果时间合法，则赋值，否则赋值0时0分0秒
	int SetTime(int hour=0,int minute=0,int second=0);
	//如果时间合法，则赋值并返回1，否则不赋值，并返回0
	int getHour();
	int getMinute();
	int getSecond();
	void ShowTime(bool flag);
	//flag为True则以24小时制显示时间，否则以 AM PM的方式显示
	//自己考虑是否需要添加其他成员函数
};

CTime::CTime(int hour, int minute, int second)
{
    if(hour >= 0 && hour < 24 && minute >= 0 && minute < 60 && second >= 0 && second < 60)
    {
        m_hour = hour;
        m_mintue = minute;
        m_second = second;
    }
    else
    {
        m_hour = 0;
        m_mintue = 0;
        m_second = 0;
    }
}

int CTime::SetTime(int hour, int minute, int second)
{
    if(hour >= 0 && hour < 24 && minute >= 0 && minute < 60 && second >= 0 && second < 60)
    {
        m_hour = hour;
        m_mintue = minute;
        m_second = second;
        return 1;
    }
    return 0;
}

int CTime::getHour()
{
    return m_hour;
}

int CTime::getMinute()
{
    return m_mintue;
}

int CTime::getSecond()
{
    return m_second;
}

void CTime::ShowTime(bool flag)
{
    if(flag)
    {
        // 24小时制
        cout << (m_hour < 10 ? "0" : "") << m_hour << ":" 
             << (m_mintue < 10 ? "0" : "") << m_mintue << ":"
             << (m_second < 10 ? "0" : "") << m_second;
    }
    else
    {
        // AM PM 方式
        int hour = m_hour % 12;
        if (hour == 0) hour = 12;
        cout << (hour < 10 ? "0" : "") << hour << ":" 
             << (m_mintue < 10 ? "0" : "") << m_mintue << ":"
             << (m_second < 10 ? "0" : "") << m_second 
             << (m_hour < 12 ? " AM" : " PM");
    }
}

class CDate
{
	int m_year,m_month,m_day;
public:
	CDate(int year=2000,int month=1,int day=1);
	//如果日期合法(不考虑闰年，但考虑月的天数)，则赋值，否则赋值2000年1月1日
	int SetDate(int year=2000,int month=1,int day=1);
	//如果日期合法(不考虑闰年，但考虑月的天数)，则赋值并返回1，否则不赋值，并返回0
	int GetYear();
	int GetMonth();
	int GetDay();
	void ShowDate(bool flag);
	//flag为TRUE，则以中文的方式显示日期，否则以MM/DD/YYYY的方式显示日期
	//自己考虑是否需要添加其他成员函数
    bool IsValidDate(int year, int month, int day);
};

bool CDate::IsValidDate(int year, int month, int day)
{
    if(year < 0 || month < 1 || month > 12 || day < 1)
        return false;
    
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    return day <= daysInMonth[month];
}

CDate::CDate(int year, int month, int day)
{
    if(IsValidDate(year, month, day))
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }
    else
    {
        m_year = 2000;
        m_month = 1;
        m_day = 1;
    }
}

int CDate::SetDate(int year, int month, int day)
{
    if(IsValidDate(year, month, day))
    {
        m_year = year;
        m_month = month;
        m_day = day;
        return 1;
    }
    return 0;
}

int CDate::GetYear()
{
    return m_year;
}

int CDate::GetMonth()
{
    return m_month;
}

int CDate::GetDay()
{
    return m_day;
}

void CDate::ShowDate(bool flag)
{
    if(flag)
    {
        // 中文方式显示
        cout << m_year << "年" << m_month << "月" << m_day << "日";
    }
    else
    {
        // MM/DD/YYYY方式显示
        cout << (m_month < 10 ? "0" : "") << m_month << "/" 
             << (m_day < 10 ? "0" : "") << m_day << "/" 
             << m_year;
    }
}

class CDateTime
{
	CTime m_time;
	CDate m_date;
public:
	//添加必要的构造函数
    CDateTime(int year = 2000, int month = 1, int day = 1, int hour = 0, int minute = 0, int second = 0);
    int SetDateTime(int year, int month, int day, int hour, int minute, int second);
    void ShowDateTime(bool dateFlag, bool timeFlag);
    int GetYear() { return m_date.GetYear(); }
    int GetMonth() { return m_date.GetMonth(); }
    int GetDay() { return m_date.GetDay(); }
    int GetHour() { return m_time.getHour(); }
    int GetMinute() { return m_time.getMinute(); }
    int GetSecond() { return m_time.getSecond(); }
};

CDateTime::CDateTime(int year, int month, int day, int hour, int minute, int second)
    : m_date(year, month, day), m_time(hour, minute, second)
{
}

int CDateTime::SetDateTime(int year, int month, int day, int hour, int minute, int second)
{
    int dateResult = m_date.SetDate(year, month, day);
    int timeResult = m_time.SetTime(hour, minute, second);
    
    if(dateResult == 0)
        return -1; // 日期设置错误
    else if(timeResult == 0)
        return -2; // 时间设置错误
    
    return 1; // 全部正确
}

void CDateTime::ShowDateTime(bool dateFlag, bool timeFlag)
{
    m_date.ShowDate(dateFlag);
    cout << " ";
    m_time.ShowTime(timeFlag);
    cout << endl;
}

int main()
{
	CDateTime d1(2014, 5, 2, 27, 12, 5);
	d1.ShowDateTime(false, true);	//第1个参数表示以英文方式显示日期, 第2个参数表示以24小时制方式显示时间

	CDateTime d2;
	d2.ShowDateTime(true, false);		//第1个参数表示以中文方式显示日期, 第2个参数表示以AM PM的方式显示时间

	int iStatus;
	iStatus=d2.SetDateTime(2014, 5, 2, 21, 55, 5);
	switch(iStatus)
	{
	case 1:
		cout<<"日期和时间数据设置正确!"<<endl;
		break;
	case -1:
		cout<<"日期数据设置不正确!"<<endl;
		break;
	case -2:
		cout<<"时间数据设置不正确!"<<endl;
		break;
	}
	d2.ShowDateTime(false, false);		//第1个参数表示以英文方式显示日期, 第2个参数表示以AM PM的方式显示时间

	cout<<"月="<<d2.GetMonth()<<endl;		//认真考虑一下如何实现此操作？
	cout<<"分钟="<<d2.GetMinute()<<endl;		//认真考虑一下如何实现此操作？
}
