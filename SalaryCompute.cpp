#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string name;
    int salary;
    static int totalEmployees; // 총 직원 수를 담당하는 static 변수

public:
    Employee(const string& name, int salary) : name(name), salary(salary) {
        totalEmployees++; // 직원 생성시 총 직원 수 증가
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

int Employee::totalEmployees = 0; // static 변수 초기화. 안하면 메모리 에러남.

class Bonus {
protected:
    int bonus;
    static int totalBonus; // 총 추가급여를 담당하는 static 변수

public:
    Bonus(int bonus) : bonus(bonus) {
        totalBonus += bonus; // 추가급여 생성시 총 추가급여 증가
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

int Bonus::totalBonus = 0; // static 변수 초기화

class FullTimeEmployee : public Employee, public Bonus { //주휴보너스 클래스
public:
    FullTimeEmployee(const string& name, int salary, int bonus)
        : Employee(name, salary), Bonus(bonus) {}

    void printDetails() {
        cout << "이름: " << getName() << endl;
        cout << "월급: " << getSalary() << endl;
        cout << "보너스: " << getBonus() << endl;
        cout << "전체 급여: " << getBonus() + getSalary() << endl;
    }
};

int main() {
    FullTimeEmployee emp1("정융", 50000, 5000);
    FullTimeEmployee emp2("윤성목", 55000, 6000);
    FullTimeEmployee emp3("오정빈", 60000, 3500);

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
