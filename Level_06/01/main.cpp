#include <iostream>


class Rectangle
{
private :
	int width;
	int height;

public:
	Rectangle(int width, int height) : width(width), height(height)
	{
		//
	}

	void ShowRecInfo()
	{
		std::cout << "높이 : " << height << "길이 : " << width << std::endl;
	}
};


class Square : public Rectangle
{
private:
	//int side;

public:
	Square(int side) : Rectangle(side, side)
	{
		
	}

	void ShowAreaInfo()
	{
		std::cout << "square : " ;
		this->ShowRecInfo();
	}
};


int main()
{
	Rectangle rec(4, 3);
	rec.ShowRecInfo();

	Square sqt(7);
	sqt.ShowAreaInfo();


	return 0;
}