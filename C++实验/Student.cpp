#include"Student.h"

Student::Student(map<string, int> grades) {
	this->grades = grades;
}

Student::Student(int id, string name, string sex, int term, int courseCount, map<string, int> grades)
{
	this->id = id;
	this->name = name;
	this->sex = sex;
	this->term = term;
	this->courseCount = courseCount;
	this->grades = grades;
	stuCount++;
}
int Student::stuCount = 0;

int Student::GetId()
{
	return id;
}

void Student::SetId(int id)
{
	this->id = id;
}

string Student::GetName()
{
	return name;
}

void Student::SetName(string name)
{
	this->name = name;
}

void Student::SetSex(string sex)
{
	this->sex = sex;
}

string Student::GetSex()
{
	return this->sex;
}

int Student::GetTerm()
{
	return term;
}

void Student::SetTerm(int term)
{
	this->term = term;
}

int Student::GetCourseCount()
{
	return courseCount;
}

void Student::SetCourseCount(int courseCount)
{
	this->courseCount = courseCount;
}

void Student::SetGrades(map<string, int> grades)
{
	this->grades = grades;
}

map<string, int> Student::GetGrades()
{
	return this->grades;
}