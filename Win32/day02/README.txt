一 NMAKE和Makefile

  1.1 NMAKE - 命令解释器，根据Makefile文件中
     定义的脚本，完成项目的编译等操作。
     
  1.2 Makefile - 定义编译/链接等脚本语言。
  
  1.3 Makefile文件的编写
    
    1.3.1 基本语法规则
      window.exe:window.obj // 依赖行
	  	  cl.exe window.c /c    // 命令行
	  	  link.exe window.obj user32.lib
	  	
	    window.exe的依赖项是window.obj,如果
	    window.obj被重新改写,window.exe将重新
	    生成.
	    通过时间戳(time stamp)判断程序是否需
	    要重新编译链接,如果当文件修改最后时间
	    与时间戳不同,将会重新编译链接.
	  1.3.2 执行过程
 	    1 NMAKE首先找到第一个依赖行，根据依赖
	      行之间的关系，建立依赖树。例如：
	         A:B
	         B:C
	         C:D
	      NMAKE会建立对应的依赖树
	         A
	         |-B
	           |-C
	             |-D
      2 在树建好后，NMAKE会首先执行D的命令行，
        然后依次执行父结点的命令行
	    3 在A的命令执行结束后,退出NMAKE.
	    4 如果需要执行指定依赖行,需要在执行
	      NMAKE时增加依赖行的名称
	         NMAKE /f Makefile.mak B <--指定从B执行

  1.4 使用
    1.4.1 NAMKE指定文件名
			NMAKE /f Makefile.mak
		1.4.2 使用缺省文件名Makefile
		  NMAKE在执行时会自动查找这个文件.

二 字符编码

	2.1 编码的历史
	  
	  2.1.1 ASCII  0-127 7位表示
	  2.1.2 ASCII扩展码 0-255 8位表示
	    代码页:通过代码页来切换对应的
	      字符
	  2.1.3 双字节字符集 DBCS
	    使用一个或两个字节表示字符.
	      
	       "A中B国"
          12 1 2 
          A: 0x41 中:0x8051
          B: 0x42 国:0x8253
          
            1    2    3    4    5     6
          0x41 0x80	0x51 0x42 0x82  0x53   
	          A      中      B      国
	  2.1.4 Unicode
	     全部使用2个字节表示字符
					"A 中 B 国"
           2  2 2 2 
          A: 0x0041 中:0x8051
          B: 0x0042 国:0x8253
          1  2  3   4    5   6   7   8
         41 00  51  80   42  00  53  82
        
       内存/硬盘等资源占用变大.
       对编程支持度.
       
  2.2 C语言和编码
      
    2.2.1 单字节的字符和字符串
      char cText = 'A';
      char * pszText = "ABCD";
      
    2.2.2 宽字节的字符
      wchar_t cText = 'A'
      wchar_t * pszText = L"ABCD";
      
    2.2.3 相关函数
      单字字符的函数,对应有多.宽字节的函数.
       strlen wcslen mbslen
       printf wprintf
       
    2.2.4 TCHAR 
      为了程序中可以方便的支持的Unicode和多字节
      字符等,所以使用TCHAR来定义字符和字符串.
      根据_UNICODE宏开关,会将TCHAR编译成不同字符
      类型.
         #ifndef _UNICODE
			   		typedef char TCHAR
			    	#define __T(x)	x
 				 #else
						typedef wchar_t TCHAR
 						#define __T(x)  L##x
				 #endif
			使用时,要增加TCHAR.H头文件支持,使用
			  _UNICODE 宏开关进行编译
			   
			   CL window.c  /D_UNICODE
				 
				 #define _UNICODE
				 #include "tchar.h"
				 
			定义方式:
			   TCAHR * pszText = __T("ABCDEF");
			   
			代码使用：使用UNICODE宏开关，通知
			　　编译器选择编译的代码．
				#ifndef _UNICODE
					int nLen = strlen( pszText );
				#else
					int nLen = wcslen( pszText );
				#endif

　　２.2.5 Unicode的控制台打印
			BOOL WriteConsole(
  			HANDLE hConsoleOutput, //控制台输出流的句柄 
  			CONST VOID *lpBuffer,//输出的字符串的指针
  		　DWORD nNumberOfCharsToWrite,//输出的字符串的长度
　　　　LPDWORD lpNumberOfCharsWritten,
              // 返回已输出字符的数量
　　　  LPVOID lpReserved ); // 保留值

	2.3 Win32程序与编码

		2.3.1 Win32 API的定义
		　每个API对多字节字符和UNICODE分别有
		　不同的版本．
		　  MessageBox 
		       MessageBoxA  多字节字符  
					 MessageBoxW  UNICODE字符
					 
		2.3.2 字符的定义，使用TEXT, 由Winnt.h提供定义
				#ifdef  UNICODE                     
				#define __TEXT(quote) L##quote      
				#else   /* UNICODE */               
				#define __TEXT(quote) quote         
				#endif /* UNICODE */  
				
				TCHAR * pszText = TEXT( "ABCD" );              

　　2.3.3 字符转换
      int WideCharToMultiByte(
			  UINT CodePage, //代码页
			  DWORD dwFlags, //转换方式
			  LPCWSTR lpWideCharStr, //需要被转换WCHAR地址
			  int cchWideChar, //需要被转换WCHAR的长度
			  LPSTR lpMultiByteStr,//用于存放转换后的结果BUFF
			  int cchMultiByte, //BUFF的长度
			  LPCSTR lpDefaultChar,//使用的缺省字符串的地址
			  LPBOOL lpUsedDefaultChar //缺省字符串被使用的标识
			);
			
			int MultiByteToWideChar(
			  UINT CodePage,// 代码页
			  DWORD dwFlags,// 转换方式
			  LPCSTR lpMultiByteStr, // 需要被转换CHAR地址
			  int cchMultiByte,//需要被转换CHAR的长度
			  LPWSTR lpWideCharStr,//用于存放转换后的结果BUFF
			  int cchWideChar );//BUFF的长度
			  
			使用方法：
			　　
			 1 将要转换的字符串，传递给函数，从
			   返回值中获取转换后字符串的长度。
			 2 分配字符串空间
			 3 再次调用函数，并将分配的空间传递给
			 　函数，获取结果.
			
			
