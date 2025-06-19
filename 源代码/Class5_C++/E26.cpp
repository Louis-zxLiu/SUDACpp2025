#include <iostream>
#include <iomanip>
using namespace std;


// 为了便于测试，提供一个系统日期类，并定义全局对象表示当前系统日期
class CSystemTime
{
private:
    int m_year, m_month, m_day;
public:
    void setDate(int y,int m, int d)
    {
        m_year=y;
        m_month=m;
        m_day=d;
    }
    int getYear()const{return m_year;}
    int getMonth()const{return m_month;}
    int getDay()const{return m_day;}
};

CSystemTime  systemTime;   // 全局变量表示当前系统时间

class CAount
{
    private:
        double m_Money=0;
        static double m_InterestRate;
        int m_year, m_month, m_day; // 存款日期
    public:
        // 设置和获取利率的静态成员函数
        static void SetInterestRate(double rate){
            m_InterestRate=rate;
        }
        static double GetInterestRate(){
            return m_InterestRate;
        }
        
        // 存款函数
        void SaveMoney(double money){
            m_Money+=money;
            // 记录存款日期
            m_year = systemTime.getYear();
            m_month = systemTime.getMonth();
            m_day = systemTime.getDay();
        }
        
        // 计算利息
        double CalcInterest(double money) const {
            if (money > m_Money) {
                return 0; // 金额大于账户本金，无法计算
            }
            
            // 计算从存款日到当前日期的天数
            int depositDays = (systemTime.getYear() - m_year) * 360 + 
                             (systemTime.getMonth() - m_month) * 30 + 
                             (systemTime.getDay() - m_day);
            
            // 计算利息：金额 * 年利率 / 360 * 天数
            return money * m_InterestRate / 360 * depositDays;
        }
        
        // 结算利息
        void SaveInterest() {
            double interest = CalcInterest(m_Money);
            m_Money += interest;
            // 更新存款日期为当前日期
            m_year = systemTime.getYear();
            m_month = systemTime.getMonth();
            m_day = systemTime.getDay();
        }
        
        // 取款函数
        double LendMoney(double money) {
            if (money > m_Money) {
                return -1; // 本金不足，返回-1表示取款失败
            }
            
            // 计算利息
            double interest = CalcInterest(money);
            // 从本金中扣除取款金额
            m_Money -= money;
            // 返回取款金额加上利息
            return money + interest;
        }
        
        // 获取存款信息，用于运算符重载
        int getYear() const { return m_year; }
        int getMonth() const { return m_month; }
        int getDay() const { return m_day; }
        double getMoney() const { return m_Money; }
        // 重载输出运算符
        friend ostream& operator<<(ostream& os, const CAount& account) {
            os << account.getYear() << "-" 
                << account.getMonth() << "-" 
                << account.getDay() << " " 
                << fixed << setprecision(2) << account.getMoney() << " " 
                << CAount::GetInterestRate();
                return os;
}
};

// 初始化静态成员变量
double CAount::m_InterestRate = 0.2;

int main()
{
    CAount aount;
    int year,month, day;
    double money,istate;
    cout<<"输入当前日期(年月日):"<<endl;
    cin>>year>>month>>day;
    systemTime.setDate(year,month,day);
    cout<<"输入存款金额:"<<endl;
    cin>>money;
    aount.SaveMoney(money);
    cout<<"当前账户信息:"<<endl;
    cout<<aount<<endl;

    cout<<"输入新的日期(年月日):"<<endl;
    cin>>year>>month>>day;
    systemTime.setDate(year,month,day);
    aount.SaveInterest();
    cout<<"当前账户信息:"<<endl;
    cout<<aount<<endl;

    cout<<"输入新的日期(年月日):"<<endl;
    cin>>year>>month>>day;
    systemTime.setDate(year,month,day);
    CAount::SetInterestRate(0.2);
    cout<<"输入取款金额:"<<endl;
    cin>>money;
    istate=aount.LendMoney(money);
    if (istate<0)
        cout<<"账户本金不足"<<endl;
    else
        cout<<"取款: "<<istate<<endl;

    cout<<"当前账户信息:"<<endl;
    cout<<aount<<endl;
	//system("pause");
	return 0;
}
