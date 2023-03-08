#include "Canvas.h"
int main()
{
	Canvas x(10, 10);
	//x.DrawCircle(5, 5, 4, '#');
	//x.FillCircle(5, 5, 3, '*');
	//x.DrawRect(1, 2, 3, 9, '-');
	//x.FillRect(2, 3, 1, 8, '+');
	x.SetPoint(2, 4, 'P');
	x.Print();
	x.Clear();

}


