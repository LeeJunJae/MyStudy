#pragma once
#include <iostream>
using namespace std;


template <typename T>
class Point
{
private:
	T yPos;
	T xPos;

public:
	void ShowPosition() const;
	

public:
	Point(T x , T y );
	~Point();

};
template<typename T>
void Point<T>::ShowPosition() const
{
	cout << "[" << yPos << "," << xPos << "]" << endl;
}

template <typename T>
Point<T>::Point(T x , T y) 
{
	this->xPos = x;
	this->yPos = y;
}

template <typename T>
Point<T>::~Point()
{

}

