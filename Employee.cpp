#include "Employee.h"
#include <iostream>
#include <iomanip>
using namespace std;

Employee::Employee(int id, const string& name, double rate, Project* proj)
    : id(id), name(name), rate(rate), worktime(0), payment(0), project(proj)
{}

void Employee::setWorkTime(double hours)
{
    worktime = hours;
}

void Employee::setProject(Project* proj)
{
    project = proj;
}

int Employee::getId() const { return id; }
string Employee::getName() const { return name; }
double Employee::getPayment() const { return payment; }
Project* Employee::getProject() const { return project; }

void Employee::printInfo() const
{
    cout << left << setw(5) << id
        << setw(25) << name
        << setw(15) << getPosition()
        << setw(10) << payment
        << setw(10) << (project ? project->getName() : "---") << endl;
}

string Employee::toFileString() const
{
    string projName = project ? project->getName() : "";
    return to_string(id) + " " + name + " " + getPosition() + " " + to_string(rate) + " " + projName;
}
