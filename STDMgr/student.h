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
	printf("학생의 총인원을 입력하세요\n");
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
		/////////////////// 이름 입력 /////////////////////////
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
		printf("데이타가 없습니다. 데이터를 입력해주세요.\n");
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
	printf("이름을 입력하시오 : \n");
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
	printf("학생의 총인원을 입력하세요");
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


	//기존 데이터 저장
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

	//새로운데이터 입력
	printf("\n신규 학생의 데이터를 입력하시오 : ");
	printf("\n이름 :  ");	
	scanf("%s", newStudentData [ stdCount].m_name);
	printf("\n국어 :  ");	
	scanf("%d", &newStudentData[stdCount ].m_iKor);
	printf("\n수학 :  ");	
	scanf("%d", &newStudentData[stdCount ].m_iMath);
	printf("\n영어 :  ");
	scanf("%d", &newStudentData[stdCount ].m_iEng);

	newStudentData[stdCount].m_number = stdCount;
	newStudentData[stdCount].m_average = (newStudentData[stdCount].m_iKor + newStudentData[stdCount].m_iMath + newStudentData[stdCount].m_iEng) / 3.0f;

	stdCount = stdCount + 1;


	//기존 메모리에 새로운메모리 주소 입력
	free(studentData);


	studentData = newStudentData;


	//메모리 해제
	//free(newStudentData);
}