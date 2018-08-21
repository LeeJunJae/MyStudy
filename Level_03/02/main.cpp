#include "NameCard.h"

//int history[3];
//
//
//void bbq(int level)
//{
//	if (level == 3)
//	{
//		return;
//	}
//
//
//
//	
//	history[level] = 1;
//	bbq(level + 1);
//	history[level] = 0;
//
//
//	history[level] = 2;
//	bbq(level + 1);
//	history[level] = 0;
//
//	
//}



int main()
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222",COMP_POS::CRLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);

	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();

	

	return 0;
}