#include "Factory.h"
#include "Personal.h"
#include "Engineer.h"
#include "Manager.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

vector<Employee*> StaffFactory::makeStaff(const string& filename, vector<Project*>& projects)
{
    vector<Employee*> staff;
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Íå óäàëîñü îòêðûòü ôàéë " << filename << endl;
        return staff;
    }

    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        int id;
        string name, position, projName;
        double rate;

        string firstName, lastName, middleName;
        iss >> id >> lastName >> firstName >> middleName >> position >> rate;
        name = lastName + " " + firstName + " " + middleName;

        if (iss >> projName)
        {
            Project* proj = nullptr;
            for (auto p : projects) {
                if (p->getName() == projName) {
                    proj = p;
                    break;
                }
            }
            if (!proj)
            {
                proj = new Project(projName, 100000);
                projects.push_back(proj);
            }

            if (position == "Cleaner")
            {
                staff.push_back(new Cleaner(id, name, rate, nullptr));
            }
            else if (position == "Driver")
            {
                staff.push_back(new Driver(id, name, rate, nullptr));
            }
            else if (position == "Programmer")
            {
                staff.push_back(new Programmer(id, name, rate, proj));
            }
            else if (position == "Tester")
            {
                staff.push_back(new Tester(id, name, rate, proj));
            }
            else if (position == "TeamLeader")
            {
                staff.push_back(new TeamLeader(id, name, rate, proj));
            }
            else if (position == "ProjectManager")
            {
                staff.push_back(new ProjectManager(id, name, rate, proj));
            }
            else if (position == "SeniorManager")
            {
                staff.push_back(new SeniorManager(id, name, rate, projects));
            }
            else
            {
                cerr << "Íåèçâåñòíàÿ äîëæíîñòü: " << position << endl;
            }
        }
        else
        {
            if (position == "Cleaner")
            {
                staff.push_back(new Cleaner(id, name, rate, nullptr));
            }
            else if (position == "Driver")
            {
                staff.push_back(new Driver(id, name, rate, nullptr));
            }
            else if (position == "SeniorManager")
            {
                staff.push_back(new SeniorManager(id, name, rate, projects));
            }
            else
            {
                cerr << "Äëÿ äîëæíîñòè " << position << " òðåáóåòñÿ ïðîåêò, íî îí íå óêàçàí." << endl;
            }
        }
    }

    file.close();
    return staff;
}
