#include "pch.h"
#include "BeginTuPo.h"
#define EXIT_THREAD -10
//��ɽ��ֹ,������ֹ.�䲻����,������֮��
extern bool readyFlag;
//Ѱ����
int BeginTuPo::FindTuPo(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	int i = 20;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	while (i>0)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//���ͻ��
		if (dm->FindPic(198, 460, 268, 538, _T("̽�����ͻ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 20, intY + 20);
			if (random_delay(index, gameclass, dm, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 700) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}

	return 1;
}
//ˢ�¹���
int BeginTuPo::ReFreshRule(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	int Rule[9] = {0,0,0,0,0,0,0,0,0};
	//�ж�ʧ�������  1
	if ((dm->FindPic(105, 106, 141, 130, _T("ͻ��(����).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) ||((dm->FindPic(105, 106, 134, 127, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (dm->FindPic(317, 110, 349, 133, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) == -1))) {
		Rule[0] = 1;
	} //2
	if ((dm->FindPic(358, 106, 394, 130, _T("ͻ��(����).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) || ((dm->FindPic(353, 105, 383, 130, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (dm->FindPic(572, 110, 598, 133, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) == -1))) {
		Rule[1] = 1;
	}//3
	if ((dm->FindPic(607, 106, 643, 130, _T("ͻ��(����).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) || ((dm->FindPic(603, 104, 634, 129, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (dm->FindPic(817, 110, 850, 133, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) == -1))) {
		Rule[2] = 1;
	}//4
	if ((dm->FindPic(107, 208, 143, 232, _T("ͻ��(����).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) || ((dm->FindPic(105, 207, 137, 228, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (dm->FindPic(317, 210, 349, 231, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) == -1))) {
		Rule[3] = 1;
	}//5
	if ((dm->FindPic(358, 208, 394, 232, _T("ͻ��(����).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) || ((dm->FindPic(355, 209, 384, 231, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (dm->FindPic(568, 210, 601, 231, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) == -1))) {
		Rule[4] = 1;
	}//6
	if ((dm->FindPic(607, 208, 643, 232, _T("ͻ��(����).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) || ((dm->FindPic(604, 207, 638, 231, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (dm->FindPic(817, 210, 850, 231, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) == -1))) {
		Rule[5] = 1;
	}//7
	if ((dm->FindPic(109, 309, 145, 333, _T("ͻ��(����).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) || ((dm->FindPic(105, 310, 137, 332, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (dm->FindPic(317, 312, 349, 331, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) == -1))) {
		Rule[6] = 1;
	}//8
	if ((dm->FindPic(359, 309, 394, 333, _T("ͻ��(����).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) || ((dm->FindPic(356, 309, 386, 331, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (dm->FindPic(567, 312, 600, 331, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) == -1))) {
		Rule[7] = 1;
	}//9
	if ((dm->FindPic(607, 309, 643, 333, _T("ͻ��(����).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) || ((dm->FindPic(602, 311, 636, 330, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (dm->FindPic(817, 312, 850, 331, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) == -1))) {
		Rule[8] = 1;
	}
	for (int i = 0; i < 9; i++) {
		if (Rule[i] == 0) { return 0; }
	}
	return 1;
}
//ˢ�¸���&&����
int BeginTuPo::ReFresh(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	int i = 10;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	while (i > 0) 
	{
		if (dm->FindPic(721, 426, 851, 473, _T("ˢ��.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			print_log(_T("ˢ��...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			if (dm->FindPic(506, 303, 632, 344, _T("ȷ��.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) {
				if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, intX + 10, intY + 10);
				if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
				if(ExitFour(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				return 1;
			}
		}
		if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 0;
}
//��������
int BeginTuPo::lockTeam(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	int i = 10;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	while (i > 0)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(609, 433, 646, 468, _T("��ͻ��������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("��������...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 13, intY + 13);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			readyFlag = FALSE;
			break;
		}
		if (dm->FindPic(609, 433, 646, 468, _T("��ͻ��������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			readyFlag = FALSE;
			break;
		}

		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 1;
}
//���븱��
int BeginTuPo::ReadyToFinish(long hd, dmsoft *dm, int count, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (readyFlag && (dm->FindPic(838, 405, 935, 474, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)) {
			print_log(_T("���׼��...\r\n"), gameclass);
			CPoint pos = random_pos(intX, intY, 1, 3);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(233, 60, 536, 253, _T("ʤ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("ս��������...\r\n"), gameclass);
			CPoint pos = random_pos(798, 429, 5, 10);
			if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(372, 352, 588, 480, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 5, 10);
			mouse_click_event(title, pos.x, pos.y);
			count++;
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (dm->FindPic(271, 40, 423, 216, _T("ʧ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("��սʧ�ܣ����ƴ���...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 5, 10);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
	}
	return count;
}
//�ж��Ƿ���ͻ��ȯ
int BeginTuPo::isHaveTicket(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	int i = 3;
	while (i > 0) {
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if ((dm->FindPic(867, 6, 886, 37, _T("ͻ��ȯ0.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && (dm->FindPic(858, 2, 885, 37, _T("ͻ��ȯ10.bmp"), _T("202020"), 0.95, 0, &intX, &intY) == -1)) {
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			return 0;
		}
		if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 1;
}
//�˳�ͻ�Ʋ���������-->ȷ��-->ʧ��
int BeginTuPo::ExitDo(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	int flag = 0;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	while (1) {
		//�˳�λ�� 0, 0, 56, 58
		if ((flag==0)&&(dm->FindPic(0, 0, 56, 58, _T("�˳�(͸��).bmp|�˳�1.bmp|�˳�.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)) {
			if (random_delay(index, gameclass, dm, 300, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(506, 293, 606, 344, _T("������ȷ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 300, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			flag = 1;
		}
		if (dm->FindPic(271, 40, 423, 216, _T("ʧ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 5, 10);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(372, 352, 588, 480, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 5, 10);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//�˳�����  418,49,529,92,
		if (dm->FindPic(418, 49, 529, 92, _T("��ͻ(������).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
	}
	
	return 1;
}
//����
int BeginTuPo::ExitFour(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//���궨��
	CPoint startXY, endXY;
	int exitFlag = 0;
	CString exitFlag_str;
	//����
	while (1) {
		if (!isHaveTicket(hd, dm, gameclass, index)) {
			break;
		}//��һ�е�һ��  ,
		if ((dm->FindPic(317, 110, 349, 133, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("�����һ�е�һ��...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			//������ťλ�÷�Χ
			startXY.x = 240, startXY.y = 267;
			endXY.x = 339, endXY.y = 310;
			//�������
			if(SelectAttack(hd, startXY, endXY, _T("����1.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			//��һ
			exitFlag_str.Format(_T("%d"),exitFlag+1);
			print_log(_T("�˳���"+exitFlag_str+"��...\r\n"), gameclass);
			if(ExitDo(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			exitFlag += 1;
		}//��һ�еڶ���  
		else if ((dm->FindPic(572, 110, 598, 133, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("�����һ�еڶ���...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			//������ťλ�÷�Χ
			startXY.x = 491, startXY.y = 267;
			endXY.x = 590, endXY.y = 310;
			//�������
			if(SelectAttack(hd, startXY, endXY, _T("����2.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			//�˶�
			exitFlag_str.Format(_T("%d"), exitFlag + 1);
			print_log(_T("�˳���" + exitFlag_str + "��...\r\n"), gameclass);
			if(ExitDo(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			exitFlag += 1;
		}//��һ�е�����  
		else if ((dm->FindPic(817, 110, 850, 133, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("�����һ�е�����...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			//������ťλ�÷�Χ
			startXY.x = 739, startXY.y = 267;
			endXY.x = 834, endXY.y = 310;
			//�������
			if(SelectAttack(hd, startXY, endXY, _T("����3.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			//����
			exitFlag_str.Format(_T("%d"), exitFlag + 1);
			print_log(_T("�˳���" + exitFlag_str + "��...\r\n"), gameclass);
			if(ExitDo(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			exitFlag += 1;
		}//�ڶ��е�һ��  
		else if ((dm->FindPic(317, 210, 349, 231, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("����ڶ��е�һ��...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			//������ťλ�÷�Χ
			startXY.x = 242, startXY.y = 370;
			endXY.x = 336, endXY.y = 413;
			//�������
			if(SelectAttack(hd, startXY, endXY, _T("����4.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			//����
			exitFlag_str.Format(_T("%d"), exitFlag + 1);
			print_log(_T("�˳���" + exitFlag_str + "��...\r\n"), gameclass);
			if(ExitDo(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			exitFlag += 1;
		}
		if (exitFlag == 4) {
			break;
		}
		
	}
	return 1;
}
//�������
int BeginTuPo::SelectAttack(long hd, CPoint startXY, CPoint endXY, CString attackImg, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//start Attack
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(startXY.x, startXY.y, endXY.x, endXY.y,attackImg, _T("202020"), 0.95, 0, &intX, &intY) != -1) {
			print_log(_T("����...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX+10, intY + 10);
			if (random_delay(index, gameclass, dm, 4000, 5000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(0, 0, 56, 58, _T("�˳�(͸��).bmp|�˳�1.bmp|�˳�.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}

//��ȡ�·�����
int BeginTuPo::CheckReward(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	int i = 20;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	while (i>0)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(372, 352, 588, 480, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 5, 10);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		i--;
		if (random_delay(index, gameclass, dm, 200, 220) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}

//��ʼ
int BeginTuPo::StartTuPo(long hd, int round, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//��ʼ��׼����־
	readyFlag = TRUE;
	//�ж��Ƿ���ͥԺ
	if (!IsInYard(dm, gameclass, index))
	{
		print_log(_T("��ȷ����ͥԺ����!!!\r\n"), gameclass);
		return 0;
	}
	if (random_delay(index, gameclass, dm, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//Ѱ��̽�����������
	int result = FindExploreLanTernAndClick(hd, dm, gameclass, index);
	if (result == 0) {
		print_log(_T("��ͥԺ���棬��δ�ҵ�̽������!!!\r\n"), gameclass);
		return 0;
	}
	else if (result == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 2500, 3500) == EXIT_THREAD) { return EXIT_THREAD; }
	//Ѱͻ��
	if (FindTuPo(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	
	//��������
	if(lockTeam(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ʼѭ��
	//����ֲ�����
	long intX, intY;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//���궨��
	CPoint startXY, endXY;
	//�������־λ
	int count = 0, flag=0;
	CString count_str;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		count_str.Format(_T("%d"), count + 1);
		//start
		//�ж��Ƿ���ȯ    ͻ�ƾ�10:858,2,885,37
		int resultTicket = isHaveTicket(hd, dm, gameclass, index);
		if (resultTicket == 0) {
			flag = 1;
			print_log(_T("û��ͻ��ȯ...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}else if(resultTicket == EXIT_THREAD) { return EXIT_THREAD; }
		//ÿ������һ�εĽ���
		if (dm->FindPic(372, 352, 588, 480, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 5, 10);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//��һ�е�һ��
		if ((dm->FindPic(317, 110, 349, 133, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)&&isHaveTicket(hd,dm,gameclass,index)) {
			print_log(_T("�����һ�е�һ��...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			//������ťλ�÷�Χ
			startXY.x = 240, startXY.y = 267;
			endXY.x = 339, endXY.y = 310;
			//�������
			print_log(_T("��" + count_str + "��ͻ�ƿ�ʼ...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("����1.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if(count == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//��һ�еڶ���
		else if ((dm->FindPic(572, 110, 598, 133, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("�����һ�еڶ���...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//������ťλ�÷�Χ
			startXY.x = 491, startXY.y = 267;
			endXY.x = 590, endXY.y = 310;
			//�������
			print_log(_T("��" + count_str + "��ͻ�ƿ�ʼ...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("����2.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//��һ�е�����
		else if ((dm->FindPic(817, 110, 850, 133, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("�����һ�е�����...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//������ťλ�÷�Χ
			startXY.x = 739, startXY.y = 267;
			endXY.x = 834, endXY.y = 310;
			//�������
			print_log(_T("��" + count_str + "��ͻ�ƿ�ʼ...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("����3.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//�ڶ��е�һ��
		else if ((dm->FindPic(317, 210, 349, 231, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("����ڶ��е�һ��...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//������ťλ�÷�Χ
			startXY.x = 242, startXY.y = 370;
			endXY.x = 336, endXY.y = 413;
			//�������
			print_log(_T("��" + count_str + "��ͻ�ƿ�ʼ...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("����4.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//�ڶ��еڶ���
		else if ((dm->FindPic(568, 210, 601, 231, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("����ڶ��еڶ���...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//������ťλ�÷�Χ
			startXY.x = 490, startXY.y = 370;
			endXY.x = 587, endXY.y = 413;
			//�������
			print_log(_T("��" + count_str + "��ͻ�ƿ�ʼ...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("����5.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//�ڶ��е�����
		else if ((dm->FindPic(817, 210, 850, 231, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("����ڶ��е�����...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//������ťλ�÷�Χ
			startXY.x = 739, startXY.y = 370;
			endXY.x = 836, endXY.y = 413;
			//�������
			print_log(_T("��" + count_str + "��ͻ�ƿ�ʼ...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("����6.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//�����е�һ��
		else if ((dm->FindPic(317, 312, 349, 331, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("��������е�һ��...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//������ťλ�÷�Χ
			startXY.x = 240, startXY.y = 470;
			endXY.x = 338, endXY.y = 515;
			//�������
			print_log(_T("��" + count_str + "��ͻ�ƿ�ʼ...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("����7.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//�����еڶ���
		else if ((dm->FindPic(567, 312, 600, 331, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("��������еڶ���...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//������ťλ�÷�Χ
			startXY.x = 491, startXY.y = 470;
			endXY.x = 586, endXY.y = 515;
			//�������
			print_log(_T("��" + count_str + "��ͻ�ƿ�ʼ...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("����8.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//�����е�����
		else if ((dm->FindPic(817, 312, 850, 331, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("��������е�����...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//������ťλ�÷�Χ
			startXY.x = 739, startXY.y = 470;
			endXY.x = 836, endXY.y = 515;
			//�������
			print_log(_T("��" + count_str + "��ͻ�ƿ�ʼ...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("����9.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if ((dm->FindPic(721, 426, 851, 473, _T("ˢ��.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)&&ReFreshRule(hd,dm,gameclass,index))
		{
			print_log(_T("��ǰû��ʣ��ͻ�ƣ����ˢ��...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			if (dm->FindPic(506, 303, 632, 344, _T("ȷ��.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) {
				if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, intX + 10, intY + 10);
				if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}

		//�ж��Ƿ���ȯ    ͻ�ƾ�10:858,2,885,37
		resultTicket = isHaveTicket(hd, dm, gameclass, index);
		if (resultTicket == 0) {
			flag = 1;
			print_log(_T("û��ͻ��ȯ...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}else if(resultTicket == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//ˢ���˳�
	if (count >= round||flag==1)
	{
		if(CheckReward(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1200, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		print_log(_T("��������ɣ������˳�����ͥԺ...\r\n"), gameclass);
		if (TupoReturnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }

	}

	return 1;
}
//���Ĵ��
int BeginTuPo::StartTuPoByExitFourAttackNine(long hd, int round, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//��ʼ��׼����־
	readyFlag = TRUE;
	//�ж��Ƿ���ͥԺ
	if (!IsInYard(dm, gameclass, index))
	{
		print_log(_T("��ȷ����ͥԺ����!!!\r\n"), gameclass);
		return 0;
	}
	if (random_delay(index, gameclass, dm, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//Ѱ��̽�����������
	int result = FindExploreLanTernAndClick(hd, dm, gameclass, index);
	if (result == 0) {
		print_log(_T("��ͥԺ���棬��δ�ҵ�̽������!!!\r\n"), gameclass);
		return 0;
	}
	else if (result == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 2500, 3500) == EXIT_THREAD) { return EXIT_THREAD; }
	//Ѱͻ��
	if (FindTuPo(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }

	//��������
	if(lockTeam(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѭ����ʼ
	//����ֲ�����
	long intX, intY;
	//��¼����ÿһ��������������
	int enterNum[9] = {0,0,0,0,0,0,0,0,0};
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//���궨��
	CPoint startXY, endXY;
	//�������־λ
	int count = 0, flag = 0;
	CString count_str;
	//���Ĵ��ģʽ��Ҫ��֮ǰˢ��һ������Ӱ��-->������ˢ����ִ��
	int resultReFresh = ReFresh(hd, dm, gameclass, index);
	if (resultReFresh == 0) {
		print_log(_T("��ȷ��ˢ�°�ťδ����ȴ�У�\r\n"), gameclass);
		return 0;
	}else if(resultReFresh == EXIT_THREAD) { return EXIT_THREAD; }
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		count_str.Format(_T("%d"), count + 1);
		//start
		//�ж��Ƿ���ȯ    ͻ�ƾ�10:858,2,885,37
		if (!isHaveTicket(hd, dm, gameclass, index)) {
			flag = 1;
			print_log(_T("û��ͻ��ȯ...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		
		//ÿ������һ�εĽ���
		if (dm->FindPic(372, 352, 588, 480, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 5, 10);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (isHaveTicket(hd, dm, gameclass, index)&&((dm->FindPic(317, 110, 349, 133, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)|| dm->FindPic(572, 110, 598, 133, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)) {
			int resultExitFour = ExitFour(hd, dm, gameclass, index);
			if(resultExitFour == EXIT_THREAD) { return EXIT_THREAD; }
			else if (resultExitFour == 1) {
				for (int i = 0; i < 9; i++) {
					enterNum[i] = 0;
				}
			}
		}
		//��һ�е�һ��
		if ((enterNum[0]<3)&&(dm->FindPic(105, 106, 134, 127, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("�����һ�е�һ��...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 100, intY + 10);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			//������ťλ�÷�Χ
			startXY.x = 240, startXY.y = 267;
			endXY.x = 339, endXY.y = 310;
			//�������
			print_log(_T("��" + count_str + "��ͻ�ƿ�ʼ...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("����1.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
			enterNum[0]+=1;
		}
		//��һ�еڶ���
		else if ((enterNum[1] < 3) && (dm->FindPic(353, 105, 383, 130, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("�����һ�еڶ���...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 100, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//������ťλ�÷�Χ
			startXY.x = 491, startXY.y = 267;
			endXY.x = 590, endXY.y = 310;
			//�������
			print_log(_T("��" + count_str + "��ͻ�ƿ�ʼ...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("����2.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
			enterNum[1] += 1;
		}
		//��һ�е�����
		else if ((enterNum[2] < 3) && (dm->FindPic(603, 104, 634, 129, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("�����һ�е�����...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 100, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//������ťλ�÷�Χ
			startXY.x = 739, startXY.y = 267;
			endXY.x = 834, endXY.y = 310;
			//�������
			print_log(_T("��" + count_str + "��ͻ�ƿ�ʼ...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("����3.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
			enterNum[2] += 1;
		}
		//�ڶ��е�һ��
		else if ((enterNum[3] < 3) && (dm->FindPic(105, 207, 137, 228, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("����ڶ��е�һ��...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 100, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//������ťλ�÷�Χ
			startXY.x = 242, startXY.y = 370;
			endXY.x = 336, endXY.y = 413;
			//�������
			print_log(_T("��" + count_str + "��ͻ�ƿ�ʼ...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("����4.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
			enterNum[3] += 1;
		}
		//�ڶ��еڶ���
		else if ((enterNum[4] < 3) && (dm->FindPic(355, 209, 384, 231, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("����ڶ��еڶ���...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 100, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//������ťλ�÷�Χ
			startXY.x = 490, startXY.y = 370;
			endXY.x = 587, endXY.y = 413;
			//�������
			print_log(_T("��" + count_str + "��ͻ�ƿ�ʼ...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("����5.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
			enterNum[4] += 1;
		}
		//�ڶ��е�����
		else if ((enterNum[5] < 3) && (dm->FindPic(604, 207, 638, 231, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("����ڶ��е�����...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 100, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//������ťλ�÷�Χ
			startXY.x = 739, startXY.y = 370;
			endXY.x = 836, endXY.y = 413;
			//�������
			print_log(_T("��" + count_str + "��ͻ�ƿ�ʼ...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("����6.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
			enterNum[5] += 1;
		}
		//�����е�һ��
		else if ((enterNum[6] < 3) && (dm->FindPic(105, 310, 137, 332, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("��������е�һ��...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 100, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//������ťλ�÷�Χ
			startXY.x = 240, startXY.y = 470;
			endXY.x = 338, endXY.y = 515;
			//�������
			print_log(_T("��" + count_str + "��ͻ�ƿ�ʼ...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("����7.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
			enterNum[6] += 1;
		}
		//�����еڶ���
		else if ((enterNum[7] < 3) && (dm->FindPic(356, 309, 386, 331, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("��������еڶ���...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 100, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//������ťλ�÷�Χ
			startXY.x = 491, startXY.y = 470;
			endXY.x = 586, endXY.y = 515;
			//�������
			print_log(_T("��" + count_str + "��ͻ�ƿ�ʼ...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("����8.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
			enterNum[7] += 1;
		}
		//�����е�����
		else if ((enterNum[8] < 3) && (dm->FindPic(602, 311, 636, 330, _T("ͻ��(δ��ս).bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1) && isHaveTicket(hd, dm, gameclass, index)) {
			print_log(_T("��������е�����...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 100, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			//������ťλ�÷�Χ
			startXY.x = 739, startXY.y = 470;
			endXY.x = 836, endXY.y = 515;
			//�������
			print_log(_T("��" + count_str + "��ͻ�ƿ�ʼ...\r\n"), gameclass);
			if(SelectAttack(hd, startXY, endXY, _T("����9.bmp"), dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			count = ReadyToFinish(hd, dm, count, gameclass, index);
			if (count == EXIT_THREAD) { return EXIT_THREAD; }
			enterNum[8] += 1;
		}
		else if ((dm->FindPic(721, 426, 851, 473, _T("ˢ��.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)&&ReFreshRule(hd, dm, gameclass, index)){
		print_log(_T("��ǰû��ʣ��ͻ�ƣ����\r\n"), gameclass);
		if(ReFresh(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			for (int i = 0; i < 9; i++) {
				enterNum[i] = 0;
			}
			if (random_delay(index, gameclass, dm, 2800, 3500) == EXIT_THREAD) { return EXIT_THREAD; }
		}

		//�ж��Ƿ���ȯ    ͻ�ƾ�10:858,2,885,37
		int resultTicket = isHaveTicket(hd, dm, gameclass, index);
		if (resultTicket == 0) {
			flag = 1;
			print_log(_T("û��ͻ��ȯ...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}else if(resultTicket == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//ˢ���˳�
	if (count >= round || flag == 1)
	{
		if(CheckReward(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1200, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
		print_log(_T("��������ɣ������˳�����ͥԺ...\r\n"), gameclass);
		if (TupoReturnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }

	}
	return 1;
}
//����ͥԺ
int BeginTuPo::TupoReturnYard(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//��ʼ����
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(861, 59, 948, 139, _T("��1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(14, 17, 67, 71, _T("����1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (IsInYard(dm, gameclass, index))
		{
			print_log(_T("�ɹ�����ͥԺ��\r\n"), gameclass);
			break;
		}
	}
	return 1;
}

