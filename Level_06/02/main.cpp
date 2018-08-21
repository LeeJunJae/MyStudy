#define _CRT_SECURE_NO_WARNINGS
#include <iostream>



class Book
{
private:
	char* title;
	char* isbn;
	int price;

public:
	Book(const char* title, const char* isbn, int price)
	{
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);


		this->isbn = new char[strlen(isbn) + 1];
		strcpy(this->isbn, isbn);

		this->price = price;
	}

	void ShowBookInfo()
	{
		std::cout << "å�̸� : " << this->title << std::endl;
		std::cout << "������ȣ : " << this->isbn << std::endl;
		std::cout << "���� : " << this->price << std::endl;
	}
};

class Ebook : public Book
{
private:
	char* DRMKey;


public:
	Ebook(const char* title, const char* isbn, int price, const char* DRMKey) : Book(title, isbn, price)
	{
		this->DRMKey = new char[strlen(DRMKey) + 1];
		strcpy(this->DRMKey, DRMKey);
	}


	void ShowEBookInfo()
	{
		ShowBookInfo();
		std::cout << "����Ű : " << DRMKey << std::endl;
	}
};
 


int main()
{
	Book book("����c++", "1010-2323-2323", 20000);
	book.ShowBookInfo();


	std::cout << std::endl;

	Ebook ebook("����c++", "1010-2323-2323", 20000, "FDXXS12");
	ebook.ShowEBookInfo();
	




	return 0;
}