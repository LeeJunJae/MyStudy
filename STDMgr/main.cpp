#include "student.h"




int main()
{
	srand(time(NULL));
	int select = 0;
	while (1)
	{
		printf("\n���ο����(0) /// ��� : (1) /// �̸��˻� : (2) /// ������ ���̺� : (3) /// ������ �ҷ����� : (4) /// �ʱ�ȭ : (9) /// ���� :10 \n");

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
