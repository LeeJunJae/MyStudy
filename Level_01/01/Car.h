#pragma once
#include <iostream>

using namespace std;

namespace CAR_CONST
{
	enum  
	{
		ID_LEN = 20, MAX_SPD = 200, FUEL_STEP = 2,
		ACC_STEP = 10, BRK_STEP = 10
	};
}

class Car
{
private:
	char gamerID[CAR_CONST::ID_LEN];
	int  fuelGage;
	int  curSpeed;

public:
	void InitMember(char* name, int fuel);
	void ShowCarState();
	void Accel();
	void Break();

public:
	Car(const char* name, int fuel);
	~Car();
};

