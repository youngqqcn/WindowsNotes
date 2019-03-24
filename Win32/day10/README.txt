一 组合框 ComboBox

  1 组合框的样式
  
    1.1 简单组合框  CBS_SIMPLE
    1.2 下拉式组合框 CBS_DROPDOWN
       能输入或者从下拉列表中选择
    1.3 下拉列表式组合框 CBS_DROPDOWNLIST
       只能从下拉列表中选择
    
  2 组合框的使用 
  
    2.1 组合框的创建
      窗口类名称是 COMBOBOX, 使用CreateWindow
      创建, 创建时要注意窗口高度(弹出的列表).
    2.2 增加选项
      CB_ADDSTRING/CB_INSERTSTRING
      CB_ADDSTRING: WPARAM为0不使用, LPARAM
                    是添加字符串的地址
    2.3 删除选项
      CB_DELETESTRING 删除指定选项
      CB_RESETCONTENT 清空所有选项
    2.4 选择
      CB_GETCURSEL 获取被选择项
      CB_SETCURSEL 设置当前的选择项
      CB_SELECTSTRING 设置选择指定的字符串所对应的项
    2.5 查找
      CB_FINDSTRING 根据指定的字符串,找到对应
                    项的索引
         1)大小写不敏感
         2)字符串和选项从左到右匹配.
         3)选项包含字符串即可
    2.6 获取选项或者被选择字符串
       CB_GETLBTEXT 获取选项的字符串
       WM_GETTEXT   获取被选择到窗口的字符串
       
    2.7 选项的数据
       可以将自定义数据信息,在选项中设置和获取.
       CB_SETITEMDATA 将数据保存到选项中
       CB_GETITEMDATA 从选项当中获取数据
       
    2.8 目录显示
       CB_DIR 将指定路径下的文件和路径信息
          显示在ComboBox当中
          wParam - 显示的类型
          lParam - 路径字符串地址
          
    2.9 通知消息
      通过WM_COMMAND消息,通知父窗口.
      CBN_SELCHANGE 当窗口的选项发生变化的
           情况下,通知父窗口.
           
二 列表框 ListBox

	1 列表框的样式
	  1.1 单选列表框 默认
	  1.2 多选列表框 LBS_MULTIPLESEL
	  
	2 列表框的使用
	  2.1 列表框的创建
	    窗口类名为LISTBOX, 使用CreateWindow/Ex
	  2.2 增加选项
	    LB_ADDSTRING
	    LB_INSERTSTRING
	  2.2 删除选项
	    LB_DELETESTRING 删除指定选项
	    LB_RESETCONTENT 清空所有选项
	  2.3 选择项的获取和设置
	    LB_GETCURSEL 获取被选择项
	    LB_SETCURSEL 设置当前被选择项
	    LB_GETSEL  获取指定项的选择状态
	    LB_SETSEL  设置指定项的选择状态
	    LB_GETSELCOUNT 获取被选择的数量
	    LB_GETSELITEMS 获取被选择项的索引
	    
    2.4 查找 LB_FINDSTRING
    2.5 获取指定项的文字
       LB_GETEXT  指定项的文字
       LB_GETTEXTLEN 指定项的文字的长度
       
    2.6 选项的数据
       LB_SETITEMDATA 将自定义数据保存到
          指定的选项当中
       LB_GETITEMDATA 将自定义数据从指定
          选项中取出
    2.7 目录信息
       LB_DIR 显示指定目录下的文件和子目录
          信息
    2.8 通知消息
       LBN_SELCHANGE 当ListBox中的选择项发生
        变化时,通知父窗口.
       注意:对于ListBox需要增加LBS_NOTIFY的
        样式,才能发送通知消息
        
三 滚动条

   1 滚动条样式
     1.1 水平滚动条 SBS_HORZ
     1.2 垂直滚动条 SBS_VERT
     
   2 滚动条的使用
     2.1 滚动条的创建
        窗口类名称 SCROLLBAR 
     2.2 消息处理   
        2.2.1 水平滚动条 WM_HSCROLL
           LOWORD(wParam) - 滚动的标示
           HIWORD(wParam) - 当前滑块的位置
           lParam - 窗口的句柄
        2.2.2 垂直滚动条 WM_VSCROLL
           LOWORD(wParam) - 滚动的标示
           HIWORD(wParam) - 当前滑块的位置
           lParam - 窗口的句柄
        2.2.3 HIWORD(wParam)只在 
          SB_THUMBPOSITION/SB_THUMBTRACK时
          有效.
     2.3 滚动条的滚动范围
        SBM_SETRANGE 设置滚动条的滚动范围
           wParam - 最小值,起始值
           lParam - 最大值,终止值
        SBM_GETRANGE 获取滚动条的滚动范围
           wParam - 最小值得存放的INT的地址
           lParam - 最大值得存放的INT的地址
     2.4 滑块位置的设置和获取
        SBM_SETPOS 设置滑块位置
           wParam - 新的滑块位置
           lParam - 重新绘制窗口
        SBM_GETPOS 获取,返回当前位置
        
四 控件的自绘制

  1 控件具有OWNERDRAW样式
    BUTTON LISTBOX COMBOBOX
  2 WM_MEASUREITEM
    计算控件的大小    
    (UINT) wParam - 控件ID
    (LPMEASUREITEMSTRUCT)lParam-控件项的大小
  3 WM_DRAWITEM
    实现控件的绘制
    (UINT) wParam - 控件ID
    (LPDRAWITEMSTRUCT)lParam - 控件绘制的信息
 





