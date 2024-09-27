#include "StudentManager.h"

//�����ָ����Ŀ����
static string targetCour;

//���캯��
StudentManager::StudentManager()
{
	// ��ʼ������ָ�����飬��ÿ��ָ��ָ��һ����Ա����
	ptr[0] = &StudentManager::Exit;
	ptr[1] = &StudentManager::AddInfo;
	ptr[2] = &StudentManager::DisplayAllInfo;
	ptr[3] = &StudentManager::StatsGrade;
	ptr[4] = &StudentManager::StateCount;
	ptr[5] = &StudentManager::DisplayTargetInfo;
	ptr[6] = &StudentManager::Sort;
	ptr[7] = &StudentManager::UpdateStu;
	ptr[8] = &StudentManager::DeleteInfo;
	// ��ȡѧ����Ϣ
	ReadInfo();
}

// ����ӿ�
void StudentManager::System()
{
    int input = 1;
    while (input) {
        // ��ʾ�˵�
        Menu();
        int select;
        cout << "��ѡ������Ҫ���еĲ�����" << endl;
        cin >> select;
        // ����û������Ƿ�����Ч��Χ��
        if (select < 0 || select > 8) {
            cout << "ѡ�����������ѡ��" << endl;
            system("pause");
            system("cls");
            continue;
        }

        // �����û�ѡ��Ĳ�����Ӧ�ĳ�Ա����
        (this->*ptr[select])();
    }
}

//�˵�
void StudentManager::Menu()
{
	//��ӡ��һ���˵����г��û�����ѡ��Ĳ���
	cout << "***************************************" << endl
		<< "*******    0.�˳�	        *******" << endl
		<< "*******    1.����ѧ��		*******" << endl
		<< "*******    2.��ʾ����ѧ����Ϣ	*******" << endl
		<< "*******    3.ͳ��ѧ���������	*******" << endl
		<< "*******    4.ͳ�ƿγ̳ɼ��ֲ�	*******" << endl
		<< "*******    5.����ѧ����Ϣ	*******" << endl
		<< "*******    6.��ѧ���ɼ�����	*******" << endl
		<< "*******    7.����ѧ����Ϣ	*******" << endl
		<< "*******    8.ɾ��ѧ����Ϣ	*******" << endl
		<< "***************************************" << endl;
}

//�˳�
void StudentManager::Exit()
{
	//�˳�����
	cout << "�˳����򣬻�ӭ�´�ʹ�ã�" << endl;
	exit(0);
}

// ���ѧ����Ϣ
void StudentManager::AddInfo()
{
    int num;
    cout << "��ѡ��Ҫ��ӵ�������" << endl;
    cin >> num;

    for (int i = 0; i < num; i++) {
	int id;
	string name;
	string sex;
	int term;
	int courseCount;
	map<string, int> grades;

	cout << "������ѧ�ţ�";
	cin >> id;

	cout << "������������";
	cin >> name;

	cout << "�������Ա�";
	cin >> sex;

	cout << "������ѧ�ڣ�";
	cin >> term;

	cout << "������γ�������";
	cin >> courseCount;

	for (int j = 0; j < courseCount; j++) {
	    string course;
	    int grade;
	    cout << "������� " << (j + 1) << " �ſεĳɼ���";
	    cin >> course >> grade;

	    // ���ɼ��Ƿ�����Ч��Χ��
	    while (grade < 0 || grade > 100) {
		cout << "�����������������ɼ���0-100����";
		cin >> grade;
	    }

	    grades.insert(make_pair(course, grade));
	}

	// �����µ�ѧ��������ӵ��б�
	Student stu(id, name, sex, term, courseCount, grades);
	stus.push_back(stu);

	// ����ѧ����Ϣ
	SaveInfo(stus);

	cout << "ѧ����Ϣ��ӳɹ���" << endl;
    }

    // ����
    system("cls");
}

//����ѧ����Ϣ
void StudentManager::UpdateStu()
{
	int id;
	cout << "������ѧ��id��";
	cin >> id;

	int id1;
	string name;
	string sex;
	//int term;
	int courseCount;
	map<string, int> grades;

	for (vector<Student>::iterator it = stus.begin(); it != stus.end(); it++) {	//����ѧ����Ϣ
		if ((*it).GetId() == id) {
			CoutInfo(it);

			cout << "�������µ�ѧ�ţ�";
			cin >> id1;
			cout << "�������µ�������";
			cin >> name;
			cout << "�������Ա�";
			cin >> sex;
			//cout << "������ѧ�ڣ�";
			//cin >> term;
			cout << "������γ�������";
			cin >> courseCount;
			cout << "������ɼ���" << endl;
			for (int j = 0; j < courseCount; j++) {
				string course;
				int grade;
				cin >> course;
				while (1) {
					cin >> grade;
					if (0 <= grade && grade <= 100)
						break;
					else
						cout << "����������������룺";
				}
				grades.insert(make_pair(course, grade));
			}
			it->SetId(id1);
			it->SetName(name);
			it->SetSex(sex);
			it->SetCourseCount(courseCount);
			it->SetGrades(grades);

			cout << "����ѧ��Ϊ:"<<id1<<"��ѧ����Ϣ�ɹ���" << endl;
			system("pause");
			system("cls");
		}
	}
	SaveInfo(stus);
}

//ɾ��
void StudentManager::DeleteInfo()
{
	int id;
	cout << "��������Ҫɾ��ѧ����id��";
	cin >> id;
	int pos = 0;
	for (vector<Student>::iterator it = stus.begin(); it != stus.end(); it++) { 		//����ѧ����Ϣ

		if ((*it).GetId() == id) {
			stus.erase(stus.begin() + pos);
			cout << "ɾ��ѧ��Ϊ:"<<id<<"��ѧ����Ϣ�ɹ���" << endl;
			system("pause");
			system("cls");
			break;
		}
		pos++;
	}
	SaveInfo(stus);
}

//��ʾ����ѧ��
void StudentManager::DisplayAllInfo()
{
	system("cls");
	for (vector<Student>::iterator it = stus.begin(); it != stus.end(); it++) {
		CoutInfo(it);
	}
	system("pause");
	system("cls");
}

//��ʾָ��ѧ��
void StudentManager::DisplayTargetInfo()
{
	int id;
	string name;
	int input;
    int term;
	cout << "��ѡ����ҷ�ʽ��" << endl
	<< "1.name		2.id		3.term" << endl;
	cin >> input;
	if (input == 1) {
		cout << "������Ҫ����ѧ����������";
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
		cout << "������Ҫ����ѧ����ѧ�ţ�";
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
		cout << "������Ҫ���ҵ�ѧ�ڣ�";
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

//��ȡָ��ѧ��
//������
vector<Student> StudentManager::AcquireStu_Name(string name)
{
	vector<Student> temp;
	for (vector<Student>::iterator it = stus.begin(); it != stus.end(); it++) {
		if ((*it).GetName() == name) {
			temp.push_back(*it);
		}
	}
	return temp;
}
//��ѧ��
vector<Student> StudentManager::AcquireStu_Id(int id)
{
	vector<Student> temp;
	for (vector<Student>::iterator it = stus.begin(); it != stus.end(); it++) {
		if ((*it).GetId() == id) {
			temp.push_back(*it);
		}
	}
	return temp;
}

//��ѧ��
vector<Student> StudentManager::AcquireStu_Term(int term) {
	vector<Student> temp;
	for (vector<Student>::iterator it = stus.begin(); it != stus.end(); it++) {
		if (it->GetTerm() == term) {
			temp.push_back(*it);
		}
	}
	return temp;
}
//���Ƿ񼰸�
vector<Student> StudentManager::AcquireStu_Fail(string course) {
	vector<Student> temp;
	for (vector<Student>::iterator it = stus.begin(); it != stus.end(); it++) {
		if (it->GetGrades().find(course)->second < 60) {
			temp.push_back(*it);
		}
	}
	return temp;
}

//��ӡѧ����Ϣ
void StudentManager::CoutInfo(vector<Student>::iterator it)  
{
	map<string, int> grades = it->GetGrades();		//û�д��л����Խ����ʣ�����ָ���Ѿ�������Ȼ����
	cout << "ѧ�ţ�" << it->GetId()
		<< "\t������" << it->GetName()
		<< " \t�Ա�" << it->GetSex()
		<< "\tѧ�ڣ�" << it->GetTerm()
		<< "\t�γ�������" << it->GetCourseCount() << endl;
	//for (map<string, int>::iterator it1 = it->GetGrades().begin(); it1 != it->GetGrades().end(); it1++) {
	cout << "�ɼ���";
	for (map<string, int>::iterator it1 = grades.begin(); it1 != grades.end(); it1++) {
		cout << it1->first << "��" << it1->second << " ";
	}
	cout << endl;
}

//ͳ��ѧ���ɼ�
void StudentManager::StatsGrade()
{
	int id;
	cout << "������ѧ��id��";
	cin >> id;
	vector<Student> s = AcquireStu_Id(id);
	if (s.size() == 0) {
		cout << "���޴��ˣ�" << endl;
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

	map<string, int>::iterator it;	//������
	for (it = grades.begin(); it != grades.end(); it++) {
		int grade = it->second;
		total += grade;

		maxGrade = maxGrade > grade ? maxGrade : grade;
		minGrade = minGrade < grade ? minGrade : grade;

		if (grade < 60)
			failCount++;
	}
	average = total / courseCount; //ƽ����
	passRate = (courseCount - failCount) / courseCount; //������
	system("cls");
	cout << "�ܷ�Ϊ��" << total
		<< "  ��߷�Ϊ��" << maxGrade
		<< "  ��ͷ�Ϊ��" << minGrade
		<< "  ������Ϊ��" << passRate << endl;
	system("pause");
	system("cls");
}

//ͳ��ѧ�Ƴɼ�
void StudentManager::StateCountInGradeRange(string course) {
	int gradeRange[5] = { 0, 0, 0, 0, 0 };	//������ 60-69 70-79 80-89 90-100
	for (vector<Student>::iterator it = stus.begin(); it!= stus.end(); it++) {
		map<string, int> grades = it->GetGrades();	//û�д��л����Խ����ʣ�����ָ���Ѿ�������Ȼ����
		int grade = grades[course];	//��ȡָ���γ̵ĳɼ�
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
	cout << "90-100������Ϊ��" << gradeRange[0] << endl
		<< "80-89������Ϊ��" << gradeRange[1] << endl
		<< "70-79������Ϊ��" << gradeRange[2] << endl
		<< "60-69������Ϊ��" << gradeRange[3] << endl
		<< "�����������Ϊ��" << gradeRange[4] << endl;
	system("pause");
	system("cls");
}
void StudentManager::StateCount() {	//ͳ�ƿγ̳ɼ��ֲ�
	string course;
	cout << "��������Ҫͳ�ƵĿ�Ŀ��";
	cin >> course;
	StateCountInGradeRange(course);	
	system("cls");
}

//������Ϣ
void StudentManager::SaveInfo(vector<Student> stus)
{
	ofstream ofs;	//����ļ���
	ofs.open(STUDENTFILE, ios::out);	//���ļ�
	for (vector<Student>::iterator it = stus.begin(); it != stus.end(); it++) {	//����ѧ����Ϣ
		int count = it->GetCourseCount();	//��ȡ�γ�����
		map<string, int> grades = it->GetGrades();	//��ȡ�ɼ�

		ofs << it->GetId() << " "	//д���ļ�
			<< it->GetName() << " "	
			<< it->GetSex() << " "
			<< count << " ";

		//for (int i = 0; i < count; i++) {
		//	ofs << grades[i] << " ";
		//}
		for (map<string, int>::iterator it1 = grades.begin(); it1 != grades.end(); it1++) {	//�����ɼ�
			ofs << it1->first << " " << it1->second << " ";
		}
		ofs << it->GetTerm() << endl;
	}

	ofs.close();
}

//��������
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
//����
void StudentManager::Sort()
{
	int input;
	cout << "��ѡ������ķ�ʽ��" << endl;
	cout << "1.�ܷ�  2.���ƿγ�" << endl;
	cin >> input;
	if (input == 1) {
		SortByTotal();
	}
	else if (input == 2) {
		string course;
		cout << "������γ����ƣ�";
		cin >> course;
		SortByCur(course);
	}
}
//���ܷ�
void StudentManager::SortByTotal()
{
	//���ֽܷ�������
	sort(stus.begin(), stus.end(), TotalDown);
	//cout << "������Ϊ��" << endl;
	DisplayAllInfo();
}
//������
void StudentManager::SortByCur(string course)
{
	targetCour = course;
	sort(stus.begin(), stus.end(), CourDown);
	DisplayAllInfo();
}

//��ȡѧ����Ϣ
void StudentManager::ReadInfo()
{
	ifstream ifs;
	ifs.open(STUDENTFILE, ios::in);

	if (!ifs.is_open()) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		ifs.close();
		return;
	}
	if (ifs.get() == EOF) {
		//cout << "�ļ�����Ϊ�գ�" << endl;
		return;
	}
	ifs.close();

	//�򿪳ɹ�
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