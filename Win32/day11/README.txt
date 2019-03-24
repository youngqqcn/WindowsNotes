一 Windows的库
  由于项目的复杂程度，或者为了提高代码的
  重用率等等，所以才引入了库程序。
  库包含两种：
    1 静态库：扩展名为LIB的文件，是不能被
        加载的程序，可以理解为目标程序的
        归档。
    2 动态库：扩展名是DLL的文件，是可以被
        应用程序加载的程序。
        
二 静态库

  1 静态库的特点
    1.1 目标程序的归档
    1.2 静态库的代码会被嵌入到程序当中。
    1.3 程序执行时不需要静态库存在

  2 C语言静态库
    2.1 创建静态库
        创建Win32静态库项目,使用*.C文件建立
        项目。
    2.2 添加静态库函数
    2.3 在程序中将静态库导入
       2.3.1 项目的Setting里设置
       2.3.2 使用关键字 pragma
        #pragma comment(lib, "../lib/winclib.lib")
    2.4 使用静态库提供的函数
       在C语言程序中，直接使用函数即可。
       
  3 C++语言的静态库
    3.1 创建静态库
       创建Win32静态库项目,使用*.CPP文件建立
       项目。
    3.2 添加静态库的函数
    3.3 导入静态库
       3.3.1 项目的Setting里设置
       3.3.2 使用关键字 pragma
        #pragma comment(lib, "../lib/wincpplib.lib")
    3.4 定义库函数的原形
       int CPP_Add( int nAdd1, int nAdd2 );
    3.5 使用库函数
    3.6 注意：
       如果在CPP文件使用C语言静态库，定义的
       静态库函数原形，需要增加 extern "C".
       例如：
       extern "C" int C_Add( int nAdd1, int nAdd2 );
       
三 动态库

  1 动态库的好处
    1.1 可以提供模块化的方式，方便协调开发。
    1.2 对源代码保护
    1.3 减小可执行文件的大小
    1.4 提供代码的重用率
    
  2 动态库的基本使用方法
    2.1 动态库的创建
    2.2 加载动态库
    2.3 获取并使用库函数、变量或类
    2.4 释放动态库
    
  3 动态库的函数
    3.1 创建
	    3.1.1 创建DLL的项目
	       使用Win32 DLL项目，创建DLL，添加
	       相应的文件。 
	    3.1.2 增加动态库函数
	    3.1.3 导出动态库函数
	      3.1.3.1 使用__declspec(dllexport)方式
	         在函数前增加这个关键字，例如
	         __declspec(dllexport) int Dll_Add()
        3.1.3.2 增加 extern "C" 方式,即
           extern "C" __declspec(dllexport)
           以C语言方式导出函数
        3.1.3.3 使用DEF文件导出
        	 增加扩展名为DEF的文件到项目中.
        	 在DEF文件中添加导出定义.
        	  LIBRARY dllfunc.dll //导出库
            EXPORTS             //导出表
	              Dll_Mul	@1      //导出函数
        	      Dll_Div	@2
	  3.2 使用
      3.2.1 隐式链接
        3.2.1.1 导入LIB
          项目的Setting或者使用#pragma导入,例如:
          #pragma comment( lib, "../lib/dllfunc.lib")
        3.2.1.2 定义函数原形
          声明一个和导出函数一致的函数定义.
          如果DLL采用extern "C"导出函数,
          需要定义extern "C"方式函数原形
        3.2.1.3 使用函数
          直接函数即可
        3.2.1.4 应用程序查找DLL的路径
          1) 查找当前应用程序的目录.
          2) 当前的工作目录
          3) 查找Windows System32的目录
          4) 查找Windows System的目录
          5) 查找Windows目录
          6) 查找环境变量PATH指定路径

      3.2.2 显示链接    
				3.2.2.1 加载动态库
				  HINSTANCE LoadLibrary(
  				LPCTSTR lpLibFileName );//DLL的路径
          返回加载好DLL的句柄
				3.2.2.2 定义函数原形对应的函数指针
				3.2.2.3 获取函数地址
				   FARPROC GetProcAddress(
					  HMODULE hModule,//DLL的句柄
					  LPCSTR lpProcName );//函数的名称
					返回对应函数地址
					注意:
					1 对于__declspec(dllexport)导出的函数,
					  由于函数名称发生变化,所以无法使用
					  函数名称获取对应的函数地址,所以
					  尽量采用隐式链接的方式.
					2 extern "C"或DEF方式导出的函数,
					  可以正常的使用函数名称获取函数地址.
				3.2.2.4 使用函数
				3.2.2.5 释放动态库
				   FreeLibrary
				   
	4 动态库的变量
	
	  4.1 定义全局变量
	  4.2 导出全局变量
	     4.2.1 __declspec(dllexport)导出
					__declspec(dllexport) int g_nValue1 = 100;
	     4.2.2 DEF文件导出
	        int g_nValue1 = 100;
	        在DEF文件的导出列表中增加
	          g_nValue1 @1 DATA
	  4.3 导入LIB文件
	  4.4 定义导入变量
	     需要使用__declspec(dllimport)定义变量.
	     extern __declspec(dllimport) int g_nValue1;
	  4.5 使用变量
	  
	5 动态库的类
	
	  5.1 创建动态库并定义类
	  5.2 从DLL中导出类
	     在类名称前增加__declspec(dllexport)定义.
	     class __declspec(dllexport) CMath 
			 { ... };
	  5.3 使用时导入LIB文件
	  5.4 导入类
	     在类名称前增加__declspec(dllimport)定义.
	     class __declspec(dllimport) CMath 
			 { ... };
	  5.5 使用类
	  5.6 关于类的导入和导出
	    1) 定义一个宏,例如:
	      #ifdef _DLLCLASS_DLL_
				#define DLLCLASS_EXT __declspec(dllexport)
				#else
				#define DLLCLASS_EXT __declspec(dllimport)
				#endif //_DLLCLASS_DLL_
		  2) 根据编译项目,修改_DLLCLASS_DLL_宏声明
		    对于导出类,需要定义_DLLCLASS_DLL_,
		    否则不需要定义 _DLLCLASS_DLL_ 宏
      3) 类的定义为
        class DLLCLASS_EXT CMath 
        { ... };
        
  6 DllMain 函数
    是DLL文件入口函数.当程序加载或者释放
    动态库的时候,会自动调用这个函数.
     BOOL WINAPI DllMain(
       HINSTANCE hinstDLL,//DLL的句柄
       DWORD fdwReason,//DLL被调用的原因
       LPVOID lpvReserved ); //保留值
     fdwReason - 
       DLL_PROCESS_ATTACH 进程加载
       DLL_THREAD_ATTACH  线程加载
       DLL_THREAD_DETACH  线程卸载
       DLL_THREAD_DETACH  进程卸载
     返回值表示是否加载成功.
    

	    
	  
	  
	 





