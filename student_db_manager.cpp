// Напишите класс на C++, который реализует простую систему управления базой данных студентов. 
// Каждый студент представлен структурой Student, 
// содержащей следующие поля: id (целочисленный идентификатор), name (строка с именем студента), 
// и age (целочисленный возраст студента). 
//
// Ваш класс должен обеспечивать следующие возможности:
//
// - Добавление нового студента в базу данных. 
// - Удаление студента по идентификатору.
// - Получение информации о студенте по идентификатору. 
// - Используйте умный указатель std::shared_ptr для хранения и управления объектами студентов в контейнере внутри класса (например, std::vector или std::map). 


#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>

struct Student {
    int id;
    std::string name;
    int age;
};

class StudentDatabase {
private:
    std::vector<std::shared_ptr<Student>> students;

public:
    void addStudent(int id, const std::string& name, int age) {
        auto newStudent = std::make_shared<Student>(Student{id, name, age});
        students.push_back(newStudent);
    }

    void deleteStudent(int id) {
        students.erase(std::remove_if(students.begin(), students.end(),
            [id](const std::shared_ptr<Student>& student) { return student->id == id; }),
            students.end());
    }

    std::shared_ptr<Student> getStudent(int id) {
        auto it = std::find_if(students.begin(), students.end(),
            [id](const std::shared_ptr<Student>& student) { return student->id == id; });

        if (it != students.end()) {
            return *it;
        }

        return nullptr;
    }
};
