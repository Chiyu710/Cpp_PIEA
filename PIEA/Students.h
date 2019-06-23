#include <cstring>
#include<fstream>
#include <iomanip>
using namespace std;
class students
{
	char name[10];
	char id[20];
	char major[10];
	int math;
	int lang;
	int policy;
	int pro;
	int sum;
	char is_year[3];
	students *next;
public:
	char* get_nam()    { return name; }
	char* get_id()     { return id; }
	char* get_major()  { return major; }
	int   get_math()   { return math; }
	int   get_lang()   { return lang; }
	int   get_policy() { return policy; }
	int   get_pro()    { return pro; }
	int   get_sum()    { return sum; }
	students* get_next() { return next; }
	void set_sum() { sum = math + lang + pro + policy; }
	void set_name(char str[10]) { strcpy_s(name, str); }
	void set_id(char str[20])   { strcpy_s(id, str); }
	void set_major(char str[10]) { strcpy_s(major, str); }
	void set_math(int grade)     { math = grade; }
	void set_lang(int grade)   { lang = grade; }
	void set_policy(int grade)  { policy = grade; }
	void set_pro(int grade)     { pro = grade; }
	void set_is(char str[3]) { strcpy_s(is_year, str); }
	void set_next(students * pstu) { next=pstu; }
	void deletestu(students * s, students *f);
	void list();
	void edit(char tname[], char ttid[], char  tmajor[], char tis[], int g1, int g2, int g3, int g4);
	void input(students* stu);
	void pinput(students* stu, int num);
	void scpy(students *obj);
	void plist();
	void ErrorCheck();
};

void students::list()
{
	cout << left << setw(6) << name;
	cout << right << setw(7) << id;
	cout << right << setw(10) << major;
	cout << right << setw(10) << is_year;
	cout << right << setw(10) << math;
	cout << right << setw(10) << lang; 
	cout << right << setw(10) << policy;
	cout << right << setw(10) << pro;
	cout << endl;
}

void students::edit(char tname[], char ttid[],char  tmajor[], char tis[], int g1, int g2, int g3, int g4)
{
	strcpy_s(name, tname);
	strcpy_s(id, ttid);
	strcpy_s(major, tmajor);
	strcpy_s(is_year, tis);
	math = g1;
	lang = g2;
	policy = g3;
	pro = g4;
	this->get_sum();
	cout << "操作成功" << endl;
}

void students::input(students* stu)
{
	ofstream fout("studentsinfo.txt", ios::out);
	while (stu != NULL)
	{
		fout << left << setw(6) << stu->name ;
		fout << right << setw(7) << stu->id ;
		fout << right << setw(10) << stu->major ;
		fout << right << setw(10) << stu->is_year;
		fout << right << setw(10) << stu->math ;
		fout << right << setw(10) << stu->lang ;
		fout << right << setw(10) << stu->policy ;
		fout << right << setw(10) << stu->pro ;
		fout << endl;
		stu = stu->next;
	}
}

void students::deletestu(students * s,students *f) 
{
	if (s == f) 
	{
		f = f->next;
		students *ts = new students;
		ts->scpy(f); f->scpy(s);  s->scpy(ts);
		delete ts;
	}
	while (s != NULL) 
	{
		if (s->next==f)
		{
			s->next = f->next;
			delete f;
			cout << "删除成功！";
			break;
		}
		s = s->next;
	}
}	

void students::pinput(students* stu,int num) 
{
	ofstream fout("PassStudentsinfo.txt", ios::out);
	while (num>0)
	{
		num--;
		fout << left << setw(6) << stu->name;
		fout << right << setw(7) << stu->id;
		fout << right << setw(10) << stu->major;
		fout << right << setw(10) << stu->is_year;
		fout << right << setw(10) << stu->math;
		fout << right << setw(10) << stu->lang;
		fout << right << setw(10) << stu->policy;
		fout << right << setw(10) << stu->pro;
		fout << right << setw(10) << stu->sum;
		fout << endl;
		stu = stu->next;
	}
}

void students::scpy(students *obj)
{
	strcpy_s(name, obj->name);
	strcpy_s(id, obj->id);
	strcpy_s(major, obj->major);
	strcpy_s(is_year, obj->is_year);
	math = obj->math;
	lang = obj->lang;
	policy = obj->policy;
	pro = obj->pro;
	sum = obj->sum;
}

void students::plist()
{
	cout << left << setw(6) << name;
	cout << right << setw(7) << id;
	cout << right << setw(10) << major;
	cout << right << setw(10) << is_year;
	cout << right << setw(10) << math;
	cout << right << setw(10) << lang;
	cout << right << setw(10) << policy;
	cout << right << setw(10) << pro;
	cout << right << setw(10) << sum;
	cout << endl;
}

void students::ErrorCheck() 
{
	if (math > 100 || lang > 150 || policy > 100 || pro > 150)
	{
		list();
		if (math > 100)   cout << "数学成绩有误！   ";
		if (lang > 150)   cout << "语言成绩有误！   ";
		if (policy > 100) cout << "政治成绩有误！   ";
		if (pro > 150)    cout << "专业成绩有误！   ";
		cout << endl<<endl;
	}
}