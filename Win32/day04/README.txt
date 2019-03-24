一 Win32消息机制

  1 消息机制
  
    过程驱动：程序是按照我们预先定义好的顺序
      执行，每执行一步，下一步都已经按照预定
      的顺序继续执行，直到程序结束。
      
    事件驱动：程序的执行顺序是无序的。某个时间
      点所执行的代码，是由外界通知。由于我们
      无法决定用户执行顺序，所以代码的执行也是
      无序。
      
    Win32的消息机制 - 事件驱动
    
  2 Win32消息程序
  
    2.1 Win32窗口注册
    2.2 Win32窗口创建
    2.3 WIn32消息循环
    	2.3.1 GetMessage 
    	  BOOL GetMessage(
				  LPMSG lpMsg,//存放获取到的消息数据
				  HWND hWnd,//获取消息的窗口句柄
				  UINT wMsgFilterMin,//消息过滤的起始消息
				  UINT wMsgFilterMax //消息过滤的终止消息
				);
				返回值BOOL：成功获取消息，返回TRUE，但是
				  当获取到WM_QUIT消息时，返回FALSE。
				可以使用PostQuitMessage向窗口发送WM_QUIT消息
				MSG - 由系统填写关于消息的参数
				hWnd- GetMessage会根据hWnd值，接收由hWnd
				  指定的窗口的消息。
				wMsgFilterMin，wMsgFilterMax - 消息过滤器，
				  要求GetMessage接收指定范围的消息。

    	2.3.2 TranslateMessage
				就是将键盘消息转换成字符消息。
				1 首先检查是否是键盘按键消息    	
				2 如果发现是按键消息，将根据按键，产生
				  一个字符消息，在下一个GetMessage执行
				  时，会收到这个消息。
			  3 如果未发现按键消息，不做任何处理。
			  
    	2.3.3 DispatchMessage
				根据消息数据内窗口句柄，找到这个窗口
				的窗口处理函数, 调用处理函数，进行消息
				处理。
				如果MSG中，HWND窗口句柄为空，
				DispatchMessage不做任何处理。
    	  
    2.4 Win32基本消息
      2.4.1 WM_DESTROY 
         窗口销毁时的消息，可以做退出或善后处理。
      2.4.2 WM_CREATE 
         窗口创建消息，是在窗口创建后，
         窗口处理函数收到第一条消息。
         可以在这个消息内做数据初始化/创建子窗口等。
         WPARAM wParam - 不使用
         LPARAM lParam - CREATESTRUCT指针
      2.4.3 WM_SIZE
         当窗口大小发生变化时，会收到这个消息。
         可以在这个消息中调整窗口布局。
         wParam - SIZE发生变化时的标识
				 LOWORD(lParam); - 客户区的宽
         HIWORD(lParam); - 客户区的高
      2.4.4 WM_SYSCOMMAND
         系统命令消息，当点击系统菜单和按钮时，
         会收到。
         可以在这个消息中，提示用户保存数据等。
         wParam - 系统命令类型
				 LOWORD(lParam) - 屏幕X坐标
				 HIWORD(lParam) - 屏幕Y坐标
 
      2.4.5 WM_PAINT 绘图消息
      2.4.6 键盘消息
      2.4.7 鼠标消息
      2.4.8 WM_TIMER定时器消息
      
    2.5 消息结构
      MSG - 消息结构
      typedef struct tagMSG {     // msg 
			    HWND   hwnd; //消息的窗口句柄   
			    UINT   message;//消息标示
			    WPARAM wParam; //消息的参数，32位
			    LPARAM lParam; //消息的参数，32位
			    DWORD  time;//消息产生的时间
			    POINT  pt; //消息产生时，鼠标的位置
			} MSG; 
 
 		2.6 消息的获取和发送
 		  2.6.1 获取GetMessage/PeekMessage
 		      GetMessage 获取消息，阻塞函数
 		      PeekMessage 获取消息，非阻塞函数
 		  2.6.2 发送SendMessage/PostMessage
 		      SendMessage 发送消息并等候消息
 		            处理结束才返回。 
 		      PostMessage 发送消息后立即返回，
 		            不关心消息处理的结果。
						LRESULT SendMessage/PostMessage(
						  HWND hWnd,      //处理消息窗口
						  UINT Msg,       //消息的ID
						  WPARAM wParam,  //消息的参数
						  LPARAM lParam );//消息的参数
						
  3 消息组成和分类
   3.1 消息组成
      窗口句柄/消息ID/消息参数（WPARAM.LPARAM）
   3.2 消息分类
      3.2.1 系统消息 - 由系统定义和使用的消息
         例如:WM_CREATE/WM_SIZE
         消息ID范围为: 0 - 0x03FF(WM_USER-1)
      3.2.2 用户定义消息 - 应用程序可以自己定义
         和使用的消息, WM_USER(0x0400)
         从WM_USER的ID开始,到0x7FFF,是用户可以
         定义使用的消息.
      3.2.3 其他消息范围
         WM_APP(0x8000)-0xBFFF:应用程序访问窗口
           的消息ID
         0xC000-0xFFFF: 应用程序访问消息,使用
           字符串注册系统产生相应消息ID
      3.2.4 用户定义消息的使用
         1)定义自定义消息ID: 
           #define   WM_FIRSTMSG  (WM_USER+1)
         2)在窗口处理函数中,响应消息
             switch( nMsg )
						 {
						 case WM_FIRSTMSG:
						   //处理函数
							break;
             }
         3)SendMessage/PostMessage发送消息
         	SendMessage( hWnd, WM_FIRSTMSG, 0, 0 );
         	
  4 消息队列
    4.1 消息队列 - 用于存储消息的内存空间,
      消息在队列中是先入先出.
    4.2 消息队列的分类
      4.2.1 系统消息队列 - 由系统维护的消息
        队列. 
      4.2.2 应用程序消息队列(线程消息对列) -
        属于每个线程的各自拥有的消息队列.
  
  5 消息和消息队列
    5.1 根据消息和消息队列关系,将消息分成两种:
      队列消息 - 可以存放在消息队列中的消息.
      非队列消息 - 发送时不进入消息队列.
    5.2 队列消息
      首先存放到消息队列当中,然后由GetMessage
      /PeekMessage取出,然后进行处理.
      例如: 鼠标消息/键盘消息/WM_PAINT/WM_QUIT
         WM_TIMER消息
    5.3 非队列消息
      消息发送直接发送给指定的窗口,查找窗口的
      处理函数,返回处理结果.
	
	6 消息的获取   
    6.1 消息循环
      6.1.1 GetMesssage从对列中获取消息,
        判断是否是WM_QUIT消息,如果发现是
        WM_QUIT消息,消息循环结束,否则继续
        下一步.
      6.1.2 TranslateMessage 翻译按键消息,
        如果发现有按键消息,产生字符消息放入
        消息对列, 继续下一步
      6.1.3 DispatchMessage 找到消息所发窗口
        的处理函数,处理消息.处理完成后,
        返回6.1.1.
    6.2 GetMesssage和PeekMessage
      6.2.1 从线程消息队列中获取消息,如果找到
        消息,就返回消息,进行消息处理. 如果未
        找到消息,执行6.2.2
      6.2.2 查找系统消息队列.通过向系统消息队
        列查询,如果找到消息,获取消息并返回,进行
        消息处理.如果未找到消息,执行6.2.3
      6.2.3 检查窗口需要重新绘制的范围,如果
        发现存在重新绘制的范围,会产生WM_PAINT消息.
        然后进行消息处理, 如果未找,执行6.2.4
      6.2.4 检查WM_TIMER定时器消息,如果发现
        存在已经到时的定时器,会产生WM_TIMER消息.
        进行消息处理. 如果未找,执行6.2.5
      6.2.5 执行内存管理工作.
      6.2.6 根据函数不同,处理结果不同:
        GetMesssage - 阻塞,等候下一条消息
        PeekMessage - 让出控制权,交给后面的代码执行.
        
  7 消息发送  
    7.1 消息发送分两种
       发送(Send)消息 - 直接发送给指定的窗口,并
          等候结果.
       投递(Post)消息 - 发送到消息队列当中,立刻
          返回,由消息循环处理.
    7.2 PostMessage和SendMessage
      PostMessage产生队列消息,由于发送后不等候
        消息处理结果,所以不能确定消息是否被处理成功.
      SendMessage产生非队列消息,可以确定消息是否成功.
        
二 WM_PAINT消息

	1 WM_PAINT的产生
	  由于窗口的互相覆盖等,产生需要绘制
	  的区域,那么会产生WM_PAINT消息.
	  一般情况下,不直接发送WM_PAINT消息,通过API
	  声明需要绘制区域,来产生WM_PAINT消息.
	  例如,可以使用InvalidateRect声明一个需要重新
	  绘制的区域.
  
  2 WM_PAINT的注意点
    2.1 如果一个消息队列中,有多个WM_PAINT消息,
     只有最后一个WM_PAINT消息会被处理.
    2.2 WM_PAINT消息处理中,要清空需要被绘制的
      区域. BeginPaint
      
  3 WM_PAINT的使用
    3.1 WM_PAINT开始时,必须调用BeginPaint
    3.2 绘制图形
    3.3 WM_PAINT处理后,必须调用EndPaint
    
三 键盘消息

  1 键盘消息
  	按键消息
    	WM_KEYDOWN 当键被按下时产生
    	WM_KEYUP 当键被释放时产生
    	WM_SYSKEYDOWN 当系统键被按下时产生 ALT/F10
    	WM_SYSKEYUP 当系统键释放时产生
    字符消息
    	WM_CHAR 当有字符键被按下时产生
      TranslateMessage会将WM_KEYDOWN消息中,
      可以显示的按键,转换成WM_CHAR的消息
  2 消息参数
    WPARAM - 虚拟键码
    LPARAM - 相关的按键信息.
  
  3 消息的使用
    3.1 当有按键消息时,首先进入系统消息队列,
      然后别程序的消息循环获取.
    3.2 消息的处理
  4 键盘消息的顺序
    对于可显示字符: WM_KEYDOWN,WM_CHAR,WM_KEYUP
    对于不可显示字符: WM_KEYDOWN,WM_KEYUP
    对于系统键:WM_SYSKEYDOWN,WM_SYSKEYUP
    如果按键一直不释放,会重复产生
         WM_KEYDOWN(WM_CHAR)
      
  
    
     
