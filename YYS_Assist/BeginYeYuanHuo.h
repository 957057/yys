#pragma once
#include "yys_function.h"
class BeginYeYuanHuo :public yys_function
{
public:
	//ѡ�����
	int ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//������
	int FindYeYuanHuo(long hd, dmsoft *dm, int gameclass, int index);
	//��������
	int lockTeam(long hd, dmsoft *dm, int gameclass, int index);
	
	//���븱��
	int EnterYeYuanHuo(long hd, dmsoft *dm, int gameclass, int index);
	//��ʼ
	int StartYeYuanHuo(long hd, int round, int layer, dmsoft *dm, int gameclass, int index);
};

