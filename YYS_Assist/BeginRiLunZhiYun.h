#pragma once
#include "yys_function.h"
class BeginRiLunZhiYun :public yys_function
{
public:
	//ѡ�����
	int ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//��ˢѡ�����
	int SingleChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//Ѱ����
	int FindRiLunZhiYun(long hd, dmsoft *dm, int gameclass, int index);
	//��������
	int lockTeam(long hd, dmsoft *dm, int gameclass, int index);

	//���븱��
	int EnterRiLunZhiYun(long hd, dmsoft *dm, int gameclass, int index);
	//��ʼ
	int SingleRiLunZhiYun(long hd, int round, int layer,CString jc, dmsoft *dm, int gameclass, int index);
	//ͥԺ�������ģʽ
	int inviteRiLunZhiYun(long hd, int round, int layer, CString jc, dmsoft *dm, int gameclass, int index);
	//ͥԺ��������ģʽ
	int BeinvitedRiLunZhiYun(long hd, int round, CString jc, dmsoft *dm, int gameclass, int index);
};

