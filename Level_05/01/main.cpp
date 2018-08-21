#include <iostream>

class Car
{
private :
	int gasolineGuage;
public:
	int GetGasGuage()
	{
		return gasolineGuage;
	}

	Car(int gasoline) : gasolineGuage(gasoline)
	{

	}
};


class HyBridCar : public Car
{
private:
	int electricGuage;
public:
	int GetElecGuage()
	{
		return electricGuage;
	}

	HyBridCar(int gasoline ,int elecGuage) : Car(gasoline), electricGuage(elecGuage)
	{
		//
	}
};


class HyBridWaterCar : public HyBridCar
{
private:
	int waterGauge;
public:
	HyBridWaterCar(int gasoline, int electric, int water) : HyBridCar(gasoline, electric), waterGauge(water)
	{
		//
	}

	void ShowCurrentGuage()
	{
		std::cout << "�ܿ� ���ָ� : " << GetGasGuage() << std::endl;
		std::cout << "�ܿ� ���ⷮ : " << GetElecGuage() << std::endl;
		std::cout << "�ܿ� ���ͷ� : " << waterGauge << std::endl;
	}
};


int main()
{
	HyBridWaterCar* waterCar = new HyBridWaterCar(10, 20, 30);

	waterCar->ShowCurrentGuage();


	delete waterCar;

	return 0;
}