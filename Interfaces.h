#pragma once
class IWorkBaseTime
{
public:
	int calcBase(int salary, int worktime) // метод расчета зарплаты исходя из оклада (за час) и отработанных часов
	{
		return salary * worktime;
	}
	virtual int calcBonus() //дополнительные выплаты
	{

	}

};

class IProjectBudget
{
public:
	int calcBudgetPart(float part, int budget) //расчет выплат из бюджета проекта
	{

	}
	int calcProAdditions() //расчет *бонусных* выплат
	{

	}

};

class IHeading
{
public: 
	int calcHeads() //расчет оплаты исходя из руководства (количество подчиненных)
	{

	}
};
