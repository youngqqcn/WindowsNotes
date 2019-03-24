一 Windows进程
	
	1 Windows进程
    进程一个容器，包含了应用程序实例的各种
    资源。Windows多任务的操作系统，因此可以
    同时执行多个进程。
    
  2 Windows进程的一些特点
    2.1 进程中包含了执行代码等资源。
    2.2 进程都具有私有的地址空间。
    2.3 每个进程都有一个ID，标识进程。
    2.4 每个进程都有自己的安全属性
    2.5 至少要包含一个可以执行的线程。
    
二 进程的环境

  1 环境信息的获取
    获取：
    LPVOID GetEnvironmentStrings(VOID)
    返回值是获取到的所有环境信息
    释放：
    BOOL FreeEnvironmentStrings(  
     LPTSTR lpszEnvironmentBlock )
    
  2 环境变量的获取和设置
    获取：
     DWORD GetEnvironmentVariable(
     LPCTSTR lpName,  //变量名称
     LPTSTR lpBuffer, //数据BUFF
     DWORD nSize      //BUFF的长度
    );
    返回值是获取到的字符串的长度
    设置：
    BOOL SetEnvironmentVariable(
     LPCTSTR lpName, //变量名称
     LPCTSTR lpValue  //变量的值
    );
    
三 进程的信息
   1 进程ID和句柄
     GetCurrentProcessID 获取进程的ID
     GetCurrentProcess 获取进程的句柄,
         返回值为-1,是当前进程的伪句柄.
         如果想获取当前进程的实际句柄
         需要使用OpenProcess函数.
   2 打开进程
     HANDLE OpenProcess(
       DWORD dwDesiredAccess, //访问模式
       BOOL bInheritHandle, //继承标识
       DWORD dwProcessId //进程ID
     );
		 返回进程的句柄
   3 获取进程的所使用的所有模块(EXE或DLL)
     使用PSAPI函数.
      BOOL EnumProcessModules(
       HANDLE hProcess,//进程句柄
       HMODULE * lphModule,//模块的数组
       DWORD cb, //数组的长度
       LPDWORD lpcbNeeded //获取到数据的字节数
      );

四 进程的使用
  1 创建进程
     WinExec 16位,现在不使用
     ShellExecute 执行打开文件等操作.
     CreateProcess 执行一个EXE可执行文件.创建
        一个进程以及它的主线程.
     BOOL CreateProcess(
  		LPCTSTR lpApplicationName,
                         //应用程序路径名
      LPTSTR lpCommandLine, //命令行
      LPSECURITY_ATTRIBUTES lpProcessAttributes,  
          //进程安全属性
      LPSECURITY_ATTRIBUTES lpThreadAttributes, 
          //线程安全属性
      BOOL bInheritHandles, //句柄继承标识
      DWORD dwCreationFlags, //创建标识
      LPVOID lpEnvironment, //环境块
      LPCTSTR lpCurrentDirectory,//当前目录
      LPSTARTUPINFO lpStartupInfo,//启动参数
      LPPROCESS_INFORMATION lpProcessInformation  
        //进程信息
      );
      当进程创建成功,可以从进程信息中获取创建
      好的进程句柄\ID等.
      如果执行程序是16的程序,那么只能使用
      lpCommandLine设置执行程序路径.
  2 打开进程
     OpenProcess
  3 结束进程
     VOID ExitProcess( UINT uExitCode );
     BOOL TerminateProcess(
      HANDLE hProcess, //进程句柄
      UINT uExitCode );  //结束代码
  4 等候进程结束
     DWORD WaitForSingleObject(
      HANDLE hHandle, //等候的句柄
      DWORD dwMilliseconds );//等候的时间,毫秒
    阻塞函数,当运行时,会在等候的时间的时间内,
    等待句柄的信号.
    
五 Windows作业(Job)

  1 Windows作业
    实际是一个进程组. 可以对作业设置权限,一旦
    进程加入到作业之内,进程的权限将被作业限制.
    
  2 作业的使用
    需要NT5.0以上支持,所有在Windows.h前定义 
      #define _WIN32_WINNT 0x0500
    2.1 创建一个作业
     HANDLE CreateJobObject(
       LPSECURITY_ATTRIBUTES lpJobAttributes,
       		// 安全属性
       LPCTSTR lpName ); //名称
     返回创建的Job句柄
    2.2 设置作业权限
     BOOL SetInformationJobObject(
      HANDLE hJob,//Job句柄
			JOBOBJECTINFOCLASS JobObjectInformationClass,
       //Job权限的类型
			LPVOID lpJobObjectInformation,
       //类型所对应的数据结构的地址
			DWORD cbJobObjectInformationLength
       //类型所对应的数据结构的长度
			);
    2.3 将进程加入作业
       BOOL AssignProcessToJobObject(
        HANDLE hJob, //作业句柄
        HANDLE hProcess );//进程句柄
    2.4 关闭作业
       CloseHandle
    2.5 结束作业
       使用TerminateJobObject结束作业.
       但是并不是所有情况下,作业内的进程
       都能被结束.
       
六 Windows线程

  1 Windows线程
    Windows进程中可以执行代码的实体,Windows
    系统可以调度的执行代码.一个进程中至少有
    一个或多个线程. 每个线程是进程的一个任务
    分支.
    
  2 线程的特点
    2.1 每个线程有一个ID.
    2.2 每个线程有自己的安全属性
    2.3 每个线程有自己的内存栈.
    
  3 进程和线程多任务
    多进程实现的多任务: 由于进程地址空间
      是属于各自私有, 内存和资源不能共享.
    多线程实现的多任务: 由于线程都是位于
      同一个进程的地址空间,内存和资源可以
      共享.
      
  4 线程的执行
    线程的执行方式采用轮询方式执行.
       A -> B -> A -> B.....
       
七 线程的使用

  1 定义线程处理函数
    DWORD WINAPI ThreadProc(
     LPVOID lpParameter );  //线程参数
  2 创建线程
    HANDLE CreateThread(
    LPSECURITY_ATTRIBUTES lpThreadAttributes,  
      //安全属性
    DWORD dwStackSize, //初始化栈的大小,缺省为0
    LPTHREAD_START_ROUTINE lpStartAddress, 
        //线程的函数指针
    LPVOID lpParameter, //线程参数
    DWORD dwCreationFlags,  //创建方式
    LPDWORD lpThreadId //返回线程ID
    );
    返回值是创建好的线程的句柄.
  3 结束线程
    ExitThread
    TerminateThread
  4 线程挂起和执行
    挂起线程
      DWORD SuspendThread( HANDLE hThread  ); 
    执行线程
     DWORD ResumeThread( HANDLE hThread  );
  5 等候线程的结束
    可以使用 WaitForSingleObject 等候线程的
    结束。
  6 关闭线程句柄
    CloseHandle

八 线程局部存储 Thread Local Storage

  1 由于多个线程使用同一个变量，各个线程
    都对变量进行操作，那么变量的值会被不同
    线程操作覆盖。
         
      通常   变量A   <-- 线程A
                     <-- 线程B
                 
      TLS    变量A   <-- 线程A
             变量A   <-- 线程B
             
   2 TLS的使用
     2.1 使用关键字 __declspec(thread) 
        __declspec(thread) CHAR * g_pszText2 = NULL;
     2.2 TLS相关API
         TlsAlloc
         TlsSetValue 
         TlsGetValue
         TlsFree 
    

    



    


   
 

    
    
    


    







