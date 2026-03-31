#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include "Employee.h"
#include "Project.h"
#include "Factory.h"
#include "Personal.h" 
#include "Engineer.h" 
#include "Manager.h"
using namespace std;

void printAllStaff(const vector<Employee*>& staff);

void printStaffByProject(const vector<Employee*>& staff, const string& projectName);

void searchByPosition(const vector<Employee*>& staff, const string& position);

void searchByName(const vector<Employee*>& staff, const string& namePart);

void searchByPayment(const vector<Employee*>& staff, double amount, bool greater);

void createProject(vector<Project*>& projects);

void addEmployeeToProject(vector<Employee*>& staff, vector<Project*>& projects);

void moveEmployeeToAnotherProject(vector<Employee*>& staff, vector<Project*>& projects);

void saveToFile(const vector<Employee*>& staff, const string& filename);


int main()
{
    setlocale(LC_ALL, ".1251");
    vector<Project*> projects;
    vector<Employee*> staff = StaffFactory::makeStaff("staff.txt", projects);

    if (staff.empty())
    {
        cout << "Нет данных о сотрудниках. Проверьте файл staff.txt" << endl;
        return 1;
    }

    for (auto emp : staff)
    {
        emp->setWorkTime(160);

        if (Driver* d = dynamic_cast<Driver*>(emp))
        {
            d->setNightHours(20);
        }
        else if (Programmer* p = dynamic_cast<Programmer*>(emp))
        {
            p->setEarlyBonus(5000);
        }
        else if (Tester* t = dynamic_cast<Tester*>(emp))
        {
            t->setBugs(10, 200);
        }
        else if (TeamLeader* tl = dynamic_cast<TeamLeader*>(emp))
        {
            tl->setSubordinates(3);
        }
        else if (ProjectManager* pm = dynamic_cast<ProjectManager*>(emp))
        {
            pm->setSubordinates(5);
        }
        else if (SeniorManager* sm = dynamic_cast<SeniorManager*>(emp))
        {
            sm->setSubordinates(10);
        }
    }

    for (auto emp : staff)
    {
        emp->calc();
    }

    int choice;
    string filename = "staff.txt";

    do
    {
        cout << endl << "\tМеню:" << endl
         << "1. Вывести всех сотрудников" << endl
         << "2. Вывести сотрудников на проекте" << endl
         << "3. Поиск по должности" << endl
         << "4. Поиск по имени" << endl
         << "5. Поиск по зарплате (больше/меньше суммы)" << endl
         << "6. Создать новый проект" << endl
         << "7. Добавить сотрудника на проект" << endl
         << "8. Перевести сотрудника на другой проект" << endl
         << "9. Сохранить в файл" << endl
         << "0. Выход" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            printAllStaff(staff);
            break;
        case 2:
        {
            string proj;
            cout << "Введите название проекта: ";
            cin >> proj;
            printStaffByProject(staff, proj);
            break;
        }
        case 3:
        {
            string pos;
            cout << "Введите должность: ";
            cin >> pos;
            searchByPosition(staff, pos);
            break;
        }
        case 4:
        {
            string name;
            cout << "Введите часть имени: ";
            cin.ignore();
            getline(cin, name);
            searchByName(staff, name);
            break;
        }
        case 5:
        {
            double amount;
            char cmp;
            cout << "Введите сумму и знак (> или <): ";
            cin >> cmp >> amount;
            searchByPayment(staff, amount, cmp == '>');
            break;
        }
        case 6:
            createProject(projects);
            break;
        case 7:
            addEmployeeToProject(staff, projects);
            break;
        case 8:
            moveEmployeeToAnotherProject(staff, projects);
            break;
        case 9:
            saveToFile(staff, filename);
            break;
        case 0:
            cout << "Выход..." << endl;;
            break;
        default:
            cout << "Неверный выбор." << endl;;
        }
    } while (choice != 0);

    for (auto emp : staff)
    {
        delete emp;
    }

    for (auto proj : projects)
    {
        delete proj;
    }
}

void printAllStaff(const vector<Employee*>& staff)
{
    cout << endl << "\tВсе сотрудники:" << endl;
    cout << left << setw(5) << "ID" << setw(25) << "ФИО" << setw(15) << "Должность"
        << setw(10) << "Зарплата" << setw(10) << "Проект" << endl;
    for (auto emp : staff)
    {
        emp->printInfo();
    }
}

void printStaffByProject(const vector<Employee*>& staff, const string& projectName)
{
    cout << endl << "\tСотрудники на проекте " << projectName << ':' << endl;
    bool found = false;
    for (auto emp : staff)
    {
        if (emp->getProject() && emp->getProject()->getName() == projectName)
        {
            emp->printInfo();
            found = true;
        }
    }
    if (!found)
    {
        cout << "Нет сотрудников на этом проекте" << endl;
    }
}

void searchByPosition(const vector<Employee*>& staff, const string& position)
{
    cout << endl << "\tСотрудники с должностью " << position << ':' << endl;
    bool found = false;
    for (auto emp : staff)
    {
        if (emp->getPosition() == position)
        {
            emp->printInfo();
            found = true;
        }
    }
    if (!found)
    {
        cout << "Таких сотрудников не существет" << endl;
    }
}

void searchByName(const vector<Employee*>& staff, const string& namePart)
{
    cout << endl << "\tПоиск по имени \"" << namePart << "\":" << endl;
    bool found = false;
    for (auto emp : staff)
    {
        if (emp->getName().find(namePart) != string::npos)
        {
            emp->printInfo();
            found = true;
        }
    }
    if (!found)
    {
        cout << "Ничего не найдено" << endl;
    }
}

void searchByPayment(const vector<Employee*>& staff, double amount, bool greater)
{
    cout << endl << "\tСотрудники с зарплатой " << (greater ? ">" : "<") << " " << amount << ':' << endl;
    bool found = false;
    for (auto emp : staff)
    {
        if ((greater && emp->getPayment() > amount) || (!greater && emp->getPayment() < amount))
        {
            emp->printInfo();
            found = true;
        }
    }
    if (!found)
    {
        cout << "Нет таких сотрудников" << endl;
    }
}

void createProject(vector<Project*>& projects)
{
    string name;
    double budget;
    cout << "Введите название нового проекта: ";
    cin >> name;
    cout << "Введите бюджет: ";
    cin >> budget;
    projects.push_back(new Project(name, budget));
    cout << "Проект создан." << endl;
}

void addEmployeeToProject(vector<Employee*>& staff, vector<Project*>& projects)
{
    int id;
    cout << "Введите ID сотрудника: ";
    cin >> id;

    Employee* emp = nullptr;
    for (auto e : staff)
    {
        if (e->getId() == id)
        {
            emp = e;
            break;
        }
    }
    if (!emp)
    {
        cout << "Такого сотрудника не существет" << endl;
        return;
    }

    if (dynamic_cast<Cleaner*>(emp) || dynamic_cast<Driver*>(emp))
    {
        cout << "Этот сотрудник не может участвовать в проекте." << endl;
        return;
    }

    string projName;
    cout << "Введите название проекта: ";
    cin >> projName;

    Project* proj = nullptr;
    for (auto p : projects)
    {
        if (p->getName() == projName)
        {
            proj = p;
            break;
        }
    }
    if (!proj)
    {
        cout << "Данного проекта не существует. Хотите создать его? (y/n): ";
        char ans;
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            double budget;
            cout << "Введите бюджет: ";
            cin >> budget;
            proj = new Project(projName, budget);
            projects.push_back(proj);
        }
        else
        {
            return;
        }
    }

    emp->setProject(proj);
    cout << "Сотрудник добавлен на проект" << endl;
}

void moveEmployeeToAnotherProject(vector<Employee*>& staff, vector<Project*>& projects)
{
    int id;
    cout << "Введите ID сотрудника: ";
    cin >> id;

    Employee* emp = nullptr;
    for (auto e : staff)
    {
        if (e->getId() == id)
        {
            emp = e;
            break;
        }
    }
    if (!emp)
    {
        cout << "Такого сотрудника не существет" << endl;
        return;
    }

    if (dynamic_cast<Cleaner*>(emp) || dynamic_cast<Driver*>(emp))
    {
        cout << "Этот сотрудник не может участвовать в проекте." << endl;
        return;
    }

    string projName;
    cout << "Введите название нового проекта: ";
    cin >> projName;

    Project* proj = nullptr;
    for (auto p : projects)
    {
        if (p->getName() == projName)
        {
            proj = p;
            break;
        }
    }
    if (!proj)
    {
        cout << "Проект не найден. Хотите создать его? (y/n): ";
        char ans;
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
        {
            double budget;
            cout << "Введите бюджет: ";
            cin >> budget;
            proj = new Project(projName, budget);
            projects.push_back(proj);
        }
        else
        {
            return;
        }
    }

    emp->setProject(proj);
    cout << "Сотрудник переведён" << endl;
}

void saveToFile(const vector<Employee*>& staff, const string& filename)
{
    fstream file(filename);
    if (!file.is_open())
    {
        cerr << "Не удалось открыть файл для записи" << endl;
        return;
    }

    for (auto emp : staff)
    {
        file << emp->toFileString() << endl;
    }
    file.close();
    cout << "Данные сохранены в " << filename << endl;
}