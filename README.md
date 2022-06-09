# YYS_ASSIST
## 阴阳师脚本护肝助手，防止头秃，珍爱生命，人人有责
#### 基于C++结合MFC开发的阴阳师辅助，结合大漠插件的图色识别函数，进行模拟人手点击操作，脚本中使用大量的随机延迟函数和随即延迟点击，
#### 并且游戏是在模拟器中运行，脚本在电脑环境运行，环境分离，只要操作得当，让脚本的行为像人一样，被检测到的几率几乎为0.
### 脚本示意图
![tags](imgs/desc.jpg)
![tags](imgs/desc2.jpg)
# 一、简单的使用方法 
###### ①点击左上角tags
![tags](imgs/点击tags.png)

###### ②选择一个发行版本进入下载相应exe
![enter](imgs/Enter.png)
###### ③选择对应屏幕缩放(100%或125%)的脚本下载即可(不同缩放的脚本只是显示效果不同，功能无任何区别)
![download](imgs/download.png)
# 二、自己编译运行
###### 1.下载源码使用VS2017及以上版本（最好是2017）打开，修改YYS_AssistDlg.cpp中的大漠插件注册（有注释），在g_dm->Reg(_T(""),_T(""));填入自己买的或找的
######   大漠注册码和附加码。
###### 2.使用大漠图色工具（百度一大堆分享的）自己截取游戏不同场景的图片（应该挺多的，可能会有亿点点工作量哈，不想截图就用现成的exe支持一下作者(●ˇ∀ˇ●)）放在项目的pic_font文件夹（桌面端也适用，不过得自己在代码中调各个场景识别范围），
######   模拟器默认分辨率[960*540 160dpi](照着这个分辨率只需截图，不用考虑识别区域坐标)
###### 3.将项目运行环境改为debug或release  平台选x86  （注意：必须为x86,大漠64位需自己定制）
###### 4.CTRL + F5运行即可开始运行脚本
