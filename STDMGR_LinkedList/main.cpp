#include "Student.h"
#include "StdMgr.h"
#include <Windows.h>
#include <time.h>

enum Menu
{
	CREATE,
	PRINT,
	SEARCH,
	CREATEDATA,
	SAVE,
	LOAD,
	Delete,
};



int main()
{
	srand(time(NULL));
	Menu title;
	int menu = 0;
	


	StdMgr stdmgr;
	while (true)
	{
		system("cls");

		std::cout << "학생 출결 관리 프로그램" << std::endl;
		std::cout << "0. 추가, 1. 출력, 2. 검색, 3. 생성, 4.저장, 5,불러오기, 6.삭제" << std::endl;
		std::cin >> menu;
		switch (menu)
		{
			case Menu::CREATE:
			{
				stdmgr.Input();
				std::cout << "입력되었습니다." << std::endl;
			}
			break;

			case Menu::PRINT:
			{
				stdmgr.Print();
				system("pause");
			}
			break;

			case Menu::SEARCH:
			{
				stdmgr.Search();
				system("pause");
			}
			break;

			case Menu::CREATEDATA:
			{
				std::cout << "학생수를 입력하세요." << std::endl;
				std::cout << "입력 : ";
				int num = 0;
				std::cin >> num;
				stdmgr.CreateData(num);
			}
			break;

			case Menu::SAVE:
			{
				stdmgr.FileSave();
			}
			break;

			case Menu::LOAD:
			{		
				
				stdmgr.FileLoad();
			}
			break;

			case Menu::Delete:
			{
				stdmgr.Delete();
				
			}
			break;

			default:
				break;
		}
	}




	return 0;
}