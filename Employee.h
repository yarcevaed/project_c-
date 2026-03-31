#pragma once
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include "Project.h"
using namespace std;

class Employee
{
protected:
    int id;
    string name;
    double worktime;
    double payment;
    double rate;
    Project* project;
public:
    Employee(int id, const string& name, double rate, Project* proj = nullptr);
    virtual ~Employee() {}

    virtual void calc() = 0;
    virtual void printInfo() const;

    void setWorkTime(double hours);
    void setProject(Project* proj);

    int getId() const;
    string getName() const;
    double getPayment() const;
    virtual string getPosition() const = 0;
    Project* getProject() const;

    virtual string toFileString() const;
};