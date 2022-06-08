#include "pch.h"
#include "BeginJueXing.h"

#define EXIT_THREAD -10

extern bool readyFlag;
//ѡ��
int BeginJueXing::ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//�Զ��ܾ�����
	if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ȡĿ��λ��
	CString bmp_pic = _T("Ҽ��.bmp|����.bmp|����.bmp|����.bmp|���.bmp|½��.bmp|���.bmp|�Ʋ�.bmp|����.bmp|ʰ��.bmp");

	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//start ѡ���
	print_log(_T("ѡ����Ѳ���...\r\n"), gameclass);
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
	case 4: {
		if (findDestination(hd, bmp_pic, layer, _T("���.bmp|���(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 5: {
		if (findDestination(hd, bmp_pic, layer, _T("½��.bmp|½��(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 6: {
		if (findDestination(hd, bmp_pic, layer, _T("���.bmp|���(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 7: {
		if (findDestination(hd, bmp_pic, layer, _T("�Ʋ�.bmp|�Ʋ�(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 8: {
		if (findDestination(hd, bmp_pic, layer, _T("����.bmp|����(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 9: {
		if (findDestination(hd, bmp_pic, layer, _T("ʰ��.bmp|ʰ��(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}

//��ˢѡ�����
int BeginJueXing::SingleChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//�Զ��ܾ�����
	if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ȡĿ��λ��
	CString bmp_pic = _T("��ˢ����Ҽ��.bmp|��ˢ���ѷ���.bmp|��ˢ��������.bmp|��ˢ��������.bmp|��ˢ�������.bmp|��ˢ����½��.bmp|��ˢ�������.bmp|��ˢ���ѰƲ�.bmp|��ˢ���Ѿ���.bmp|��ˢ����ʰ��.bmp");

	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//start ѡ���
	print_log(_T("ѡ����Ѳ���...\r\n"), gameclass);
	switch (layer)
	{
	case 0: {
		if (findDestination(hd, bmp_pic, layer, _T("��ˢ����Ҽ��.bmp|��ˢ����Ҽ��(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestination(hd, bmp_pic, layer, _T("��ˢ���ѷ���.bmp|��ˢ���ѷ���(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestination(hd, bmp_pic, layer, _T("��ˢ��������.bmp|��ˢ��������(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 3: {
		if (findDestination(hd, bmp_pic, layer, _T("��ˢ��������.bmp|��ˢ��������(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 4: {
		if (findDestination(hd, bmp_pic, layer, _T("��ˢ�������.bmp|��ˢ�������(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 5: {
		if (findDestination(hd, bmp_pic, layer, _T("��ˢ����½��.bmp|��ˢ����½��(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 6: {
		if (findDestination(hd, bmp_pic, layer, _T("��ˢ�������.bmp|��ˢ�������(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 7: {
		if (findDestination(hd, bmp_pic, layer, _T("��ˢ���ѰƲ�.bmp|��ˢ���ѰƲ�(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 8: {
		if (findDestination(hd, bmp_pic, layer, _T("��ˢ���Ѿ���.bmp|��ˢ���Ѿ���(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 9: {
		if (findDestination(hd, bmp_pic, layer, _T("��ˢ����ʰ��.bmp|��ˢ����ʰ��(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}

//�����ѡ����ֻ���뷽�����������
int BeginJueXing::WhichToSelect(long hd, dmsoft *dm, CPoint startXY, CPoint endXY, CString source_pic, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	int i = 15;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	long intX, intY;
	while (i > 0)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//������
		if (dm->FindPic(startXY.x, startXY.y, endXY.x, endXY.y, source_pic, _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 5);
			if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
			return 1;
		}
		if (random_delay(index, gameclass, dm, 250, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 0;
}
//ѡ���ĸ�
int BeginJueXing::ChooseMonster(long hd, dmsoft *dm, int monster_kind, int gameclass, int index) {
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
	CString source_pic;
	switch (monster_kind)
	{
		//��  54,275,101,393,
	case 0: {
		startXY.x = 54, startXY.y = 275;
		endXY.x = 101, endXY.y = 393;
		source_pic = _T("������.bmp");
		print_log(_T("ѡ�������...\r\n"), gameclass);
		int resultSelect = WhichToSelect(hd, dm, startXY, endXY, source_pic, gameclass, index);
		if (resultSelect == 1){ break; }
		else if (resultSelect == EXIT_THREAD) { return EXIT_THREAD; }
		else if(resultSelect == 0){ return 0; }
	}//�� 279,281,329,396,
	case 1: {
		startXY.x = 279, startXY.y = 281;
		endXY.x = 329, endXY.y = 396;
		source_pic = _T("������.bmp");
		print_log(_T("ѡ�������...\r\n"), gameclass);
		int resultSelect = WhichToSelect(hd, dm, startXY, endXY, source_pic, gameclass, index);
		if (resultSelect == 1) { break; }
		else if (resultSelect == EXIT_THREAD) { return EXIT_THREAD; }
		else if (resultSelect == 0) { return 0; }
	}//ˮ  501,279,552,394,
	case 2: {
		startXY.x = 501, startXY.y = 279;
		endXY.x = 552, endXY.y = 394;
		source_pic = _T("ˮ����.bmp");
		print_log(_T("ѡ��ˮ����...\r\n"), gameclass);
		int resultSelect = WhichToSelect(hd, dm, startXY, endXY, source_pic, gameclass, index);
		if (resultSelect == 1) { break; }
		else if (resultSelect == EXIT_THREAD) { return EXIT_THREAD; }
		else if (resultSelect == 0) { return 0; }
	}//�� 728,269,770,390,
	case 3: {
		startXY.x = 728, startXY.y = 269;
		endXY.x = 770, endXY.y = 390;
		source_pic = _T("������.bmp");
		print_log(_T("ѡ��������...\r\n"), gameclass);
		int resultSelect = WhichToSelect(hd, dm, startXY, endXY, source_pic, gameclass, index);
		if (resultSelect == 1) { break; }
		else if (resultSelect == EXIT_THREAD) { return EXIT_THREAD; }
		else if (resultSelect == 0) { return 0; }
	}
	default:
		break;
	}
	return 1;
}

//Ѱ����
int BeginJueXing::FindJueXing(long hd, dmsoft *dm, int gameclass, int index) {
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
		if (dm->FindPic(25, 453, 109, 537, _T("���Ѳ���.bmp|���Ѳ���2.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
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
int BeginJueXing::lockTeam(long hd, dmsoft *dm, int gameclass, int index) {
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
int BeginJueXing::EnterJueXing(long hd, dmsoft *dm, int gameclass, int index) {
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

		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}

//ͥԺ�������ģʽ
int BeginJueXing::inviteJueXing(long hd, int round, int mode, int layer, CString jc, dmsoft *dm, int gameclass, int index) {
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
	//ѡ������

	//��ȡĿ��λ��
	CString bmp_pic = _T("̽��(����).bmp|����ҵ����.bmp|���ѷ�ת��.bmp|����ˮ����.bmp|�������׹�.bmp|����.bmp|����֮��.bmp|����֮��.bmp|������ӡ.bmp|��������.bmp|�������.bmp|����.bmp|���ͻ��.bmp");
	CPoint startXY, endXY;
	startXY.x = 101, startXY.y = 75;
	endXY.x = 276, endXY.y = 503;

	//�ҵ����Ѳ����
	CString mode_str;
	if (mode==0)
	{
		mode_str = _T("����ҵ����.bmp|����ҵ����(ѡ��).bmp");
	}else if (mode == 1) {
		mode_str = _T("���ѷ�ת��.bmp|���ѷ�ת��(ѡ��).bmp");
	}
	else if (mode == 2) {
		mode_str = _T("����ˮ����.bmp|����ˮ����(ѡ��).bmp");
	}
	else if (mode == 3) {
		mode_str = _T("�������׹�.bmp|�������׹�(ѡ��).bmp");
	}
	findDestination(hd, bmp_pic, mode+1, mode_str, startXY, endXY, dm, gameclass, index);
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ��
	//ѡ��㲢���
	startXY.x = 293, startXY.y = 129;
	endXY.x = 442, endXY.y = 432;
	int resultLayer = ChooseLayer(hd, layer, startXY, endXY, dm, gameclass, index);
	if (resultLayer == 0) {
		print_log(_T("δ�ҵ�Ŀ�����!!!\r\n"), gameclass);
		return 0;
	}
	else if (resultLayer == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//��������--�������
	int resultCreat = CreatTeamToInvite(hd, dm, gameclass, index);
	if (resultCreat == 0) {
		print_log(_T("��������ʧ��!!!\r\n"), gameclass);
		//δ�ҵ�������ѣ�����ͥԺ��رռӳ�
		startXY.x = 290, startXY.y = 10;
		endXY.x = 346, endXY.y = 80;
		if (random_delay(index, gameclass, dm, 1200, 2400) == EXIT_THREAD) { return EXIT_THREAD; }
		if (auto_close_jc(hd, _T("����"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		return 0;
	}else if(resultCreat == EXIT_THREAD){ return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ʼѭ��
	int count = 0;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//�����Ѽ�����鲢����ս
		if (IsEnterTeam(hd, dm, count, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//�Զ����ӳ�
		if (count == 0)
		{
			startXY.x = 82, startXY.y = 479;
			endXY.x = 121, endXY.y = 539;
			if (auto_open_jc(hd, _T("����"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		//������Ѹ���
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		print_log(_T("��" + count_str + "�־��ѿ�ʼ...\r\n"), gameclass);
		if (InviteEnterEvent(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }

		if (count == 0)
		{
			if (DefalutInvite(hd, dm, gameclass, index) == EXIT_THREAD){ return EXIT_THREAD; }
		}
		count++;

	}
	//ˢ���˳�
	if (count >= round)
	{
		print_log(_T("��������ɣ������˳�����ͥԺ...\r\n"), gameclass);
		if (returnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }

		//�Զ��ؼӳ�
		startXY.x = 290, startXY.y = 10;
		endXY.x = 346, endXY.y = 80;
		if (auto_close_jc(hd, _T("����"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}

	return 1;
}
//ͥԺ��������ģʽ
int BeginJueXing::BeinvitedJueXing(long hd, int round, CString jc, dmsoft *dm, int gameclass, int index) {
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
	//�Զ����ӳ�
	CPoint startXY, endXY;
	startXY.x = 294, startXY.y = 19;
	endXY.x = 336, endXY.y = 72;
	if (auto_open_jc(hd, _T("����"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD){ return EXIT_THREAD; }
	//��ʼѭ��
	int count = 0;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		//�����᪴��߸���
		print_log(_T("�ȴ���������...\r\n"), gameclass);
		if (ReceiveEnterEvent(hd, dm, count, _T("����"), gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;

	}
	//ˢ���˳�
	if (count >= round)
	{
		print_log(_T("��������ɣ������˳�����ͥԺ...\r\n"), gameclass);
		if (returnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }

		//�Զ��ؼӳ�
		startXY.x = 290, startXY.y = 10;
		endXY.x = 346, endXY.y = 80;
		if (auto_close_jc(hd, _T("����"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}

	return 1;
}
//��ʼ��ˢ
int BeginJueXing::SingleJueXing(long hd, int round, int monster_kind, int layer, CString jc, dmsoft *dm, int gameclass, int index) {
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
	//�Զ����ӳ�
	CPoint startXY, endXY;
	startXY.x = 294, startXY.y = 19;
	endXY.x = 336, endXY.y = 72;
	if (auto_open_jc(hd, _T("����"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	//Ѱ��̽�����������
	int result = FindExploreLanTernAndClick(hd, dm, gameclass, index);
	if (result == 0) {
		print_log(_T("��ͥԺ���棬��δ�ҵ�̽������!!!\r\n"), gameclass);
		return 0;
	}
	else if (result == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 2500, 3500) == EXIT_THREAD) { return EXIT_THREAD; }
	//Ѱ����
	if(FindJueXing(hd, dm, gameclass, index) == EXIT_THREAD){ return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ���ĸ�
	int resultChooseMonster = ChooseMonster(hd, dm, monster_kind, gameclass, index);
	if (resultChooseMonster == 0) {
		print_log(_T("δ�ҵ����룡\r\n"), gameclass);
		return 0;
	}else if(resultChooseMonster == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ���� 
	startXY.x = 109, startXY.y = 103;
	endXY.x = 362, endXY.y = 451;
	int resultSingleChoose = SingleChooseLayer(hd, layer, startXY, endXY, dm, gameclass, index);
	if (resultSingleChoose == 0) {
		print_log(_T("δ�ҵ�Ŀ��!!!\r\n"), gameclass);
		return 0;
	}
	else if (resultSingleChoose == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//��������
	if(lockTeam(hd, dm, gameclass, index) == EXIT_THREAD){ return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ʼѭ��
	int count = 0;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }

		//������Ѹ���
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		print_log(_T("��" + count_str + "�־��ѿ�ʼ...\r\n"), gameclass);
		if (EnterJueXing(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;

	}
	//ˢ���˳�
	if (count >= round)
	{
		print_log(_T("��������ɣ������˳�����ͥԺ...\r\n"), gameclass);
		if (returnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1000, 1800) == EXIT_THREAD) { return EXIT_THREAD; }
		//�Զ��ؼӳ�
		startXY.x = 290, startXY.y = 10;
		endXY.x = 346, endXY.y = 80;
		if (auto_close_jc(hd, _T("����"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}

	return 1;
}
/**
 *                      ������ . ����Ա֮��
 *
 *                  ʮ��������ãã��д���򣬵�������
 *                      ǧ�д��룬Bug�δ��ء�
 *                  ��ʹ����������������ģ�Ϧ�ϳ���
 *
 *                  �쵼ÿ�����뷨������ģ�����æ��
 *                      ������ԣ�Ω����ǧ�С�
 *                  ÿ��ƻ���ɺ����ҹ���£��Ӱ��
 */