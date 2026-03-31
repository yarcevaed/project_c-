#pragma once
#include <iostream>
#include <string>
using namespace std;


class Project
{

private:

    string name;
    double budget;

public:

    Project(const string& name, double budget);
    string getName() const;
    double getBudget() const;
    void setBudget(double newBudget);
};
