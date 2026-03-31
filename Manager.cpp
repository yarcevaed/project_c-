
#include "Manager.h"
#include <iostream>
using namespace std;

ProjectManager::ProjectManager(int id, const string& name, double rate, Project* proj)
    : Employee(id, name, rate, proj), subordinates(0)
{

}

void ProjectManager::setSubordinates(int count)
{
    subordinates = count;
}

double ProjectManager::calcBudgetPart() const
{
    if (project)
    {
        return project->getBudget() * 0.05;
    }
    return 0;
}

double ProjectManager::calcProAdditions() const
{
    return 0;
}

double ProjectManager::calcHeading() const
{
    return subordinates * 300;
}

void ProjectManager::calc() {
    payment = rate + calcBudgetPart() + calcHeading();
}

string ProjectManager::getPosition() const
{
    return "ProjectManager";
}

SeniorManager::SeniorManager(int id, const string& name, double rate, const vector<Project*>& projects)
    : ProjectManager(id, name, rate, nullptr), allProjects(projects)
{

}

void SeniorManager::setSubordinates(int count)
{
    ProjectManager::setSubordinates(count);
}

double SeniorManager::calcBudgetPart() const
{
    double total = 0;
    for (auto proj : allProjects)
    {
        total += proj->getBudget() * 0.02;
    }
    return total;
}

void SeniorManager::calc()
{
    payment = rate + calcBudgetPart() + calcHeading();
}

string SeniorManager::getPosition() const
{
    return "SeniorManager";
}
