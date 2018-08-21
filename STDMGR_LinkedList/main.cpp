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

		std::cout << "�л� ��� ���� ���α׷�" << std::endl;
		std::cout << "0. �߰�, 1. ���, 2. �˻�, 3. ����, 4.����, 5,�ҷ�����, 6.����" << std::endl;
		std::cin >> menu;
		switch (menu)
		{
			case Menu::CREATE:
			{
				stdmgr.Input();
				std::cout << "�ԷµǾ����ϴ�." << std::endl;
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
				std::cout << "�л����� �Է��ϼ���." << std::endl;
				std::cout << "�Է� : ";
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