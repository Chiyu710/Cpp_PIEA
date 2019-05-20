#include<iostream>
#include<fstream>
#include<cstring>
#include<windows.h>
#include "Grade.h"
#include"Students.h"
#include "Grade.cpp"
using namespace std;
int main()
{
	students* find(students *s, char str[20]);
	bool check(students* stu, cgrade *s);
	void plist(students*pstu, int num);
	char info[20];
	int grade;
	char password[10];
	char cpassword[10];
	char tname[10], ttid[20], tmajor[10], tis[3];
	int g1, g2, g3, g4;
	ifstream passwd("password.txt",ios::in);
	ifstream stuin("studentsinfo.txt", ios::in);
	passwd >> cpassword;
	students*news = new students;
	students *stu = new students;
	students *pstu = new students;
	students *tail;
	students *ptail;
	students *fp = new students;
	students* ff = new students;
	cgrade*s = new cgrade;
	stuin >> stu->name;
	stuin >> stu->id;
	stuin >> stu->major;
	stuin >> stu->is_year;
	stuin >> stu->math;
	stuin >> stu->lang;
	stuin >> stu->policy;
	stuin >> stu->pro;
	stu->get_sum();
	stu->next = NULL;
	pstu->next = NULL;
	tail = stu;
	ptail = pstu;
	while (stuin>>info) 
	{
		students *p = new students;
		students *pp = new students; //为过线学生造位置
		strcpy_s(p->name,info);
		stuin >>p->id;
		stuin >> p->major;
		stuin >> p->is_year;
		stuin >> p->math;
		stuin >> p->lang;
		stuin >> p->policy;
		stuin >> p->pro;
		p->get_sum();
		p->next = NULL;
		pp->next = NULL; //为过线学生造位置
		tail->next = p;
		tail = p;
		ptail->next = pp;//为过线学生造位置
		ptail = pp;//为过线学生造位置
	}
	//pstu = pstu->next;
	stuin.close();
	passwd.close();
	students* infop = new students;
	int i1 = 0, i2,temp;
	while (i1 != -1)
	{
		i1 = 0, i2 = 0;
		cout << "    ------------------------------------------------------\n";
		cout << "    |           欢迎进入研究生录取系统                     |" << endl;
		cout << "    |           1.登陆                                     |" << endl;
		cout << "    |           2.退出                                     |" << endl;
		cout << "    ------------------------------------------------------\n";
		cout << "               请选择：";
		cin >> i1;
		system("cls");
		switch (i1) {
		case 1:
			cout << "请输入密码：";
			while (cin >> password && i1!=-1)
			{
				if (strcmp(password, cpassword) == 0)
				{
					cout << "进入成功" << endl;
					Sleep(1000);
					system("cls");
					while (i1 != -1)
					{
						i1 = 0;
						cout << "----------------------------------\n";
						cout << "|    1.学生信息管理                |" << endl;
						cout << "|    2.进行过线学生筛选            |" << endl;
						cout << "----------------------------------\n";
						cout << "*输入-1退出" << endl;
						cout << " 请选择：";
						cin >> i1;
						system("cls");
						switch (i1)
						{
						case 1:
							while (i1 != -1)
							{
								i1 = 0;
								system("cls");
								cout << "----------------------------------\n";
								cout << "1.查看学生信息" << endl;
								cout << "2.修改学生信息" << endl;
								cout << "3.增加学生信息" << endl;
								cout << "4.删除学生信息" << endl;
								cout << "----------------------------------\n";
								cout << "*输入-1返回" << endl;
								cin >> i1;
								switch (i1)
								{
								case 1: 
									system("cls");
									cout << "---------------------------------------------------------------\n";
									infop = stu;
									while (infop!=NULL) 
									{
										infop->list();
										infop=infop->next;
									}
									cout << "输入任何数字返回:";
									cin >> i1;
									break;
								case 2: system("cls");
									cout << "请输入要修改的学生的准考证号：";
									char tid[20];
									cin >> tid;
									infop = stu;
									ff=find(stu, tid);
									if (ff == NULL) cout << "未找到相应学生 请重试！";
									else {
										ff->list();
										cout << "请输入该学生修改后的信息" << endl;
										cin >> tname >> ttid >> tmajor >> tis >> g1 >> g2 >> g3 >> g4;
										ff->edit(tname, ttid, tmajor, tis, g1, g2, g3, g4);
										stu->input(stu);
									};
									Sleep(1000);
									break;
								case 3: 
									system("cls");
									cout << "-----------------输入Exit返回---------------\n";
									cout << "请输入新增学生的信息：";
									cin >> tname;
									if (strcmp(tname, "Exit") == 0) break;
									cin>> ttid >> tmajor >> tis >> g1 >> g2 >> g3 >> g4;
									news->edit(tname, ttid, tmajor, tis, g1, g2, g3, g4);
									news->next = stu;
									stu = news;
									stu->input(stu);
									Sleep(1000);	break;
								case 4:system("cls");
									cout << "请输入要删除的学生的准考证号：";
									cin >> tid;
									infop = stu;
									ff = find(stu, tid);
									if (ff == NULL) cout << "未找到相应学生 请重试！"; 
									else {
										ff->list();
										cout << "确认删除该学生？" << endl;
										cout << "1.确认删除" << '\t' << "2.取消" << endl;
										cin >> temp;
										if (temp == 1) { stu->deletestu(stu,ff); stu->input(stu); }
									};
									Sleep(1000);	break; 
									break;
								default:i1=-1;       break;

								}

							}
							i1 = 0;
							system("cls");
							break;
						case 2: 
							while (i1 != -1)
							{
								i1 = 0;
								system("cls");
								cout << "----------------------------------\n";
								cout << "1.输入最低成绩要求" << endl;
								cout << "2.输出过线学生" << endl;
								cout << "----------------------------------\n";
								cout << "*输入-1返回" << endl;
								cin >> i1;
								switch (i1)
								{
								case 1:
									system("cls");
									int lmath, lpolicy, llang, lpro, lsum;
									cout << "数学最低分："; cin >> lmath;   cout << endl;
									cout << "外语最低分："; cin >> llang;   cout << endl;
									cout << "政治最低分："; cin >> lpolicy; cout << endl;
									cout << "专业最低分："; cin >> lpro;    cout << endl;
									cout << "总分最低分："; cin >> lsum;    cout << endl;
									s->setcgrade(lmath, lpolicy, llang, lpro, lsum);
									Sleep(1000);
									break;
								case 2: 
									int pnum;
									system("cls");
									pnum = 0;
									ff = stu;
									fp = pstu;
									while (ff != NULL)
									{
										
										if (check(ff, s)) 
										{
											pnum++;
											fp->scpy(ff);
											fp = fp->next;
										}
										ff = ff->next;
									}
									fp = pstu;
									plist(fp, pnum);
									fp->pinput(fp,pnum);
									while(pnum>0)
									{
										fp->list();
										fp = fp->next;
										pnum--;
									}
									
									
									cout << "输入任何数字返回:";
									cin >> i1;
									break;
								default: i1 = -1;       break;

								}

							}
							i1 = 0;
							system("cls");
							break;
						default: break;
						}
					}
					if (i1 == -1) break;
				}
				else
				{
					cout << "--密码错误，请重试--" << endl;
					Sleep(1000);
					system("cls");
					cout << "请输入密码：";
				}
			}
			break;
		case 2:
			i1 = -1;
			break;



		default:

			cout << "输入错误" << endl;
			i1 = -1;

			break;

		}
	}

	cout << "谢谢使用" << endl;
	system("pause");
	return 0;
}

students* find(students *s, char str[20])
{
	students* find = new students;
	find = s;
	while (find != NULL)
	{
		if (strcmp(find->id, str) == 0) {
		 return find;
		}
		find = find->next;
	}
	return NULL;
}

bool check(students* stu,cgrade *s)
{
	bool f = 1;
	if (stu->math < s->math) return  0;
	if (stu->lang < s->lang) return  0;
	if (stu->policy < s->policy) return  0;
	if (stu->pro < s->pro) return  0;
	if (stu->Sum < s->sum) return  0;
	return  f;
}

void plist(students*pstu, int num)
{
	students *ts = new students;
	students *s = pstu;
	for (int i = 1; i <= num ; i++)
	{
		for (int j = 1; j <= num  - i; j++)
		{

			if (pstu->Sum < pstu->next->Sum)
			{
				//cout << "fixed!!";
				//pstu->list();
				ts->scpy(pstu->next);
				pstu->next->scpy(pstu);
				pstu->scpy(ts);
			}
			pstu = pstu->next;
		}
		pstu = s;
	}
	pstu = s;
}

