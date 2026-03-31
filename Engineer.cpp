#include "Engineer.h"
#include <iostream>
using namespace std;

Engineer::Engineer(int id, const string& name, double rate, Project* proj)
    : Personal(id, name, rate, proj)
{}

double Engineer::calcBudgetPart() const
{
    if (project)
    {
        return project->getBudget() * 0.01;
    }
    return 0;
}

double Engineer::calcProAdditions() const
{
    return 0;
}

void Engineer::calc()
{
    payment = calcBase() + calcBonus() + calcBudgetPart() + calcProAdditions();
}

string Engineer::getPosition() const
{
    return "Engineer";
}

Programmer::Programmer(int id, const string& name, double rate, Project* proj)
    : Engineer(id, name, rate, proj), earlyBonus(0)
{}

void Programmer::setEarlyBonus(double bonus)
{
    earlyBonus = bonus;
}

double Programmer::calcProAdditions() const
{
    return earlyBonus;
}

string Programmer::getPosition() const
{
    return "Programmer";
}

Tester::Tester(int id, const string& name, double rate, Project* proj)
    : Engineer(id, name, rate, proj), foundBugs(0), bonusPerBug(0)
{}

void Tester::setBugs(int bugs, double perBug)
{
    foundBugs = bugs;
    bonusPerBug = perBug;
}

double Tester::calcProAdditions() const
{
    return foundBugs * bonusPerBug;
}

string Tester::getPosition() const
{
    return "Tester";
}

TeamLeader::TeamLeader(int id, const string& name, double rate, Project* proj)
    : Programmer(id, name, rate, proj), subordinates(0) 
{}

void TeamLeader::setSubordinates(int count) {
    subordinates = count;
}

double TeamLeader::calcHeading() const
{
    return subordinates * 500;
}

void TeamLeader::calc()
{
    Programmer::calc();
    payment += calcHeading();
}

string TeamLeader::getPosition() const
{
    return "TeamLeader";
}