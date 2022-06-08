#pragma once
#include"obj.h"

extern struct ThreadInfo {
	bool pause;
	bool start;
	bool stop;
	bool suspend_flag;
};

//�߳�״̬��ʼ��
int initThreadInfo();

class yys_function
{
public:
	//����ַ���
	int SplitString(LPCTSTR lpszStr, LPCTSTR lpszSplit, CStringArray& rArrString, BOOL bAllowNullString);
	//���ļ�
	int ReadFile(CString filePath, CStringArray& ListArray);
	//д�ļ�
	int WriteFile(CString filePath, CStringArray& ListArray);
	//��ȡ���ھ��
	HWND findHandle(CString windowname);

	//�༭���β׷������
	void print_log(TCHAR szMsg[], int gameclass);
	//����¼����ֱ���Ϊ125% ����������Ҫclick_x��click_y  ������1.25
	//click_x,click_y:����Ӿ������
	void mouse_click_event(CString windowname, int click_x, int click_y);

	//����ƶ�
	void mouse_move(CString windowname, int start_x, int start_y, int end_x, int end_y);

	//�漴ƫ�����꣬��ֹ��Ϸ��Ҽ��  (�������ң���������ƫ��,��Ϊ��ֵ)
	CPoint random_pos(int pos_x, int pos_y, int offsetX, int offsetY);

	//����ӳٵ������ֹ��Ϸ��Ҽ��
	int random_delay(int index, int gameclass, dmsoft *dm,int time_min = 1000, int time_max = 2500);

	//�ж��Ƿ���ͥԺ
	bool IsInYard(dmsoft *dm,int gameclass, int index);
	//�ж�ͥԺ�Ƿ�չ��
	bool IsShowYard(dmsoft *dm,int gameclass, int index);
	//չ��ͥԺ
	int showYard(dmsoft *dm, int gameclass, int index);
	//Ѱ��̽�����������
	int FindExploreLanTernAndClick(long hd, dmsoft *dm,int gameclass, int index);

	//������
	int CombineTeamAction(long hd, dmsoft *dm, int gameclass, int index);
	//��ȡ��ǰλ��
	long findNowSection(CString sourcePic, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//Ѱ��Ŀ��λ�ò����
	int findDestination(long hd, CString allpic, long destinationLoc, CString destPic, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index);
	//��������
	int CreatTeamToInvite(long hd, dmsoft *dm, int gameclass, int index);
	//����
	int unlock(long hd, dmsoft *dm, int gameclass, int index);
	//�����Ƿ�������
	int IsEnterTeam(long hd, dmsoft *dm, int count, int gameclass, int index);
	//������븱��
	int InviteEnterEvent(long hd, dmsoft *dm, int gameclass, int index);
	//����������븱��
	int ReceiveEnterEvent(long hd, dmsoft *dm, int count, CString gameMode, int gameclass, int index);

	//Ĭ���������
	int DefalutInvite(long hd, dmsoft *dm, int gameclass, int index);
	//�Զ����ӳ�
	int auto_open_jc(long hd, CString jc_category, CString jc_index, CPoint start_xy, CPoint end_xy, dmsoft *dm, int gameclass, int index);
	//�Զ��ؼӳ�
	int auto_close_jc(long hd, CString jc_category, CString jc_index, CPoint start_xy, CPoint end_xy, dmsoft *dm, int gameclass, int index);
	//�Զ��ܾ����ͷ�ӡ
	int AutoRejectXS(long hd, dmsoft *dm, int gameclass, int index);
	//����ͥԺ
	int returnYard(long hd, dmsoft *dm, int gameclass, int index);
};

