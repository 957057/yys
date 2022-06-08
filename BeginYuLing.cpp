#include "pch.h"
#include "BeginYuLing.h"
#define EXIT_THREAD -10

extern bool readyFlag;
//ѡ��
int BeginYuLing::ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) {
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
	CString bmp_pic = _T("����Ҽ��.bmp|���鷡��.bmp|��������.bmp");
	//start ѡ���
	print_log(_T("ѡ���������...\r\n"), gameclass);
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
		if (findDestination(hd, bmp_pic, layer, _T("���鷡��.bmp|���鷡��(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
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
	default:
		return 0;
	}
	return 1;
}
//�����ѡ����ֻ���鷽�����������
int BeginYuLing::WhichToSelect(long hd, dmsoft *dm, CPoint startXY, CPoint endXY, CString source_pic[2], int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	int i = 15;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	long intX, intY;
	while (i>0)
	{	
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//������
		if (dm->FindPic(startXY.x, startXY.y, endXY.x, endXY.y, source_pic[0], _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 5);
			if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			return 1;
		}//δ����
		if (dm->FindPic(startXY.x, startXY.y, endXY.x, endXY.y, source_pic[1], _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			return 0;
		}
		if (random_delay(index, gameclass, dm, 250, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 0;
}
//ѡ���ĸ�
int BeginYuLing::ChooseMonster(long hd, dmsoft *dm, int monster_kind, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	int i = 15;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//����һЩ����
	CPoint startXY, endXY;
	CString source_pic[2];
	switch (monster_kind)
	{
	//����  96,360,146,485,
	case 0: {
		startXY.x = 96, startXY.y = 360;
		endXY.x = 146, endXY.y = 485;
		source_pic[0] = _T("������.bmp"), source_pic[1] = _T("������(δ����).bmp");
		int resultToSelect = WhichToSelect(hd, dm, startXY, endXY, source_pic, gameclass, index);
		if (resultToSelect == 1)
		{
			print_log(_T("ѡ������...\r\n"), gameclass);
			break;
		}else if(resultToSelect == 0){ return 0; }
		else if(resultToSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}//�ײ���
	case 1: {
		startXY.x = 316, startXY.y = 319;
		endXY.x = 364, endXY.y = 479;
		source_pic[0] = _T("���ײ���.bmp"), source_pic[1] = _T("���ײ���(δ����).bmp");
		int resultToSelect = WhichToSelect(hd, dm, startXY, endXY, source_pic, gameclass, index);
		if (resultToSelect == 1)
		{
			print_log(_T("ѡ�񰵰ײ���...\r\n"), gameclass);
			break;
		}else if (resultToSelect == 0) { return 0; }
		else if (resultToSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}//�ڱ� 526,356,587,486,
	case 2: {
		startXY.x = 526, startXY.y = 356;
		endXY.x = 587, endXY.y = 486;
		source_pic[0] = _T("���ڱ�.bmp"), source_pic[1] = _T("���ڱ�(δ����).bmp");
		int resultToSelect = WhichToSelect(hd, dm, startXY, endXY, source_pic, gameclass, index);
		if (resultToSelect == 1)
		{
			print_log(_T("ѡ�񰵺ڱ�...\r\n"), gameclass);
			break;
		}else if (resultToSelect == 0) { return 0; }
		else if (resultToSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}//��ȸ  750,358,801,483
	case 3: {
		startXY.x = 750, startXY.y = 358;
		endXY.x = 801, endXY.y = 483;
		source_pic[0] = _T("����ȸ.bmp"), source_pic[1] = _T("����ȸ(δ����).bmp");
		int resultToSelect = WhichToSelect(hd, dm, startXY, endXY, source_pic, gameclass, index);
		if (resultToSelect == 1)
		{
			print_log(_T("ѡ�񰵿�ȸ...\r\n"), gameclass);
			break;
		}else if (resultToSelect == 0) { return 0; }
		else if (resultToSelect == EXIT_THREAD) { return EXIT_THREAD; }
	}
	default:
		break;
	}
	return 1;
}

//Ѱ����
int BeginYuLing::FindYuLing(long hd, dmsoft *dm, int gameclass, int index) {
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
		if (dm->FindPic(273, 460, 352, 537, _T("̽������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 20);
			if (random_delay(index, gameclass, dm, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 700) == EXIT_THREAD) { return EXIT_THREAD; }
	}

	return 1;
}
//��������
int BeginYuLing::lockTeam(long hd, dmsoft *dm, int gameclass, int index) {
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
		if (dm->FindPic(411, 415, 452, 454, _T("�����������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("��������...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 13, intY + 13);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			readyFlag = FALSE;
			break;
		}
		if (dm->FindPic(411, 415, 452, 454, _T("������������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			readyFlag = FALSE;
			break;
		}

		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 1;
}
//���븱��
int BeginYuLing::EnterYuLing(long hd, dmsoft *dm, int gameclass, int index) {
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
		if (dm->FindPic(824, 437, 902, 505, _T("��ս����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
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
		if (dm->FindPic(271, 40, 423, 216, _T("ʧ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("��սʧ��\r\n"), gameclass);
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
//��ʼ
int BeginYuLing::StartYuLing(long hd, int round, int monster_kind, int layer, dmsoft *dm, int gameclass, int index) {
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
	//Ѱ����
	if(FindYuLing(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ���ĸ�
	if (!ChooseMonster(hd, dm, monster_kind, gameclass, index)) {
		print_log(_T("��������տ���δ������\r\n"), gameclass);
		print_log(_T("���ڷ���ͥԺ...\r\n"), gameclass);
		if (returnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		return 0;
	}
	//ѡ����
	CPoint startXY, endXY;
	startXY.x = 109, startXY.y = 103;
	endXY.x = 362, endXY.y = 451;
	int resultLayer = ChooseLayer(hd, layer, startXY, endXY, dm, gameclass, index);
	if (resultLayer == 0) {
		print_log(_T("δ�ҵ�Ŀ��!!!\r\n"), gameclass);
		return 0;
	}else if(resultLayer == EXIT_THREAD) { return EXIT_THREAD; }
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

		//�������鸱��
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		print_log(_T("��" + count_str + "�����鿪ʼ...\r\n"), gameclass);
		if(EnterYuLing(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
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
