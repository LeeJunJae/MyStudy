#include "student.h"




int main()
{
	srand(time(NULL));
	int select = 0;
	while (1)
	{
		printf("\n새로운데이터(0) /// 출력 : (1) /// 이름검색 : (2) /// 데이터 세이브 : (3) /// 데이터 불러오기 : (4) /// 초기화 : (9) /// 종료 :10 \n");

		scanf("%d", &select);
		if (select == Exit)
			break;


		system("cls");
		switch (select)
			{
				case NewData:
				{
					CreateData();
				}
				break;				

				case Print:
				{
					PrintData();
				}
				break;

				case FindName:
				{
					SearchName();
				}
				break;

				case SaveData:
				{
					FileSave();
				}
				break;

				case LoadData:
				{
					FileLoad();
				}
				break;

				case InitData:
				{
					Initailize();
				}
				break;

				
		}
	}
	free(newStudentData);
	free(studentData);
	
	return 0;
}
