一 系统菜单

  1 执行系统提供的窗口命令，例如最大化、关闭
    等命令。本质上和普通菜单一样，所以我们也
    可以在程序中使用这个菜单
    
  2 系统菜单的使用
    2.1 获取系统菜单
       GetSystemMenu
       HMENU GetSystemMenu(
  			HWND hWnd, //要获取的窗口句柄
  		  BOOL bRevert  //获取时重置标示
			 );
			 
			 bRevert: TRUE 重置 FLASE 不重置
			 当Revert为TRUE时，会将菜单重新置成默认
			 的状态，并返回菜单句柄。如果为FALSE，
			 菜单项不重置，获取到当前系统菜单的状态。
			 
    2.2 修改系统菜单，例如增加、删除
       2.2.1 AppednMenu
       2.2.2 InsertMenu 
         比AppednMenu增加了一个插入菜单项的位置或ID。
       2.2.3 删除菜单项 
        BOOL RemoveMenu( //
  			HMENU hMenu, //菜单句柄
  			UINT uPosition,//菜单项的位置或ID
  			UINT uFlags );//菜单项的位置或ID的标示。
  			uFlags为MF_BYCOMMAND， uPosition为菜单ID
  			uFlags为MF_BYPOSITION，uPosition为菜单位置
      
    2.3 系统菜单的命令响应
       系统菜单的命令响应，是在WM_SYSCOMMAND中。
       WPARAM - LOWORD(wParam)为增加的菜单的ID
       	int nID = LOWORD( wParam );
				switch( nID )
				{
				case 1001:
				  //...
					break;
				}
				
二 右键菜单
  1 右键菜单
    当在窗口点击鼠标右键时，弹出的菜单。
  2 右键菜单的使用
    2.1 创建菜单
      CreatePopupMenu
    2.2 菜单增加
    	AppendMenu
    2.3 菜单的显示
      BOOL TrackPopupMenu(
  			HMENU hMenu, //显示的菜单句柄
  			UINT uFlags, //显示的方式
 			  int x, //菜单的X屏幕坐标
  		  int y, //菜单的Y屏幕坐标
		    int nReserved, //保留,必须为0
  		  HWND hWnd, //处理菜单命令的窗口句柄
  		  CONST RECT *prcRect ); //忽略
    2.4 菜单的命令处理
    	WM_COMMAND 
    2.5 使用右键菜单的位置
      2.5.1 WM_RBUTTONUP 消息
        在WM_RBUTTONUP中,添加菜单的创建及显示,
        右键消息坐标,转换成屏幕坐标使用.
          ClientToScreen.
      2.5.2 WM_CONTEXTMENU 消息
        用于显示右键的菜单的消息.
          WPARAM - 右键抬起时对应窗口句柄
          LPARAM - 右键抬起时鼠标的屏幕坐标位置
             LOWORD(lParam) - X屏幕坐标
             HIWORD(lParam) - Y屏幕坐标
      2.5.3 WM_RBUTTONUP和WM_CONTEXTMENU对比
        1) 坐标系不同, WM_RBUTTONUP客户区坐标
           WM_CONTEXTMENU屏幕坐标
        2) 先有WM_RBUTTONUP消息,
           后有WM_CONTEXTMENU消息
    
三 资源的使用

  1 资源文件
    图标、光标、字符串、菜单、加速键和
    对话框资源,位图资源等等。
    资源脚本文件 - 扩展名为RC文件。定义了
      资源和相关文件等等信息。
    资源编译器 - RC.exe
    
  2 图标资源ICON
   
    2.1 常用的几种大小: 16X16, 32X32,48X48
    2.2 使用
       HICON LoadIcon(
  			HINSTANCE hInstance, //应用程序的句柄
		    LPCTSTR lpIconName );//图标的ID字符串
    2.3 系统提供的图标
       hInstance为空, lpIconName为定义的系统图标.
    2.4 自己绘制的图表
       hInstance为图标所在的应用程序的实例句柄
    2.5 注意点：
      一个图标文件中,可以包含多种大小、颜色不同
      的图标，系统使用图标时，通过大小来匹配，
      如果未找到大小完全一致的，那么会使用大小
      最接近的图标格式替换。
    
  3 光标资源
    
    3.1 光标资源
      热点 Hotspot - 可以产生鼠标点击的位置
    3.2 使用
      HCURSOR LoadCursor(
  		HINSTANCE hInstance, //应用程序实例句柄
      LPCTSTR lpCursorName); //光标的ID
    3.3 系统的光标
      hInstance为空，lpCursorName指定为系统的
      光标即可获得
    3.4 自绘制的光标
      hInstance不能为空。
    3.5 WM_SETCURSOR消息
      当鼠标在窗口内就会产生。可以在程序执行
      的过程中修改鼠标样式。
        wParam - 窗口句柄;
        LOWORD(lParam) - 所在位置的标识
        HIWORD(lParam) - 鼠标的消息ID
      SetCursour 设置当前窗口的光标

  4 字符串资源
  
    4.1 包含字符串的资源
    4.2 使用
      int LoadString(
  		  HINSTANCE hInstance,//程序句柄
  	    UINT uID, //字符串资源的ID
        LPTSTR lpBuffer, //存放字符串的BUFF
        int nBufferMax ); //BUFF的大小
      返回获取字符串的长度
      
  5 菜单资源
    5.1 添加菜单资源
    5.2 加载菜单资源
     HMENU LoadMenu(
      HINSTANCE hInstance, //应用程序句柄
      LPCTSTR lpMenuName );//菜单ID字符串
     返回加载成功的菜单的句柄
    5.3 命令处理
      使用添加的菜单ID的宏,在WM_COMMAND消息
      中,处理菜单命令.

  6 加速键资源
    6.1 加速键的作用
      可以使用加速键执行命令. 例如Ctrl+S存盘.
    6.2 加速键资源的添加
    6.3 加速键的使用
      6.3.1 加载
       HACCEL LoadAccelerators(
  			HINSTANCE hInstance,//资源所在的应用程序句柄
        LPCTSTR lpTableName ); //加速键表的ID字符串
        加载成功返回加速键表的句柄
      6.3.2 增加消息处理
        int TranslateAccelerator(
  			 HWND hWnd, //处理加速键的窗口句柄
  		   HACCEL hAccTable, //加速键表
         LPMSG lpMsg );//MSG结构的地址
    6.4 关于加速键的消息
      TranslateAccelerator的作用是将WM_KEYDOWN
      或者WM_SYSKEYDOWN消息,翻译成WM_COMMAND
      或者WM_SYSCOMMAND消息.
      当收到KEYDOWN或者SYSKEYDOWN的消息时,会根据
      加速键表中按键和命令ID对应关系,找到相应的
      命令ID,然后调用窗口处理函数,执行WM_COMMAND
      或者WM_SYSCOMMAND消息.
      当找到对应命令ID并执行后，TranslateAccelerator
      返回非零，那么就不再执行后续的处理，消息
      循环等候下一条消息。否则，继续让消息循环中
      的TansnlateMessage和DispatchMessage处理。
      
四 程序编写

  1 定时器设置
    实现定时器的关闭和打开
      





