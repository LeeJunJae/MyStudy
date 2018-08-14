#include  <stdio.h>
#define PI 3.14159

struct MyStruct
{
	int num = 5;
};

void main()
{
	int number = 5;
	float ouzo = 13.5;
	int cost = 31000;

	printf("The %d women drank %f glasses of ouzo.\n", number, ouzo);
	printf("The value of pi is %f.\n", PI);
	printf("히 안녕하세요, \n");
		printf("%c%d\n", '$', cost);
	printf("If you want to print percent...put character %%.\n");
	printf("number = %d", number = 1 + 3);


	MyStruct* p;
	MyStruct st;
	p = &st;

	(*p).num = 10;

}
