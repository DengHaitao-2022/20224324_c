#pragma once
#include<iostream>
#include"Student.h"
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;

#define STUDENTFILE "student_file.txt"

class StudentManager
{
public:
	StudentManager();
	void System();		//管理接口
	//菜单
	void Menu();
	//退出
	void Exit();
	//录入学生信息
	void AddInfo();
	//更新学生信息
	void UpdateStu();
	//删除
	void DeleteInfo();
	//列出所有学生信息
	void DisplayAllInfo();
	//显示指定学生信息
	void DisplayTargetInfo();
	//查询
	vector<Student> AcquireStu_Name(string name);		//by Term, Id, Failing grades
	vector<Student> AcquireStu_Id(int id);
	vector<Student> AcquireStu_Term(int term);
	vector<Student> AcquireStu_Fail(string course);
	//打印
	void CoutInfo(vector<Student>::iterator it);
	//统计成绩（总分、平均分、最高分、最低分、及格率）
	void StatsGrade();
	//统计一科分数段人数
	void StateCountInGradeRange(string course);
	void StateCount();
	//成绩排序
	void Sort();
	//对总分进行排序
	void SortByTotal();
	//对某一课程进行排序
	void SortByCur(string course);
	//保存信息
	void SaveInfo(vector<Student> stus);
	//读取信息
	void ReadInfo();

private:
	vector<Student> stus;
	void (StudentManager::*ptr[9])();
}; 