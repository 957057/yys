#include "pch.h"
#include "BeginExplore.h"
#define EXIT_THREAD -10

extern CString g_path;
int BeginExplore::isExplore(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	int i = 3;
	long intX, intY;
	while (i > 0)
	{
		//�Զ��ܾ�����
		/**
		 *        ɽ���꣬��ˮΪ�ߣ�������������ѩ����غ�,�˸��������
		 */
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(749, 81, 823, 142, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			long parentHandle = dm->GetWindow(hd, 0);
			CString title = dm->GetWindowTitle(parentHandle);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 2, intY + 2);
			if (random_delay(index, gameclass, dm, 2000, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		i--;
		if (random_delay(index, gameclass, dm, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}

//ѡ��
int BeginExplore::ChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//�Զ��ܾ�����
	if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ȡĿ��λ��
	CString bmp_pic = _T("��һ��.bmp|�ڶ���.bmp|������.bmp|������.bmp|������.bmp|������.bmp|������.bmp|�ڰ���.bmp|�ھ���.bmp|��ʮ��.bmp|��ʮһ��.bmp|��ʮ����.bmp|��ʮ����.bmp|��ʮ����.bmp|��ʮ����.bmp|��ʮ����.bmp|��ʮ����.bmp|��ʮ����.bmp|��ʮ����.bmp|�ڶ�ʮ��.bmp|�ڶ�ʮһ��.bmp|�ڶ�ʮ����.bmp|�ڶ�ʮ����.bmp|�ڶ�ʮ����.bmp|�ڶ�ʮ����.bmp|�ڶ�ʮ����.bmp|�ڶ�ʮ����.bmp|�ڶ�ʮ����.bmp");

	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//start ѡ���
	print_log(_T("ѡ��ָ���ؿ�...\r\n"), gameclass);
	switch (layer)
	{
	case 0: {
		if (findDestination(hd, bmp_pic, layer, _T("��һ��.bmp|��һ��(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestination(hd, bmp_pic, layer, _T("�ڶ���.bmp|�ڶ���(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestination(hd, bmp_pic, layer, _T("������.bmp|������(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 3: {
		if (findDestination(hd, bmp_pic, layer, _T("������.bmp|������(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 4: {
		if (findDestination(hd, bmp_pic, layer, _T("������.bmp|������(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
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
		if (findDestination(hd, bmp_pic, layer, _T("������.bmp|������(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 7: {
		if (findDestination(hd, bmp_pic, layer, _T("�ڰ���.bmp|�ڰ���(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 8: {
		if (findDestination(hd, bmp_pic, layer, _T("�ھ���.bmp|�ھ���(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 9: {
		if (findDestination(hd, bmp_pic, layer, _T("��ʮ��.bmp|��ʮ��(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 10: {
		if (findDestination(hd, bmp_pic, layer, _T("��ʮһ��.bmp|��ʮһ��(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 11: {

		if (findDestination(hd, bmp_pic, layer, _T("��ʮ����.bmp|��ʮ����(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 12: {

		if (findDestination(hd, bmp_pic, layer, _T("��ʮ����.bmp|��ʮ����(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 13: {

		if (findDestination(hd, bmp_pic, layer, _T("��ʮ����.bmp|��ʮ����(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 14: {

		if (findDestination(hd, bmp_pic, layer, _T("��ʮ����.bmp|��ʮ����(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 15: {

		if (findDestination(hd, bmp_pic, layer, _T("��ʮ����.bmp|��ʮ����(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 16: {

		if (findDestination(hd, bmp_pic, layer, _T("��ʮ����.bmp|��ʮ����(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 17: {

		if (findDestination(hd, bmp_pic, layer, _T("��ʮ����.bmp|��ʮ����(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 18: {

		if (findDestination(hd, bmp_pic, layer, _T("��ʮ����.bmp|��ʮ����(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 19: {

		if (findDestination(hd, bmp_pic, layer, _T("�ڶ�ʮ��.bmp|�ڶ�ʮ��(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 20: {

		if (findDestination(hd, bmp_pic, layer, _T("�ڶ�ʮһ��.bmp|�ڶ�ʮһ��(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 21: {

		if (findDestination(hd, bmp_pic, layer, _T("�ڶ�ʮ����.bmp|�ڶ�ʮ����(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 22: {

		if (findDestination(hd, bmp_pic, layer, _T("�ڶ�ʮ����.bmp|�ڶ�ʮ����(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 23: {

		if (findDestination(hd, bmp_pic, layer, _T("�ڶ�ʮ����.bmp|�ڶ�ʮ����(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 24: {

		if (findDestination(hd, bmp_pic, layer, _T("�ڶ�ʮ����.bmp|�ڶ�ʮ����(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 25: {

		if (findDestination(hd, bmp_pic, layer, _T("�ڶ�ʮ����.bmp|�ڶ�ʮ����(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 26: {

		if (findDestination(hd, bmp_pic, layer, _T("�ڶ�ʮ����.bmp|�ڶ�ʮ����(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 27: {

		if (findDestination(hd, bmp_pic, layer, _T("�ڶ�ʮ����.bmp|�ڶ�ʮ����(ѡ��).bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	return 1;
}

//��ˢѡ��
int BeginExplore::SingleChooseLayer(long hd, int layer, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//�Զ��ܾ�����
	if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ȡĿ��λ��
	CString bmp_pic = _T("1.bmp|2.bmp|3.bmp|4.bmp|5.bmp|6.bmp|7.bmp|8.bmp|9.bmp|10.bmp|11.bmp|12.bmp|13.bmp|14.bmp|15.bmp|16.bmp|17.bmp|18.bmp|19.bmp|20.bmp|21.bmp|22.bmp|23.bmp|24.bmp|25.bmp|26.bmp|27.bmp|28.bmp");
	CString bmp_pic2 = _T("1-1.bmp|2-1.bmp|3-1.bmp|4-1.bmp|5-1.bmp|6-1.bmp|7-1.bmp|8-1.bmp|9-1.bmp|10-1.bmp|11-1.bmp|12-1.bmp|13-1.bmp|14-1.bmp|15-1.bmp|16-1.bmp|17-1.bmp|18-1.bmp|19-1.bmp|20-1.bmp|21-1.bmp|22-1.bmp|23-1.bmp|24-1.bmp|25-1.bmp|26-1.bmp|27-1.bmp|28-1.bmp");

	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//start ѡ���
	print_log(_T("ѡ��ָ���ؿ�...\r\n"), gameclass);
	switch (layer)
	{
	case 0: {
		if (findDestination(hd, bmp_pic, layer, _T("1.bmp|1-1.bmp"),startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("1.bmp|1-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else {
			return 0;
		}
	}
	case 1: {
		if (findDestination(hd, bmp_pic, layer, _T("2.bmp|2-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("2.bmp|2-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 2: {
		if (findDestination(hd, bmp_pic, layer, _T("3.bmp|3-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("3.bmp|3-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 3: {
		if (findDestination(hd, bmp_pic, layer, _T("4.bmp|4-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("4.bmp|4-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 4: {
		if (findDestination(hd, bmp_pic, layer, _T("5.bmp|5-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("5.bmp|5-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 5: {
		if (findDestination(hd, bmp_pic, layer, _T("6.bmp|6-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("6.bmp|6-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 6: {
		if (findDestination(hd, bmp_pic, layer, _T("7.bmp|7-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic, layer, _T("7.bmp|7-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 7: {
		if (findDestination(hd, bmp_pic, layer, _T("8.bmp|8-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("8.bmp|8-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 8: {
		if (findDestination(hd, bmp_pic, layer, _T("9.bmp|8-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("9.bmp|8-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 9: {
		if (findDestination(hd, bmp_pic, layer, _T("10.bmp|10-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("10.bmp|10-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 10: {
		if (findDestination(hd, bmp_pic, layer, _T("11.bmp|11-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("11.bmp|11-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 11: {

		if (findDestination(hd, bmp_pic, layer, _T("12.bmp|12-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("12.bmp|12-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 12: {

		if (findDestination(hd, bmp_pic, layer, _T("13.bmp|13-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("13.bmp|13-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 13: {

		if (findDestination(hd, bmp_pic, layer, _T("14.bmp|14-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("14.bmp|14-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 14: {

		if (findDestination(hd, bmp_pic, layer, _T("15.bmp|15-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("15.bmp|15-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 15: {

		if (findDestination(hd, bmp_pic, layer, _T("16.bmp|16-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("16.bmp|16-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 16: {

		if (findDestination(hd, bmp_pic, layer, _T("17.bmp|17-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("17.bmp|17-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 17: {

		if (findDestination(hd, bmp_pic, layer, _T("18.bmp|18-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("18.bmp|18-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 18: {

		if (findDestination(hd, bmp_pic, layer, _T("19.bmp|19-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("19.bmp|19-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 19: {

		if (findDestination(hd, bmp_pic, layer, _T("20.bmp|20-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("20.bmp|20-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 20: {

		if (findDestination(hd, bmp_pic, layer, _T("21.bmp|21-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("21.bmp|21-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 21: {

		if (findDestination(hd, bmp_pic, layer, _T("22.bmp|22-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("22.bmp|22-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 22: {

		if (findDestination(hd, bmp_pic, layer, _T("23.bmp|23-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("23.bmp|23-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 23: {

		if (findDestination(hd, bmp_pic, layer, _T("24.bmp|24-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("24.bmp|24-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 24: {

		if (findDestination(hd, bmp_pic, layer, _T("25.bmp|25-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("25.bmp|25-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 25: {

		if (findDestination(hd, bmp_pic, layer, _T("26.bmp|26-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("26.bmp|26-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 26: {

		if (findDestination(hd, bmp_pic, layer, _T("27.bmp|27-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("27.bmp|27-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	case 27: {

		if (findDestination(hd, bmp_pic, layer, _T("28.bmp|28-1.bmp"), startXY, endXY, dm, gameclass, index) || findDestination(hd, bmp_pic2, layer, _T("28.bmp|28-1.bmp"), startXY, endXY, dm, gameclass, index))
			break;
		else
			return 0;
	}
	default:
		return 0;
	}
	print_log(_T("��ѡ��...\r\n"), gameclass);
	return 1;
}
//ѡ���Ѷ�
int BeginExplore::ChooseDiff(long hd, int diff, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//ѡ���Ѷ�
	long intX, intY;
	int i = 10;
	//��ͨ(δѡ��) 221,142,283,199,   ����(δѡ��)  320,142,386,201,
	if (diff)
	{
		while (i > 0)
		{
			//�Զ��ܾ�����
			if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			if (dm->FindPic(221, 142, 283, 199, _T("��ͨ(δѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
			{
				print_log(_T("��ѡ�������Ѷ�...\r\n"), gameclass);
				return 1;
			}
			else if (dm->FindPic(320, 142, 386, 201, _T("����(δѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				print_log(_T("ѡ�������Ѷ�...\r\n"), gameclass);
				mouse_click_event(title, intX + 16, intY);
				if (random_delay(index, gameclass, dm, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (random_delay(index, gameclass, dm, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
			i--;
		}
	}
	else if (!diff)
	{
		while (i > 0)
		{
			//�Զ��ܾ�����
			if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			if (dm->FindPic(320, 142, 386, 201, _T("����(δѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
			{
				print_log(_T("��ѡ����ͨ�Ѷ�...\r\n"), gameclass);
				return 1;
			}
			else if (dm->FindPic(221, 142, 283, 199, _T("��ͨ(δѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				print_log(_T("ѡ����ͨ�Ѷ�...\r\n"), gameclass);
				mouse_click_event(title, intX + 16, intY);
				if (random_delay(index, gameclass, dm, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (random_delay(index, gameclass, dm, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
			i--;
		}
	}
	return 0;
}

int BeginExplore::clickExplore(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	int i = 10;
	long intX, intY;
	long findRes;
	while (i > 0)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		findRes = dm->FindPic(642, 367, 773, 438, _T("̽����ť.bmp"), _T("202020"), 0.9, 0, &intX, &intY);
		if (findRes != -1)
		{
			break;
		}
		if (random_delay(index, gameclass, dm, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	if (findRes != -1)
	{
		//��ȡ�����ڱ���
		long parentHandle = dm->GetWindow(hd, 0);
		CString title = dm->GetWindowTitle(parentHandle);
		//���
		print_log(_T("����̽������...\r\n"), gameclass);
		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		mouse_click_event(title, intX, intY);
		if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		return 1;
	}
	return 0;
}

int BeginExplore::autoRotate(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	long rotateRes;
	int i = 10;
	while (i > 0)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		rotateRes = dm->FindPic(86, 493, 107, 515, _T("�Զ��ֻ�.bmp|�Զ��ֻ�1.bmp|�Զ��ֻ�2.bmp|�Զ��ֻ�3.bmp"), _T("101010"), 0.95, 0, &intX, &intY);
		if (rotateRes != -1)
		{

			break;
		}
		if (random_delay(index, gameclass, dm, 280, 320) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	if (rotateRes != -1)
	{
		//��ȡ�����ڱ���
		long parentHandle = dm->GetWindow(hd, 0);
		CString title = dm->GetWindowTitle(parentHandle);
		//���
		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		mouse_click_event(title, intX+1, intY+1);
		if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		return 1;
	}
	return 0;
}

int BeginExplore::findCommonMonster(long hd, dmsoft *dm, int gameclass, int index,int speed) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	long findRes;
	int i = 15;
	while (i > 0)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		findRes = dm->FindPic(9, 30, 957, 446, _T("monster_common1.bmp|monster_common2.bmp|monster_common3.bmp|monster_common4.bmp|monster_common5.bmp"), _T("202020"), 0.8, 0, &intX, &intY);
		if (findRes != -1)
		{
			break;
		}
		if (speed == 0) {
			if (random_delay(index, gameclass, dm, 180, 220) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if (speed == 1) {
			if (random_delay(index, gameclass, dm, 20, 50) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		i--;
	}
	if (findRes != -1)
	{
		//��ȡ�����ڱ���
		long parentHandle = dm->GetWindow(hd, 0);
		CString title = dm->GetWindowTitle(parentHandle);
		//���
		print_log(_T("�ҵ���ͨ��...\r\n"), gameclass);
		mouse_click_event(title, intX, intY);
		if (random_delay(index, gameclass, dm, 3800, 4200) == EXIT_THREAD) { return EXIT_THREAD; }
		while (1)
		{
			//�Զ��ܾ�����
			if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			if (dm->FindPic(9, 30, 957, 446, _T("monster_common1.bmp|monster_common2.bmp|monster_common3.bmp|monster_common4.bmp|monster_common5.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1)
			{
				//���
				print_log(_T("�ҵ���ͨ��...\r\n"), gameclass);
				mouse_click_event(title, intX, intY);
				if (random_delay(index, gameclass, dm, 3800, 4200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (dm->FindPic(838, 405, 935, 474, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				print_log(_T("���׼��...\r\n"), gameclass);
				CPoint pos = random_pos(intX, intY, 1, 3);
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, pos.x, pos.y);
				if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (dm->FindPic(233, 30, 536, 253, _T("ʤ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
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
				if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
			if (dm->FindPic(421, 289, 538, 350, _T("������ȷ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (random_delay(index, gameclass, dm, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, intX, intY);
				if (random_delay(index, gameclass, dm, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}

		}
		return 1;
	}
	return 0;
}

int BeginExplore::findBossMonster(long hd, dmsoft *dm, int gameclass, int index, int speed) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	long findRes;
	int i = 10;
	while (i > 0)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		findRes = dm->FindPic(9, 30, 957, 446, _T("monster_boss.bmp|monster_boss1.bmp|monster_boss2.bmp"), _T("202020"), 0.8, 0, &intX, &intY);
		if (findRes != -1)
		{
			break;
		}
		if (speed == 0) {
			if (random_delay(index, gameclass, dm, 180, 220) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if (speed == 1) {
			if (random_delay(index, gameclass, dm, 20, 50) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		i--;
	}
	if (findRes != -1)
	{
		//��ȡ�����ڱ���
		long parentHandle = dm->GetWindow(hd, 0);
		CString title = dm->GetWindowTitle(parentHandle);
		//���
		print_log(_T("����Boss...\r\n"), gameclass);
		mouse_click_event(title, intX, intY);
		if (random_delay(index, gameclass, dm, 3800, 4200) == EXIT_THREAD) { return EXIT_THREAD; }
		while (1)
		{
			//�Զ��ܾ�����
			if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			if (dm->FindPic(9, 30, 957, 446, _T("monster_boss.bmp|monster_boss1.bmp|monster_boss2.bmp"), _T("202020"), 0.8, 0, &intX, &intY) != -1)
			{
				//���
				print_log(_T("����Boss...\r\n"), gameclass);
				mouse_click_event(title, intX, intY);
				if (random_delay(index, gameclass, dm, 3800, 4200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (dm->FindPic(838, 405, 935, 474, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				print_log(_T("���׼��...\r\n"), gameclass);
				CPoint pos = random_pos(intX, intY, 1, 3);
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, pos.x, pos.y);
				if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (dm->FindPic(233, 30, 536, 253, _T("ʤ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				print_log(_T("ս��������...\r\n"), gameclass);
				CPoint pos = random_pos(798, 429, 5, 10);
				if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, pos.x, pos.y);
				if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			if (dm->FindPic(372, 352, 588, 480, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				CPoint pos = random_pos(798, 436, 5, 10);
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, pos.x, pos.y);
				if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
			if (dm->FindPic(421, 289, 538, 350, _T("������ȷ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (random_delay(index, gameclass, dm, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, intX, intY);
				if (random_delay(index, gameclass, dm, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		return 1;
	}
	return 0;
}

//��������---�������
int BeginExplore::InnerCreatTeamToInvite(long hd, dmsoft *dm, int preferArea, int gameclass, int index) {
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
		if (dm->FindPic(552, 361, 595, 401, _T("������(δѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			print_log(_T("Ȩ�޲�����...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}//557,365,591,398,
		else if (dm->FindPic(557, 365, 591, 398, _T("������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
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
		if (dm->FindPic(449, 159, 517, 219, _T("��.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			print_log(_T("�������...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 12, intY + 10);
			if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		else if (dm->FindPic(770, 146, 862, 234, _T("̽����.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			print_log(_T("�������...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 12, intY + 10);
			if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	//������ѻ����
	i = 20;
	while (i > 0)
	{
		if (preferArea==0)
		{
			if (dm->FindPic(353, 61, 434, 109, _T("����(δѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
			{
				print_log(_T("ѡ��ͬ������...\r\n"), gameclass);
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, intX + 20, intY + 10);
				if (random_delay(index, gameclass, dm, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
		}else if (preferArea == 1)
		{
			if (dm->FindPic(440, 68, 516, 103, _T("����(δѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
			{
				print_log(_T("ѡ���������...\r\n"), gameclass);
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, intX + 20, intY + 10);
				if (random_delay(index, gameclass, dm, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
		}
		
		if (random_delay(index, gameclass, dm, 400, 600) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	//�ж��Ƿ�Ϊ�����ӣ��������룬�����˳�
	i = 20;
	long recentRes;
	while (i > 0)
	{
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

int BeginExplore::EnterExplore(long hd, dmsoft *dm, int gameclass, int index, int speed) {
	if (dm == NULL)
	{
		return 0;
	}
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//�߶���־
	int moveFlag = -5;
	//���븱��
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		int resultBoss = findBossMonster(hd, dm, gameclass, index, speed);
		if (resultBoss == 0)
		{
			int resultCommon = findCommonMonster(hd, dm, gameclass, index, speed);
			if ((resultCommon == 0) && (moveFlag < 0)) {
				if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, 790, 412);
				moveFlag++;
				if (random_delay(index, gameclass, dm, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if ((resultCommon == 0) && (moveFlag >= 0) && (moveFlag <5)) {
				if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, 226, 505);
				moveFlag++;
				if (random_delay(index, gameclass, dm, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if ((resultCommon == 0) && (moveFlag >= 5)) {
				moveFlag = -5;
			}
			else if (resultCommon == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if (resultBoss == EXIT_THREAD) { return EXIT_THREAD; }
		else if (resultBoss == 1) { break; }
	}
	return 1;
}

int BeginExplore::SingleEnterExplore(long hd, dmsoft *dm, CString progressBar, CString materialKinds, int gameclass, int index, int speed) {
	if (dm == NULL)
	{
		return 0;
	}
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//�߶���־
	int moveFlag = -5;
	//���븱��
	while (1)
	{
		if (IsChangeMaterial(hd, dm, gameclass, index) == 0) {
			//�Զ��ܾ�����
			if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			int resultBoss = findBossMonster(hd, dm, gameclass, index, speed);
			if (resultBoss == 0)
			{
				int resultCommon = findCommonMonster(hd, dm, gameclass, index, speed);
				if ((resultCommon == 0) && (moveFlag < 0)) {
					if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, 790, 412);
					moveFlag++;
					if (random_delay(index, gameclass, dm, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				else if ((resultCommon == 0) && (moveFlag >= 0) && (moveFlag < 5)) {
					if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, 226, 505);
					moveFlag++;
					if (random_delay(index, gameclass, dm, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				else if ((resultCommon == 0) && (moveFlag >= 5)) {
					moveFlag = -5;
				}
				else if (resultCommon == EXIT_THREAD) { return EXIT_THREAD; }
			}
			else if (resultBoss == EXIT_THREAD) { return EXIT_THREAD; }
			else if (resultBoss == 1) { break; }
		}
		else {
			AutoReplaceMaterial(hd, progressBar, materialKinds, dm, gameclass, index);
		}
	}
	return 1;
}

int BeginExplore::ReceiveTreasure(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	while (1)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		long findRes = dm->FindPic(0, 0, 960, 540, _T("����.bmp|������.bmp"), _T("202020"), 0.9, 0, &intX, &intY);
		if (findRes != -1)
		{
			print_log(_T("��ȡ���佱��...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 2, intY + 2);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(340, 110, 632, 228, _T("��ý���.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			print_log(_T("��ý���...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD){ return EXIT_THREAD; }
			mouse_click_event(title, 798, 429);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(346, 144, 467, 212, _T("��ý���(��).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(427, 359, 788, 465, _T("��Ӱ�ť.bmp|̽����ť.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			if (dm->FindPic(502, 300, 636, 343, _T("ȷ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = random_pos(intX, intY, 20, 25);
				mouse_click_event(title, pos.x, pos.y);
				if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			break;
		}
		else if (dm->FindPic(27, 455, 116, 540, _T("���Ѳ���.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			if (dm->FindPic(502, 300, 636, 343, _T("ȷ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = random_pos(intX, intY, 20, 25);
				mouse_click_event(title, pos.x, pos.y);
				if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			break;
		}
		else if (dm->FindPic(502, 300, 636, 343, _T("ȷ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(intX, intY, 20, 25);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		else if (IsOutExploreByYard(dm,gameclass,index)) {
			if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			if (dm->FindPic(502, 300, 636, 343, _T("ȷ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				CPoint pos = random_pos(intX, intY, 20, 25);
				mouse_click_event(title, pos.x, pos.y);
				if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
				break;
			}
			break;
		}
	}
	return 1;
}
//�ж��Ƿ���Ҫ������
int BeginExplore::IsChangeMaterial(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	int i = 3;
	while (i>0) {
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(86, 493, 107, 515, _T("�Զ��ֻ�.bmp|�Զ��ֻ�1.bmp|�Զ��ֻ�2.bmp|�Զ��ֻ�3.bmp"), _T("101010"), 0.95, 0, &intX, &intY) != -1) {
			print_log(_T("�򲹳�ս����������...\r\n"), gameclass);
			return 1;
		}
		if (random_delay(index, gameclass, dm, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 0;
}
//ѡ����ֹ���
int BeginExplore::WhatMaterialToSelect(long hd, dmsoft *dm, CString materialKinds, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	if (materialKinds == _T("0")) {
		if (dm->FindPic(103, 220, 151, 270, _T("N��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 2, intY + 2);
			if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (materialKinds == _T("1")) {
		if (dm->FindPic(25, 211, 73, 257, _T("�ز�.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 2, intY + 2);
			if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	return 1;
}
//����������ѡ��
int BeginExplore::SelectProgressBar(long hd, dmsoft *dm, CString progress, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	print_log(_T("ѡ�����...\r\n"), gameclass);
	if (progress == _T("0")) {
		if (dm->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 45, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("1")) {
		if (dm->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 75, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("2")) {
		if (dm->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 105, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("3")) {
		if (dm->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 135, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("4")) {
		if (dm->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 165, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("5")) {
		if (dm->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 195, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("6")) {
		if (dm->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 225, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("7")) {
		if (dm->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 255, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("8")) {
		if (dm->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 285, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("9")) {
		if (dm->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 315, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("10")) {
		if (dm->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 345, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("11")) {
		if (dm->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 375, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("12")) {
		if (dm->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 405, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("13")) {
		if (dm->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 435, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("14")) {
		if (dm->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 465, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("15")) {
		if (dm->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 495, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("16")) {
		if (dm->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 525, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("17")) {
		if (dm->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 555, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("18")) {
		if (dm->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 585, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	else if (progress == _T("19")) {
		if (dm->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_move(title, intX + 15, intY, intX + 615, intY);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
	}
	return 1;
}
//�Զ�������
int BeginExplore::AutoReplaceMaterial(long hd, CString progressBar, CString materialKinds, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	int allFlag = 0;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(21, 468, 73, 537, _T("����ֽ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			print_log(_T("��ʼ�Զ�������...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 12, intY + 18);
			if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(352, 78, 466, 122, _T("�򲹳�ս.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			break;
		}
	}
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if ((allFlag==0)&&(dm->FindPic(352, 78, 466, 122, _T("�򲹳�ս.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1))
		{
			print_log(_T("ѡ�������ʽ��...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 245, intY + 112);
			if (random_delay(index, gameclass, dm, 1000, 1100) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 245, intY + 112);
			if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			allFlag = 1;
			break;
		}
	}
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(19, 467, 76, 513, _T("ȫ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			long clickX = intX, clickY = intY;
			if (dm->FindPic(103, 220, 151, 270, _T("N��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) == -1) {
				print_log(_T("ѡ��������...\r\n"), gameclass);
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, clickX + 5, clickY + 5);
				if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if ((dm->FindPic(103, 220, 151, 270, _T("N��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)||(dm->FindPic(25, 211, 73, 257, _T("�ز�.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1))
		{
			break;
		}
	}
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		WhatMaterialToSelect(hd, dm, materialKinds, gameclass, index);
		//27,466,73,509,
		if ((dm->FindPic(27, 466, 73, 509, _T("N��(��ѡ).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)|| (dm->FindPic(27, 466, 73, 509, _T("�ز�(��ѡ).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1))
		{
			break;
		}
	}
	SelectProgressBar(hd, dm, progressBar, gameclass, index);
	long startX, startY, beginX = 81;
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if ((beginX<735) && (dm->FindPic(beginX, 359, 863, 430, _T("��ս.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)){
			startX = intX, startY = intY;
			if (dm->FindPic(intX - 87, intY, intX - 20, intY + 100, _T("��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) == -1) {
				print_log(_T("�����ս�б�...\r\n"), gameclass);
				HWND sub_hd = findHandle(title);
				SendMessage(sub_hd, WM_LBUTTONDOWN, 0, MAKELPARAM(startX + 9, startY + 7));
				Sleep(2500);
				SendMessage(sub_hd, WM_LBUTTONUP, 0, MAKELPARAM(startX + 9, startY + 7));
			}
			else {
				beginX = startX + 80;
			}
		}
		else if(beginX >= 735){
			if (dm->FindPic(80, 506, 739, 539, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
				if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_move(title, intX + 15, intY, intX + 37, intY);
				beginX = 81;
				if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			}
		}
		if (dm->FindPic(772, 79, 873, 122, _T("������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("��ս�б�����...\r\n"), gameclass);
			break;
		}
	}
	while (1) {
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(822, 289, 910, 371, _T("����ȷ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("ȷ���򲹳�ս...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 2, intY + 2);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(21, 468, 73, 537, _T("����ֽ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			print_log(_T("�ѷ��ظ���...\r\n"), gameclass);
			break;
		}
	}
	if (random_delay(index, gameclass, dm, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	autoRotate(hd, dm, gameclass, index);
	return 1;
}
//ͨ��ͥԺ�ж��Ƿ������---������ֹͣ�¼�
int BeginExplore::IsOutExploreByYard(dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	dm->SetDict(0, _T("fontStock.txt"));
	dm->UseDict(0);
	//start findFunc
	long intX, intY;
	long exploreRes, FpRes, rewordRes;
	//��̽������
	FpRes = dm->FindPic(0, 0, 960, 275, _T("̽������.bmp|̽������1.bmp|̽������2.bmp|̽������3.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
	exploreRes = dm->FindStrFast(0, 0, 960, 275, _T("̽��|̽��1|̽��2|̽��3"), _T("1D1914-1E1915"), 0.95, &intX, &intY);
	//�����ͷ�ӡ
	rewordRes = dm->FindStrFast(0, 0, 960, 324, _T("���ͷ�ӡ"), _T("C9B7A7-364856"), 0.95, &intX, &intY);
	if ((exploreRes != -1) || (rewordRes != -1) || (FpRes != -1))
	{
		return 1;
	}
	else {
		return 0;
	}
}
//��ӽ��븱��
int BeginExplore::receiveEnterExplore(long hd, dmsoft *dm, int count, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	int flag = 0;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	while (1)
	{
		if (IsOutExploreByYard(dm, gameclass, index))
		{
			break;
		}
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (count == 0)
		{
			if (dm->FindPic(27, 518, 67, 540, _T("����.bmp"), _T("101010"), 0.95, 0, &intX, &intY) != -1)
			{
				if ((dm->FindPic(86, 493, 107, 515, _T("�Զ��ֻ�.bmp|�Զ��ֻ�1.bmp|�Զ��ֻ�2.bmp|�Զ��ֻ�3.bmp"), _T("101010"), 0.95, 0, &intX, &intY) != -1) && flag == 0)
				{
					print_log(_T("�Զ��ֻ��ѿ���...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX + 1, intY + 1);
					if (random_delay(index, gameclass, dm, 800, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
					flag = 1;
				}
			}
			
		}
		//��׼��
		if (dm->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("���׼��...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(intX, intY, 1, 5);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//ʤ������

		if (dm->FindPic(286, 34, 438, 169, _T("ʤ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("ս��������...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1200, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 429, 1, 5);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 500, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(388, 372, 567, 456, _T("��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 1, 5);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(421, 289, 538, 350, _T("������ȷ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX,intY);
			if (random_delay(index, gameclass, dm, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(0, 0, 960, 540, _T("����.bmp|������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			print_log(_T("��ȡ���佱��...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 2, intY + 2);
			if (random_delay(index, gameclass, dm, 200, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(340, 110, 632, 228, _T("��ý���.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			print_log(_T("��ý���...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, 798, 429);
			if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(346, 144, 467, 212, _T("��ý���(��).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX+5, intY+10);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (IsOutExploreByYard(dm, gameclass, index))
		{
			break;
		}
		if (random_delay(index, gameclass, dm, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//��������
int BeginExplore::ReceiveInvite(long hd, dmsoft *dm, int count, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);

	CString count_str;
	count_str.Format(_T("%d"), count + 1);
	print_log(_T("�ȴ���������...\r\n"), gameclass);
	while (1)
	{
		if (dm->FindPic(74, 164, 136, 219, _T("��������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			count_str.Format(_T("%d"), count + 1);
			print_log(_T("��������...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 13);
			print_log(_T("��" + count_str + "��̽����ʼ...\r\n"), gameclass);
			count++;
			if (random_delay(index, gameclass, dm, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 600) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return count;
}
//�����ѽ���������ս 
int BeginExplore::IsEnterTeamRepeat(long hd, dmsoft *dm, int count, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	int timerRecord = 0;
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
		if (dm->FindPic(874, 436, 953, 518, _T("��ս.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
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
		Sleep(1000);
		timerRecord++;
		if (timerRecord >= 20) {
			while (1) {
				if (dm->FindPic(770, 146, 862, 234, _T("̽����.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
				{
					print_log(_T("�������...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX + 12, intY + 10);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(404, 119, 483, 157, _T("������.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
				{
					print_log(_T("����...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX - 50, intY + 40);
					if (random_delay(index, gameclass, dm, 2000, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(536, 407, 632, 454, _T("����.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
					if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX + 10, intY + 5);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					break;
				}
			}
			timerRecord = 0;
		}
		
	}
	return 1;
}
//̽����ˢ
int BeginExplore::SingleExplore(long hd, int round,int layer, int diff, CString jc, int speed, CString progressBar, CString materialKinds, int MaterialMode, dmsoft *dm,int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//�ж��Ƿ���ͥԺ
	if (!IsInYard(dm,gameclass,index))
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
	}else if(result == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 2500, 3500) == EXIT_THREAD) { return EXIT_THREAD; }
	//�Զ����ӳ�
	CPoint startXY, endXY;
	startXY.x = 310, startXY.y = 8;
	endXY.x = 351, endXY.y = 60;
	if (auto_open_jc(hd, _T("̽��"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	//������ѡ���������
	if (isExplore(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	int count = 0;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//ѡ���½ڲ����
		CPoint startXY, endXY;
		startXY.x = 777, startXY.y = 131;
		endXY.x = 952, endXY.y = 508;
		//�жϿ�ʼǰ�Ƿ����½ڵ㿪״̬
		int resultExplore = dm->FindPic(642, 367, 773, 438, _T("̽����ť.bmp"), _T("202020"), 0.9, 0, &intX, &intY);
		if (resultExplore == -1) {
			if (SingleChooseLayer(hd, layer, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//ѡ���Ѷ�
		if (count == 0)
		{
			print_log(_T("ѡ���Ѷ�...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 1200, 1600) == EXIT_THREAD) { return EXIT_THREAD; }
			if (ChooseDiff(hd, diff, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
			if (random_delay(index, gameclass, dm, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
		}

		//���̽����ť
		if (clickExplore(hd, dm, gameclass, index)== EXIT_THREAD) { return EXIT_THREAD; }
		//�Զ��ֻ�
		if (count == 0)
		{
			print_log(_T("ѡ���Զ��ֻ�...\r\n"), gameclass);
			if (autoRotate(hd, dm, gameclass, index)== EXIT_THREAD) { return EXIT_THREAD; }
		}
		//���븱��
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		print_log(_T("��" + count_str + "��̽����ʼ...\r\n"),gameclass);
		if (MaterialMode == 0) {
			if (EnterExplore(hd, dm, gameclass, index, speed) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		else if (MaterialMode == 1) {
			if (SingleEnterExplore(hd, dm, progressBar, materialKinds, gameclass, index, speed) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		count++;
		//��ȡ��������
		if (ReceiveTreasure(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//ˢ���˳�
	if (count>=round)
	{
		print_log(_T("��������ɣ������˳�����ͥԺ...\r\n"), gameclass);
		if (ExploreReturnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
		
		//�Զ��ؼӳ�
		startXY.x = 290, startXY.y = 10;
		endXY.x = 346, endXY.y = 80;
		if (auto_close_jc(hd, _T("̽��"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}

//����������
int BeginExplore::inviteExplore(long hd, int round, int layer, CString jc, int preferArea, int speed, dmsoft *dm, int gameclass, int index) {
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
	//�Զ����ӳ�
	CPoint startXY, endXY;
	startXY.x = 294, startXY.y = 19;
	endXY.x = 336, endXY.y = 72;
	if (auto_open_jc(hd, _T("̽��"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	//�ж�ͥԺ�Ƿ�չ��,��δչ��ʹ֮չ��
	if (showYard(dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//������
	int resultCombine = CombineTeamAction(hd, dm, gameclass, index);
	if (resultCombine == 0) {
		print_log(_T("�ܱ�Ǹ��δ�ҵ���Ӱ�ť...\r\n"), gameclass);
		return 0;
	}else if(resultCombine == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ��̽��

	//��ȡ��ǰλ��ѡ��
	CString bmp_pic = _T("̽��(����).bmp|����ҵ����.bmp|���ѷ�ת��.bmp|����ˮ����.bmp|�������׹�.bmp|����.bmp|����֮��.bmp|����֮��.bmp|������ӡ.bmp|��������.bmp|�������.bmp|����.bmp|���ͻ��.bmp");
	startXY.x = 101, startXY.y = 75;
	endXY.x = 276, endXY.y = 503;

	//�ҵ�̽�������
	findDestination(hd, bmp_pic, 5, _T("̽��(����).bmp|̽��(����)(ѡ��).bmp"), startXY, endXY, dm, gameclass, index);
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//ѡ��
	//ѡ��㲢���
	startXY.x = 293, startXY.y = 129;
	endXY.x = 442, endXY.y = 432;
	if (ChooseLayer(hd, layer, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	//��������--�������
	if (!InnerCreatTeamToInvite(hd, dm, preferArea, gameclass, index)) {
		print_log(_T("��������ʧ��!!!\r\n"), gameclass);
		//δ�ҵ�������ѣ�����ͥԺ��رռӳ�
		startXY.x = 290, startXY.y = 10;
		endXY.x = 346, endXY.y = 80;
		if (random_delay(index, gameclass, dm, 1200, 2400) == EXIT_THREAD) { return EXIT_THREAD; }
		if (auto_close_jc(hd, _T("̽��"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		return 0;
	}
	if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	int count = 0;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//�����Ѽ�����鲢����ս
		if (IsEnterTeamRepeat(hd, dm, count, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//�Զ��ֻ�
		if (count == 0)
		{
			if (random_delay(index, gameclass, dm, 1500, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			print_log(_T("ѡ���Զ��ֻ�...\r\n"), gameclass);
			if (autoRotate(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (random_delay(index, gameclass, dm, 1000, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		//����̽������
		//���븱��
		CString count_str;
		count_str.Format(_T("%d"), count + 1);
		print_log(_T("��" + count_str + "��̽����ʼ...\r\n"), gameclass);
		if (EnterExplore(hd, dm, gameclass, index, speed) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;
		//��ȡ��������
		if (ReceiveTreasure(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 100, 200) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//ˢ���˳�
	if (count >= round)
	{
		print_log(_T("��������ɣ������˳�����ͥԺ...\r\n"), gameclass);
		if (ExploreReturnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }

		//�Զ��ؼӳ�
		startXY.x = 290, startXY.y = 10;
		endXY.x = 346, endXY.y = 80;
		if (auto_close_jc(hd, _T("̽��"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//��ӽ�������
int BeginExplore::BeinvitedExplore(long hd, int round, CString jc, dmsoft *dm, int gameclass, int index) {
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
	//�Զ����ӳ�
	CPoint startXY, endXY;
	startXY.x = 294, startXY.y = 19;
	endXY.x = 336, endXY.y = 72;
	if (auto_open_jc(hd, _T("̽��"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	//��ʼѭ��
	int count = 0;
	while (count < round)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		//��������
		if (ReceiveInvite(hd, dm, count, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 2000, 3500) == EXIT_THREAD) { return EXIT_THREAD; }
		//����̽������
		if (receiveEnterExplore(hd, dm, count, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		count++;
		if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	//ˢ���˳�
	if (count >= round)
	{
		if (ReceiveTreasure(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		print_log(_T("��������ɣ������˳�����ͥԺ...\r\n"), gameclass);
		if (ExploreReturnYard(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 600, 1200) == EXIT_THREAD) { return EXIT_THREAD; }

		//�Զ��ؼӳ�
		startXY.x = 290, startXY.y = 10;
		endXY.x = 346, endXY.y = 80;
		if (auto_close_jc(hd, _T("̽��"), jc, startXY, endXY, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (random_delay(index, gameclass, dm, 1000, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
	}

	return 1;
}

//����ͥԺ
int BeginExplore::ExploreReturnYard(long hd, dmsoft *dm, int gameclass, int index) {
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
		if (dm->FindPic(760, 83, 814, 135, _T("��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(15, 13, 73, 72, _T("����1.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}//760, 83, 814, 135,
		if (dm->FindPic(9, 18, 61, 76, _T("����5.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(523, 286, 640, 320, _T("̽��ȷ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(506, 303, 631, 346, _T("ȷ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(9, 1, 65, 59, _T("����4.bmp|����8.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (dm->FindPic(506, 303, 631, 346, _T("ȷ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1) {
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
