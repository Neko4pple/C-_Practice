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

public: //�����Ҵ� ����(������)
    MyClass(string className, int size) : className(className), size(size) {
        p = new Student[size];
    }

    ~MyClass() { //���� ��ȯ(�Ҹ���)
        delete[] p;
    }

    // get �Լ�
    string getClassName() { return className; }
    void setClassName(string className) { this->className = className; }

    // set �Լ�
    void setStudentName(int index, string name) {
        if (index >= 0 && index < size) {
            p[index].setName(name);
        }
        else {
            cout << "Invalid index." << endl;
        }
    }

    // �л� �̸� ���
    void displayStudents() {
        cout << "�б� " << className  << "�� �л����� ������ ����." << endl;
        for (int i = 0; i < size; ++i) {
            cout << "�л� #" << i + 1 << ": " << p[i].getName() << endl;
        }
    }
};

int main() {
    // special class�� �л� �̸� ���
    MyClass special("Special", 3);

    string name1;
    string name2;
    string name3;

    cout << "�л� 3���� �̸��� �Է��Ͻÿ�" << endl;
    cout << "�л� #1�� �̸�: ";
    cin >> name1;
    cout << "�л� #2�� �̸�: ";
    cin >> name2;
    cout << "�л� #3�� �̸�: ";
    cin >> name3;

    // set�Լ� ���
    special.setStudentName(0, name1);
    special.setStudentName(1, name2);
    special.setStudentName(2, name3);

    // ���
    special.displayStudents();

    return 0;
}


//201903268 ����