#pragma once
#include "Employee.h"
#include "Interfaces.h"
class Personal : public Employee, public IWorkBaseTime
{
public:
    Personal(int id, string name, int rate, int worktime) : Employee(id, name, rate, worktime) {}
    int calcBase(int rate, int worktime)
};

class Cleaner : Personal
{

};

class Driver : Personal
{           
public:

    int NightHours;                 //Добавляем ночные часы
    Driver(int id, string name, int rate, int worktime) : Personal(id, name, rate, worktime) 
    {
        int NightHours = 0;
    }
    int calcBase(int rate, int worktimen)
    
};
