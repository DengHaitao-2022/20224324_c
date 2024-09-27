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
	void System();		//����ӿ�
	//�˵�
	void Menu();
	//�˳�
	void Exit();
	//¼��ѧ����Ϣ
	void AddInfo();
	//����ѧ����Ϣ
	void UpdateStu();
	//ɾ��
	void DeleteInfo();
	//�г�����ѧ����Ϣ
	void DisplayAllInfo();
	//��ʾָ��ѧ����Ϣ
	void DisplayTargetInfo();
	//��ѯ
	vector<Student> AcquireStu_Name(string name);		//by Term, Id, Failing grades
	vector<Student> AcquireStu_Id(int id);
	vector<Student> AcquireStu_Term(int term);
	vector<Student> AcquireStu_Fail(string course);
	//��ӡ
	void CoutInfo(vector<Student>::iterator it);
	//ͳ�Ƴɼ����ܷ֡�ƽ���֡���߷֡���ͷ֡������ʣ�
	void StatsGrade();
	//ͳ��һ�Ʒ���������
	void StateCountInGradeRange(string course);
	void StateCount();
	//�ɼ�����
	void Sort();
	//���ֽܷ�������
	void SortByTotal();
	//��ĳһ�γ̽�������
	void SortByCur(string course);
	//������Ϣ
	void SaveInfo(vector<Student> stus);
	//��ȡ��Ϣ
	void ReadInfo();

private:
	vector<Student> stus;
	void (StudentManager::*ptr[9])();
}; 