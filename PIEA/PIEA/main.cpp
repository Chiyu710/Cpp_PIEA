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
	students *tail;
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
	tail = stu;
	while (stuin>>info) 
	{
		students *p = new students;
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
		tail->next = p;
		tail = p;
	}
	stuin.close();
	passwd.close();
	students* infop = new students;
	students* ff = new students;
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
									cout << "请输入新增学生的信息：";

									cin >> tname >> ttid >> tmajor >> tis >> g1 >> g2 >> g3 >> g4;
									news->edit(tname, ttid, tmajor, tis, g1, g2, g3, g4);
									news->next = stu;
									stu = news;
									stu->input(stu);
									Sleep(1000);	break;
								case 4: ff = stu; ff->input(ff);  break;
								default:;       break;

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
								cin >> i1;
								switch (i1)
								{
								case 1: 				break;
								case 2: 				break;
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
				/*
				  while(i!=-1)
				  {
					 // fh=0;
					  
					   case 2:
						   while(fh!=-1)
						   {

							   blist.find(i);
							   cout<<"输入任意数字返回"<<endl;
							   cin>>fh;
							   fh=-1;
						   }
							   break;
					   case 3:
						   while(fh!=-1)
						   {
							   blist.advancedfind();
							   cout<<"输入任意数字返回"<<endl;
							   cin>>fh;
							   fh=-1;
						   }
						   break;
					   }
					   fh=0;
				  }*/
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