#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

// 定义学生结构体，包含姓名和绩点
struct Student {
	std::string name;
	double gpa;
};

// 自定义排序函数，先按照绩点排序，绩点相同则按照姓名的 ASCII 码值排序
bool compare(const Student& a, const Student& b) {
	if (a.gpa != b.gpa)
		return a.gpa > b.gpa;
	return a.name < b.name;
}

int main() {
	int classCount;  // 班级数量
	std::cin >> classCount;
	for (int i = 0; i < classCount; ++i) {
		int courseCount;  // 课程数量
		std::cin >> courseCount;
		std::vector<int> credits(courseCount);  // 存储每门课程的学分
		for (int j = 0; j < courseCount; ++j) {
			std::cin >> credits[j];
		}
		
		int studentCount;  // 学生数量
		std::cin >> studentCount;
		std::vector<Student> students(studentCount);  // 存储每个学生的信息
		for (int j = 0; j < studentCount; ++j) {
			std::cin >> students[j].name;
			double totalPoints = 0;  // 存储总绩点
			for (int k = 0; k < courseCount; ++k) {
				int score;  // 存储每门课程的成绩
				std::cin >> score;
				if (score >= 60) {  // 如果成绩大于等于60，则计算绩点
					totalPoints += ((score - 50) + 10 * credits[k]);
				}
			}
			students[j].gpa = totalPoints / 10;  // 计算学生的总绩点
		}
		
		// 使用自定义的 compare 函数对学生进行排序
		std::sort(students.begin(), students.end(), compare);
		
		// 输出班级信息和学生的排名
		std::cout << "class #" << (i + 1) << ":" << std::endl;
		for (const auto& s : students) {
			std::cout << std::left << std::setw(10) << s.name << " " << std::fixed << std::setprecision(2) << s.gpa << std::endl;
		}
		if (i != classCount - 1) {
			std::cout << std::endl;
		}
	}
	
	return 0;
}
