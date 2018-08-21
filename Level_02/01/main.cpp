#include "POINT.h"
#include "RECTANGLE.h"


int main()
{
	POINT pos1;
	
	if (!pos1.InitMembers(-2, 4))
		cout << "½ÇÆÐ" << endl;

	pos1.InitMembers(2, 4);

	POINT pos2;
	pos2.InitMembers(10, 10);

	RECTANGLE rec;
	rec.InitMembers(pos1, pos2);

	rec.ShowRectInfo();


	return 0;
}