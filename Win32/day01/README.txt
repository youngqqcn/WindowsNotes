Win32 Windows编程

	1 Windows编程基础
	2 Windows文字的编码
	3 窗口程序
	4 窗口消息
	5 菜单和加速键
	6 绘图
	7 对话框
	8 基本控件
  .....
  
一 Windows编程基础

	1 Win32应用程序的基本类型
	
	  1.1 控制台程序
	     不需要完善的Windows窗口，可以使用DOS窗口
	     的方式显示。
	  1.2 Win32窗口程序
	     包含窗口的程序。可以通过窗口与程序进行交互。
	  1.3 Win32库程序
	     提供已有的代码，供其他程序使用。
	     动态库：DLL 是在执行的时候可以加载的程序。
	     静态库：LIB 是在编译链接是使用的程序。
	  1.4 对比
	     1.4.1 程序的入口函数不同
	        控制台：main
	        Win32窗口程序：WinMain
	        动态库DLL：DllMain
	        静态库LIB：无
	        
	     1.4.2 编译链接后存在的形式不同
	        控制台和Win32窗口程序：EXE文件，可以执行
	        动态库DLL：DLL文件，无法执行
	        静态库LIB：LIB文件，无法执行
	        
	     1.4.3 执行结果不同
	        控制台：使用DOS窗口，自己没有窗口。
	        Win32窗口程序：会产生自己的窗口，
	           可以将结果输出或者从窗口接受输入。
	        动态库DLL：自己无法执行,提供可以执行
	          的代码,当EXE等程序执行时,可以使用
	          这些代码.执行时,该库必须在指定的路径.
	        静态库LIB: 自己无法执行,提供给程序在
	          编译链接时使用,将库中的代码嵌入到
	          程序当中.执行时,不需要该库存在.
	     

二 Win32窗口程序和编译环境

	 2.1 开发和编译环境
	   VC1.5 - VC6.0(2008) - VC10.0(2010)
	 
	   2.1.1 编译器 CL.EXE
	     将原代码编译目标代码. OBJ文件.
	   2.1.2 链接器 Link.EXE
	     将OBJ文件和库函数链接.生成EXE.
	   2.1.3 资源编译器 rc.exe
	     将资源脚本编译成可以链接的文件(RES).
	   
	 2.2 头文件和库
	   2.2.1 头文件 windows.h包含了windows
	     常用的定义等.其他,还包含了一些其他的
	     头文件:
	      windef.h - 定义了各种的数据类型
				winbase.h- 定义了kernel的相关函数
				wingdi.h - 定义了绘图和文字
				winuser.h- 窗口 控件等函数
				winnt.h - 提供Unicode支持

	   2.2.2 库
	      kernel32.lib - 提供进程/线程/内存等等
	          API函数支持
	      user32.lib - 包括窗户/界面等等.
	      gdi32.lib  - 提供绘图/文字等。
	   
	 2.3 Hello World程序
	 
	   2.3.1 入口函数
     int WinMain( 
        HINSTANCE hInstance, 
        HINSTANCE hPrevInstance,
        LPSTR pszCmdLine,
        int  nShowCmd )
     hInstance - 	应用程序的实例句柄     
	   hPrevInstance - 该应用程序的前一个实例句柄
	   pszCmdLine - 命令行参数
	   nShowCmd - 窗口的显示方式
	   
	   2.3.2 MessageBox
	   
	 2.4 编译环境的准备
	 
	   在VC98的BIN目录下VCVARS32.BAT   
	   
	 2.5 编译CL.EXE
	 		CL的常用选项
	 			/c 只编译不链接
	 			/TC 编译C文件
	 			/TP 编译C++文件
	          如果不指定,CL会根据文件类型自动区分
	      /I 头文件所在路径
	    字符大小写敏感
	 2.6 链接LINK.EXE
	    LINK常用选项:
	    	/out:文件名,链接成指定文件名的程序
	 			/LIBPATH:LIB文件存放的路径, /LIBPATH:"E:\XXX"
	 			/SUBSYSTEM: CONSOLE/WINDOW
	 		字符大小写不敏感
	 
	 2.7 执行
	    正常执行或带参数执行
	    
三 第一个窗口程序

   3.1 入口函数WinMain
   3.2 窗口处理函数
     当窗口处理消息事件时,系统调用该函数
   	LRESULT CALLBACK WindowProc(
	  HWND hwnd,      // 窗口的句柄
  	UINT uMsg,      // 消息的ID号
  	WPARAM wParam,  // 消息所对应的参数
  	LPARAM lParam   // 消息所对应的参数
		);
   3.3 注册窗口类型
    typedef struct _WNDCLASS { 
    UINT    style;  //窗口类的风格
    WNDPROC lpfnWndProc; //窗口处理函数
    int     cbClsExtra; //窗口类附加数据大小
    int     cbWndExtra; //窗口附加数据大小
    HANDLE  hInstance; //当前应用程序的实例句柄
    HICON   hIcon; //窗口图标
    HCURSOR hCursor; //窗口的鼠标
    HBRUSH  hbrBackground; //窗口的背景画刷
    LPCTSTR lpszMenuName; //菜单
    LPCTSTR lpszClassName; //类型名称
    } WNDCLASS;
    
    注册函数 RegisterClass
   3.4 创建窗口
     HWND CreateWindow(
  		LPCTSTR lpClassName,  //窗口类型名称
  		LPCTSTR lpWindowName, //窗口名称
  		DWORD dwStyle,        //窗口类型
  		int x,                //窗口的左上角X坐边
  		int y,                //窗口的左上角X坐边
  		int nWidth,           //窗口的宽度
  		int nHeight,          //窗口的高度
  		HWND hWndParent,      //父窗口句柄
  		HMENU hMenu,          //窗口菜单句柄
  	  HANDLE hInstance,     //应用程序的实例句柄
  	  LPVOID lpParam        //创建的参数，一般为NULL
		  );

   3.5 显示窗口
     ShowWindow 显示窗口
        BOOL ShowWindow(
  			HWND hWnd,     //显示的窗口句柄
  		  int nCmdShow   //显示的方式
			  );
     UpdateWindow 刷新窗口
   3.6 消息处理
     GetMessage 获取消息
   	 DispatchMessage 派发消息
   
   3.7 程序退出
     窗口销毁时，退出程序。在WndProc中实现。
        WM_DESTROY: 当窗口销毁时，会调用WndProc
          传递给使用者。
        PostQuitMessage：发送一个退出消息。
        
四 资源的处理

	4.1 资源和资源脚本
	   资源：ICON/CUSRUR/BITMAP/MENU......
	   资源脚本: 扩展名为rc文件。
	4.2 编译资源
	   使用rc.exe编译资源，生成RES文件
	4.3 链接资源
	   使用link.exe将RES文件链接到程序当中
	4.4 ICON的使用
	  LoadIcon从指定程序中加载ICON资源。
	  

五 NMAKE和Makefile

   1 NMAKE - 命令解释器
     Makefile - 脚本语言定义的文件
     
     
