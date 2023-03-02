#include "global.h"
#include<cstring>
int compareName(Student a, Student b)
{
	int comper = strcmp(a.GetName(), b.GetName());

	if (comper > 0)
		return 1;
	if (comper == 0)
		return 0;
	return -1;
}


int compareMath(Student a, Student b)
{
	if (a.GetMath() > b.GetMath())
		return 1;
	if (a.GetMath() < b.GetMath())
		return -1;
	return 0;
}

int compareEng(Student a, Student b)
{
	if (a.GetEng() > b.GetEng())
		return 1;
	if (a.GetEng() < b.GetEng())
		return -1;
	return 0;
}

int compareHis(Student a, Student b)
{
	if (a.GetHis() > b.GetHis())
		return 1;
	if (a.GetHis() < b.GetHis())
		return -1;
	return 0;
}

int compareAvg(Student a, Student b)
{
	if (a.Avg() > b.Avg())
		return 1;
	if (a.Avg() < b.Avg())
		return -1;
	return 0;
}


