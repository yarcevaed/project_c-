#pragma once
#include "Employee.h"
class Personal : public Employee
{
public:
    Personal(int id, string name, double rate) : Employee(id, name, rate) {}

    double calcBase(double hours, double rate) override //производим расчет зарплаты
    {
        return hours * rate;
    }

    void calc() override {
        payment = calcBase(worktime, rate);
    }
};

class Cleaner : Personal
{

};

class Driver : Personal
{

};
