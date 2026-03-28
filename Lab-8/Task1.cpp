#include <iostream>
#include <string>
using namespace std;

void printEmployeeSalary(class Employee);

class Employee {
private:
    int    employeeID;
    string employeeName;
    double employeeSalary;

public:
    friend class Payroll;
    friend void printEmployeeSalary(Employee emp);

    Employee() : employeeID(0), employeeName(""), employeeSalary(0.0) {}

    Employee(int id, string name, double salary)
        : employeeID(id), employeeName(name), employeeSalary(salary) {}

    int getID() const { return employeeID; }
    string getName() const { return employeeName; }
    double getSalary() const { return employeeSalary; }
};

class Payroll {
private:
    double taxRate;
    double benefitsCost;

public:
    Payroll(double tax, double benefits)
        : taxRate(tax), benefitsCost(benefits) {}

    double calculateNetSalary(Employee emp) {
        double grossSalary = emp.employeeSalary + 1000.0;
        double netSalary = grossSalary - (grossSalary * taxRate) - benefitsCost;
        return netSalary;
    }
};

void printEmployeeSalary(Employee emp) {
    cout << "  Name   : " << emp.employeeName    << "\n"
         << "  Salary : $" << emp.employeeSalary << "\n";
}

int main() {
    const int MAX_EMPLOYEES = 100;
    Employee employees[MAX_EMPLOYEES];
    int numEmployees;

    cout << "========================================\n";
    cout << "       EMPLOYEE PAYROLL SYSTEM          \n";
    cout << "========================================\n\n";

    double taxRate, benefitsCost;
    cout << "Enter tax rate (e.g. 0.15 for 15%): ";
    cin  >> taxRate;
    cout << "Enter benefits cost ($)            : ";
    cin  >> benefitsCost;

    Payroll payroll(taxRate, benefitsCost);

    cout << "\nHow many employees? ";
    cin  >> numEmployees;

    if (numEmployees > MAX_EMPLOYEES) {
        cout << "Maximum allowed is " << MAX_EMPLOYEES
             << ". Setting to " << MAX_EMPLOYEES << ".\n";
        numEmployees = MAX_EMPLOYEES;
    }

    cin.ignore();

    for (int i = 0; i < numEmployees; i++) {
        int    id;
        string name;
        double salary;

        cout << "\n--- Employee " << (i + 1) << " ---\n";
        cout << "  Enter ID     : ";  cin >> id;
        cin.ignore();
        cout << "  Enter Name   : ";  getline(cin, name);
        cout << "  Enter Salary : ";  cin >> salary;
        cin.ignore();

        employees[i] = Employee(id, name, salary);
    }

    cout << "\n========================================\n";
    cout << "            PAYROLL RESULTS             \n";
    cout << "========================================\n";

    for (int i = 0; i < numEmployees; i++) {
        cout << "\nEmployee " << (i + 1) << ":\n";
        printEmployeeSalary(employees[i]);

        double gross = employees[i].getSalary() + 1000.0;
        double net   = payroll.calculateNetSalary(employees[i]);

        cout << "  Gross Salary : $" << gross << "\n";
        cout << "  Net Salary   : $" << net   << "\n";
        cout << "----------------------------------------\n";
    }

    return 0;
}