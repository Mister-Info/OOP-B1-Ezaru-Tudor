#include "Vector.h"

int main()
{

	Vector<int> v;
	v.insert(0, 10);
	v.insert(1, 5);
	v.insert(2, 20);
	v.insert(3, -9);
	v.sort();
	v.print();
	v.remove(2);
	v.print();

}