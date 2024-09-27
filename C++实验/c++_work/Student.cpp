#include"Student.h"

//构造函数
Student::Student(map<string, int> grades) {
	
	this->grades = grades;
}

Student::Student(int id, string name, string sex, int term, int courseCount, map<string, int> grades)
{
// 设置学生信息
this->id = id;
this->name = name;
this->sex = sex;
this->term = term;
this->courseCount = courseCount;
this->grades = grades;
stuCount++;  // 更新学生数量
}

// 初始化静态成员变量 stuCount
int Student::stuCount = 0;

// 获取学生 ID
int Student::GetId() {
    return id;
}

// 设置学生 ID
void Student::SetId(int id) {
    this->id = id;
}

// 获取学生姓名
string Student::GetName() {
    return name;
}

// 设置学生姓名
void Student::SetName(string name) {
    this->name = name;
}

// 设置学生性别
void Student::SetSex(string sex) {
    this->sex = sex;
}

// 获取学生性别
string Student::GetSex() {
    return this->sex;
}

// 获取学生学期
int Student::GetTerm() {
    return term;
}

void Student::SetTerm(int term) {
	this->term = term;
}

int Student::GetCourseCount() {
	return courseCount;
}

void Student::SetCourseCount(int courseCount) {
	this->courseCount = courseCount;
}

void Student::SetGrades(map<string, int> grades) {
	this->grades = grades;
}

map<string, int> Student::GetGrades() {
	return this->grades;
}