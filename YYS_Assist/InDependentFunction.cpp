#include "pch.h"
#include "InDependentFunction.h"
#define EXIT_THREAD -10

//�ٹ�ҹ��
int InDependentFunction::StartBaiGui(long hd, int round, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	if (dm->FindPic(782, 412, 882, 496, _T("�ٹ����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1)
	{
		print_log(_T("�����ٹ�ҹ��ҳ��...\r\n"), gameclass);
		return 0;
	}
	print_log(_T("Ĭ��1000��Ʊ����ʱ���ɸ���...\r\n"), gameclass);
	int count = 0;
	while (count < round) {
		//�ܾ�����
		AutoRejectXS(hd, dm, gameclass, index);
		if (dm->FindPic(782, 412, 882, 496, _T("�ٹ����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			print_log(_T("����ٹ�ҹ��...\r\n"), gameclass);
			mouse_click_event(title, intX + 10, intY + 20);
			if (random_delay(index, gameclass, dm, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}//416,3,553,59,
		if (dm->FindPic(416, 3, 553, 59, _T("�ٹ�ҹ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
			if (dm->FindPic(442, 69, 521, 441, _T("�ٹ�Ѻ.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1) {
				if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
				print_log(_T("Ѻʽ��...\r\n"), gameclass);
				CPoint pos = random_pos(477, 314, 1, 4);
				mouse_click_event(title, pos.x, pos.y);
				if (random_delay(index, gameclass, dm, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (dm->FindPic(442, 69, 521, 441, _T("�ٹ�Ѻ.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (dm->FindPic(833, 427, 915, 481, _T("�ٹ�ʼ.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
					if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
					CString count_str;
					count_str.Format(_T("%d"), count + 1);
					print_log(_T("��"+count_str+"�ְٹ�ҹ�п�ʼ...\r\n"), gameclass);
					mouse_click_event(title, intX + 10, intY + 5);
					if (random_delay(index, gameclass, dm, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
			}
		}
		if (dm->FindPic(44, 473, 101, 514, _T("�ٹ���.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			print_log(_T("��ʼ����...\r\n"), gameclass);
			count++;
			while (1) {
				AutoRejectXS(hd, dm, gameclass, index);
				CPoint posx = random_pos(507, 295, -200, 200);
				CPoint posy = random_pos(507, 295, -5, 5);
				if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, posx.x, posy.y);
				int beanRes = dm->FindPic(34, 468, 134, 515, _T("����0��.bmp|����0��.bmp"), _T("202020"), 0.9, 0, &intX, &intY);
				int timeRes = dm->FindPic(448, 1, 508, 50,  _T("ʱ����.bmp"), _T("202020"), 0.9, 0, &intX, &intY);
				while ((beanRes != -1) || (timeRes != -1)) {
					if (dm->FindPic(72, 165, 117, 335, _T("�ٹ���Լ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
						if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 5);
						if (random_delay(index, gameclass, dm, 1000, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					if (dm->FindPic(782, 412, 882, 496, _T("�ٹ����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
						break;
					}
					if (random_delay(index, gameclass, dm, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(782, 412, 882, 496, _T("�ٹ����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
					break;
				}
			}
			//34,468,134,515,  0��
			//448,1,508,50,    ʱ����
		}
	}
	if (count >= round) {
		print_log(_T("��ɰٹ�ҹ��...\r\n"), gameclass);
		return 1;
	}
}
//�»
int InDependentFunction::StartNewEvent(long hd, int round, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	/*if (dm->FindPic(670, 299, 919, 505, _T("��ʼѲ��.bmp|ս��Ѳ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1)
	{
		print_log(_T("�����ҳ��...\r\n"), gameclass);
		return 0;
	}*/
	print_log(_T("��ʼǰ���Լ���������...\r\n"), gameclass);
	int count = 0;
	while (count < round) {
		//�ܾ�����
		AutoRejectXS(hd, dm, gameclass, index);
		/*if (dm->FindPic(670, 299, 707, 423, _T("ս��Ѳ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			print_log(_T("����ս��Ѳ��...\r\n"), gameclass);
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(612, 145, 669, 267, _T("ս��Ѳ��1.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			print_log(_T("����ս��Ѳ��...\r\n"), gameclass);
			mouse_click_event(title, intX, intY + 20);
			if (random_delay(index, gameclass, dm, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(825, 412, 919, 505, _T("��ʼѲ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			print_log(_T("��ʼѲ��...\r\n"), gameclass);
			mouse_click_event(title, intX + 10, intY + 10);
			if (random_delay(index, gameclass, dm, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}*/
		if (dm->FindPic(0, 0, 960, 540, _T("���ս.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			CString count_str;
			count_str.Format(_T("%d"), count + 1);
			print_log(_T("��" + count_str + "����ս��ʼ...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			print_log(_T("��ʼ��ս...\r\n"), gameclass);
			mouse_click_event(title, intX + 10, intY + 10);
			count++;
			if (random_delay(index, gameclass, dm, 2000, 3000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(286, 34, 438, 169, _T("ʤ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("ս��������...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1200, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 429, 1, 5);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 500, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(335, 256, 616, 497, _T("��.bmp|��(�ײ�).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("��ȡ����...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 1, 5);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	//ˢ���˳�
	if (count >= round)
	{
		print_log(_T("���������.\r\n"), gameclass);
		if (random_delay(index, gameclass, dm, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
/*
					  .::::.
					 .::::::::.
					:::::::::::
				 ..:::::::::::'
			  '::::::::::::'
				.::::::::::
		   '::::::::::::::..
				..::::::::::::.
			  ``::::::::::::::::
			   ::::``:::::::::'        .:::.
			  ::::'   ':::::'       .::::::::.
			.::::'      ::::     .:::::::'::::.
		   .:::'       :::::  .:::::::::' ':::::.
		  .::'        :::::.:::::::::'      ':::::.
		 .::'         ::::::::::::::'         ``::::.
	 ...:::           ::::::::::::'              ``::.
	```` ':.          ':::::::::'                  ::::..
					   '.:::::'                    ':'````..
*/