/*
������Ҫ�ӿڽ��ܣ��������궼Ϊ������꣬����ڰ󶨵Ĵ��ڣ�

findHandle(CString windowname) //��ȡ���ھ�� windowname��Ҫ�󶨴��ڵ�����(һ���ڴ������Ͻ�)���磺�׵�ģ����  

mouse_click_event(CString windowname, int click_x, int click_y) ������¼�(��̨���) windowname��ͬ��  
	click_x��click_y��Ҫ�����������꣨����ڰ󶨵Ĵ��ڣ�  

mouse_move(CString windowname, int start_x, int start_y, int end_x, int end_y)//����϶��¼� windowname��ͬ�� 
	start_x��start_y���϶��������   end_x,end_y���϶��յ�����  

random_pos(int pos_x, int pos_y, int offsetX, int offsetY) �漴ƫ�����꣬��ֹ��Ϸ��Ҽ�� 
	pos_x��pos_y��ԭ���� offsetX��offsetY������x,yƫ�Ƶľ��룬����ֵ��������  

random_delay(int index, int gameclass, dmsoft *dm, int time_min, int time_max) ����ӳٵ������ֹ��Ϸ��Ҽ��(�ڲ�����������ͣ��ֹͣ��ʵ��)  
           index������(���߳�������ʾ��Ϸһ[0]����Ϸ��[1])  gameclass: ���߳�������ʶ��Ϸһ/��(0��1) 
		   dm����Į���� time_min��time_max���ӳٵ�ʱ�䷶Χ����λ��ms��  

IsInYard(dmsoft *dm, int gameclass,int index) �ж��Ƿ���ͥԺ��index������(���߳�������ʾ��Ϸһ[0]����Ϸ��[1]) 
gameclass: ���߳�������ʶ��Ϸһ/��(0��1) dm����Į����  

IsShowYard(dmsoft *dm,int gameclass, int index) �ж�ͥԺ�Ƿ�չ�� true:չ�� false:�ر�  

showYard(dmsoft *dm,int gameclass, int index) չ��ͥԺ  

FindExploreLanTernAndClick(long hd, dmsoft *dm,int gameclass, int index) Ѱ��̽�����������  

CombineTeamAction(long hd, dmsoft *dm, int gameclass, int index) ������ hd�����ھ��  

findNowSection(CString sourcePic, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) ��ȡ��ǰ�Ĳ���λ�ã�
                                                                                                      �����ж��������ʲô�����϶�  
 		sourcePic��ͼƬԴ����|�ָ�����ͼƬ�� startXY��endXY��ʶ��Χ������ֵ��Ѱ�ҵ���ͼƬ��ͼƬԴ�е�λ��(�±�) δ�ҵ�����-1  

findDestination(long hd, CString allpic, long destinationLoc, CString destPic, CPoint startXY, CPoint endXY, dmsoft *dm, int gameclass, int index) 
        Ѱ��Ŀ��λ�ò����(����ѡ��)  
 		hd�����ھ�� allpic��ͼƬԴ����|�ָ�����ͼƬ��destinationLoc��Ŀ��λ��(ͨ��findNowSection��ȡ)
	    destPic��Ŀ��ͼƬ(Ҫ�ҵ�ͼƬ) startXY��endXY��ʶ��Χ  

CreatTeamToInvite(long hd, dmsoft *dm, int gameclass, int index) �Ӵ������鵽�������   

unlock(long hd, dmsoft *dm, int gameclass, int index) ��������  

IsEnterTeam(long hd, dmsoft *dm, int count, int gameclass, int index) �������Ƿ������飬�����룺�����ս��δ���룺�ȴ�  
		count����¼�ڼ�����  
InviteEnterEvent(long hd, dmsoft *dm, int gameclass, int index) �ӳ����븱����Ĳ����¼�����׼����ʤ������  

ReceiveEnterEvent(long hd, dmsoft *dm,int count, CString gameMode, int gameclass, int index) ��Ա���븱����Ĳ����¼���������ͨ/Ĭ�����룬
																							 ��׼����ʤ������  
 		count����¼�ڼ����� gameMode����Ϸģʽ�����ꡢ���顢����֮�ɡ�����֮����  

DefalutInvite(long hd, dmsoft *dm, int gameclass, int index) ��һ�ֽ���������Ĭ�������¼� 

auto_open_jc(long hd, CString jc_category, CString jc_index, CPoint start_xy, CPoint end_xy, dmsoft *dm, int gameclass, int index) �Զ����ӳ�  
		hd:���ھ�� jc_category���ӳ�������ꡢ���ѡ�̽��  
		����̽����������Ҽӳɣ���δʵ�ִ��룬����λ�ã���50%����ӳɡ�100����ӳ� 50/100�����ϼӳ�  start_xy,end_xy��Ѱ�ҵļӳ�λ�÷�Χ  

auto_close_jc(long hd, CString jc_category, CString jc_index, CPoint start_xy, CPoint end_xy, dmsoft *dm, int gameclass, int index) �Զ��ؼӳ�  
		hd:���ھ�� jc_category���ӳ�������ꡢ���ѡ�̽��  
	    ����̽����������Ҽӳɣ���δʵ�ִ��룬����λ�ã���50%����ӳɡ�100����ӳ� 50/100�����ϼӳ� start_xy,end_xy��Ѱ�ҵļӳ�λ�÷�Χ

AutoRejectXS(long hd, dmsoft *dm, int gameclass, int index) �Զ��ܾ�����  

returnYard(long hd,dmsoft *dm, int gameclass, int index) ����ͥԺ  

�������ļ�����

BeginChangeYuHun.cpp��  		�Զ�������Ԥ��ʵ��  
BeginExplore.cpp��		̽������ʵ��  
BeginJueXing.cpp��		���ѹ���ʵ��  
BeginRest.cpp��			��ʱ��Ϣ����ʵ��  
BeginRiLunZhiYun.cpp��		����֮��ʵ��  
BeginTuPo.cpp��			����ͻ��ʵ��  
BeginYaoQiFengYin.cpp		 ������ӡʵ��  
BeginYeYuanHuo.cpp��		ҵԭ��ʵ��  
BeginYongShengZhiHai.cpp��	����֮��ʵ��  
BeginYuhun.cpp��			���깦��ʵ��  
BeginYuLing.cpp��		���鹦��ʵ��  
CDragStatic.cpp��		�϶���ȡ���  

CGame_   :CGame_��ͷ�Ķ���MFCͼ�λ������ʵ�֣�������������б�������ʾ�����ݵ�һЩ�����չʾ�¼��������¹���һ�㲻���޸�  
*/

