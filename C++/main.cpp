#include <iostream>

class AAA
{

public:
	virtual void fct()
	{
		std::cout << "call aaa" << std::endl;
	}
};


class BBB : public AAA
{
public:
	void fct()
	{
		std::cout << "call bbb" << std::endl;
	}
};

class CCC : public BBB
{
public:
	 void fct()
	{
		std::cout << "call CCC" << std::endl;
	}
};
int main()
{
	AAA* aaa = new CCC;

	aaa->fct();
	//////////

	return 0;
}