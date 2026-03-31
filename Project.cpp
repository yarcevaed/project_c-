#include "Project.h"
using namespace std;

Project::Project(const string& name, double budget) : name(name), budget(budget) 
{}
string Project::getName() const { return name; }
double Project::getBudget() const { return budget; }
void Project::setBudget(double newBudget) { budget = newBudget; }