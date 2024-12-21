#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string name;
    int salary;
    static int totalEmployees; // �� ���� ���� ����ϴ� static ����

public:
    Employee(const string& name, int salary) : name(name), salary(salary) {
        totalEmployees++; // ���� ������ �� ���� �� ����
    }

    void setName(const string& name) {
        this->name = name;
    }

    void setSalary(int salary) {
        this->salary = salary;
    }

    string getName() const {
        return name;
    }

    int getSalary() const {
        return salary;
    }

    static int getTotalEmployees() {
        return totalEmployees;
    }
};

int Employee::totalEmployees = 0; // static ���� �ʱ�ȭ. ���ϸ� �޸� ������.

class Bonus {
protected:
    int bonus;
    static int totalBonus; // �� �߰��޿��� ����ϴ� static ����

public:
    Bonus(int bonus) : bonus(bonus) {
        totalBonus += bonus; // �߰��޿� ������ �� �߰��޿� ����
    }

    void setBonus(int bonus) {
        this->bonus = bonus;
    }

    int getBonus() const {
        return bonus;
    }

    static int getTotalBonus() {
        return totalBonus;
    }
};

int Bonus::totalBonus = 0; // static ���� �ʱ�ȭ

class FullTimeEmployee : public Employee, public Bonus { //���޺��ʽ� Ŭ����
public:
    FullTimeEmployee(const string& name, int salary, int bonus)
        : Employee(name, salary), Bonus(bonus) {}

    void printDetails() {
        cout << "�̸�: " << getName() << endl;
        cout << "����: " << getSalary() << endl;
        cout << "���ʽ�: " << getBonus() << endl;
        cout << "��ü �޿�: " << getBonus() + getSalary() << endl;
    }
};

int main() {
    FullTimeEmployee emp1("����", 50000, 5000);
    FullTimeEmployee emp2("������", 55000, 6000);
    FullTimeEmployee emp3("������", 60000, 3500);

    cout << "Employee 1 Details: " << endl;
    emp1.printDetails();
    cout << endl;

    cout << "Employee 2 Details: "<< endl;
    emp2.printDetails();
    cout << endl;

    cout << "Employee 3 Details: " << endl;
    emp3.printDetails();
    cout << endl;

    cout << "Total Employees: " << Employee::getTotalEmployees() << endl;
    cout << "Total Bonus: " << Bonus::getTotalBonus() << endl;

    return 0;
}
