#include "Car.h"




int main()
{
	Car* car = new Car("KIM", 100);
	//car->InitMember("KIM", 100);

	car->Accel();
	car->Accel();
	car->Accel();
	car->Accel();

	car->ShowCarState();

	car->Break();

	car->ShowCarState();

	car->~Car();




	return 0;
}