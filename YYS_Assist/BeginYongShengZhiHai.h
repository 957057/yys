#pragma once
#include "yys_function.h"
class BeginYongShengZhiHai :public yys_function
{
public:
	//ѡ�����
	int ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//�жϺ����Ƿ����
	int InnerIsEnterTeam(long hd, dmsoft *dm, int count, int gameclass, int index);
	//��������---�������
	int CreatYszhTeamToInvite(long hd, dmsoft *dm, int gameclass, int index);
	
	//��ˢѡ�����
	int SingleChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//Ѱ����
	int FindYongShengZhiHai(long hd, dmsoft *dm, int gameclass, int index);
	//��������
	int lockTeam(long hd, dmsoft *dm, int gameclass, int index);

	//���븱��
	int EnterYongShengZhiHai(long hd, dmsoft *dm, int gameclass, int index);
	//��ʼ
	int SingleYongShengZhiHai(long hd, int round, int layer, CString jc, dmsoft *dm, int gameclass, int index);
	
	
	//ͥԺ�������ģʽ
	int inviteYongShengZhiHai(long hd, int round, int layer, CString jc, dmsoft *dm, int gameclass, int index);
	//ͥԺ��������ģʽ
	int BeinvitedYongShengZhiHai(long hd, int round, CString jc, dmsoft *dm, int gameclass, int index);
};

