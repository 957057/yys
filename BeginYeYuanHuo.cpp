#include "pch.h"
#include "BeginYeYuanHuo.h"
#define EXIT_THREAD -10
//����������㼲��һ�տ�����������
extern bool readyFlag;
//ѡ��
int BeginYeYuanHuo::ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) {
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
	CString bmp_pic = _T("̰֮��.bmp|��֮��.bmp|��֮��.bmp");
	//start ѡ���
	print_log(_T("ѡ��ҵԭ��̰|��|��...\r\n"), gameclass);
	switch (layer)
	{
	case 0: {
		if (findDestination(hd, bmp_pic, layer, _T("̰֮��.bmp|̰֮��(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestination(hd, bmp_pic, layer, _T("��֮��.bmp|��֮��(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestination(hd, bmp_pic, layer, _T("��֮��.bmp|��֮��(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
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
int BeginYeYuanHuo::FindYeYuanHuo(long hd, dmsoft *dm, int gameclass, int index) {
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
		//����Զ�ƥ��
		if (dm->FindPic(111, 456, 193, 537, _T("̽������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX+10, intY+20);
			if (random_delay(index, gameclass, dm, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//��ҵԭ��
		if (dm->FindPic(308, 80, 381, 224, _T("��ˢҵԭ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
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
int BeginYeYuanHuo::lockTeam(long hd, dmsoft *dm, int gameclass, int index) {
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
	while (i>0)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(411, 415, 452, 454, _T("��������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("��������...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX+13, intY+13);
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
int BeginYeYuanHuo::EnterYeYuanHuo(long hd, dmsoft *dm, int gameclass, int index) {
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
		if (dm->FindPic(824, 437, 902, 505, _T("��սҵԭ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
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
//��ʼ
int BeginYeYuanHuo::StartYeYuanHuo(long hd, int round, int layer,  dmsoft *dm, int gameclass, int index) {
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
	//Ѱҵԭ��
	if(FindYeYuanHuo(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ����
	CPoint startXY, endXY;
	startXY.x = 110, startXY.y = 93;
	endXY.x = 360, endXY.y = 439;
	int resultLayer = ChooseLayer(hd, layer, startXY, endXY, dm, gameclass, index);
	if (resultLayer == 0) {
		print_log(_T("δ�ҵ�Ŀ��!!!\r\n"), gameclass);
		return 0;
	}else if(resultLayer == EXIT_THREAD){ return EXIT_THREAD; }
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
		print_log(_T("��" + count_str + "��ҵԭ��ʼ...\r\n"), gameclass);
		if(EnterYeYuanHuo(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
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
