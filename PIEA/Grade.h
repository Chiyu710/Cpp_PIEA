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
		cout << "����ɹ���"<<endl;
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
	cout << left << setw(10) <<"��ѧ:"<< math << endl;
	cout << left << setw(10) <<"����:" <<lang<<endl;
	cout << left << setw(10) <<"����:"<< policy<<endl;
	cout << left << setw(10) <<"רҵ��:"<< pro<<endl;
	cout << left << setw(10) << "�ܷ�:"<<sum<<endl;
	cout << endl;
}