#pragma once
#include "yys_function.h"
class BeginExplore : public yys_function
{
public:
	//�ж��Ƿ���̽������
	int isExplore(long hd, dmsoft *dm, int gameclass,int index);
	//ѡ�����
	int ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//ѡ�����
	int SingleChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//ѡ���Ѷ�
	int ChooseDiff(long hd, int diff, dmsoft *dm, int gameclass, int index);
	//���̽��
	int clickExplore(long hd, dmsoft *dm, int gameclass, int index);
	//���븱�������
	//����Զ��ֻ�--�Ժ��ʵ��ȫ�Զ��ֻ�
	int autoRotate(long hd, dmsoft *dm, int gameclass, int index);
	//��С�� speed:ˢ���ٶ�
	int findCommonMonster(long hd, dmsoft *dm, int gameclass, int index,int speed);
	//��boss
	int findBossMonster(long hd, dmsoft *dm, int gameclass, int index, int speed);
	//�������
	int InnerCreatTeamToInvite(long hd, dmsoft *dm, int preferArea, int gameclass, int index);
	//���븱������ʼ̽��
	int EnterExplore(long hd, dmsoft *dm, int gameclass, int index, int speed);
	//��ˢģʽ���븱������ʼ̽��
	int SingleEnterExplore(long hd, dmsoft *dm, CString progressBar, CString materialKinds, int gameclass, int index, int speed);
	//��ȡ��������
	int ReceiveTreasure(long hd, dmsoft *dm, int gameclass, int index);
	//ͨ��ͥԺ�ж��Ƿ������
	int IsOutExploreByYard(dmsoft *dm, int gameclass, int index);
	//��ӽ��븱��
	int receiveEnterExplore(long hd, dmsoft *dm, int count, int gameclass, int index);
	//�����ѽ���������ս 
	int IsEnterTeamRepeat(long hd, dmsoft *dm, int count, int gameclass, int index);
	//�ж��Ƿ���Ҫ������
	int IsChangeMaterial(long hd, dmsoft *dm, int gameclass, int index);
	//ѡ����ֹ���
	int WhatMaterialToSelect(long hd, dmsoft *dm, CString materialKinds, int gameclass, int index);
	//����������ѡ��
	int SelectProgressBar(long hd, dmsoft *dm, CString progress, int gameclass, int index);
	//�Զ�������
	int AutoReplaceMaterial(long hd, CString progressBar, CString materialKinds, dmsoft *dm, int gameclass, int index);
	//��������
	int ReceiveInvite(long hd, dmsoft *dm, int count, int gameclass, int index);
	//��ˢ
	int SingleExplore(long hd, int round, int layer, int diff, CString jc, int speed, CString progressBar, CString materialKinds, int MaterialMode, dmsoft *dm, int gameclass, int index);
	//����������
	int inviteExplore(long hd, int round, int layer, CString jc, int preferArea, int speed, dmsoft *dm, int gameclass, int index);
	//��ӽ�������
	int BeinvitedExplore(long hd, int round, CString jc, dmsoft *dm, int gameclass, int index);
	//����ͥԺ
	int ExploreReturnYard(long hd, dmsoft *dm, int gameclass, int index);
};
