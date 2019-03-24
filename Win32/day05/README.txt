一 鼠标消息

  1 鼠标消息
    1) 基本鼠标消息
    WM_LBUTTONDOWN   左键按下
    WM_LBUTTONUP     左键抬起
    WM_RBUTTONDOWN   右键按下
    WM_RBUTTONUP     右键抬起
    WM_MOUSEMOVE     鼠标移动
    2) 双击消息
    WM_LBUTTONDBLCLK 左键双击 
    WM_RBUTTONDBLCLK 右键双击
    3) 滚轮消息
    WM_MOUSEWHEEL    鼠标滚轮
  
  2 消息的参数
    WPARAM - 当前键盘和鼠标按键状态，例如MK_CONTROL/
        MK_SHIFT,MK_LBUTTON等
    LPARAM - 当前鼠标的坐标,坐标的原点是窗口
      客户区的左上角.
       X坐标 - LOWORD(lParam),低16位
       Y坐标 - HIWORD(lParam),高16位
    参数具体内容和具体鼠标消息有稍微不同. 
    
  3 消息的使用
  
    3.1 基本鼠标消息,只需在窗口处理函数增加
      消息处理即可. 当消息来临,获取鼠标和按键
      状态.例如:
      	case WM_MOUSEMOVE:
				{
					int nX = LOWORD(lParam);
					int nY = HIWORD(lParam);
				}
				
		  附:坐标转换的函数 ClientToScreen
		    可以将鼠标坐标转换为屏幕的坐标.

   3.2 双击消息
		 3.2.1 窗口注册要增加 CS_DBLCLKS 类型
			 wce.style = CS_DBLCLKS|...;
		 3.2.2 在窗口处理函数中增加消息处理
		 3.2.3 产生过程,例如:WM_LBUTTONDBLCLK
		    WM_LBUTTONDOWN
		    WM_LBUTTONUP
		    WM_LBUTTONDBLCLK
		    WM_LBUTTONUP
		    连续两次LBUTTONDOWN的时间间隔小于
		    预定的双击时间间隔,就会产生
		    LBUTTONDBLCLK消息. 
		    双击时间间隔可以通过控制面板调整.

	3.3 滚轮消息
		3.3.1 由于WM_MOUSEWHEEL需要Winnt4.0以上
		  版本支持,所以需要包含在windows.h的头
		  文件前,增加 _WIN32_WINNT 宏定义,
        #define _WIN32_WINNT 0x0400
    3.3.2 在窗口处理函数中增加消息处理
    3.3.3 参数
     LPARAM 与其它鼠标消息类同
     WPARAM - LOWORD(WPARAM) 表示按键状态
              HIWORD(WPARAM) 滚轮滚动幅度,
                120的倍数,可以为正负值.
        正值: 滚轮向上滚动, 一般窗口向上滚动
        负值: 滚轮向下滚动, 一般窗口向下滚动


二 定时器消息

	1 定时器消息 WM_TIMER
	  按照定时器设置时间段,自动向窗口发送一个
	  定时器消息WM_TIMER. 优先级比较低.
	  定时器精度比较低,毫秒级别.消息产生时间
	  也精度比较低.
	  
	2 消息和函数
	  2.1 WM_TIMER  - 消息ID
	  	wParam: 定时器的ID
	  	lParam: 定时器的处理函数

	  2.2 SetTimer  - 设置一个定时器
	    UINT SetTimer(
  		HWND hWnd, //窗口的句柄,可以为NULL
  		UINT nIDEvent,//定时器的ID,0为不预设ID
  		UINT uElapse,//定时器时间间隔,毫秒级别
  		TIMERPROC lpTimerFunc );//定时器的处理函数,可以为NULL
			返回一个创建好的定时器ID

		2.3 KillTimer - 结束一个定时器
		  BOOL KillTimer(
				  HWND hWnd,//窗口句柄
				  UINT uIDEvent );//定时器ID
				
		2.4 TimerProc - 定时器处理函数
	  	VOID CALLBACK TimerProc(
		  	HWND hwnd, //窗口句柄
				UINT uMsg, //WM_TIMER消息ID
				UINT idEvent,//定时器ID
				DWORD dwTime   );//当前系统时间

  3 使用方式
    3.1 创建定时器 SetTimer
    	3.1.1 指定窗口句柄HWND,那么 TIMERPROC 参数
    	  可以为空,那么WM_TIMER消息将会发送给指定
    	  窗口. 如果未指定, TIMERPROC不能空, 必须
    	  指定定时器处理程序.
    	3.1.2 如果指定定时器ID,SetTimer会按照这个
    	  ID创建定时器, 如果未指定,会返回一个创建
    	  定时器ID.
       	nTimerID = SetTimer( NULL, 0, 7 * 1000,
       	   TimerProc1 );
    3.2 处理消息
      可以根据消息传入定时器ID号,分别处理.
    3.3 结束定时器
      在不使用时, KillTimer结束定时器.
		  KillTimer( hWnd, 1000 );

三 菜单
  1 菜单基础
    菜单 - 每个菜单会有一个HMENU句柄
    菜单项 - 每个菜单项会有一个ID号,可以
          根据这个ID执行不同的操作
  2 菜单的使用
    2.1 菜单创建
      2.1.1 CreateMenu - MENU 菜单
      2.1.2 CreatePopupMenu - 
         POPUPMENU 弹出式菜单
      2.1.3 AppenedMenu - 增加菜单项
			  BOOL AppendMenu(
			  HMENU hMenu, //菜单句柄
			  UINT uFlags, //菜单项标示
			  UINT uIDNewItem, //菜单项的ID或者子菜单句柄
			  LPCTSTR lpNewItem ); //菜单项的名称
				uFlags: 
				  MF_STRING - lpNewItem是一个字符串
				  MF_POPUP  - uIDNewItem是一个子菜单句柄
				  MF_SEPARATOR - 增加分隔项
				  MF_CHECKED/MF_UNCHECKED - 
				    设置和取消菜单项的对勾
				  MF_DISABLED/MF_ENABLE - 菜单项禁止和
				    允许状态
	  2.2 菜单的命令响应
	    2.2.1 WM_COMMAND消息
	      当用户点击菜单、按钮控件等时，系统会向
	      窗口发送WM_COAMMD消息。
	        WPARAM：HIWORD - 通知消息标识
	                LOWORD - 菜单项的ID号
	        LPARAM：控件的句柄
	    2.2.2 命令处理
	       根据菜单项的ID号作相应处理。
	       
	  2.3 菜单项的状态
	     2.3.1 WM_INITMENUPOPUP消息
	       当用户点击菜单，显示弹出菜单之前，系统
	       会向窗口发送WM_INITMENUPOPUP消息。
	       WPARAM：是菜单句柄
	       LPARAM：LOWORD - 菜单位置
	               HIWORD - 是否是系统菜单
	     2.3.2 命令处理
	       根据WPARAM的菜单句柄，使用MenuAPI函数，
	       修改菜单状态。
	        CheckMenuItem - 选择
	        EnableMenuItem - 允许和禁止
	        SetMenuItemInfo - 可以设置更多信息
	        
	  
	       
	    
	      
				  




