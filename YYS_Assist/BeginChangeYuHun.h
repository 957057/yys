#pragma once
#include "yys_function.h"

class BeginChangeYuHun : public yys_function
{
public:
	//ѡ�����
	int SelectGroup(long hd, dmsoft *dm, CPoint clickXY, int gameclass, int index);
	//Ԥ������
	int StartChangeYuHun(long hd, dmsoft *dm, int group, int team, int gameclass, int index);

	//Ԥ����������
	int StartChangeYuHunDouble(long hd, dmsoft *dm, int group, int team1, int team2, int gameclass, int index);
};

