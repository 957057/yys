#include "pch.h"
#include "BeginYongShengZhiHai.h"
#define EXIT_THREAD -10
//��Ʒ�˼��̻�ɫ���й��������³���
extern bool readyFlag;

int BeginYongShengZhiHai::ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//�Զ��ܾ�����
	if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ȡĿ��λ��
	CString bmp_pic = _T("Ҽ��.bmp|����.bmp|����.bmp|����.bmp");

	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//start ѡ���
	print_log(_T("ѡ������֮������...\r\n"), gameclass);
	switch (layer)
	{
	case 0: {
		if (findDestination(hd, bmp_pic, layer, _T("Ҽ��.bmp|Ҽ��(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestination(hd, bmp_pic, layer, _T("����.bmp|����(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestination(hd, bmp_pic, layer, _T("����.bmp|����(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 3: {
		if (findDestination(hd, bmp_pic, layer, _T("����.bmp|����(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}

//��������---�������
int BeginYongShengZhiHai::CreatYszhTeamToInvite(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//�����������
	int i = 20;
	while (i > 0)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(741, 443, 875, 498, _T("��������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			print_log(_T("��������...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 5);
			if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	//���ù���Ȩ��
	i = 20;
	while (i > 0)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(555, 361, 592, 398, _T("������(δѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			print_log(_T("Ȩ�޲�����...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	//�������
	i = 20;
	long creatRes, cancelRes;
	while (i > 0)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		cancelRes = dm->FindPic(247, 415, 360, 472, _T("ȡ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		creatRes = dm->FindPic(603, 412, 712, 475, _T("����.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		if ((cancelRes != -1) && (creatRes != -1))
		{
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 5);
			if (random_delay(index, gameclass, dm, 1200, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}

	//�������
	i = 20;
	while (i > 0)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(630, 187, 691, 248, _T("����֮����.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			print_log(_T("�������...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 12, intY + 10);
			if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}else if (dm->FindPic(235, 184, 296, 246, _T("����֮����.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (dm->FindPic(444, 197, 520, 279, _T("�л�λ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
			{
				print_log(_T("�л�λ��...\r\n"), gameclass);
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, intX + 12, intY + 10);
				if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	//���������
	i = 20;
	while (i > 0)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(353, 61, 434, 109, _T("���(δѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			print_log(_T("�����Ӻ���...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 20, intY + 10);
			if (random_delay(index, gameclass, dm, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 400, 600) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	//�ж��Ƿ�Ϊ�����ӣ��������룬�����˳�
	i = 20;
	long recentRes;
	while (i > 0)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		recentRes = dm->FindPic(404, 119, 483, 157, _T("������.bmp"), _T("202020"), 0.95, 0, &intX, &intY);
		if (recentRes != -1)
		{
			print_log(_T("����...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX - 50, intY + 40);
			if (random_delay(index, gameclass, dm, 2000, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 400, 600) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	//���������Ӻ��ѣ�����ͥԺ
	if (recentRes == -1)
	{
		print_log(_T("δ�ҵ������Ӻ��ѣ�����ͥԺ��...\r\n"), gameclass);
		if (returnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		return 0;
	}
	//�������
	i = 20;
	long inviteRes, inCancelRes;
	while (i > 0)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		inCancelRes = dm->FindPic(327, 401, 432, 458, _T("����ȡ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY);
		inviteRes = dm->FindPic(536, 407, 632, 454, _T("����.bmp"), _T("202020"), 0.9, 0, &intX, &intY);
		if ((inCancelRes != -1) && (inviteRes != -1))
		{
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 5);
			if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 1;
}

//�����ѽ���������ս 
int BeginYongShengZhiHai::InnerIsEnterTeam(long hd, dmsoft *dm, int count, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//�������Ƿ�������
	print_log(_T("�ȴ����Ѽ������...\r\n"), gameclass);
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//����ս
		if (dm->FindPic(860, 429, 946, 510, _T("����֮����ս.bmp"), _T("202020"), 0.98, 0, &intX, &intY) != -1)
		{
			print_log(_T("�����Ѽ������...\r\n"), gameclass);
			if (count == 0)
			{
				//�ȴ����Ѳ�������������
				if (random_delay(index, gameclass, dm, 3000, 4000) == EXIT_THREAD) { return EXIT_THREAD; }
				if (unlock(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (random_delay(index, gameclass, dm, 500, 700) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//���ƫ����������
			CPoint pos = random_pos(intX, intY, 5, 10);
			if (random_delay(index, gameclass, dm, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 2000, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
	}
	return 1;
}

//��ˢѡ��
int BeginYongShengZhiHai::SingleChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//�Զ��ܾ�����
	if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//��ȡĿ��λ��
	CString bmp_pic = _T("����Ҽ��.bmp|��������.bmp|��������.bmp|��������.bmp");
	//start ѡ���
	print_log(_T("ѡ������֮��...\r\n"), gameclass);
	switch (layer)
	{
	case 0: {
		if (findDestination(hd, bmp_pic, layer, _T("����Ҽ��.bmp|����Ҽ��(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestination(hd, bmp_pic, layer, _T("��������.bmp|��������(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestination(hd, bmp_pic, layer, _T("��������.bmp|��������(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 3: {
		if (findDestination(hd, bmp_pic, layer, _T("��������.bmp|��������(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}
//Ѱ����
int BeginYongShengZhiHai::FindYongShengZhiHai(long hd, dmsoft *dm, int gameclass, int index) {
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
		//�������
		if (dm->FindPic(111, 456, 193, 537, _T("̽������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 20);
			if (random_delay(index, gameclass, dm, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//������֮��
		if (dm->FindPic(857, 79, 919, 234, _T("��ˢ����֮��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 20);
			if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 700) == EXIT_THREAD) { return EXIT_THREAD; }
	}

	return 1;
}
//��������
int BeginYongShengZhiHai::lockTeam(long hd, dmsoft *dm, int gameclass, int index) {
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
		if (dm->FindPic(411, 415, 452, 454, _T("��������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("��������...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 13, intY + 13);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			readyFlag = FALSE;
			break;
		}
		if (dm->FindPic(411, 415, 452, 454, _T("��������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			readyFlag = FALSE;
			break;
		}

		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 1;
}
//���븱��
int BeginYongShengZhiHai::EnterYongShengZhiHai(long hd, dmsoft *dm, int gameclass, int index) {
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
		if (dm->FindPic(824, 437, 902, 505, _T("��ˢ������ս.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("�����ս...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(intX, intY, 10, 20);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
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
		if (dm->FindPic(335, 256, 616, 497, _T("��.bmp|��(�ײ�).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 5, 10);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (dm->FindPic(421, 289, 538, 350, _T("������ȷ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY);
			if (random_delay(index, gameclass, dm, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//��ʼ��ˢ
int BeginYongShengZhiHai::SingleYongShengZhiHai(long hd, int round, int layer, CString jc, dmsoft *dm, int gameclass, int index) {
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
	//Ѱ����֮��
	if(FindYongShengZhiHai(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ����
	CPoint startXY, endXY;
	startXY.x = 110, startXY.y = 93;
	endXY.x = 360, endXY.y = 439;
	int resultSingleChoose = SingleChooseLayer(hd, layer, startXY, endXY, dm, gameclass, index);
	if (resultSingleChoose == 0) {
		print_log(_T("δ�ҵ�Ŀ��!!!\r\n"), gameclass);
		return 0;
	}else if(resultSingleChoose == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//��������
	if(lockTeam(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ʼѭ��
	int count = 0;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//����ҵԭ�𸱱�
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		print_log(_T("��" + count_str + "������֮����ʼ...\r\n"), gameclass);
		if(EnterYongShengZhiHai(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;

	}
	//ˢ���˳�
	if (count >= round)
	{
		print_log(_T("��������ɣ������˳�����ͥԺ...\r\n"), gameclass);
		if (returnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	}

	return 1;
}

//ͥԺ�������ģʽ
int BeginYongShengZhiHai::inviteYongShengZhiHai(long hd, int round, int layer, CString jc, dmsoft *dm, int gameclass, int index) {
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
	//�ж�ͥԺ�Ƿ�չ��,��δչ��ʹ֮չ��
	if (showYard(dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//������
	int resultCombine = CombineTeamAction(hd, dm, gameclass, index);
	if (resultCombine == 0) {
		print_log(_T("�ܱ�Ǹ��δ�ҵ���Ӱ�ť...\r\n"), gameclass);
		return 0;
	}
	else if (resultCombine == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ������֮��

	//��ȡĿ��λ��
	CString bmp_pic = _T("̽��(����).bmp|����ҵ����.bmp|���ѷ�ת��.bmp|����ˮ����.bmp|�������׹�.bmp|����.bmp|����֮��.bmp|����֮��.bmp|������ӡ.bmp|��������.bmp|�������.bmp|����.bmp|���ͻ��.bmp");
	CPoint startXY, endXY;
	startXY.x = 101, startXY.y = 75;
	endXY.x = 276, endXY.y = 503;

	//�ҵ����겢���
	findDestination(hd, bmp_pic, 7, _T("����֮��.bmp|����֮��(ѡ��).bmp"), startXY, endXY, dm, gameclass, index);
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ��
	//ѡ��㲢���
	startXY.x = 293, startXY.y = 129;
	endXY.x = 442, endXY.y = 432;
	int resultLayer = ChooseLayer(hd, layer, startXY, endXY, dm, gameclass, index);
	if (resultLayer == 0) {
		print_log(_T("δ�ҵ�Ŀ�����!!!\r\n"), gameclass);
		return 0;
	}else if(resultLayer == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//��������--�������
	int resultCreat = CreatYszhTeamToInvite(hd, dm, gameclass, index);
	if (resultCreat == 0) {
		print_log(_T("��������ʧ��!!!\r\n"), gameclass);
		return 0;
	}else if(resultCreat == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }

	//��ʼѭ��
	int count = 0;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//�����Ѽ�����鲢����ս
		if(InnerIsEnterTeam(hd, dm, count, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		//��������֮������
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		print_log(_T("��" + count_str + "������֮����ʼ...\r\n"), gameclass);
		if (InviteEnterEvent(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }

		if (count == 0)
		{
			if (DefalutInvite(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		count++;

	}
	//ˢ���˳�
	if (count >= round)
	{
		print_log(_T("��������ɣ������˳�����ͥԺ...\r\n"), gameclass);
		if (returnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	}

	return 1;
}
//ͥԺ��������ģʽ
int BeginYongShengZhiHai::BeinvitedYongShengZhiHai(long hd, int round, CString jc, dmsoft *dm, int gameclass, int index) {
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
	//��ʼѭ��
	int count = 0;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		//�����᪴��߸���
		print_log(_T("�ȴ���������...\r\n"), gameclass);
		if (ReceiveEnterEvent(hd, dm, count, _T("����֮��"), gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;

	}
	//ˢ���˳�
	if (count >= round)
	{
		print_log(_T("��������ɣ������˳�����ͥԺ...\r\n"), gameclass);
		if (returnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	}

	return 1;
}
