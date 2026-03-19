#pragma once
#include <string>
using namespace std;

class Project
{
private:

    string name;
    int budget;

public:

    Project(const string& name, int budget);

    string getName() const;

    int getBudget() const;

    void setBudget(int newBudget);
};