#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"
#include <string.h>

using namespace CAR_CONST;

void Car::InitMember(char* name, int fuel)
{
	strcpy(this->gamerID, name);
	this->fuelGage = fuel;
	this->curSpeed = 0;

}

void Car::ShowCarState()
{
	cout << "ID : " << gamerID << endl;
	cout << "연료 : " << fuelGage << endl;
	cout << "현재속도 : " << curSpeed << endl;
}

void Car::Accel()
{
	if (curSpeed > 200)
	{
		cout << "제한속도 허용범위를 초과했습니다." << endl;
		curSpeed = 200;
	}
	else
	{
		curSpeed += ACC_STEP;
		fuelGage -= FUEL_STEP;
	}
	
}
void Car::Break()
{
	if ( curSpeed < 0)
	{
		cout << "차가 정지하였습니다." << endl;
		curSpeed = 0;
	}
	else
	{
		curSpeed -= BRK_STEP;
	}
}



Car::Car(const char* name, int fuel)
{
	strcpy(this->gamerID, name);
	this->fuelGage = fuel;
	this->curSpeed = 0;

}


Car::~Car()
{
	delete[] gamerID;

}
