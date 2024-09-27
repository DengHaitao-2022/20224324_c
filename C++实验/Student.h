#pragma once
#include<string>
#include<map>
using namespace std;

class Student {
public:
	Student(map<string, int> grades);
	Student(int id, string name, string sex, int term, int courseCount, map<string, int> grades);
	int GetId();
	void SetId(int id);
	string GetName();
	void SetName(string name);
	void SetSex(string sex);
	string GetSex();

	int GetTerm();
	void SetTerm(int term);
	int GetCourseCount();
	void SetCourseCount(int courseCount);
	//int* GetGrades();

	void SetGrades(map<string, int> grades);
	map<string, int> GetGrades();

private:
	int id;				//ѧ��
	string name;		//����
	string sex;			//�Ա�
	int term;			//ѧ��
	int courseCount;	//�γ�����
	map<string, int> grades;
	static int stuCount;
};
