#pragma once
#include <vector>
#include <string>
#include "Employee.h"
#include "Project.h"

class StaffFactory 
{
public:
    static vector<Employee*> makeStaff(const string& filename, vector<Project*>& projects);
};
