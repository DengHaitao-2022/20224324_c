#include"Student.h"

//���캯��
Student::Student(map<string, int> grades) {
	
	this->grades = grades;
}

Student::Student(int id, string name, string sex, int term, int courseCount, map<string, int> grades)
{
// ����ѧ����Ϣ
this->id = id;
this->name = name;
this->sex = sex;
this->term = term;
this->courseCount = courseCount;
this->grades = grades;
stuCount++;  // ����ѧ������
}

// ��ʼ����̬��Ա���� stuCount
int Student::stuCount = 0;

// ��ȡѧ�� ID
int Student::GetId() {
    return id;
}

// ����ѧ�� ID
void Student::SetId(int id) {
    this->id = id;
}

// ��ȡѧ������
string Student::GetName() {
    return name;
}

// ����ѧ������
void Student::SetName(string name) {
    this->name = name;
}

// ����ѧ���Ա�
void Student::SetSex(string sex) {
    this->sex = sex;
}

// ��ȡѧ���Ա�
string Student::GetSex() {
    return this->sex;
}

// ��ȡѧ��ѧ��
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