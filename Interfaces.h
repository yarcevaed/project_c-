#pragma once
class IWorkBaseTime
{

public:

    virtual ~IWorkBaseTime() {}
    virtual double calcBase() const = 0;
    virtual double calcBonus() const = 0;
};

class IProjectBudget
{

public:

    virtual ~IProjectBudget() {}
    virtual double calcBudgetPart() const = 0;
    virtual double calcProAdditions() const = 0;
};

class IHeading
{

public:

    virtual ~IHeading() {}
    virtual double calcHeading() const = 0;
};