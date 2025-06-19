#include <iostream>
#include <string>
using namespace std;

class CPerson
{
private:
 	string  m_name;       // 姓名
	int   m_age;		      // 年龄
	char  m_sex;		     // 性别
public:
    CPerson(const string& name, int  age, char sex)
	{
		m_name = name;
		m_age = age;
		m_sex = sex;
    }
    CPerson()
    {
        m_name = "无名";
        m_age = 0;
        m_sex = 'M';
    }
    void  print() const
    {
         cout<<"姓名:"<<m_name<<"\n年龄:"<<m_age<<"\n";
      if (m_sex == 'M')
         cout<<"性别:男"<<endl;
      else
         cout<<"性别:女"<<endl;
    }
};

class CStudent:public CPerson
{
    private:
        string college;    // 学生所属大学名称
        int g;            // 学生所在年级
    public:
        // 无参构造函数，设置默认值
        // 姓名："无名"，年龄：18，性别：男，大学："苏州大学"，年级：1
        CStudent():CPerson("无名",18,'M'){
            college="苏州大学";
            g=1;
        }

        // 带参数的构造函数
        // 参数说明：
        // name: 学生姓名
        // age: 学生年龄
        // sex: 学生性别
        // collageName: 大学名称
        // grade: 年级
        CStudent(string name, int age, char sex, string collageName, int grade):
            CPerson(name,age,sex)
        {
            college=collageName;
            g=grade;
        }
        // 显示学生信息
        // 调用基类的print()显示基本信息（姓名、年龄、性别）
        // 然后显示大学名称和年级信息
        void print() {
            CPerson::print();
            cout<<"大学:"<<college<<"\n年级:"<<g<<'\n';
        }
};


int main()
{
   CStudent st1,st2("Liming",21,'M',"苏州大学",1);
   cout<<"学生1的信息:"<<endl;
   st1.print();

   cout<<"\n学生2的信息:"<<endl;
   st2.print();

   return 0;
}
