#pragma once
#include "yys_function.h"
class BeginJueXing :public yys_function
{
public:
	//ѡ�����
	int ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//��ˢѡ�����
	int SingleChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//�����ѡ����ֻ���뷽�����������
	int WhichToSelect(long hd, dmsoft *dm, CPoint startXY, CPoint endXY, CString source_pic, int gameclass, int index);
	//ѡ���ĸ�
	int ChooseMonster(long hd, dmsoft *dm, int monster_kind, int gameclass, int index);
	//�Ҹ���
	int FindJueXing(long hd, dmsoft *dm, int gameclass, int index);
	//��������
	int lockTeam(long hd, dmsoft *dm, int gameclass, int index);
	//���븱��
	int EnterJueXing(long hd, dmsoft *dm, int gameclass, int index);
	//ͥԺ�������ģʽ
	int inviteJueXing(long hd, int round, int mode,  int layer, CString jc, dmsoft *dm, int gameclass, int index);
	//ͥԺ��������ģʽ
	int BeinvitedJueXing(long hd, int round, CString jc, dmsoft *dm, int gameclass, int index);
	//��ˢ
	int SingleJueXing(long hd, int round, int monster_kind, int layer, CString jc, dmsoft *dm, int gameclass, int index);
};

