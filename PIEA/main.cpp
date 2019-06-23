#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<windows.h>
#include "Grade.h"
#include"Students.h"
#include "Grade.cpp"
using namespace std;
int main()
{	
	string major[30]; //专业分类数组
	students* find(students *s, char str[20]);
	bool check(students* stu, cgrade *s);
	void plist(students*pstu, int num);
	int MajorCheck(string s,string ma[30]);
	void Majorsort(students* stu,string ma[30]);
	void MajorAdd(cgrade[],string [],int );
	char info[20];
	int grade;
	int tm = 0,mnum,psum;
	char password[10];
	char cpassword[10];
	char tname[10], ttid[20], tmajor[10], tis[3];
	int g1, g2, g3, g4;
	ifstream passwd("password.txt",ios::in);
	ifstream stuin("studentsinfo.txt", ios::in);
	passwd >> cpassword;
	students * ttp = new students;
	students*news = new students;
	students *stu = new students;
	students *pstu = new students;
	students *tmp = new students;
	students *tail;
	students *ptail;
	students *fp;
	students* ff;
	students* slp;
	cgrade*s = new cgrade;
	stuin >> tname;
	stuin >> ttid;
	stuin >> tmajor;
	major[0] = tmajor;
	stuin >> tis;
	stuin >> g1;
	stuin >> g2;
	stuin >> g3;
	stuin >> g4;
	stu->set_name(tname);
	stu->set_id(ttid);
	stu->set_major(tmajor);
	stu->set_is(tis);
	stu->set_math(g1);
	stu->set_lang(g2);
	stu->set_policy(g3);
	stu->set_pro(g4);
	stu->set_sum();
	stu->set_next(NULL);
	pstu->set_next(NULL);
	tail = stu;
	ptail = pstu;
	while (stuin>>tname) 
	{
		students *p = new students;
		students *pp = new students; //为过线学生造位置
		stuin >> ttid;
		stuin >> tmajor;
		MajorCheck(tmajor,major); //增加专业
		stuin >> tis;
		stuin >> g1;
		stuin >> g2;
		stuin >> g3;
		stuin >> g4;
		p->set_name(tname);
		p->set_id(ttid);
		p->set_major(tmajor);
		p->set_is(tis);
		p->set_math(g1);
		p->set_lang(g2);
		p->set_policy(g3);
		p->set_pro(g4);
		p->set_sum();
		p->set_next(NULL);
		pp->set_next(NULL); //为过线学生造位置
		tail->set_next(p);
		tail = p;
		ptail->set_next(pp);//为过线学生造位置
		ptail = pp;//为过线学生造位置
	}
	//pstu = pstu->get_next();
	stuin.close();
	passwd.close();
	students* infop = new students;
	int i1 = 0, i2,temp;
	cgrade grad[30];
	int it=0;
	while (major[it][0]!='\0') 
	{
		grad[it].set_major(major[it]);
		it++;
	}
	//专业类初始化
	while (i1 != -1)
	{
		i1 = 0, i2 = 0;
		cout << "    ------------------------------------------------------\n";
		cout << "    |           欢迎进入研究生录取系统                     |" << endl;
		cout << "    |           1.登录                                     |" << endl;
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
									Majorsort(stu,major);
									while (infop!=NULL) 
									{
										infop->list();
										infop=infop->get_next();
									}
									cout << endl<<endl<<endl;
									cout << "------以下是错误信息-------" << endl;
									infop = stu;
									do { infop->ErrorCheck(); } while (infop = infop->get_next());
									cout << "输入任何数字返回:";
									cin >> i1;
									break;
								case 2: system("cls");
									cout << "-----------------输入Exit返回---------------\n";
									cout << "请输入要修改的学生的准考证号：";
									char tid[20];
									cin >> tid;
									cout << endl;
									if (strcmp(tid, "Exit") == 0) break;
									infop = stu;
									ff=find(stu, tid);
									if (ff == NULL) cout << "未找到相应学生 请重试！";
									else {
										ff->list();
										cout << "请输入该学生修改后的信息" << endl;
										cin >> tname >> ttid >> tmajor >> tis >> g1 >> g2 >> g3 >> g4;
										if (MajorCheck(tmajor, major))
										{
											cout << "新增 " << tmajor << " 专业" << endl;
											cout << "1.确定   2.取消" << endl;
											cin >> temp;
											if (temp == 2) break;
											MajorAdd(grad, major, MajorCheck(tmajor, major));
										}
										ff->edit(tname, ttid, tmajor, tis, g1, g2, g3, g4);
										ff->set_sum();
										stu->input(stu);
									};
									Sleep(1000);
									break;

								case 3: 
									system("cls");
									cout << "-----------------输入Exit返回---------------\n";
									cout << "请输入学生名字：";
									cin >> tname;
									cout << endl;
									if (strcmp(tname, "Exit") == 0) break;
									cout << "请输入准考证号：";
									cin >> tid;
									cout << endl;
									infop = stu;
									ff = find(stu, tid);
									if (ff != NULL) 
									{
										cout << "该准考证号重复！" <<endl<<endl;
										ff->list();
										cout << endl;
										cout << "1.覆盖   2.取消" << endl;
										cin >> temp;
										if (temp == 2) break;
										else 
										{
											cout << "继续输入" << endl;
											Sleep(500);
											system("cls");
											cout << "请依次输入专业、是否应届、数学成绩、语言成绩、政治成绩、专业成绩：";
											cin >> tmajor >> tis >> g1 >> g2 >> g3 >> g4;
											cout << "确定增加？" << endl;
											cout << "1.确定   2.取消" << endl;
											cin >> temp;
											if (temp == 2) break;
											if (MajorCheck(tmajor, major)) 
											{
												cout << "新增 " << tmajor << " 专业" << endl;
												cout << "1.确定   2.取消" << endl;
												cin >> temp;
												if (temp == 2) break;
												MajorAdd(grad, major, MajorCheck(tmajor, major));
											}
											ff->edit(tname, tid, tmajor, tis, g1, g2, g3, g4);
											Sleep(1000);
											break;
										}
									}
									cout << "请依次输入专业、是否应届、数学成绩、语言成绩、政治成绩、专业成绩：";
									cin>> tmajor >> tis >> g1 >> g2 >> g3 >> g4;
									cout << "确定增加？" << endl;
									cout << "1.确定   2.取消" << endl;
									cin >> temp;
									if (temp == 2) break;
									if (MajorCheck(tmajor, major))
									{
										cout << "新增 " << tmajor << " 专业" << endl;
										cout << "1.确定   2.取消" << endl;
										cin >> temp;
										if (temp == 2) break;
										MajorAdd(grad, major, MajorCheck(tmajor, major));
									}
									news->edit(tname, tid, tmajor, tis, g1, g2, g3, g4);
									news->set_next(stu);
									stu = news;
									stu->input(stu);
									Sleep(1000);	break;
								case 4:system("cls");
									cout << "-----------------输入Exit返回---------------\n";
									cout << "请输入要删除的学生的准考证号：";
									cin >> tid;
									if (strcmp(tid, "Exit") == 0) break;
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
								cout << "3.输出各专业最低成绩要求" << endl;
								cout << "----------------------------------\n";
								cout << "*输入-1返回" << endl;
								cin >> i1;
								switch (i1)
								{
								case 1:
									system("cls");
									int lmath, lpolicy, llang, lpro, lsum;
									tm = 0;
									while (grad[tm].get_major()[0]!='\0')
									{
										cout << "请输入<";
										cout << grad[tm].get_major();
										cout<<">专业成绩要求" << endl;
										cout << "数学最低分："; cin >> lmath;   cout << endl;
										cout << "外语最低分："; cin >> llang;   cout << endl;
										cout << "政治最低分："; cin >> lpolicy; cout << endl;
										cout << "专业最低分："; cin >> lpro;    cout << endl;
										cout << "总分最低分："; cin >> lsum;    cout << endl;
										grad[tm].setcgrade(lmath, lpolicy, llang, lpro, lsum);
										tm++;
									}
									
									Sleep(1000);
									break;
								case 2: 

									system("cls");
									ff = stu;
									fp = pstu;
									mnum = 0;
									temp = 0;
									psum = 0;
									while (grad[mnum].get_major()[0] != '\0')
									{
										while (ff && ff->get_major()== grad[mnum].get_major())
										{
											if (check(ff, grad + mnum)) 
											{
												fp->scpy(ff);
												fp = fp->get_next();
											}
											temp++;
											ff = ff->get_next();
										}
										slp = pstu;
										for (int ii = psum; ii > 0; ii--) 
										{
											slp = slp->get_next();
										}
										plist(slp, temp);	
										psum += temp;
										temp = psum;
										ff = stu;
										while (ff && temp>0) 
										{
											//ff->list();
											ff = ff->get_next();
											temp--;
										}
										if (ff == NULL)break;
										mnum++;
									}
									fp = pstu;
									cout << "--------" << fp->get_major() << "-------" << endl;
									temp = 1;
									while (fp) 
									{
										
										if (fp->get_major() == grad[temp].get_major())
										{
											cout << "--------" << fp->get_major() << "-------" << endl;
											temp++;
										} 
										fp->plist();
										fp=fp->get_next();
									}
									pstu->pinput(pstu,psum);
									cout << "输入任何数字返回:";
									cin >> i1;
									break;
								case 3:
									system("cls");
									tm = 0;
									while (grad[tm].get_major()[0] != '\0')
									{
										cout << "----------------------------------\n";
										cout << "<"<< grad[tm].get_major()<< ">" << endl;
										grad[tm].gradelist();
										tm++;
									}
									cout << "输入任何数字返回:";
									cin >> i1;
									break;
								default: i1 = -1;       break;

								}

							}
							i1 = 0; //  yuan0
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
			i1 = -11;

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
		if (strcmp(find->get_id(), str) == 0) {
		 return find;
		}
		find = find->get_next();
	}
	return NULL;
}

bool check(students* stu,cgrade *s)
{
	bool f = 1;
	if (stu->get_math() < s->get_math()) return  0;
	if (stu->get_lang() < s->get_lang()) return  0;
	if (stu->get_policy() < s->get_policy()) return  0;
	if (stu->get_pro() < s->get_pro()) return  0;
	if (stu->get_sum() < s->get_sum()) return  0;
	return  f;
}

void plist(students*pstu, int num)
{
	if (num == 1) ;
	else {
		students *ts = new students;
		students *s = pstu;
		for (int i = 1; i <= num; i++)
		{
			for (int j = 1; j <= num - i; j++)
			{

				if (pstu->get_sum() < pstu->get_next()->get_sum())
				{
					ts->scpy(pstu->get_next());
					pstu->get_next()->scpy(pstu);
					pstu->scpy(ts);
				}
				pstu = pstu->get_next();
			}
			pstu = s;
		}
		pstu = s;
	}
}

int MajorCheck(string s, string ma[30])
{
	int n=0;
	for (int i = 0; i < 30; i++)
	{
		if (s == ma[i]) break;
		if (ma[i][0] == '\0') {n = i; break;}
	}
	if (n != 0) 
	{
		ma[n] = s;
	}
	return n;
}

void Majorsort(students* stu, string ma[30])
{
	int i;
	i = 0;
	students temp;
	//string smj;
	students *p = new students;
	students *pp = new students;
	p = stu;
	while (ma[i][0] != '\0') 
	{
		while (p != NULL) 
		{
			//smj = p->get_major();
			if (p->get_major() != ma[i]) 
			{
				pp = p->get_next();
				while (pp != NULL) 
				{
					if (pp->get_major() == ma[i]) 
					{
						temp.scpy(pp);
						pp->scpy(p);
						p->scpy(&temp);
					}//swap
					pp = pp->get_next();
				}
			}
			p = p->get_next();
		}
		i++;
	}
	p = stu;
	p->input(p);
}

void MajorAdd(cgrade g[], string maj[30], int it) 
{
	while (maj[it][0] != '\0')
	{
		g[it].set_major(maj[it]);
		it++;
	}
}