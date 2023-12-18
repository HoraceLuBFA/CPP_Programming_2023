#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    std::string studentClass;
    int rollNumber;
    double marks;

public:
    // 构造函数
    Student(const std::string& studentName,
        const std::string& sClass, int rollNum, double studentMarks)
        : name(studentName)
        , studentClass(sClass)
        , rollNumber(rollNum)
        , marks(studentMarks)
    {
    }

    // 成员函数 根据分数判断成绩
    std::string calculateGrade()
    {
        if (marks >= 90) {
            return "A+";
        } else if (marks >= 80) {
            return "A";
        } else if (marks >= 70) {
            return "B";
        } else if (marks >= 60) {
            return "C";
        } else {
            return "D";
        }
    }

    // 成员函数 显示成绩
    void displayInformation()
    {
        std::cout << "\n\n姓名: " << name << std::endl;
        std::cout << "班级: " << studentClass << std::endl;
        std::cout << "学号: " << rollNumber << std::endl;
        std::cout << "分数: " << marks << std::endl;
        std::cout << "成绩: " << calculateGrade() << std::endl;
    }
};

int main()
{
    // 创建学生对象
    std::string studentName;
    std::string sClass;
    int rollNum;
    double studentMarks;
    std::cout << "学生信息: ";
    std::cout << "\n姓名: ";
    std::getline(std::cin, studentName);

    std::cout << "班级: ";
    std::getline(std::cin, sClass);

    std::cout << "学号: ";
    std::cin >> rollNum;

    std::cout << "分数（0-100）: ";
    std::cin >> studentMarks;

    Student student(studentName, sClass, rollNum, studentMarks);

    // 显示学生信息
    student.displayInformation();

    return 0;
}
