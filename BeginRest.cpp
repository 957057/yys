#include "pch.h"
#include "BeginRest.h"
#define EXIT_THREAD -10
//������Զ��������Զ���� (��������)��
int BeginRest::StartRest(long hd, dmsoft *dm, int minite, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//�Զ��ܾ�����
	if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	int sec = minite * 60000;
	print_log(_T("��Ϣ��...\r\n"),gameclass);
	if (random_delay(index, gameclass, dm, sec, sec+1) == EXIT_THREAD) { return EXIT_THREAD; }
	print_log(_T("��Ϣ����.\r\n"), gameclass);
	//�Զ��ܾ�����
	if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
	return 1;
}