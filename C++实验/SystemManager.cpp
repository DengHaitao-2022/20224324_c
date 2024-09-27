#include "SystemManager.h"

//排序的指定科目名称
static string targetCour;

SystemManager::SystemManager()
{
	ptr[0] = &SystemManager::Exit;
	ptr[1] = &SystemManager::AddInfo;
	ptr[2] = &SystemManager::DisplayAllInfo;
	ptr[3] = &SystemManager::StatsGrade;
	ptr[4] = &SystemManager::StateCount;
	ptr[5] = &SystemManager::DisplayTargetInfo;
	ptr[6] = &SystemManager::Sort;
	ptr[7] = &SystemManager::UpdateStu;
	ptr[8] = &SystemManager::DeleteInfo;

	ReadInfo();
}

//管理接口
void SystemManager::System()
{
	int input = 1;
	while (input) {
		Menu();
		int select;
		cout << "请选择您将要进行的操作：" << endl;
		cin >> select;
		if (select < 0 || select > 8) {
			cout << "选择错误，请重新选择：" << endl;
			system("pause");
			system("cls");
			continue;
		}

		(this->*ptr[select])();
	}
}

//菜单
void SystemManager::Menu()
{
	cout << "***************************************" << endl
		<< "*******    0.退出	        *******" << endl
		<< "*******    1.增加学生		*******" << endl
		<< "*******    2.显示所有学生信息	*******" << endl
		<< "*******    3.统计学生各科情况	*******" << endl
		<< "*******    4.统计课程成绩分布	*******" << endl
		<< "*******    5.查找学生信息	*******" << endl
		<< "*******    6.对学生成绩排序	*******" << endl
		<< "*******    7.更新学生信息	*******" << endl
		<< "*******    8.删除学生信息	*******" << endl
		<< "***************************************" << endl;
}

//退出
void SystemManager::Exit()
{
	cout << "退出程序，欢迎下次使用！" << endl;
	exit(0);
}

//添加
void SystemManager::AddInfo()
{
	int num;
	cout << "请选择要添加的人数：" << endl;
	cin >> num;

	int id;
	string name;
	string sex;
	int term;
	int courseCount;
	map<string, int> grades;

	for (int i = 0; i < num; i++) {
		cout << "请输入学号：";
		cin >> id;
		cout << "请输入姓名：";
		cin >> name;
		cout << "请输入性别：";
		cin >> sex;
		cout << "请输入学期：";
		cin >> term;
		cout << "请输入课程数量：";
		cin >> courseCount;
		cout << "请输入成绩：" << endl;
		for (int j = 0; j < courseCount; j++) {
			string course;
			int grade;
			cin >> course;
			while (1) {
				cin >> grade;
				if (0 <= grade && grade <= 100)
					break;
				else
					cout << "输入错误，请重新输入：";
			}

			grades.insert(make_pair(course, grade));
		}
		Student stu(id, name, sex, term, courseCount, grades);
		stus.push_back(stu);
		SaveInfo(stus);
		cout << "添加成功！" << endl;
		system("pause");
		system("cls");
	}
}

//更新学生信息
void SystemManager::UpdateStu()
{
	int id;
	cout << "请输入学生id：";
	cin >> id;

	int id1;
	string name;
	string sex;
	//int term;
	int courseCount;
	map<string, int> grades;

	for (vector<Student>::iterator it = stus.begin(); it != stus.end(); it++) {
		if ((*it).GetId() == id) {
			CoutInfo(it);

			cout << "请输入新的学号：";
			cin >> id1;
			cout << "请输入新的姓名：";
			cin >> name;
			cout << "请输入性别：";
			cin >> sex;
			//cout << "请输入学期：";
			//cin >> term;
			cout << "请输入课程数量：";
			cin >> courseCount;
			cout << "请输入成绩：" << endl;
			for (int j = 0; j < courseCount; j++) {
				string course;
				int grade;
				cin >> course;
				while (1) {
					cin >> grade;
					if (0 <= grade && grade <= 100)
						break;
					else
						cout << "输入错误，请重新输入：";
				}
				grades.insert(make_pair(course, grade));
			}
			it->SetId(id1);
			it->SetName(name);
			it->SetSex(sex);
			it->SetCourseCount(courseCount);
			it->SetGrades(grades);

			cout << "更新成功！" << endl;
			system("pause");
			system("cls");
		}
	}
	SaveInfo(stus);
}

//删除
void SystemManager::DeleteInfo()
{
	int id;
	cout << "请输入需要删除学生的id：";
	cin >> id;
	int pos = 0;
	for (vector<Student>::iterator it = stus.begin(); it != stus.end(); it++) {

		if ((*it).GetId() == id) {
			stus.erase(stus.begin() + pos);
			cout << "删除成功！" << endl;
			system("pause");
			system("cls");
			break;
		}
		pos++;
	}
	SaveInfo(stus);
}

//显示所有学生
void SystemManager::DisplayAllInfo()
{
	system("cls");
	for (vector<Student>::iterator it = stus.begin(); it != stus.end(); it++) {
		CoutInfo(it);
	}
	system("pause");
	system("cls");
}

//显示指定学生
void SystemManager::DisplayTargetInfo()
{
	int id;
	string name;
	int term;
	int input;
	cout << "请选择查找方式：" << endl
		<< "1.name		2.id		3.term" << endl;
	cin >> input;
	if (input == 1) {
		cout << "请输入要查找学生的姓名：";
		cin >> name;
		system("cls");
		vector<Student> stusTemp = AcquireStu_Name(name);
		for (vector<Student>::iterator it = stusTemp.begin(); it != stusTemp.end(); it++) {
			CoutInfo(it);
		}
		system("pause;");
		system("cls");
	}
	if (input == 2) {
		cout << "请输入要查找学生的学号：";
		cin >> id;
		system("cls");
		vector<Student> stusTemp = AcquireStu_Id(id);
		for (vector<Student>::iterator it = stusTemp.begin(); it != stusTemp.end(); it++) {
			CoutInfo(it);
		}
		system("pause;");
		system("cls");
	}
	if (input == 3) {
		cout << "请输入要查找的学期：";
		cin >> term;
		system("cls");
		vector<Student> stusTemp = AcquireStu_Term(term);
		for (vector<Student>::iterator it = stusTemp.begin(); it != stusTemp.end(); it++) {
			CoutInfo(it);
		}
		system("pause;");
		system("cls");
	}
}

//获取指定学生
//按姓名
vector<Student> SystemManager::AcquireStu_Name(string name)
{
	vector<Student> temp;
	for (vector<Student>::iterator it = stus.begin(); it != stus.end(); it++) {
		if ((*it).GetName() == name) {
			temp.push_back(*it);
		}
	}
	return temp;
}
//按学号
vector<Student> SystemManager::AcquireStu_Id(int id)
{
	vector<Student> temp;
	for (vector<Student>::iterator it = stus.begin(); it != stus.end(); it++) {
		if ((*it).GetId() == id) {
			temp.push_back(*it);
		}
	}
	return temp;
}
//按学期
vector<Student> SystemManager::AcquireStu_Term(int term)
{
	vector<Student> temp;
	for (vector<Student>::iterator it = stus.begin(); it != stus.end(); it++) {
		if ((*it).GetId() == term) {
			temp.push_back(*it);
		}
	}
	return temp;

}
//按是否及格
vector<Student> SystemManager::AcquireStu_Fail(string course) {
	vector<Student> temp;
	for (vector<Student>::iterator it = stus.begin(); it != stus.end(); it++) {
		if (it->GetGrades().find(course)->second < 60) {
			temp.push_back(*it);
		}
	}
	return temp;
}

//打印学生信息
void SystemManager::CoutInfo(vector<Student>::iterator it)
{
	map<string, int> grades = it->GetGrades();		//没有此行会出现越界访问，就是指针已经销毁任然访问
	cout << "学号：" << it->GetId()
		<< "\t姓名：" << it->GetName()
		<< " \t性别：" << it->GetSex()
		<< "\t学期：" << it->GetTerm()
		<< "\t课程数量：" << it->GetCourseCount() << endl;
	//for (map<string, int>::iterator it1 = it->GetGrades().begin(); it1 != it->GetGrades().end(); it1++) {
	cout << "成绩：";
	for (map<string, int>::iterator it1 = grades.begin(); it1 != grades.end(); it1++) {
		cout << it1->first << "：" << it1->second << " ";
	}
	cout << endl;
}

//统计学生成绩
void SystemManager::StatsGrade()
{
	int id;
	cout << "请输入学生id：";
	cin >> id;
	vector<Student> s = AcquireStu_Id(id);
	if (s.size() == 0) {
		cout << "查无此人！" << endl;
		system("pause");
		system("cls");
		return;
	}
	map<string, int> grades = s[0].GetGrades();

	int total = 0;
	int average = 0;
	int maxGrade = 0;
	int minGrade = 0;
	float passRate = 0;
	int failCount = 0;
	int courseCount = s[0].GetCourseCount();

	map<string, int>::iterator it;
	for (it = grades.begin(); it != grades.end(); it++) {
		int grade = it->second;
		total += grade;

		maxGrade = maxGrade > grade ? maxGrade : grade;
		minGrade = minGrade < grade ? minGrade : grade;

		if (grade < 60)
			failCount++;
	}
	average = total / courseCount;
	passRate = (courseCount - failCount) / courseCount;
	system("cls");
	cout << "总分为：" << total
		<< "  最高分为：" << maxGrade
		<< "  最低分为：" << minGrade
		<< "  及格率为：" << passRate << endl;
	system("pause");
	system("cls");
}

//统计学科成绩
void SystemManager::StateCountInGradeRange(string course) {
	int gradeRange[5] = { 0, 0, 0, 0, 0 };	//不及格 60-69 70-79 80-89 90-100
	for (vector<Student>::iterator it = stus.begin(); it!= stus.end(); it++) {
		map<string, int> grades = it->GetGrades();
		int grade = grades[course];
		if (grade >= 90)
			gradeRange[0]++;
		else if (80 <= grade && grade < 90)
			gradeRange[1]++;
		else if (70 <= grade && grade < 80)
			gradeRange[2]++;
		else if (60 <= grade && grade < 70)
			gradeRange[3]++;
		else
			gradeRange[4]++;
	}
	system("cls");
	cout << "90-100的人数为：" << gradeRange[0] << endl
		<< "80-89的人数为：" << gradeRange[1] << endl
		<< "70-79的人数为：" << gradeRange[2] << endl
		<< "60-69的人数为：" << gradeRange[3] << endl
		<< "不及格的人数为：" << gradeRange[4] << endl;
	system("pause");
	system("cls");
}
void SystemManager::StateCount() {
	string course;
	cout << "请输入需要统计的科目：";
	cin >> course;
	StateCountInGradeRange(course);
	system("cls");
}

//保存信息
void SystemManager::SaveInfo(vector<Student> stus)
{
	ofstream ofs;
	ofs.open(STUDENTFILE, ios::out);
	for (vector<Student>::iterator it = stus.begin(); it != stus.end(); it++) {
		int count = it->GetCourseCount();
		map<string, int> grades = it->GetGrades();

		ofs << it->GetId() << " "
			<< it->GetName() << " "
			<< it->GetSex() << " "
			<< count << " ";

		//for (int i = 0; i < count; i++) {
		//	ofs << grades[i] << " ";
		//}
		for (map<string, int>::iterator it1 = grades.begin(); it1 != grades.end(); it1++) {
			ofs << it1->first << " " << it1->second << " ";
		}
		ofs << it->GetTerm() << endl;
	}

	ofs.close();
}

//降序排序
bool TotalDown(Student s1, Student s2) {
	map<string, int> grades1 = s1.GetGrades();
	map<string, int> grades2 = s2.GetGrades();
	int total1 = 0;
	for (map<string, int>::iterator it = grades1.begin(); it != grades1.end(); it++) {
		total1 += it->second;
	}
	int total2 = 0;
	for (map<string, int>::iterator it = grades2.begin(); it != grades2.end(); it++) {
		total2 += it->second;
	}
	return total1 > total2;
}
bool CourDown(Student s1, Student s2) {
	map<string, int> grades1 = s1.GetGrades();
	map<string, int> grades2 = s2.GetGrades();
	return grades1[targetCour] > grades2[targetCour];
}
//排序
void SystemManager::Sort()
{
	int input;
	cout << "请选择排序的方式：" << endl;
	cout << "1.总分  2.单科课程" << endl;
	cin >> input;
	if (input == 1) {
		SortByTotal();
	}
	else if (input == 2) {
		string course;
		cout << "请输入课程名称：";
		cin >> course;
		SortByCur(course);
	}
}
//按总分
void SystemManager::SortByTotal()
{
	sort(stus.begin(), stus.end(), TotalDown);
	//cout << "排序结果为：" << endl;
	DisplayAllInfo();
}
//按单科
void SystemManager::SortByCur(string course)
{
	targetCour = course;
	sort(stus.begin(), stus.end(), CourDown);
	DisplayAllInfo();
}

//读取学生信息
void SystemManager::ReadInfo()
{
	ifstream ifs;
	ifs.open(STUDENTFILE, ios::in);

	if (!ifs.is_open()) {
		cout << "文件打开失败！" << endl;
		ifs.close();
		return;
	}
	if (ifs.get() == EOF) {
		//cout << "文件数据为空！" << endl;
		return;
	}
	ifs.close();

	//打开成功
	ifs.open(STUDENTFILE, ios::in);

	while (1) {
		int id;
		string name;
		string sex;
		int term;
		int courseCount;
		map<string, int> grades;
		ifs >> id >> name >> sex >> courseCount;
		for (int i = 0; i < courseCount; i++) {
			string course;
			int grade;
			ifs >> course >> grade;
			grades.insert(pair<string, int>(course, grade));
		}
		ifs >> term;
		Student s(id, name, sex, term, courseCount, grades);
		stus.push_back(s);
		if (ifs.get() == EOF)
			break;
	}
	stus.pop_back();
	ifs.close();
}
