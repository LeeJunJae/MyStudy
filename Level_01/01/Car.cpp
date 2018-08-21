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
	cout << "���� : " << fuelGage << endl;
	cout << "����ӵ� : " << curSpeed << endl;
}

void Car::Accel()
{
	if (curSpeed > 200)
	{
		cout << "���Ѽӵ� �������� �ʰ��߽��ϴ�." << endl;
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
		cout << "���� �����Ͽ����ϴ�." << endl;
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
