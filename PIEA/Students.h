#include <cstring>
#include<fstream>
using namespace std;
class students
{
public:
	char name[10];   
	char id[20];     
	char major[10];  
	int math;        
	int lang;       
	int policy;      
	int pro;        
	int Sum;       
	char is_year[3];   
	students *next;
	void get_sum() { Sum = math + lang + pro + policy; }
	void deletestu(students * s, students *f);
	void list();
	void edit(char tname[], char ttid[], char  tmajor[], char tis[], int g1, int g2, int g3, int g4);
	void input(students* stu);
	void pinput(students* stu, int num);
	void scpy(students *obj);
};

void students::list()
{
	cout << name << '\t' << id << '\t' << major << '\t' << is_year <<'\t'<< math << '\t' << lang << '\t' << policy << '\t' << pro << '\t' << Sum << endl;

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
	cout << "修改成功" << endl;
}

void students::input(students* stu)
{
	ofstream fout("studentsinfo.txt", ios::out);
	while (stu != NULL)
	{
		fout << stu->name << '\t';
		fout << stu->id << '\t';
		fout << stu->major << '\t';
		fout << stu->is_year << '\t';
		fout << stu->math << '\t';
		fout << stu->lang << '\t';
		fout << stu->policy << '\t';
		fout << stu->pro << '\t';
		fout << endl;
		stu = stu->next;
	}
}

void students::deletestu(students * s,students *f) 
{
	if (s == f) { f = s->next; s->next = s->next->next; f->next = s; s = f; f = f->next; }
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
		fout << stu->name << '\t';
		fout << stu->id << '\t';
		fout << stu->major << '\t';
		fout << stu->is_year << '\t';
		fout << stu->math << '\t';
		fout << stu->lang << '\t';
		fout << stu->policy << '\t';
		fout << stu->pro << '\t';
		fout << stu->Sum << '\t';
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
	Sum = obj->Sum;
}

/*void set_name(char str[10]) { strcpy_s(name, str); }
	void set_id(char str[20])   { strcpy_s(id, str); }
	void set_major(char str[10]) { strcpy_s(major, str); }
	void set_math(int grade)     { math = grade; }
	void set_lang(int grade)   { lang = grade; }
	void set_policy(int grade)  { policy = grade; }
	void set_pro(int grade)     { pro = grade; }
	void set_is(char str[3]) { strcpy_s(is_year, str); }*/