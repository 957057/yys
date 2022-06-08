#include "pch.h"
#include "BeginYaoQiFengYin.h"
#define EXIT_THREAD -10

//ѡ��	���۶�Լȡ�������������
int BeginYaoQiFengYin::ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//�Զ��ܾ�����
	if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ȡĿ��λ��
	CString bmp_pic = _T("�������.bmp|��ͼ.bmp|��Ů.bmp|����.bmp|����Ů.bmp|������.bmp|��ʹ��.bmp|С����.bmp|�պͷ�.bmp");

	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//start ѡ���
	print_log(_T("ѡ��������ӡ����...\r\n"), gameclass);
	switch (layer)
	{
	case 0: {
		if (findDestination(hd, bmp_pic, layer, _T("�������.bmp|�������(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestination(hd, bmp_pic, layer, _T("��ͼ.bmp|��ͼ(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestination(hd, bmp_pic, layer, _T("��Ů.bmp|��Ů(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
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
	case 4: {
		if (findDestination(hd, bmp_pic, layer, _T("����Ů.bmp|����Ů(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 5: {
		if (findDestination(hd, bmp_pic, layer, _T("������.bmp|������(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 6: {
		if (findDestination(hd, bmp_pic, layer, _T("��ʹ��.bmp|��ʹ��(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 7: {
		if (findDestination(hd, bmp_pic, layer, _T("С����.bmp|С����(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 8: {
		if (findDestination(hd, bmp_pic, layer, _T("�պͷ�.bmp|�պͷ�(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}
int BeginYaoQiFengYin::EnterYaoQiFengYin(long hd, int condition, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//����ֲ�����
	long intX, intY;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//�Զ�ƥ��
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//������
		if (dm->FindPic(262, 444, 323, 510, _T("���.bmp|��ɫ���.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			print_log(_T("������...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY);
		}
		//����Զ�ƥ��
		if (dm->FindPic(517, 443, 665, 495, _T("�Զ�ƥ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			print_log(_T("�Ŷ���...\r\n"), gameclass);
		}
		//���Լ���Ϊ����������ս
		if (dm->FindPic(874, 436, 953, 518, _T("��ս.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			if (condition==0) {
				print_log(_T("�Լ���Ϊ�����������ս...\r\n"), gameclass);
				//���ƫ����������
				CPoint pos = random_pos(intX, intY, 5, 10);
				if (random_delay(index, gameclass, dm, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, pos.x, pos.y);
				if (random_delay(index, gameclass, dm, 2000, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if (condition == 1) {
				print_log(_T("��Ϊ�����������˳�����ͥԺ...\r\n"), gameclass);
				if (returnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (random_delay(index, gameclass, dm, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
		}
		//��׼��
		if (dm->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("���׼��...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(intX, intY, 1, 5);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//ʤ������
		if (dm->FindPic(286, 34, 438, 169, _T("ʤ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("ս��������...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1200, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 429, 1, 5);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(335, 256, 616, 497, _T("��.bmp|��(�ײ�).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 1, 5);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 700) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//��ʼ
int BeginYaoQiFengYin::StartYaoQiFengYin(long hd, int round, int monsterKind, int condition, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	
	//�ж��Ƿ���ͥԺ
	if (!IsInYard(dm, gameclass, index))
	{
		print_log(_T("��ȷ����ͥԺ����!!!\r\n"), gameclass);
		return 0;
	}
	if (random_delay(index, gameclass, dm, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	//�ж�ͥԺ�Ƿ�չ��,��δչ��ʹ֮չ��
	if (showYard(dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	//�˳��߳�
	if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//������
	int resultCombine = CombineTeamAction(hd, dm, gameclass, index);
	if (resultCombine == 0) {
		print_log(_T("�ܱ�Ǹ��δ�ҵ���Ӱ�ť...\r\n"), gameclass);
		return 0;
	}
	else if (resultCombine == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ��������ӡ

	//��ȡĿ��λ��
	CString bmp_pic = _T("̽��(����).bmp|����ҵ����.bmp|���ѷ�ת��.bmp|����ˮ����.bmp|�������׹�.bmp|����.bmp|����֮��.bmp|����֮��.bmp|������ӡ.bmp|��������.bmp|�������.bmp|����.bmp|���ͻ��.bmp");
	CPoint startXY, endXY;
	startXY.x = 101, startXY.y = 75;
	endXY.x = 276, endXY.y = 503;

	//�ҵ�������ӡ�����
	findDestination(hd, bmp_pic, 8, _T("������ӡ.bmp|������ӡ(ѡ��).bmp"), startXY, endXY, dm, gameclass, index);
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ��
	//ѡ��㲢���
	startXY.x = 293, startXY.y = 129;
	endXY.x = 442, endXY.y = 432;
	int resultLayer = ChooseLayer(hd, monsterKind, startXY, endXY, dm, gameclass, index);
	if (resultLayer == 0) {
		print_log(_T("δ�ҵ�Ŀ��!!!\r\n"), gameclass);
		return 0;
	}else if(resultLayer == EXIT_THREAD){ return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	
	//��ʼѭ��
	int count = 0;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		
		//����������ӡ����
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		print_log(_T("��" + count_str + "��������ӡ��ʼ...\r\n"), gameclass);
		if(EnterYaoQiFengYin(hd, condition, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
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
