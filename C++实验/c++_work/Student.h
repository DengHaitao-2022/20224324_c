#pragma once
#include<string>
#include<map>
using namespace std;

class Student {
public:
	
	Student(map<string, int> grades);	//构造函数, 用于测试
	Student(int id, string name, string sex, int term, int courseCount, map<string, int> grades);	//构造函数, 用于测试
	int GetId();	//获取学号
	void SetId(int id);		//设置学号
	string GetName();		//获取姓名
	void SetName(string name);		//设置姓名
	void SetSex(string sex);		//设置性别
	string GetSex();	//获取性别

	int GetTerm();	//获取学期
	void SetTerm(int term);	//设置学期
	int GetCourseCount();	//获取课程数量
	void SetCourseCount(int courseCount);	//设置课程数量
	//int* GetGrades();	//获取成绩

	void SetGrades(map<string, int> grades);	//设置成绩
	map<string, int> GetGrades();	//获取成绩

private:
	int id;				//学号
	string name;		//姓名
	string sex;			//性别
	int term;			//学期
	int courseCount;	//课程数量
	map<string, int> grades;	//成绩
	static int stuCount;	//学生数量
};