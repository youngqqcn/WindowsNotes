一 Windows绘图

  1 图形绘制
  
    1.1 图形绘制的方式
      获取到绘图句柄-设备描述表(DC),使用相应
      的绘图的API,在设备上绘制图形.
      
    1.2 颜色
      R\G\B三色, 每种颜色8位, 共24位颜色.
      32位颜色: 颜色数量24位颜色, 多出来的8位
         表示灰度.
      16位: 颜色数量2的16次方.
      
      Win32下,颜色的定义 COLORREF(DWORD), RGB宏
      定义颜色
      	COLORREF nColor = RGB( 0,  0,  0 );
        COLORREF nColor = RGB( 255,255,255 );
        COLORREF nColor = RGB( 255,0,  0 );
      从一个颜色中获取RGB三色:
        int nBlue = GetBValue( nColor );
        int nRed  = GetRValue( nColor );
        int nGreen= GetGValue( nColor );
  
    1.3 点的绘制和获取
      绘制: COLORREF SetPixel(
  			HDC hdc, //DC句柄
  			int X, //x坐标
  			int Y, //y坐标
  		COLORREF crColor ); // 点的颜色

      获取: COLORREF GetPixel(
				  HDC hdc,   //DC句柄
				  int XPos,  //x坐标
				  int nYPos ); //y坐标
				返回指定坐标位置的点的颜色

    1.4 直线的绘制
      MoveToEx 移动当前点到指定位置
      LineTo 从当前点绘制直线到指定位置
    
    1.5 弧的绘制
       Arc和AngleArc提供不同的绘制弧的方式:
       1.5.1 BOOL Arc( HDC hdc, 
				  int nLeftRect, // 外切矩形的坐标
				  int nTopRect,//外切矩形的坐标
				  int nRightRect,//外切矩形的坐标
				  int nBottomRect,//外切矩形的坐标
				  int nXStartArc,//起始切割半径的X坐标
				  int nYStartArc,//起始切割半径的Y坐标
				  int nXEndArc, //终止切割半径的X坐标
				  int nYEndArc ); //终止切割半径的X坐标
			 可以使用SetArcDirection函数,设置Arc函数
			 切割方向:顺时针和逆时针.
       1.5.2 BOOL AngleArc(
  			HDC hdc, // handle to device context
  			int X, //圆心的X坐标
  			int Y, //圆心的Y坐标
  			DWORD dwRadius,//圆的半径
  			FLOAT eStartAngle,//开始角度
  		  FLOAT eSweepAngle );//夹角

    1.6 折线
       1.6.1 BOOL Polyline(
  			HDC hdc, //DC句柄
  			CONST POINT *lppt,//Polyline顶点的坐标数组
  			int cPoints ); //顶点数组的长度
       1.6.2 PolylineTo 与Polyline类似, 只是在
          绘制Polyline前,从当前点使用LineTo绘
          制直线到Polyline的第一个顶点.
       1.6.3 绘制多组折线 PolyPolyline
          BOOL PolyPolyline( HDC hdc,
  				CONST POINT *lppt,//所有点的数组
  			  CONST DWORD *lpdwPolyPoints,//每组点的数量
  			  DWORD cCount );//分组的数量
         例如:
         	DWORD nGroup[] = { 4, 3 };
	        PolyPolyline( hDC, ptPolyLine,nGroup, 2 );

     1.7 Bizer曲线
     		BOOL PolyBezier(HDC hdc, 
         CONST POINT *lppt,//点数组,最少4个点
  			 DWORD cPoints );//点的数量
  			 4个点: 1和4是端点,2.3点是控制点
         7个点: 1.4.7是端点,其余是控制点
     
     1.8 多样式的线条
        BOOL PolyDraw( HDC hdc,
        CONST POINT *lppt,//各个点的数组
  			CONST BYTE *lpbTypes, //从某点到下一点的绘制方式 pointer to line and curve identifiers
  			int cCount); //点的数量
  			lpbTypes - PT_MOVETO  移动到该点
  			           PT_LINETO  绘直线
                   PT_BIZERTO Biezer曲线
                   
     1.9 矩形的绘制
       1.9.1 普通矩形 Rectangle 
       1.9.2 带圆角的矩形 
        BOOL RoundRect( HDC hdc,
        int nLeftRect, //左上X坐标
  		  int nTopRect, //左上Y坐标
        int nRightRect,//右下X坐标
        int nBottomRect, //右下Y坐标
        int nWidth, //生成圆角的椭圆的宽度
        int nHeight );//生成圆角的椭圆的高度

     1.10 椭圆和圆
       BOOL Ellipse( HDC hdc,
       int nLeftRect, //外切矩形左上X坐标
  	   int nTopRect,//外切矩形左上Y坐标
       int nRightRect, //外切矩形右下X坐标
       int nBottomRect); //外切矩形右下Y坐标
       
     1.11 饼Pie
       BOOL Pie( HDC hdc, 
       int nLeftRect, //外切矩形左上X坐标
  		 int nTopRect, //外切矩形左上Y坐标
       int nRightRect,  //外切矩形右下X坐标
       int nBottomRect, //外切矩形右下Y坐标
       int nXRadial1,//切割起始半径X坐标
       int nYRadial1,//切割起始半径Y坐标
       int nXRadial2,//切割终止半径X坐标
  	   int nYRadial2 );//切割终止半径Y坐标

     1.12 弦
       BOOL Chord( HDC hdc, 
       int nLeftRect, //外切矩形左上X坐标
  		 int nTopRect, //外切矩形左上Y坐标
       int nRightRect,  //外切矩形右下X坐标
       int nBottomRect, //外切矩形右下Y坐标
       int nXRadial1,//切割起始半径X坐标
       int nYRadial1,//切割起始半径Y坐标
       int nXRadial2,//切割终止半径X坐标
  	   int nYRadial2 );//切割终止半径Y坐标
       
     1.13 多边形
       BOOL Polygon( HDC hdc,
        CONST POINT *lpPoints, //多边形的顶点
        int nCount ); //顶点的数量
       PolyPolygon 可以绘制多组多边形
       
  2 GDI绘图对象 - 画笔
  	2.1 画笔的作用
  	  可以控制线条的颜色、样式、宽度。
  	2.2 画笔的使用
  	  2.2.1 创建画笔 CreatePen
  	     HPEN CreatePen(
  				int fnPenStyle, //画笔的样式
  			  int nWidth, //画笔的宽度
  				COLORREF crColor);//画笔的颜色
  	  2.2.2 置成当前DC可以使用的画笔
  	     HGDIOBJ SelectObject(
  			  HDC hdc, // 当前DC的句柄
          HGDIOBJ hgdiobj );//要使用的GDI对象句柄
        返回当前DC原来使用的同类型的GDI对象句柄。
  	  2.2.3 绘制图形
  	  2.2.4 从当前DC中取出画笔,即将旧画笔
  	     放入当前DC中
  	        SelectObject( hDC, hOldPen );
  	  2.2.5 销毁画笔
  	     DeleteObject( hPen );
  	     画笔使用时，由于绘图资源有限，一定要
  	     注意释放。
   	  
  3 GDI绘图对象 - 画刷
    3.1 画刷的作用
      填充封闭图形，包括样式、颜色等。
      
    3.2 画刷的使用
      3.2.1 创建画刷
         CreateSolidBrush 创建实心画刷
         CreateHatchBrush 创建阴影线的画刷
      3.2.2 置成当前DC可以使用的画刷
         SelectObject 和画笔使用方式类似
      3.2.3 绘制图形
      3.2.4 取出画刷
         SelectObject 和画笔使用方式类似
      3.2.5 销毁画刷
         DeleteObject 和画笔使用方式类似




