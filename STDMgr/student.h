#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <tchar.h>
#include <stdlib.h> // rand(), srand()
#include <time.h> 
#include <string.h> 
#include <conio.h> // conio.h

struct Student
{
	char  m_name[4];
	int   m_number;
	int   m_iKor;
	int   m_iMath;
	int   m_iEng;
	float m_average;
};


Student* studentData = 0;
Student* newStudentData = 0;
int      stdCount    = 0;

enum SELECTMENU
{
	NewData,
	Print,
	FindName,
	SaveData,
	LoadData,
	InitData     = 9,
	Exit         = 10,
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void Initailize()
{
	printf("�л��� ���ο��� �Է��ϼ���\n");
	scanf ("%d", &stdCount);

	if (studentData != NULL)
	{
		free(studentData);
		studentData = 0;
	}
	

	if(studentData == NULL)
	{
		studentData = (Student*)malloc(sizeof(Student) * stdCount);
	}

	
	//

	for (int i = 0; i < stdCount; i++)
	{
		/////////////////// �̸� �Է� /////////////////////////
		studentData[i].m_name[0] = 65 + rand() % 26;
		studentData[i].m_name[1] = 65 + rand() % 26;
		studentData[i].m_name[2] = 65 + rand() % 26;
		studentData[i].m_name[3] = '\0';
		////////////////////////////////////////////////
		studentData[i].m_number  = i;
		studentData[i].m_iEng    = rand() % 100;
		studentData[i].m_iKor    = rand() % 100;
		studentData[i].m_iMath   = rand() % 100;

		int stdSum = studentData[i].m_iEng + studentData[i].m_iKor + studentData[i].m_iMath;
		studentData[i].m_average = stdSum / 3.0f;
	}
}


void PrintData()
{
	if (studentData == NULL)
	{
		printf("����Ÿ�� �����ϴ�. �����͸� �Է����ּ���.\n");
		return;
	}
	for (int i = 0; i < stdCount; i++)
	{
		printf("\n%3d",		 studentData[i].m_number);
		printf("  %8s",		 studentData[i].m_name);
		printf("  %3d",		 studentData[i].m_iKor);
		printf("  %3d",		 studentData[i].m_iEng);
		printf("  %3d",      studentData[i].m_iMath);
		printf("  %10.4f",   studentData[i].m_average);
	}
}


void SearchName()
{
	char findName[5] = { 0, };
	printf("�̸��� �Է��Ͻÿ� : \n");
	scanf("%s", &findName);

	for (int i = 0; i < stdCount; i++)
	{
		if (0 == strcmp(studentData[i].m_name, findName))
		{
			printf("\n%3d",      studentData[i].m_number);
			printf("  %8s",      studentData[i].m_name);
			printf("  %3d",      studentData[i].m_iKor);
			printf("  %3d",	     studentData[i].m_iEng);
			printf("  %3d",	     studentData[i].m_iMath);
			printf("  %10.4f\n", studentData[i].m_average);
		}
		break;
	}
}


void FileSave()
{
	FILE* fp;
	fp = fopen("data.txt", "w");
	for (int i = 0; i < stdCount; i++)
	{
		fprintf(fp, "%d %s %d %d %d %10.4f", 
			studentData[i].m_number, 
			studentData[i].m_name, 
			studentData[i].m_iKor, 
			studentData[i].m_iEng, 
			studentData[i].m_iMath, 
			studentData[i].m_average);
		fprintf(fp, "\n");
	}
	fclose(fp);
}


void FileLoad()
{
	printf("�л��� ���ο��� �Է��ϼ���");
	scanf("%d", &stdCount);


	if (studentData != NULL)
	{
		free(studentData);
		studentData = 0;
	}
	
	if(studentData == NULL)
	{
		studentData = (Student*)malloc(sizeof(Student) * stdCount);
	}


	FILE* fp;
	fp = fopen("data.txt", "r");


	for (int i = 0; i < stdCount; i++)
	{
		fscanf(fp, "%d %s %d %d %d %f", 
			&studentData[i].m_number, 
			studentData[i].m_name, 
			&studentData[i].m_iKor,
			&studentData[i].m_iEng, 
			&studentData[i].m_iMath, 
			&studentData[i].m_average);
	}

	fclose(fp);
}

void CreateData()
{
	
	newStudentData = (Student*)malloc(sizeof(Student) * (stdCount + 1));


	//���� ������ ����
	for (int i = 0; i < stdCount; i++)
	{
		newStudentData[i].m_name[0] = studentData[i].m_name[0];
		newStudentData[i].m_name[1] = studentData[i].m_name[1];
		newStudentData[i].m_name[2] = studentData[i].m_name[2];
		newStudentData[i].m_name[3] = studentData[i].m_name[3];
		newStudentData[i].m_number  = studentData[i].m_number;
		newStudentData[i].m_iEng    = studentData[i].m_iEng;
		newStudentData[i].m_iKor    = studentData[i].m_iKor;
		newStudentData[i].m_iMath   = studentData[i].m_iMath;
		newStudentData[i].m_average = studentData[i].m_average;
	}

	//���ο���� �Է�
	printf("\n�ű� �л��� �����͸� �Է��Ͻÿ� : ");
	printf("\n�̸� :  ");	
	scanf("%s", newStudentData [ stdCount].m_name);
	printf("\n���� :  ");	
	scanf("%d", &newStudentData[stdCount ].m_iKor);
	printf("\n���� :  ");	
	scanf("%d", &newStudentData[stdCount ].m_iMath);
	printf("\n���� :  ");
	scanf("%d", &newStudentData[stdCount ].m_iEng);

	newStudentData[stdCount].m_number = stdCount;
	newStudentData[stdCount].m_average = (newStudentData[stdCount].m_iKor + newStudentData[stdCount].m_iMath + newStudentData[stdCount].m_iEng) / 3.0f;

	stdCount = stdCount + 1;


	//���� �޸𸮿� ���ο�޸� �ּ� �Է�
	free(studentData);


	studentData = newStudentData;


	//�޸� ����
	//free(newStudentData);
}