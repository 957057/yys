#pragma once
#include "yys_function.h"
class BeginTuPo :public yys_function
{
public:
	//������
	int FindTuPo(long hd, dmsoft *dm, int gameclass, int index);
	//ˢ�¹���
	int ReFreshRule(long hd, dmsoft *dm, int gameclass, int index);
	//ˢ�¸���
	int ReFresh(long hd, dmsoft *dm, int gameclass, int index);
	//��������
	int lockTeam(long hd, dmsoft *dm, int gameclass, int index);
	//�ж��Ƿ���ͻ��ȯ
	int isHaveTicket(long hd, dmsoft *dm, int gameclass, int index);
	//�˳�ͻ�Ʋ���������-->ȷ��-->ʧ��
	int ExitDo(long hd, dmsoft *dm, int gameclass, int index);
	//����
	int ExitFour(long hd, dmsoft *dm, int gameclass, int index);
	//ѡ��ؿ�
	int SelectAttack(long hd, CPoint startXY, CPoint endXY, CString attackImg, dmsoft *dm, int gameclass, int index);
	//׼��---����
	int ReadyToFinish(long hd, dmsoft *dm,int count, int gameclass, int index);
	//��ȡ�·�����
	int CheckReward(long hd, dmsoft *dm, int gameclass, int index);
	//��ʼ
	int StartTuPo(long hd, int round, dmsoft *dm, int gameclass, int index);
	//���Ĵ��
	int StartTuPoByExitFourAttackNine(long hd, int round, dmsoft *dm, int gameclass, int index);
	int TupoReturnYard(long hd, dmsoft *dm, int gameclass, int index);
};

