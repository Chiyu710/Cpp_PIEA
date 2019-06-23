#include<iomanip>
using namespace std;
class cgrade 
{
	int math;
	int lang;
	int policy;
	int pro;
	int sum;
	string major;
public:
	void setcgrade(int g1=0,int g2=0,int g3=0,int g4=0,int s1=0) 
	{
		math = g1;
		lang = g2;
		policy = g3;
		pro = g4;
		sum = s1;
		cout << "输入成功！"<<endl;
	}
	string get_major() { return major; }
	void gradelist();
	void set_major(string s) { major = s; }
	int   get_math() { return math; }
	int   get_lang() { return lang; }
	int   get_policy() { return policy; }
	int   get_pro() { return pro; }
	int   get_sum() { return sum; }
	cgrade(int g1 = 0, int g2 = 0, int g3 = 0, int g4 = 0, int s1 = 0) 
	{
		math = g1;
		lang = g2;
		policy = g3;
		pro = g4;
		sum = s1;
	}
};

void cgrade::gradelist() 
{
	cout << left << setw(10) <<"数学:"<< math << endl;
	cout << left << setw(10) <<"语言:" <<lang<<endl;
	cout << left << setw(10) <<"政治:"<< policy<<endl;
	cout << left << setw(10) <<"专业课:"<< pro<<endl;
	cout << left << setw(10) << "总分:"<<sum<<endl;
	cout << endl;
}