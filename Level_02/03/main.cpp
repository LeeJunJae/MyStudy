#include "POINT.h"
#include "RECTANGLE.h"
#include "Ring.h"


int main()
{
	Ring ring;
	ring.InitMember(1, 1, 4, 2, 2, 9);

	ring.PrintInfo();


	return 0;
}