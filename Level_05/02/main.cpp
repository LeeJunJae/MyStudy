#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;


class MyFrienInfo
{
private:
	char* name;
	int age;
public:
	MyFrienInfo(char* name, int age) : name(name), age(age)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);

		this->age = age;
		std::cout << "BaseClass called" << std::endl;
	}
	~MyFrienInfo()
	{
		delete[] name;
	}

	void ShowMyFriendInfo()

	{

		cout << "이름: " << name << endl;

		cout << "나이: " << age << endl;

	}
};


class MyFirendDetailInfo : public MyFrienInfo
{
private:
	char* addr;
	char* phone;
public:
	MyFirendDetailInfo(char* name, int age, char* addr, char* phone) : MyFrienInfo(name, age), addr(addr), phone(phone)
	{
		this->addr = new char[strlen(addr) + 1];
		strcpy(this->addr, addr);
		this->phone = new char[strlen(phone) + 1];
		strcpy(this->phone, phone);
		std::cout << "DerivedClass called" << std::endl;
	}
	~MyFirendDetailInfo()
	{
		delete[] addr;
		delete[] phone;
	}

	void ShowMyFriendDetailInfo()

	{
		ShowMyFriendInfo();

		cout << "주소: " << addr << endl;

		cout << "전화: " << phone << endl << endl;

	}
};










int main()
{

	MyFirendDetailInfo* fr = new MyFirendDetailInfo("LJJ", 10, "JJ", "010");

	fr->ShowMyFriendDetailInfo();

	return 0;
}