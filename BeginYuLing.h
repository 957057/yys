#pragma once
#include "yys_function.h"
class BeginYuLing :public yys_function
{
public:
	//ѡ�����
	int ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//�����ѡ����ֻ���鷽�����������
	int WhichToSelect(long hd, dmsoft *dm, CPoint startXY, CPoint endXY, CString source_pic[2], int gameclass, int index);
	//ѡ���ĸ�
	int ChooseMonster(long hd, dmsoft *dm, int monster_kind, int gameclass, int index);
	//�Ҹ���
	int FindYuLing(long hd, dmsoft *dm, int gameclass, int index);
	//��������
	int lockTeam(long hd, dmsoft *dm, int gameclass, int index);

	//���븱��
	int EnterYuLing(long hd, dmsoft *dm, int gameclass, int index);
	//��ʼ
	int StartYuLing(long hd, int round, int monster_kind, int layer, dmsoft *dm, int gameclass, int index);
};

