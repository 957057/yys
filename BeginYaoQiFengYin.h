#pragma once
#include "yys_function.h"
class BeginYaoQiFengYin :public yys_function
{
public:
	//ѡ�����
	int ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//���븱��
	int EnterYaoQiFengYin(long hd, int condition, dmsoft *dm, int gameclass, int index);
	//��ʼ
	int StartYaoQiFengYin(long hd, int round, int monsterKind, int condition, dmsoft *dm, int gameclass, int index);
};

