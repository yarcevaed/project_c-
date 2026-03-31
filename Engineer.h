#pragma once
#include <iostream>
#include "Personal.h"
#include "Interfaces.h"
using namespace std;

class Engineer : public Personal, public IProjectBudget
{
public:

    Engineer(int id, const string& name, double rate, Project* proj);
    virtual ~Engineer() {}

    virtual double calcBudgetPart() const override;
    virtual double calcProAdditions() const override;

    virtual void calc() override;
    virtual string getPosition() const override;
};

class Programmer : public Engineer
{
private:

    double earlyBonus;

public:

    Programmer(int id, const string& name, double rate, Project* proj);
    void setEarlyBonus(double bonus);
    virtual double calcProAdditions() const override;
    virtual string getPosition() const override;
};

class Tester : public Engineer
{
private:

    int foundBugs;
    double bonusPerBug;
public:

    Tester(int id, const string& name, double rate, Project* proj);
    void setBugs(int bugs, double perBug);
    virtual double calcProAdditions() const override;
    virtual string getPosition() const override;
};

class TeamLeader : public Programmer, public IHeading
{
private:

    int subordinates;
public:

    TeamLeader(int id, const string& name, double rate, Project* proj);
    void setSubordinates(int count);
    virtual double calcHeading() const override;
    virtual void calc() override;
    virtual string getPosition() const override;
};
