#pragma once
#include <iostream>
#include "Employee.h"
#include "Interfaces.h"
using namespace std;

class Personal : public Employee, public IWorkBaseTime
{

public:

    Personal(int id, const string& name, double rate, Project* proj = nullptr);
    virtual ~Personal() {}

    virtual double calcBase() const override;
    virtual double calcBonus() const override;

    virtual void calc() override;
    virtual string getPosition() const override;
};

class Cleaner : public Personal
{

public:

    Cleaner(int id, const string& name, double rate, Project* proj = nullptr);
    virtual std::string getPosition() const override;
};

class Driver : public Personal
{

private:

    double nightHours;
    double nightRate;

public:

    Driver(int id, const string& name, double rate, Project* proj = nullptr);
    void setNightHours(double hours);
    virtual double calcBonus() const override;
    virtual string getPosition() const override;
};
