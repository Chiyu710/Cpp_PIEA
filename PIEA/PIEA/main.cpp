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
	string major[30]; //רҵ��������
	students* find(students *s, char str[20]);
	bool check(students* stu, cgrade *s);
	void plist(students*pstu, int num);
	int MajorCheck(string s,string ma[30]);
	void Majorsort(students* stu,string ma[30]);
	void MajorAdd(cgrade[],string [],int );
	char info[20];
	int grade;
	int tm = 0;
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
		students *pp = new students; //Ϊ����ѧ����λ��
		stuin >> ttid;
		stuin >> tmajor;
		MajorCheck(tmajor,major); //����רҵ
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
		pp->set_next(NULL); //Ϊ����ѧ����λ��
		tail->set_next(p);
		tail = p;
		ptail->set_next(pp);//Ϊ����ѧ����λ��
		ptail = pp;//Ϊ����ѧ����λ��
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
	//רҵ���ʼ��
	while (i1 != -1)
	{
		i1 = 0, i2 = 0;
		cout << "    ------------------------------------------------------\n";
		cout << "    |           ��ӭ�����о���¼ȡϵͳ                     |" << endl;
		cout << "    |           1.��¼                                     |" << endl;
		cout << "    |           2.�˳�                                     |" << endl;
		cout << "    ------------------------------------------------------\n";
		cout << "               ��ѡ��";
		cin >> i1;
		system("cls");
		switch (i1) {
		case 1:
			cout << "���������룺";
			while (cin >> password && i1!=-1)
			{
				if (strcmp(password, cpassword) == 0)
				{
					cout << "����ɹ�" << endl;
					Sleep(1000);
					system("cls");
					while (i1 != -1)
					{
						i1 = 0;
						cout << "----------------------------------\n";
						cout << "|    1.ѧ����Ϣ����                |" << endl;
						cout << "|    2.���й���ѧ��ɸѡ            |" << endl;
						cout << "----------------------------------\n";
						cout << "*����-1�˳�" << endl;
						cout << " ��ѡ��";
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
								cout << "1.�鿴ѧ����Ϣ" << endl;
								cout << "2.�޸�ѧ����Ϣ" << endl;
								cout << "3.����ѧ����Ϣ" << endl;
								cout << "4.ɾ��ѧ����Ϣ" << endl;
								cout << "----------------------------------\n";
								cout << "*����-1����" << endl;
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
									cout << "------�����Ǵ�����Ϣ-------" << endl;
									infop = stu;
									do { infop->ErrorCheck(); } while (infop = infop->get_next());
									cout << "�����κ����ַ���:";
									cin >> i1;
									break;
								case 2: system("cls");
									cout << "-----------------����Exit����---------------\n";
									cout << "������Ҫ�޸ĵ�ѧ����׼��֤�ţ�";
									char tid[20];
									cin >> tid;
									cout << endl;
									if (strcmp(tid, "Exit") == 0) break;
									infop = stu;
									ff=find(stu, tid);
									if (ff == NULL) cout << "δ�ҵ���Ӧѧ�� �����ԣ�";
									else {
										ff->list();
										cout << "�������ѧ���޸ĺ����Ϣ" << endl;
										cin >> tname >> ttid >> tmajor >> tis >> g1 >> g2 >> g3 >> g4;
										if (MajorCheck(tmajor, major))
										{
											cout << "���� " << tmajor << " רҵ" << endl;
											cout << "1.ȷ��   2.ȡ��" << endl;
											cin >> temp;
											if (temp == 2) break;
											MajorAdd(grad, major, MajorCheck(tmajor, major));
										}
										ff->edit(tname, ttid, tmajor, tis, g1, g2, g3, g4);
										stu->input(stu);
									};
									Sleep(1000);
									break;

								case 3: 
									system("cls");
									cout << "-----------------����Exit����---------------\n";
									cout << "������ѧ�����֣�";
									cin >> tname;
									cout << endl;
									if (strcmp(tname, "Exit") == 0) break;
									cout << "������׼��֤�ţ�";
									cin >> tid;
									cout << endl;
									infop = stu;
									ff = find(stu, tid);
									if (ff != NULL) 
									{
										cout << "��׼��֤���ظ���" <<endl<<endl;
										ff->list();
										cout << endl;
										cout << "1.����   2.ȡ��" << endl;
										cin >> temp;
										if (temp == 2) break;
										else 
										{
											cout << "��������" << endl;
											Sleep(500);
											system("cls");
											cout << "����������רҵ���Ƿ�Ӧ�졢��ѧ�ɼ������Գɼ������γɼ���רҵ�ɼ���";
											cin >> tmajor >> tis >> g1 >> g2 >> g3 >> g4;
											cout << "ȷ�����ӣ�" << endl;
											cout << "1.ȷ��   2.ȡ��" << endl;
											cin >> temp;
											if (temp == 2) break;
											if (MajorCheck(tmajor, major)) 
											{
												cout << "���� " << tmajor << " רҵ" << endl;
												cout << "1.ȷ��   2.ȡ��" << endl;
												cin >> temp;
												if (temp == 2) break;
												MajorAdd(grad, major, MajorCheck(tmajor, major));
											}
											ff->edit(tname, tid, tmajor, tis, g1, g2, g3, g4);
											Sleep(1000);
											break;
										}
									}
									cout << "����������רҵ���Ƿ�Ӧ�졢��ѧ�ɼ������Գɼ������γɼ���רҵ�ɼ���";
									cin>> tmajor >> tis >> g1 >> g2 >> g3 >> g4;
									cout << "ȷ�����ӣ�" << endl;
									cout << "1.ȷ��   2.ȡ��" << endl;
									cin >> temp;
									if (temp == 2) break;
									if (MajorCheck(tmajor, major))
									{
										cout << "���� " << tmajor << " רҵ" << endl;
										cout << "1.ȷ��   2.ȡ��" << endl;
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
									cout << "-----------------����Exit����---------------\n";
									cout << "������Ҫɾ����ѧ����׼��֤�ţ�";
									cin >> tid;
									if (strcmp(tid, "Exit") == 0) break;
									infop = stu;
									ff = find(stu, tid);
									if (ff == NULL) cout << "δ�ҵ���Ӧѧ�� �����ԣ�"; 
									else {
										ff->list();
										cout << "ȷ��ɾ����ѧ����" << endl;
										cout << "1.ȷ��ɾ��" << '\t' << "2.ȡ��" << endl;
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
								cout << "1.������ͳɼ�Ҫ��" << endl;
								cout << "2.�������ѧ��" << endl;
								cout << "3.�����רҵ��ͳɼ�Ҫ��" << endl;
								cout << "----------------------------------\n";
								cout << "*����-1����" << endl;
								cin >> i1;
								switch (i1)
								{
								case 1:
									system("cls");
									int lmath, lpolicy, llang, lpro, lsum;
									tm = 0;
									while (grad[tm].get_major()[0]!='\0')
									{
										cout << "������<";
										cout << grad[tm].get_major();
										cout<<">רҵ�ɼ�Ҫ��" << endl;
										cout << "��ѧ��ͷ֣�"; cin >> lmath;   cout << endl;
										cout << "������ͷ֣�"; cin >> llang;   cout << endl;
										cout << "������ͷ֣�"; cin >> lpolicy; cout << endl;
										cout << "רҵ��ͷ֣�"; cin >> lpro;    cout << endl;
										cout << "�ܷ���ͷ֣�"; cin >> lsum;    cout << endl;
										grad[tm].setcgrade(lmath, lpolicy, llang, lpro, lsum);
										tm++;
									}
									
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
											fp = fp->get_next();
										}
										ff = ff->get_next();
									}
									fp = pstu;
									plist(fp, pnum);
									fp->pinput(fp,pnum);
									while(pnum>0)
									{
										fp->plist();
										fp = fp->get_next();
										pnum--;
									}
									
									
									cout << "�����κ����ַ���:";
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
									cout << "�����κ����ַ���:";
									cin >> i1;
									break;
								default: i1 = -1;       break;

								}

							}
							i1 = -1; //  yuan0
							system("cls");
							break;
						default: break;
						}
					}
					if (i1 == -1) break;
				}
				else
				{
					cout << "--�������������--" << endl;
					Sleep(1000);
					system("cls");
					cout << "���������룺";
				}
			}
			break;
		case 2:
			i1 = -1;
			break;



		default:

			cout << "�������" << endl;
			i1 = 0;

			break;

		}
	}

	cout << "ллʹ��" << endl;
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
	students *ts = new students;
	students *s = pstu;
	for (int i = 1; i <= num ; i++)
	{
		for (int j = 1; j <= num  - i; j++)
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