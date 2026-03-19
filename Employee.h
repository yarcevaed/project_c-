#pragma once
#include <iostream>
#include <string>
using namespace std;
class Employee
{ protected:
    int id;                 // id
    string name;            // ФИО
    int worktime;           // отработанные часы
    int payment;            // вся зарплата
    int rate;             //ставка за час

public:
    // Конструктор
    Employee(int _id, string _name) 
    {
        id = _id;
        name = _name;
        worktime = 0;
        payment = 0;

    }

    // Виртуальный деструктор (чтоб всe правильно удалялось)
    virtual ~Employee() {}

    // Геттеры
    int getId() 
    {
        return id; 
    }
    string getName()
    {
        return name;
    }
    int getPayment() 
    { 
        return payment; 
    }
    int getWorkTime()  
    {
        return worktime; 
    }

    // Сеттер для времени
    void setWorkTime(int time)
    {
        worktime = time;
    }

    // Виртуальные методы (будут переопределяться в наследниках)
    virtual void calc() = 0;  // чистый виртуальный - значит Employee абстрактный
    virtual void printInfo() 
    {
        cout << "ID: " << id << ", Имя: " << name
            << ", Часы: " << worktime << ", Зарплата: " << payment << endl;
    }
};

