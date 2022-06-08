#pragma once
#include "pch.h"
#include "yys_function.h"
#include "CGame1.h"
#include "CGame_RunLog1.h"
#include "CGame_RunLog2.h"
#include<random>
#include<ctime>
#include<iomanip>
#define EXIT_THREAD -10

extern CGame_RunLog1 *plog1;
extern CGame_RunLog2 *plog2;
extern bool readyFlag;
ThreadInfo threadState[2];

//��ʼ���߳�״̬��Ϣ
int initThreadInfo() {
	int i;
	for (i=0;i<2;i++)
	{
		threadState[i].pause = false;
		threadState[i].start = false;
		threadState[i].stop = false;
		threadState[i].suspend_flag = false;
	}
	return 1;
}
//����ַ���
int yys_function::SplitString(LPCTSTR lpszStr, LPCTSTR lpszSplit, CStringArray& rArrString, BOOL bAllowNullString)
{
	rArrString.RemoveAll();
	CString szStr = lpszStr;
	szStr.TrimLeft();
	szStr.TrimRight();

	if (szStr.GetLength() == 0)
	{
		return 0;
	}

	CString szSplit = lpszSplit;

	if (szSplit.GetLength() == 0)
	{
		rArrString.Add(szStr);
		return 1;
	}

	CString s;
	int n;

	do
	{
		n = szStr.Find(szSplit);

		if (n > 0)
		{
			rArrString.Add(szStr.Left(n));
			szStr = szStr.Right(szStr.GetLength() - n - szSplit.GetLength());
			szStr.TrimLeft();
		}
		else if (n == 0)
		{
			if (bAllowNullString)
			{
				rArrString.Add(_T(""));
			}

			szStr = szStr.Right(szStr.GetLength() - szSplit.GetLength());
			szStr.TrimLeft();
		}
		else
		{
			if ((szStr.GetLength() > 0) || bAllowNullString)
			{
				rArrString.Add(szStr);
			}

			break;
		}
	} while (1);

	return (int)rArrString.GetSize();
}
//���ļ�
int yys_function::ReadFile(CString filePath, CStringArray& ListArray)
{
	ListArray.RemoveAll();
	if (!PathFileExists(filePath))
	{
		MessageBox(NULL, _T("�ļ�·��������!!!"), _T(""), 0);
		return 0;
	}
	//�������
	char* old_locale = _strdup(setlocale(LC_CTYPE, NULL));
	setlocale(LC_CTYPE, "chs");

	CStdioFile file;
	if (!file.Open(filePath, CFile::modeRead))
	{
		MessageBox(NULL, _T("��ȡ�ļ�ʧ��!!!"), _T(""), 0);
		return 0;
	}
	CString strValue = _T("");
	while (file.ReadString(strValue))
	{
		ListArray.Add(strValue);
	}
	file.Close();
	//�ͷ���Դ
	setlocale(LC_CTYPE, old_locale);
	free(old_locale);
	return (int)ListArray.GetSize();
}
//д�ļ�
int yys_function::WriteFile(CString filePath, CStringArray& ListArray)
{
	//�������
	char* old_locale = _strdup(setlocale(LC_CTYPE, NULL));
	setlocale(LC_CTYPE, "chs");
	
	CStdioFile file;
	int listSize = ListArray.GetSize();
	if (listSize == 0) {
		MessageBox(NULL, _T("�����б�Ϊ��!!!"), _T(""), 0);
		return 0;
	}
	if (!file.Open(filePath, CFile::modeWrite| CFile::modeCreate))
	{
		MessageBox(NULL, _T("д���ļ�ʧ��!!!"), _T(""), 0);
		return 0;
	}
	
	for (int i = 0; i < listSize; i++) {
		file.SeekToEnd();
		file.WriteString(ListArray.GetAt(i)+ _T("\n"));
	}
	file.Close();
	if (ListArray.GetSize() != 0) {
		MessageBox(NULL, _T("�����б����ɹ�!!!"), _T(""), 0);
	}
	ListArray.RemoveAll();
	//�ͷ���Դ
	setlocale(LC_CTYPE, old_locale);
	free(old_locale);
	return 1;
}
//��ȡ�Ӵ��ھ��
HWND yys_function::findHandle(CString windowname) {
	HWND hd = FindWindow(NULL, windowname);
	HWND sub_hd = GetWindow(hd, GW_CHILD);
	return sub_hd;
}

//�༭���β׷������
void yys_function::print_log(TCHAR szMsg[],int gameclass) {
	if (gameclass==0)
	{
		int iLen = plog1->m_runLog.GetWindowTextLength();
		plog1->m_runLog.SetSel(iLen, iLen, FALSE);
		plog1->m_runLog.ReplaceSel(szMsg, FALSE);
	}else if (gameclass == 1)
	{

		int iLen = plog2->m_runLog.GetWindowTextLength();
		plog2->m_runLog.SetSel(iLen, iLen, FALSE);
		plog2->m_runLog.ReplaceSel(szMsg, FALSE);
	}
	
	return;
}
//������¼� click_x,click_y:����Ӿ������
void yys_function::mouse_click_event(CString windowname, int click_x, int click_y) {
	HWND sub_hd = findHandle(windowname);

	SendMessage(sub_hd, WM_LBUTTONDOWN, 0, MAKELPARAM(click_x, click_y));
	Sleep(50);
	SendMessage(sub_hd, WM_LBUTTONUP, 0, MAKELPARAM(click_x, click_y));
	return;
}

//����ƶ�
void yys_function::mouse_move(CString windowname, int start_x, int start_y, int end_x, int end_y) {
	HWND sub_hd = findHandle(windowname);
	SendMessage(sub_hd, WM_LBUTTONDOWN, 0, MAKELPARAM(start_x, start_y));
	Sleep(500);
	SendMessage(sub_hd, WM_MOUSEMOVE, 0, MAKELPARAM(end_x, end_y));
	Sleep(500);
	SendMessage(sub_hd, WM_LBUTTONUP, 0, MAKELPARAM(end_x, end_y));
	Sleep(1000);
	return;
}

//�漴ƫ�����꣬��ֹ��Ϸ��Ҽ��
CPoint yys_function::random_pos(int pos_x, int pos_y, int offsetX, int offsetY) {
	std::default_random_engine e;
	//��������
	e.seed(unsigned(time(NULL)));
	//offsetX��offsetY
	std::uniform_real_distribution<double> u(offsetX, offsetY);
	CPoint pos;
	pos.x = pos_x + u(e), pos.y = pos_y + u(e);
	return pos;
}
//����ӳٵ������ֹ��Ϸ��Ҽ��
int yys_function::random_delay(int index, int gameclass, dmsoft *dm, int time_min, int time_max) {
	std::default_random_engine e;
	//��������
	e.seed(unsigned(time(NULL)));
	//time_min��time_max
	std::uniform_real_distribution<double> u(time_min, time_max);
	Sleep(u(e));
	//��ͣ
	if (threadState[index].pause)
	{
		print_log(_T("�߳��ѹ���\r\n"), gameclass);
		if (dm!=NULL)
		{
			dm->EnableBind(5);
		}
		while (1)
		{
			Sleep(3000);
			if (!threadState[index].pause)
			{
				print_log(_T("�߳��ѻָ�\r\n"), gameclass);
				if (dm != NULL)
				{
					dm->EnableBind(1);
				}
				break;
			}//��ͣʱ�˳�
			if (threadState[index].stop)
			{
				break;
			}
		}
	}//ֹͣ
	if (threadState[index].stop) {
		threadState[index].start = false;
		return EXIT_THREAD;
	}
	return 1;
}

//�ж��Ƿ���ͥԺ true:�� false:����
bool yys_function::IsInYard(dmsoft *dm, int gameclass,int index) {
	if (dm==NULL)
	{
		return false;
	}
	dm->SetDict(0, _T("fontStock.txt"));
	dm->UseDict(0);
	//start findFunc
	long intX, intY;
	long exploreRes, FpRes, rewordRes;
	int i = 20;
	while (i > 0)
	{
		//��̽������
		FpRes = dm->FindPic(0, 0, 960, 275, _T("̽������.bmp|̽������1.bmp|̽������2.bmp|̽������3.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		exploreRes = dm->FindStrFast(0, 0, 960, 275, _T("̽��|̽��1|̽��2|̽��3"), _T("1D1914-1E1915"), 0.85, &intX, &intY);
		//�����ͷ�ӡ
		rewordRes = dm->FindPic(290, 10, 346, 80, _T("�ӳ�1.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		if ((exploreRes !=-1) || (rewordRes !=-1)|| (FpRes!=-1))
		{
			break;
		}
		random_delay(index, gameclass, dm, 200, 250);
		i--;
	}
	//�ж��Ƿ��ҵ�
	if ((exploreRes != -1) || (rewordRes != -1) || (FpRes != -1))
	{
		print_log(_T("����ͥԺ����...\r\n"), gameclass);
		return TRUE;
	}
	else {
		return FALSE;
	}
}
//�ж�ͥԺ�Ƿ�չ�� true:չ�� false:�ر�
bool yys_function::IsShowYard(dmsoft *dm,int gameclass, int index) {
	if (dm == NULL)
	{
		return false;
	}
	//��ӡ������  C1B7AE-232827
	dm->SetDict(0, _T("fontStock.txt"));
	dm->UseDict(0);
	//start findFunc
	long intX, intY;
	long teamRes, teamRes2, organizeReg;
	int i = 20;
	while (i > 0)
	{
		//�����
		teamRes = dm->FindStrFast(261, 484, 427, 514, _T("���"), _T("C1B7AE-232827"), 0.95, &intX, &intY);
		teamRes2=dm->FindPic(262, 444, 323, 510, _T("���.bmp|��ɫ���.bmp"), _T("202020"), 0.95, 0, &intX, &intY);
		//�������
		organizeReg = dm->FindStrFast(261, 484, 427, 514, _T("�����"), _T("C1B7AE-232827"), 0.95, &intX, &intY);
		if (teamRes2!=-1||teamRes != -1 || organizeReg != -1)
		{
			break;
		}
		random_delay(index, gameclass, dm, 200, 250);
		i--;
	}
	//�ж��Ƿ��ҵ�
	if (teamRes2!=-1|| teamRes != -1 || organizeReg != -1)
	{
		print_log(_T("ͥԺ��չ��...\r\n"), gameclass);
		return TRUE;
	}
	else {
		return FALSE;
	}
}

//չ��ͥԺ
int yys_function::showYard(dmsoft *dm,int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	BOOL isShow = IsShowYard(dm, gameclass, index);
	if (!isShow)
	{
		if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
		print_log(_T("չ��ͥԺ...\r\n"), gameclass);
		dm->MoveToEx(901, 468, 14, 43);
		dm->delay(1000);
		dm->LeftClick();
		return 1;
	}
	return 0;
}

//Ѱ��̽�����������
int yys_function::FindExploreLanTernAndClick(long hd, dmsoft *dm,int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	dm->SetDict(0, _T("fontStock.txt"));
	dm->UseDict(0);
	//start findFunc
	long intX, intY;
	long FpX, FpY;
	long exploreRes,FpRes;
	int i = 20;
	print_log(_T("Ѱ��̽������...\r\n"), gameclass);
	while (i > 0)
	{
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//��̽������1B1703-1C1803
		exploreRes = dm->FindStrFast(0, 0, 960, 275, _T("̽��|̽��1|̽��2|̽��3|̽��4|̽��5"), _T("1D1914-1E1915"), 0.85, &intX, &intY);
		FpRes = dm->FindPic(0, 0, 960, 275, _T("̽������.bmp|̽������1.bmp|̽������2.bmp|̽������3.bmp"), _T("202020"), 0.85, 0, &FpX, &FpY);
		if (exploreRes != -1|| FpRes!=-1)
		{
			print_log(_T("�ҵ�̽������\r\n"), gameclass);
			//��ȡ�����ڱ���
			long parentHandle = dm->GetWindow(hd, 0);
			CString title = dm->GetWindowTitle(parentHandle);
			//���
			if (exploreRes != -1) {
				if (random_delay(index, gameclass, dm, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, intX + 5, intY + 15);
				return 1;
			}else if (FpRes != -1) {
				if (random_delay(index, gameclass, dm, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
				mouse_click_event(title, FpX + 5, FpY + 15);
				return 1;
			}
			
		}
		if (random_delay(index, gameclass, dm, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 0;
}
//������
int yys_function::CombineTeamAction(long hd, dmsoft *dm, int gameclass, int index) {
	//������
	if (dm == NULL)
	{
		return false;
	}
	//��ӡ������  C1B7AE-232827
	dm->SetDict(0, _T("fontStock.txt"));
	dm->UseDict(0);

	long intX, intY;
	long teamRes, organizeReg;

	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);

	int i = 20;
	while (i > 0)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//�����
		teamRes = dm->FindStrFast(261, 484, 427, 514, _T("���"), _T("C1B7AE-232827"), 0.95, &intX, &intY);
		organizeReg = dm->FindPic(262, 444, 323, 510, _T("���.bmp|��ɫ���.bmp"), _T("202020"), 0.95, 0, &intX, &intY);
		if (teamRes != -1 || organizeReg != -1)
		{
			break;
		}
		if (random_delay(index, gameclass, dm, 200, 250) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	//�ж��Ƿ��ҵ�
	if (teamRes != -1 || organizeReg != -1)
	{
		print_log(_T("������...\r\n"), gameclass);
		if (random_delay(index, gameclass, dm, 450, 500) == EXIT_THREAD) { return EXIT_THREAD; }
		mouse_click_event(title, intX, intY);
		return 1;
	}
	else {
		return 0;
	}
}

//��ȡ��ǰλ��
long yys_function::findNowSection(CString sourcePic, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long findLoc;
	int i = 20;
	long intX, intY;

	while (i > 0)
	{
		findLoc = dm->FindPic(startXY.x, startXY.y, endXY.x, endXY.y, sourcePic, _T("202020"), 0.75, 0, &intX, &intY);
		if (findLoc != -1)
		{
			break;
		}
		if (random_delay(index, gameclass, dm, 480, 520) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	if (findLoc != -1)
	{
		return findLoc;
	}
	else {
		return -1;
	}
}
//Ѱ��Ŀ��λ�ò����---������ֹͣ
int yys_function::findDestination(long hd, CString allpic, long destinationLoc, CString destPic, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	long intX, intY;
	//����
	int startx = (startXY.x + endXY.x) / 2;
	int starty = startXY.y+(endXY.y - startXY.y)*0.2, endy = startXY.y + (endXY.y - startXY.y)*0.85;
	int i = 15;
	while (i > 0)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//��Ŀǰ����λ��
		long nowLoc = findNowSection(allpic, startXY, endXY, dm, gameclass, index);
		if (nowLoc == -1) {
			if(allpic.Left(7) == _T("1-1.bmp")){ print_log(_T("δ�ҵ���ǰ����λ�ã�NowLoc��...\r\n"), gameclass); }
			return 0;
		}
		//����
		if (destinationLoc <= nowLoc)
		{
			if (dm->FindPic(startXY.x, startXY.y, endXY.x, endXY.y, destPic, _T("202020"), 0.75, 0, &intX, &intY) != -1)
			{
				random_delay(index, gameclass, dm, 2000, 2500);
				mouse_click_event(title, intX + 24, intY + 20);
				return 1;
			}
			else
			{
				random_delay(index, gameclass, dm, 500, 800);
				mouse_move(title, startx, starty, startx, endy);
			}

		}//����
		else if (destinationLoc > nowLoc)
		{
			if (dm->FindPic(startXY.x, startXY.y, endXY.x, endXY.y, destPic, _T("202020"), 0.75, 0, &intX, &intY) != -1)
			{
				random_delay(index, gameclass, dm, 2000, 2500);
				mouse_click_event(title, intX + 24, intY + 20);
				return 1;
			}
			else
			{
				random_delay(index, gameclass, dm, 500, 800);
				mouse_move(title, startx, endy, startx, starty);
			}

		}
		random_delay(index, gameclass, dm, 480, 520);
		i--;
	}
	return 0;
}

//��������---�������
int yys_function::CreatTeamToInvite(long hd, dmsoft *dm, int gameclass, int index) {
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
		if (dm->FindPic(555, 361, 592, 398, _T("������(δѡ��).bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
			print_log(_T("Ȩ�޲�����...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 10);
			if (random_delay(index, gameclass, dm, 500, 1500) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}//557,365,591,398,
		if (dm->FindPic(557, 365, 591, 398, _T("������.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
		{
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
	//���������
	i = 20;
	while (i > 0)
	{
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
//����
int yys_function::unlock(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	int i = 10;
	//��������or����
	if (random_delay(index, gameclass, dm, 1000, 1200) == EXIT_THREAD) { return EXIT_THREAD; }
	while (i > 0)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		if (dm->FindPic(17, 481, 44, 509, _T("����״̬.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			break;
		}
		if (dm->FindPic(17, 481, 44, 509, _T("����״̬.bmp"), _T("202020"), 0.95, 0, &intX, &intY) != -1)
		{
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 6, intY + 8);
			break;
		}
		if (random_delay(index, gameclass, dm, 400, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 1;
}

//�����ѽ���������ս 
int yys_function::IsEnterTeam(long hd, dmsoft *dm, int count, int gameclass, int index) {
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
		if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//������븱��
int yys_function::InviteEnterEvent(long hd, dmsoft *dm, int gameclass, int index) {
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
		//��׼��
		if (readyFlag && (dm->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)) {
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
//����������븱��  public
int yys_function::ReceiveEnterEvent(long hd, dmsoft *dm,int count, CString gameMode, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	CString count_str;
	count_str.Format(_T("%d"), count + 2);
	int flag = 0;
	//��ʼ
	while (1)
	{
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//����Ĭ������
		if (dm->FindPic(147, 163, 207, 219, _T("����Ĭ������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			count_str.Format(_T("%d"), count +1);
			print_log(_T("����Ĭ������...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 13);
			print_log(_T("��" + count_str + "��" + gameMode + "��ʼ...\r\n"), gameclass);
			flag = 2;
			readyFlag = FALSE;
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}//������ͨ����
		else if (dm->FindPic(74, 164, 136, 219, _T("��������.bmp"), _T("202020"), 0.9, 0, &intX, &intY)!=-1) {
			count_str.Format(_T("%d"), count + 1);
			print_log(_T("������ͨ����...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 13);
			print_log(_T("��" + count_str + "��" + gameMode + "��ʼ...\r\n"), gameclass);
			flag = 1;
			readyFlag = TRUE;
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//��׼��
		if (readyFlag &&(dm->FindPic(832, 393, 941, 536, _T("׼��.bmp|׼��2.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1)) {
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
		if (dm->FindPic(335, 256, 616, 497, _T("��.bmp|��(�ײ�).bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			CPoint pos = random_pos(798, 436, 1, 5);
			mouse_click_event(title, pos.x, pos.y);
			if (random_delay(index, gameclass, dm, 1800, 2200) == EXIT_THREAD) { return EXIT_THREAD; }
			if (flag==0)
			{
				print_log(_T("��" + count_str + "��" + gameMode + "��ʼ...\r\n"), gameclass);
			}
			if (flag == 2)
			{
				count_str.Format(_T("%d"), count + 2);
				print_log(_T("��" + count_str + "��"+gameMode+"��ʼ...\r\n"), gameclass);
			}
			break;
		}
		if (dm->FindPic(421, 289, 538, 350, _T("������ȷ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX, intY);
			if (random_delay(index, gameclass, dm, 500, 1300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		if (random_delay(index, gameclass, dm, 500, 700) == EXIT_THREAD) { return EXIT_THREAD; }
	}
	return 1;
}
//Ĭ���������  public
int yys_function::DefalutInvite(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	int i = 10;
	while (i > 0)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//Ĭ������
		if (dm->FindPic(401, 251, 555, 289, _T("Ĭ���������.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("Ĭ���������...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 13);
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	i = 10;
	while (i > 0)
	{
		//���ȷ��
		if (dm->FindPic(505, 302, 634, 343, _T("ȷ��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 13);
			if (random_delay(index, gameclass, dm, 1800, 2500) == EXIT_THREAD) { return EXIT_THREAD; }
			readyFlag = FALSE;
			break;
		}
		if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
		i--;
	}
	return 1;
}

//�Զ����ӳ�
int yys_function::auto_open_jc(long hd, CString jc_category, CString jc_index, CPoint start_xy, CPoint end_xy, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//�Ƿ�ѡ���Զ����ؼӳ�
	//����
	if (jc_category==_T("����"))
	{
		if (jc_index == _T("1"))
		{
			print_log(_T("���ڴ򿪼ӳ�...\r\n"), gameclass);
			//����ӳɵ���
			int yh_move = 0;
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("�ӳ�1.bmp|�ӳ�2.bmp|�ӳ�3.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("����ӳɵ���...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX, intY);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("���ڼӳɽ���...\r\n"), gameclass);
					break;
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//�жϼӳ�״̬
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(271, 88, 351, 378, _T("����ӳ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) !=-1)
				{
					long yhjc_X = intX, yhjc_Y = intY;
					if (dm->FindPic(yhjc_X + 278, yhjc_Y - 11, yhjc_X + 308, yhjc_Y + 32, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("������ӳ�...\r\n"), gameclass);
						//������ӳ�
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(yhjc_X + 278, yhjc_Y - 11, yhjc_X + 308, yhjc_Y + 32, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("�ӳ��Ѵ򿪣��رռӳɽ���...\r\n"), gameclass);
						//�رռӳɿ�
						if (dm->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							mouse_click_event(title, 128, 364);
							if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (yh_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						yh_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((yh_move >= 2)&&(yh_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						yh_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						yh_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
	}
	//����
	else if (jc_category == _T("����"))
	{
		if (jc_index == _T("1"))
		{
			print_log(_T("���ڴ򿪼ӳ�...\r\n"), gameclass);
			int jx_move = 0;
			//����ӳ�
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("�ӳ�1.bmp|�ӳ�2.bmp|�ӳ�3.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("����ӳɵ���...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX, intY);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("���ڼӳɽ���...\r\n"), gameclass);
					break;
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//�жϼӳ�״̬
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(271, 88, 351, 378, _T("���Ѽӳ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					long jxjc_X = intX, jxjc_Y = intY;
					if (dm->FindPic(jxjc_X + 278, jxjc_Y - 11, jxjc_X + 308, jxjc_Y + 32, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("�򿪾��Ѽӳ�...\r\n"), gameclass);
						//�򿪼ӳ�
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(jxjc_X + 278, jxjc_Y - 11, jxjc_X + 308, jxjc_Y + 32, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("�ӳ��Ѵ򿪣��رռӳɽ���...\r\n"), gameclass);
						//�رռӳɿ�
						if (dm->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							mouse_click_event(title, 128, 364);
							if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (jx_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						jx_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jx_move >= 2) && (jx_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						jx_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jx_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
	}
	//̽��
	else if (jc_category == _T("̽��"))
	{
		//4B4744-4C4744
		//����ȫ������
		if (jc_index == _T("1"))
		{
			print_log(_T("���ڴ򿪼ӳ�...\r\n"), gameclass);
			//����ӳ�
			int jy_move = 0;
			bool jy100Flag = false, jy50Flag = false;
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("�ӳ�1.bmp|�ӳ�2.bmp|�ӳ�3.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("����ӳɵ���...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX, intY);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("���ڼӳɽ���...\r\n"), gameclass);
					break;
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//�жϼӳ�״̬
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				//50%�ӳ�
				if (dm->FindPic(360, 92, 570, 358, _T("����50.bmp|����50-1.bmp|����50-2.bmp|����50-3.bmp"), _T("101010"), 0.75, 0, &intX, &intY) != -1)
				{
					long jyjc_X = intX, jyjc_Y = intY;
					if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("��50%����ӳ�...\r\n"), gameclass);
						//�򿪼ӳ�
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						jy50Flag = true;
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("50%����ӳ��Ѵ�...\r\n"), gameclass);
						jy50Flag = true;
						break;
					}
				}
				else {
					if (jy_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			while (1) {
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				//100%�ӳ�
				if (dm->FindPic(360, 92, 570, 358, _T("����100.bmp|����100-1.bmp|����100-2.bmp|����100-3.bmp"), _T("101010"), 0.75, 0, &intX, &intY) != -1)
				{
					long jyjc_X = intX, jyjc_Y = intY;
					if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("��100%����ӳ�...\r\n"), gameclass);
						//�򿪼ӳ�
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						jy100Flag = true;
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("100%����ӳ��Ѵ�...\r\n"), gameclass);
						jy100Flag = true;
						break;
					}
				}
				else {
					if (jy_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//��������رռӳɵ���
			while (1) {
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (jy50Flag && jy100Flag) {
					print_log(_T("�ӳ���ȫ���򿪣��رռӳɽ���...\r\n"), gameclass);
					//�رռӳɿ�
					if (dm->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
					{
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, 128, 364);
						if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
						break;
					}
				}
				else {
					print_log(_T("�ӳɴ�ʧ�ܣ�������...\r\n"), gameclass);
					break;
				}
			}
			return 1;
		}
		//�������
		else if (jc_index == _T("2"))
		{
			print_log(_T("���ڴ򿪼ӳ�...\r\n"), gameclass);
			print_log(_T("��Ҽӳɹ�����δʵ�֣����ֶ��򿪼ӳɺ��ٿ����ű�...\r\n"), gameclass);
			//�ݲ�ʵ�ִ˹���
			return 1;
		}
		//����50%����
		else if (jc_index == _T("3"))
		{
			print_log(_T("���ڴ򿪼ӳ�...\r\n"), gameclass);
			int jy_move = 0;
			//����ӳ�
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("�ӳ�1.bmp|�ӳ�2.bmp|�ӳ�3.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("����ӳɵ���...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX, intY);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("���ڼӳɽ���...\r\n"), gameclass);
					break;
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//�жϼӳ�״̬
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				//50%�ӳ�
				if (dm->FindPic(360, 92, 570, 358, _T("����50.bmp|����50-1.bmp|����50-2.bmp|����50-3.bmp"), _T("101010"), 0.75, 0, &intX, &intY) != -1)
				{
					long jyjc_X = intX, jyjc_Y = intY;
					if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("��50%����ӳ�...\r\n"), gameclass);
						//�򿪼ӳ�
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("50%����ӳ��Ѵ�...\r\n"), gameclass);
						//�رռӳɿ�
						if (dm->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							mouse_click_event(title, 128, 364);
							if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (jy_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
		//����100%����
		else if (jc_index == _T("4"))
		{
		int jy_move = 0;
		print_log(_T("���ڴ򿪼ӳ�...\r\n"), gameclass);
			//����ӳ�
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("�ӳ�1.bmp|�ӳ�2.bmp|�ӳ�3.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("����ӳɵ���...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX, intY);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("���ڼӳɽ���...\r\n"), gameclass);
					break;
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}

			//�жϼӳ�״̬
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				//100%�ӳ�
				if (dm->FindPic(360, 92, 570, 358, _T("����100.bmp|����100-1.bmp|����100-2.bmp|����100-3.bmp"), _T("101010"), 0.75, 0, &intX, &intY) != -1)
				{
					long jyjc_X = intX, jyjc_Y = intY;
					if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("��100%����ӳ�...\r\n"), gameclass);
						//�򿪼ӳ�
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("100%����ӳ��Ѵ�...\r\n"), gameclass);
						//�رռӳɿ�
						if (dm->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							mouse_click_event(title, 128, 364);
							if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (jy_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }	
			}
			return 1;
		}
	}
}
//�Զ��ؼӳ�
int yys_function::auto_close_jc(long hd, CString jc_category, CString jc_index, CPoint start_xy, CPoint end_xy, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//�Ƿ�ѡ���Զ����ؼӳ�
	//����
	if (jc_category == _T("����"))
	{
		if (jc_index == _T("1"))
		{
			print_log(_T("���ڹرռӳ�...\r\n"), gameclass);
			//����ӳɵ���
			int yh_move = 0;
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("�ӳ�1.bmp|�ӳ�2.bmp|�ӳ�3.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("����ӳɵ���...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX, intY);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("���ڼӳɽ���...\r\n"), gameclass);
					break;
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//�жϼӳ�״̬
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(271, 88, 351, 378, _T("����ӳ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					long yhjc_X = intX, yhjc_Y = intY;
					if (dm->FindPic(yhjc_X + 278, yhjc_Y - 11, yhjc_X + 308, yhjc_Y + 32, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("�ر�����ӳ�...\r\n"), gameclass);
						//�ر�����ӳ�
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(yhjc_X + 278, yhjc_Y - 11, yhjc_X + 308, yhjc_Y + 32, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("�ӳ��ѹرգ��رռӳɽ���...\r\n"), gameclass);
						//�رռӳɿ�
						if (dm->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							mouse_click_event(title, 128, 364);
							if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (yh_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						yh_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((yh_move >= 2) && (yh_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						yh_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						yh_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
	}
	//����
	else if (jc_category == _T("����"))
	{
		if (jc_index == _T("1"))
		{
			print_log(_T("���ڹرռӳ�...\r\n"), gameclass);
			int jx_move = 0;
			//����ӳ�
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("�ӳ�1.bmp|�ӳ�2.bmp|�ӳ�3.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("����ӳɵ���...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX, intY);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("���ڼӳɽ���...\r\n"), gameclass);
					break;
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//�жϼӳ�״̬
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(271, 88, 351, 378, _T("���Ѽӳ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					long jxjc_X = intX, jxjc_Y = intY;
					if (dm->FindPic(jxjc_X + 278, jxjc_Y - 11, jxjc_X + 308, jxjc_Y + 32, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("�رվ��Ѽӳ�...\r\n"), gameclass);
						//�رռӳ�
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(jxjc_X + 278, jxjc_Y - 11, jxjc_X + 308, jxjc_Y + 32, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("�ӳ��ѹرգ��رռӳɽ���...\r\n"), gameclass);
						//�رռӳɿ�
						if (dm->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							mouse_click_event(title, 128, 364);
							if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (jx_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						jx_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jx_move >= 2) && (jx_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						jx_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jx_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
	}
	//̽��
	else if (jc_category == _T("̽��"))
	{
		//4B4744-4C4744
		//����ȫ������
		if (jc_index == _T("1"))
		{
			print_log(_T("���ڹرռӳ�...\r\n"), gameclass);
			//����ӳ�
			int jy_move = 0;
			bool jy100Flag = true, jy50Flag = true;
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("�ӳ�1.bmp|�ӳ�2.bmp|�ӳ�3.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("����ӳɵ���...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX, intY);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("���ڼӳɽ���...\r\n"), gameclass);
					break;
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//�жϼӳ�״̬
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				//50%�ӳ�
				if (dm->FindPic(360, 92, 570, 358, _T("����50.bmp|����50-1.bmp|����50-2.bmp|����50-3.bmp"), _T("101010"), 0.75, 0, &intX, &intY) != -1)
				{
					long jyjc_X = intX, jyjc_Y = intY;
					if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("�ر�50%����ӳ�...\r\n"), gameclass);
						//�رռӳ�
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						jy50Flag = false;
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("50%����ӳ��ѹر�...\r\n"), gameclass);
						jy50Flag = false;
						break;
					}
				}
				else {
					if (jy_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			while (1) {
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				//100%�ӳ�
				if (dm->FindPic(360, 92, 570, 358, _T("����100.bmp|����100-1.bmp|����100-2.bmp|����100-3.bmp"), _T("101010"), 0.75, 0, &intX, &intY) != -1)
				{
					long jyjc_X = intX, jyjc_Y = intY;
					if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("�ر�100%����ӳ�...\r\n"), gameclass);
						//�رռӳ�
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						jy100Flag = false;
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("100%����ӳ��ѹر�...\r\n"), gameclass);
						jy100Flag = false;
						break;
					}
				}
				else {
					if (jy_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//��������رռӳɵ���
			while (1) {
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if ((!jy50Flag) && (!jy100Flag)) {
					print_log(_T("�ӳ���ȫ���رգ��رռӳɽ���...\r\n"), gameclass);
					//�رռӳɿ�
					if (dm->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
					{
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, 128, 364);
						if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
						break;
					}
				}
				else {
					print_log(_T("�ӳɹر�ʧ�ܣ�������...\r\n"), gameclass);
					break;
				}
			}
			return 1;
		}
		//�رս��
		else if (jc_index == _T("2"))
		{
			print_log(_T("���ڹرռӳ�...\r\n"), gameclass);
			print_log(_T("��Ҽӳɹ�����δʵ�֣����ֶ��رս�Ҽӳ�...\r\n"), gameclass);
			//�ݲ�ʵ�ִ˹���
			return 1;
		}
		//�ر�50%����
		else if (jc_index == _T("3"))
		{
			print_log(_T("���ڹرռӳ�...\r\n"), gameclass);
			int jy_move = 0;
			//����ӳ�
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("�ӳ�1.bmp|�ӳ�2.bmp|�ӳ�3.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("����ӳɵ���...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX, intY);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("���ڼӳɽ���...\r\n"), gameclass);
					break;
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			//�жϼӳ�״̬
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				//50%�ӳ�
				if (dm->FindPic(360, 92, 570, 358, _T("����50.bmp|����50-1.bmp|����50-2.bmp|����50-3.bmp"), _T("101010"), 0.75, 0, &intX, &intY) != -1)
				{
					long jyjc_X = intX, jyjc_Y = intY;
					if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("�ر�50%����ӳ�...\r\n"), gameclass);
						//�رռӳ�
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("50%����ӳ��ѹر�...\r\n"), gameclass);
						//�رռӳɿ�
						if (dm->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							mouse_click_event(title, 128, 364);
							if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (jy_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
		//�ر�100%����
		else if (jc_index == _T("4"))
		{
			int jy_move = 0;
			print_log(_T("���ڹرռӳ�...\r\n"), gameclass);
			//����ӳ�
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				if (dm->FindPic(start_xy.x, start_xy.y, end_xy.x, end_xy.y, _T("�ӳ�1.bmp|�ӳ�2.bmp|�ӳ�3.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("����ӳɵ���...\r\n"), gameclass);
					if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					mouse_click_event(title, intX, intY);
					if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
				}
				if (dm->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
				{
					print_log(_T("���ڼӳɽ���...\r\n"), gameclass);
					break;
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}

			//�жϼӳ�״̬
			while (1)
			{
				//�Զ��ܾ�����
				if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
				//100%�ӳ�
				if (dm->FindPic(360, 92, 570, 358, _T("����100.bmp|����100-1.bmp|����100-2.bmp|����100-3.bmp"), _T("101010"), 0.75, 0, &intX, &intY) != -1)
				{
					long jyjc_X = intX, jyjc_Y = intY;
					if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("�ӳɴ�.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("�ر�100%����ӳ�...\r\n"), gameclass);
						//�رռӳ�
						if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_click_event(title, intX + 10, intY + 10);
						if (random_delay(index, gameclass, dm, 1500, 2000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if (dm->FindPic(jyjc_X + 117, jyjc_Y - 8, jyjc_X + 141, jyjc_Y + 30, _T("�ӳ�δ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY) != -1)
					{
						print_log(_T("100%����ӳ��ѹر�...\r\n"), gameclass);
						//�رռӳɿ�
						if (dm->FindPic(237, 358, 388, 423, _T("�ӳɱ�־.bmp"), _T("000000"), 0.85, 0, &intX, &intY) != -1)
						{
							if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
							mouse_click_event(title, 128, 364);
							if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
							break;
						}
					}
				}
				else {
					if (jy_move < 2) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 316, 430, 213);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else if ((jy_move >= 2) && (jy_move < 4)) {
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
						mouse_move(title, 430, 213, 430, 316);
						jy_move++;
						if (random_delay(index, gameclass, dm, 500, 1000) == EXIT_THREAD) { return EXIT_THREAD; }
					}
					else {
						jy_move = 0;
					}
				}
				if (random_delay(index, gameclass, dm, 500, 800) == EXIT_THREAD) { return EXIT_THREAD; }
			}
			return 1;
		}
	}
}
//�Զ��ܾ����ͷ�ӡ
int yys_function::AutoRejectXS(long hd, dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	long intX, intY;
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);
	//�ܾ����ͷ�ӡ
	if (dm->FindPic(380, 109, 422, 151, _T("Э.bmp|��.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
		if (dm->FindPic(614, 361, 668, 416, _T("�ܾ�.bmp"), _T("202020"), 0.9, 0, &intX, &intY) != -1) {
			print_log(_T("�ܾ�����...\r\n"), gameclass);
			if (random_delay(index, gameclass, dm, 300, 600) == EXIT_THREAD) { return EXIT_THREAD; }
			mouse_click_event(title, intX + 10, intY + 13);
			if (random_delay(index, gameclass, dm, 200, 220) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		
	}
	return 1;
}

//����ͥԺ
int yys_function::returnYard(long hd,dmsoft *dm, int gameclass, int index) {
	if (dm == NULL)
	{
		return 0;
	}
	//��ȡ�����ڱ���
	long parentHandle = dm->GetWindow(hd, 0);
	CString title = dm->GetWindowTitle(parentHandle);

	long intX, intY;
	long exitRes1, exitRes2;
	while (true)
	{
		//�Զ��ܾ�����
		if (AutoRejectXS(hd, dm, gameclass, index) == EXIT_THREAD) { return EXIT_THREAD; }
		//�Һ���
		exitRes1=dm->FindPic(735, 29, 968, 175, _T("��.bmp|��1.bmp|��2.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		if (exitRes1!=-1)
		{
			mouse_click_event(title, intX+5, intY+5);
			if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//�ҷ���
		exitRes1 = dm->FindPic(0, 0, 217, 107, _T("����1.bmp|����2.bmp|����3.bmp|����4.bmp|����5.bmp|����6.bmp|����7.bmp|����8.bmp|�˳�.bmp|�˳�2.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		if (exitRes1 != -1)
		{
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//���������˳� case3���˳��������
		exitRes1 = dm->FindPic(512, 396, 649, 468, _T("����.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		exitRes2 = dm->FindPic(303, 397, 448, 465, _T("����ȡ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		if ((exitRes1 != -1) && (exitRes2 != -1))
		{
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//̽���˳�
		exitRes1= dm->FindPic(299, 271, 457, 337, _T("̽��ȡ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		exitRes2 = dm->FindPic(505, 274, 656, 334, _T("̽��ȷ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		if ((exitRes1!=-1)&&(exitRes2!=-1))
		{
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//���������˳� case1��ȡ����������
		exitRes1 = dm->FindPic(598, 406, 714, 481, _T("����.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		exitRes2 = dm->FindPic(239, 408, 363, 481, _T("ȡ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		if ((exitRes1 != -1) && (exitRes2 != -1))
		{
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		//���������˳� case2���˳�������
		exitRes1 = dm->FindPic(312, 289, 466, 360, _T("�˶�ȡ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		exitRes2 = dm->FindPic(488, 293, 644, 356, _T("ȷ��.bmp"), _T("202020"), 0.85, 0, &intX, &intY);
		if ((exitRes1 != -1) && (exitRes2 != -1))
		{
			mouse_click_event(title, intX + 5, intY + 5);
			if (random_delay(index, gameclass, dm, 200, 300) == EXIT_THREAD) { return EXIT_THREAD; }
		}
		
		if (IsInYard(dm,gameclass,index))
		{
			print_log(_T("�ɹ�����ͥԺ��\r\n"), gameclass);
			break;
		}
	}
	return 1;
}
/*
 *				���߾����ô��롿
 *			ҹ��ǧ�й�����δ��һ�����Ѷ���
 *		    �ж�����ͺͷ�ǣ�Ů�ӽ������¿ݡ�
 *
 */