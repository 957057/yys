#pragma once
#include "yys_function.h"
class InDependentFunction :public yys_function
{
public:
	//�ٹ�ҹ��
	int StartBaiGui(long hd, int round, dmsoft *dm, int gameclass, int index);
	//�»
	int StartNewEvent(long hd, int round, dmsoft *dm, int gameclass, int index);
};

