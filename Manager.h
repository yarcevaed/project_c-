
#pragma once
#include "Employee.h"
#include "Interfaces.h"
#include <vector>
using namespace std;

class ProjectManager : public Employee, public IProjectBudget, public IHeading
{

private:

    int subordinates;

public:

    ProjectManager(int id, const string& name, double rate, Project* proj);
    void setSubordinates(int count);

    virtual double calcBudgetPart() const override;
    virtual double calcProAdditions() const override;

    virtual double calcHeading() const override;

    virtual void calc() override;
    virtual string getPosition() const override;
};

class SeniorManager : public ProjectManager
{

private:

    vector<Project*> allProjects;

public:

    SeniorManager(int id, const string& name, double rate, const vector<Project*>& projects);
    void setSubordinates(int count);

    virtual double calcBudgetPart() const override;

    virtual void calc() override;
    virtual string getPosition() const override;
};
