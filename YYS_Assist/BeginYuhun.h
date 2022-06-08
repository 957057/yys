#pragma once
#include "yys_function.h"
class BeginYuhun :public yys_function
{
public:
	//ѡ�����
	int ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//��ˢѡ�����
	int SingleChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//Ѱ����
	int FindYuHun(long hd, dmsoft *dm, int gameclass, int index);
	//��������
	int lockTeam(long hd, dmsoft *dm, int gameclass, int index);
	//���븱��
	int EnterYuHun(long hd, dmsoft *dm, int gameclass, int index);
	//ͥԺ�������ģʽ
	int inviteYuhun(long hd, int round, int layer, CString jc, dmsoft *dm, int gameclass, int index);
	//ͥԺ��������ģʽ
	int BeinvitedYuhun(long hd, int round, CString jc, dmsoft *dm, int gameclass, int index);
	//��ˢ
	int SingleYuHun(long hd, int round, int layer, CString jc, dmsoft *dm, int gameclass, int index);
	//����ͥԺ
	int YuHunReturnYard(long hd, dmsoft *dm, int gameclass, int index);
};
