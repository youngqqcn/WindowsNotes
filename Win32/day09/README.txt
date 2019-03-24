一 对话框

  1 对话框的分类
  2 对话框的基本使用方式
  3 对话框资源
  4 有模式对话框的使用
  5 无模式对话框的使用
    5.1 添加对话框资源
    5.2 定义窗口处理函数
       BOOL CALLBACK DialogProc(
        HWND hwndDlg,  // handle to dialog box
				UINT uMsg,     // message
				WPARAM wParam, // first message parameter
				LPARAM lParam 	); // second message parameter
    5.3 创建对话框
       HWND CreateDialog(
			  HINSTANCE hInstance,//应用程序实例句柄
			  LPCTSTR lpTemplate,//对话框的资源ID
			  HWND hWndParent,//父窗口
			  DLGPROC lpDialogFunc );//对话框的窗口处理函数
  		 返回值是创建好的对话框的窗口句柄。
    5.4 显示对话框
       ShowWindow
    5.5 关闭对话框
       EndDialog
    5.6 与有模式对话框对比
       创建函数: 有模式对话框 DialogBox
                 无模式对话框 CreateDialog
       程序执行方式: 
        有模式对话框会阻塞,禁止其他窗口的输入
        无模式对话框会让主程序,不影响其它窗口的输入

  6 对话框中的消息        
  
    WM_INITDIALOG消息,用途类似于WM_CREATE消息
    可以在对话框创建完成后,进行数据初始化.
    它与WM_CREATE不同之处是,WM_INITDIALOG消息
    会在对话框资源模板上的所有子控件(按钮等)
    创建完成后,再发送给对话框窗口. 
      wParam - 当前接受输入焦点子控件窗口句柄
      lParam - 创建时附带的参数

  7 对话框和普通窗口的对比
    7.1 创建方式 
      普通窗口: CreateWindow/Ex
      对话框: DialogBox/CreateDialog
    7.2 消息
      普通窗口: 会收到WM_CREATE
      对话框:   WM_INITDIALOG
    7.3 关闭方式:
      普通窗口: DestoryWindow等
      对话框: EndDialog
      
二 子控件

  1 子控件
  
    1.1 控件的类型
    由Windows系统定义的窗口类型,可以提供
    相应的功能.包括按钮、文本编辑框、静态框等.
    
    1.2 控件的创建
    都可以使用CreateWindow/CreateWindowEx
    创建，并获取到控件HWND。创建时每个子控件
    都要有相应的ID号，ID号要求不重复。
    
    1.3 控件的消息
    子控件和父窗口(一般窗口或者对话框)的交互
    都是通过消息完成。如果子窗口状态发生变化，
    子窗口会向父窗口发送相应的消息。
    一般父窗口会使用SendMessage函数向子窗口
    发送消息。
    父窗口响应子窗口发送的消息一般是在
    WM_COMMAND进行处理。
     
三 静态框

  1 静态框创建
    窗口类的名称 - STATIC, 用于窗口上
    显示文字等, 如果使用SS_ICON/SS_BITMAP
    风格可以显示ICON和BITMAP
    
    文本静态框 - 创建时使用SS_SIMPLE即可
    ICON静态框 - 创建时需要使用SS_ICON, 并且
       将静态框的窗口名称设置成对应ICON的资源
       ID号,例如"#101".
    
  2 静态框的命令相应
    2.1 静态框要添加SS_NOTIFY风格
    2.2 WM_COMMAND进行处理
       WPARAM - HIWORD 命令ID
                LOWORD 静态框的窗口ID
       LPARAM - 静态框的窗口句柄.  
    
  3 静态框的消息
    调用SendMessage函数,向Static控件发送消息
    例如: STM_SETICON消息修改控件显示图标
      SendMessage( hStatic, STM_SETICON,
				(WPARAM)hIcon, 0 );
		其他:
	  GetDlgItem 从窗口中获取指定ID的子控件的
	    窗口句柄
	    
四 按钮

   1 按钮的分类
     根据创建按钮时使用的风格:
     1.1 下压式按钮 PUSH BUTTON 
        正常下压式按钮 BS_PUSHBUTTON 
        三态下压按钮 BS_3STATE/BS_AUTO3STATE
     1.2 分组按钮 Group Button
        按钮样式:BS_GROUPBOX
     1.3 多选按钮   Check Box 
        按钮样式:BS_CHECKBOX/BS_AUTOCHECKBOX
     1.4 单选按钮   Radio Box
        按钮样式:BS_RADIOBUTTON/
                 BS_AUTORADIOBUTTON
                 
   2 下压式按钮的使用
     2.1 创建按钮
        创建时使用BUTTON
     2.2 命令消息
        BN_CLICKED消息: 当点击按钮通过
          WM_COMMAND消息通知父窗口
     2.3 通知消息 
        SendMessage
        
   3 分组按钮
     3.1 创建分组按钮
     3.2 常用于对窗口内控件划分区域,增加
        界面的友好性
        
   4 多选按钮 CheckBox
     4.1 创建使用 BS_CHECKBOX/BS_AUTOCHECKBOX
       BS_AUTOCHECKBOX 选择状态系统自动维护
       BS_CHECKBOX 选择状态需要自己维护
     4.2 命令响应
       BN_CLICKED 通过WM_COMMAND消息
     4.3 通知消息
       BM_GETCHECK 获取当前按钮被选择的状态
       BM_SETCHECK 设置当前按钮被选择的状态
          wParam 用于设置状态标示
       状态: BST_CHECKED 或 BST_UNCHECKED
       
   5 单选按钮 RadioBox
     5.1 创建使用 BS_RADIOBUTTON/BS_AUTORADIOBUTTON
       BS_AUTORADIOBUTTON 选择状态系统自动维护
       BS_RADIOBUTTON 选择状态需要自己维护
       注意:
       RadionBox分组 - 使用WS_GROUP样式,可以将
       RadionBox分成多个组.
          A CreateWindow (  ,,,WS_GROUP );
          B CreateWindow...
          C CreateWindow (  ,,,WS_GROUP );
          D CreaetWindow...
          A和B是一组, C和D是一组
     5.2 命令响应
       BN_CLICKED 通过WM_COMMAND消息
     5.3 通知消息
       与CheckBox类似
       
五 文本编辑框

  1 文本编辑框的样式
    1.1 单行文本编辑框 - 默认样式
    1.2 多行文本编辑框 - ES_MULTILINE
    1.3 密码文本编辑框 - ES_PASSWORD
  2 文本编辑框的使用
    2.1 创建 
       窗口类名称EDIT.
    2.2 Notify消息
       EN_CHANGE 当编辑框内容发生变化时,
         会通知父窗口
    2.3 EDIT窗口消息
       EM_SETSEL 选择消息 WPARAM是起始字符位置
           LPARAM是终止字符位置
       窗口消息: WM_COPY, WM_PASET,WM_CUT等消息
         WM_SETTEXT, WM_GETTEXT, WM_GETTEXTLEN
         SetWindowText
         GetWindowText/GetWindowTextLen
         
          
         
    
       
    
     
    
    
  
      
    
    
    

    
                 



