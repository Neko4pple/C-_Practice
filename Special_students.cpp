#include <iostream>
#include <string>

using namespace std;

class Student {
    string name;

public:
    Student(string name = "") : name(name) {}
    string getName() { return name; }
    void setName(string name) { this->name = name; }
};

class MyClass {
    string className;
    Student* p;
    int size;

public: //동적할당 시행(생성자)
    MyClass(string className, int size) : className(className), size(size) {
        p = new Student[size];
    }

    ~MyClass() { //공간 반환(소멸자)
        delete[] p;
    }

    // get 함수
    string getClassName() { return className; }
    void setClassName(string className) { this->className = className; }

    // set 함수
    void setStudentName(int index, string name) {
        if (index >= 0 && index < size) {
            p[index].setName(name);
        }
        else {
            cout << "Invalid index." << endl;
        }
    }

    // 학생 이름 출력
    void displayStudents() {
        cout << "학급 " << className  << "의 학생들은 다음과 같다." << endl;
        for (int i = 0; i < size; ++i) {
            cout << "학생 #" << i + 1 << ": " << p[i].getName() << endl;
        }
    }
};

int main() {
    // special class의 학생 이름 출력
    MyClass special("Special", 3);

    string name1;
    string name2;
    string name3;

    cout << "학생 3명의 이름을 입력하시오" << endl;
    cout << "학생 #1의 이름: ";
    cin >> name1;
    cout << "학생 #2의 이름: ";
    cin >> name2;
    cout << "학생 #3의 이름: ";
    cin >> name3;

    // set함수 사용
    special.setStudentName(0, name1);
    special.setStudentName(1, name2);
    special.setStudentName(2, name3);

    // 출력
    special.displayStudents();

    return 0;
}


//201903268 정융