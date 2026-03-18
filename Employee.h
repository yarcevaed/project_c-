#pragma once
#include <iostream>
#include <string>
using namespace std;
class Employee
{ protected:
    int id;                 // табельный номер
    string name;            // ФИО
    double worktime;        // отработанные часы
    double payment;         // вся зарплата
    double rate;            //ставка за час

public:
    // Конструктор
    Employee(int _id, string _name) 
    {
        id = _id;
        name = _name;
        worktime = 0;
        payment = 0;

    }

    // Виртуальный деструктор (чтоб всё правильно удалялось)
    virtual ~Employee() {}

    // Сеттер для времени
    void setWorkTime(double time)
    {
        worktime = time;
    }

    // Геттеры
    int getId() { return id; }
    string getName() { return name; }
    double getPayment() { return payment; }
    double getWorkTime() { return worktime; }

    // Виртуальные методы (будут переопределяться в наследниках)
    virtual void calc() = 0;  // чистый виртуальный - значит Employee абстрактный
    virtual void printInfo() {
        cout << "ID: " << id << ", Имя: " << name
            << ", Часы: " << worktime << ", Зарплата: " << payment << endl;
    }
};

