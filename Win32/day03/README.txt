一 窗口注册和创建

  1 Win32窗口程序创建步骤
  
    1.1 WinMain入口函数的定义
    1.2 WindowProc函数的定义
    1.3 注册窗口类
      RegisterClass/RegisterClassEx
    1.4 创建窗口
      CreateWindow/CreateWindowEx
    1.5 窗口的显示和刷新
      ShowWindow/UpdateWindow
    1.6 消息处理
      GetMessage/DispatchMessage
    1.7 窗口退出
      WM_DESTROY/PostQuitMessage
      
  2 窗口的注册
  	
  	2.1 窗口类的分类
  	  2.1.1 系统全局的窗口类.比如按钮("BUTTON")、
  	    文本编辑框("EDIT")等。
  	  2.1.2 应用程序的全局窗口类。可以在一个应用
  	    程序中EXE、DLL等所有模块中使用的窗口类。
  	  2.1.3 局部窗口类。只能在本模块中使用的
  	    窗口类。
  	    
  	2.2 实现窗口类的注册
  	  2.2.1 系统全局的窗口类，无需注册直接使用。
  			使用CreateWindow函数，在CLASSNAME中指定
  			系统已经定义好的窗口类型名称即可。
  	  2.2.2 应用程序的全局窗口类,需要用代码实现
  	    注册，在注册时需要增加CS_GLOBALCLASS定义。
  	    实现方式：
  	       WNDCLASS wc = {0};
  	       wc.style = CS_GLOBALCLASS|CS_HREDRAW..;
  	       ....
  	       RegisterClass( &wc );
  	  2.2.3 局部窗口类，不是增加CS_GLOBALCLASS定义。
  			使用RegisterClass和RegisterClassEx注册
				typedef struct _WNDCLASSEX { 
    				UINT    cbSize; //结构体的大小
					  UINT    style; 
					  WNDPROC lpfnWndProc; 
					  int     cbClsExtra; 
					  int     cbWndExtra; 
					  HANDLE  hInstance; 
					  HICON   hIcon; 
					  HCURSOR hCursor; 
					  HBRUSH  hbrBackground; 
					  LPCTSTR lpszMenuName; 
					  LPCTSTR lpszClassName; 
					  HICON   hIconSm; //小图标
					} WNDCLASSEX; 
				2.2.4 窗口类风格
				   CS_HREDRAW 窗口水平变化，重新绘制窗口。
				   CS_VREDRAW 窗口垂直变化，重新绘制窗口。
				   CS_DBCLICK 窗口可以接收鼠标双击消息
				   CS_GLOBALCLASS 创建应用程序全局窗口类。
				   CS_BYTEALIGNWINDOW 窗口对齐方式,以8的倍数对齐
				   CS_BYTEALIGNCLIENT 窗口客户区对齐方式,以8的倍数对齐
				   CS_CLASSDC 所有这种类型的窗口使用同一个DC(设备描述表,绘图使用)
				   CS_OWNDC 每个窗口拥有自己的DC
				   CS_PARENTDC 使用父窗口的DC
				   CS_SAVEBITS 是用位图保存窗口界面,可以提高
				           窗口界面的刷新性能
				   CS_NOCLOSE 禁止关闭命令.
				
				2.2.5 窗口类的附加数据 cbClsExtra
				  在窗口类的数据信息中添加自己信息.
				   cbClsExtra 用于添加信息的内存的大小
				   SetClassLong 将信息保存到内存中
				   GetClassLong 将信息从内存中取出
				     DWORD SetClassLong(
							  HWND hWnd,//窗口的句柄
							  int nIndex, //值的索引号
							  LONG dwNewLong   //值
							);
						 DWORD GetClassLong(
							  HWND hWnd,//窗口的句柄
							  int nIndex, //值的索引号
							);
					cbClsExtra的长度一般是4字节的倍数
				2.2.6 窗口附加数据 cbWndExtra
				   在窗口的数据信息中添加自己信息.
  	      cbWndExtra 用于添加信息的内存的大小
  	      SetWindowLong 将信息保存到内存中
  	      GetWindowLong 将信息从内存中取出
  	
  	2.3 窗口类的相关函数
  		RegisterClass/RegisterClassEx 注册
  	  UnregisterClass 注销
  	  GetClassInfo/GetClassInfoEx 获取信息
  	  GetClassName 获取窗口的窗口类名称
  	  GetClassLong/SetClassLong 窗口类附加数据的设置和获取
  	  GetWindowLong/SetWindowLong 窗口的附加数据的设置和获取
  	
    2.4 创建窗口时如何定位窗口类
    
      2.4.1 查找应用程序局部的窗口类。如果找到，
            执行2.4.2，否则执行2.4.3
      2.4.2 如果找到名称一致的窗口类，会比较
            HISNTANCE句柄。如果相等，就使用找到
            的窗口类信息创建窗口，如果不同，继续
            查找，执行2.4.3。
      2.4.3 如果未找到名称一致的窗口类，会继续
            在应用程序全局窗口类中查找。如果找到，
            执行2.4.4，否则执行2.4.5
      2.4.4 全局窗口类找到一致的，使用找到
            的窗口类信息创建窗口。
      2.4.5 系统全局窗口类中查找。如果找到，创建
            窗口，否则返回失败。
 
  3 窗口创建
   
    3.1 窗口创建函数
      CreateWindow/CreateWindowEx
      HWND CreateWindowEx(
				  DWORD dwExStyle,//窗口的扩展样式
				  LPCTSTR lpClassName,  // pointer to registered class name
				  LPCTSTR lpWindowName, // pointer to window name
				  DWORD dwStyle,        // window style
				  int x,                // horizontal position of window
				  int y,                // vertical position of window
				  int nWidth,           // window width
				  int nHeight,          // window height
				  HWND hWndParent,      // handle to parent or owner window
				  HMENU hMenu,          // handle to menu, or child-window identifier
				  HINSTANCE hInstance,  // handle to application instance
				  LPVOID lpParam );     // pointer to window-creation data
		 3.2 窗口风格和扩展风格
		 
		    窗口风格: WS_XXXX定义的风格,是窗口的
		        基本风格.
		    扩展风格: WS_EX_XXXXX 定义的风格,是窗口
		        的扩展风格.比如: ToolWindow窗口等等.
		    在CreateWindow可以使用基本窗口风格,扩展
		    的窗口风格,需要使用CreateWindowEx设置.
		    
		    WS_OVERLAPPED窗口,层叠式窗口
		    WS_POPUP窗口,弹出式窗口
		    WS_CHILD窗口,子窗口
		    
     3.3 父窗口和子窗口
        3.3.1 CreateWindow时,指定父窗口
        3.3.2 将窗口的风格增加WS_CHILD
        3.3.3 可以使用SetParent和GetParent
           函数设置和获取指定窗口的父窗口.
           
        其他: MoveWindow 移动窗口.
        
     3.4 MDI窗口的创建
        3.4.1 创建主窗口
           注册主窗口类型,创建主窗口.
						HWND hWnd = CreateWindowEx( 0,
							pszClassName, "MainWnd", 
							WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
							CW_USEDEFAULT, CW_USEDEFAULT,
							CW_USEDEFAULT, NULL, NULL, g_hInst,
							NULL );
        3.4.2 MDICLIENT窗口
        		1 添加CLIENTCREATESTRUCT结构,作为附加数据
						CLIENTCREATESTRUCT cs = { 0 };
						cs.idFirstChild = 1000;//MDI第一个子窗口的ID
						2 创建时,使用"MDICLIENT"窗口类型.
						3 它的父窗口是主窗口
						HWND hWnd = CreateWindowEx( 0,
							"MDICLIENT", "MainWnd", 
							WS_CHILD|WS_VISIBLE, CW_USEDEFAULT,
							CW_USEDEFAULT, CW_USEDEFAULT,
							CW_USEDEFAULT, hParent, NULL, g_hInst,
							&cs );
        3.4.3 创建一个MDI子窗口
            1 注册主窗口类型,创建子窗口
            2 它的父窗口为MDICLIENT窗口
            3 增加WS_EX_MDICHILD的风格
					  HWND hWnd = 
					  CreateWindowEx( WS_EX_MDICHILD,
						pszClassName, "ChildWnd", 
						WS_CHILD|WS_VISIBLE, CW_USEDEFAULT,
						CW_USEDEFAULT, CW_USEDEFAULT,
						CW_USEDEFAULT, hParent, NULL, 
						g_hInst, NULL );
