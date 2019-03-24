一 线程局部存储 Thread Local Storage

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
       2.2.1 创建TLS索引
         DWORD TlsAlloc(VOID)
         返回一个TLS索引号
       2.2.2 设置值
         BOOL TlsSetValue(
         DWORD dwTlsIndex, //TLS索引
         LPVOID lpTlsValue //保存的值
         );
       2.2.3 获取值
         LPVOID TlsGetValue(
          DWORD dwTlsIndex  //TLS索引
         );
         返回存放在索引内的值
       2.2.4 释放
         BOOL TlsFree(
          DWORD dwTlsIndex   //TLS索引
         );

二 线程同步

  1 多线程的问题
    
    A停止 -> B开始 -〉B停止 -> A开始
    
     当线程停止会保存寄存器的状态。
     当线程开始会恢复寄存器的状态。
     
    AB线程都使用printf的问题:
    A线程调用printf时，printf正在输出
    当中，A挂起，B执行，B线程也调用
    printf输出B的数据,画面会出现A的
    数据输出1部分,然后是B的数据;
    B挂起，A执行, A继续输出自己的数据.
    所以,由于多线程的切换,产生数据混乱.
     
  2 问题的解决 - 同步机制
    2.1 原子锁
    2.2 临界区
    2.3 事件
    2.4 互斥
    2.5 信号量
    2.6 可等候定时器
    
  3 等候多个内核对象事件
    DWORD WaitForMultipleObjects(
     DWORD nCount,//句柄的数量
     CONST HANDLE *lpHandles,//句柄数组
     BOOL fWaitAll, //等候方式
    DWORD dwMilliseconds );//等候时间
    等候方式fWaitAll:
       TRUE - 每个句柄都有事件,解除阻塞
       FALSE - 其中一个句柄有事件,解除阻塞

三 原子锁
  
  1 g_nValue++执行
    线程A通过寄存器完成加法运算,假设
    g_nValue正在加到10000时,线程切换到B,
    A的寄存器中保存10000数字,B从10000
    开始加数据,当B加到15000时,线程切换
    到A,A恢复寄存器的值,A会继续从10000开始
    累加,就将B完成5000的加法覆盖.
    
  2 原子锁
    执行单个指令时,锁定操作,不允许其他
    线程访问.
    
  3 用法
    InterlockedIncrement ++运算
    InterlockedDecrement --运算
    InterlockedCompareExchange ?运算
    
四 临界区
  
  1 临界区作用
    线程在执行代码时,将代码锁定,不允
    许其他线程执行,只有该线程离开后,
    其他线程才能使用这些代码
    
  2 临界区的使用
    2.1 初始化临界区
       VOID InitializeCriticalSection(
       LPCRITICAL_SECTION lpCriticalSection
         //临界区结构地址
       );

    2.2 临界区加锁
       VOID EnterCriticalSection(
  			LPCRITICAL_SECTION lpCriticalSection   // pointer to critical 
          //临界区
		    );

    2.3 临界区解锁
       VOID LeaveCriticalSection(
       LPCRITICAL_SECTION lpCriticalSection 
          // 临界区 
       );
    2.4 释放临界区
       VOID DeleteCriticalSection(
       LPCRITICAL_SECTION lpCriticalSection   
               //临界区
       );
  3 和原子锁相比
    原子锁是一条语句
    临界区可以完成多条语句的锁定.
  
五 事件

  1 事件
    通知的作用,当收到事件时,线程可以执行.
    否则,线程将等候事件发生.
    
  2 事件的用法
    2.1 创建事件
			HANDLE CreateEvent(
       LPSECURITY_ATTRIBUTES lpEventAttributes,
                      //安全属性
       BOOL bManualReset,//重置方式
       BOOL bInitialState, //初始化状态
       LPCTSTR lpName //名称
 			 );
 			返回创建好的事件句柄
 			bManualReset - 事件重置方式, TRUE
 			  手动和FALSE自动重置. 如果为FALSE,
 			  系统在等候到事件后,会自动将事件
 			  重置为无信号状态. 如果为TRUE,我们
 			  必须自己使用ResetEvent重置状态.
      bInitialState - 初始化状态, TRUE为
         有信号,FALSE无信号.
   2.2 等候事件
      WaitForSingleObject/
      WaitForMultipleObjects
    2.3 触发事件
      BOOL SetEvent(
      HANDLE hEvent //事件句柄
      );
    2.4 关闭事件
      CloseHandle
    2.5 重置事件
      BOOL ResetEvent(
       HANDLE hEvent //事件句柄
      );
    2.6 其他函数
      OpenEvent
      PulseEvent
      
六 互斥量 

  1 互斥量
    多个线程同时只能有一个执行.
    
  2 互斥量使用
    2.1 创建互斥
      HANDLE CreateMutex(
        LPSECURITY_ATTRIBUTES lpMutexAttributes,
                       //安全属性
        BOOL bInitialOwner,  
                       //初始化的拥有线程
  			LPCTSTR lpName ); //名称
			bInitialOwner - TRUE表示当前创建互斥
			 量的线程拥有互斥, FALSE为不拥有.
    2.2 等候互斥
       WaitForSingleObject
       WaitForMultipleObjects
    2.3 重置互斥
       ReleaseMutex 
    2.4 关闭互斥
       CloseHandle
    2.5 使用互斥线程,按照谁先等候谁先
       拥有互斥量的规则顺序执行.
    2.6 其他函数
      OpenMutex 打开互斥

七 信号量
   
  1 信号量
    通知的作用,和事件类似.但是与事件不同.
    事件只维护一个值0或者1.
    信号量维护一个变量,0时无信号,大于0有
    信号.
    
  2 信号量的使用
    2.1 创建信号量
    	HANDLE CreateSemaphore(
       LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
                       //安全属性
       LONG lInitialCount,//初始信号量
       LONG lMaximumCount,//最大信号量
       LPCTSTR lpName //命名
	    );
      返回创建好的信号量句柄.
    2.2 等候信号量
      WaitForSingleObject
      WaitForMultipleObjects
    2.3 释放信号
      BOOL ReleaseSemaphore(
       HANDLE hSemaphore, //信号量句柄
       LONG lReleaseCount,//释放信号的数量
       LPLONG lpPreviousCount //释放前的数量
      );
    2.4 关闭信号量
      CloseHandle
    2.5 打开信号量
      OpenSemaphore
      
八 可等候定时器

  1 可等候定时器
    是一个更加精确系统提供的定时器.能够
    达到100ns级别. 
    
  2 定时器的使用
    2.1 创建定时器
    	HANDLE CreateWaitableTimer(
      LPSECURITY_ATTRIBUTES lpTimerAttributes,
                      //安全属性
      BOOL bManualReset,//重置方式
      LPCTSTR lpTimerName //命名
      );
      返回创建好的定时器的句柄
    2.2 设置定时器
      BOOL SetWaitableTimer(
       HANDLE hTimer, //定时器句柄
       const LARGE_INTEGER *pDueTime,
        //定时器第一次触发的时间,100ns级别
       LONG lPeriod, 
        //后续每次触发的间隔,毫秒级别
       PTIMERAPCROUTINE pfnCompletionRoutine,  
        //APC处理函数
       LPVOID lpArgToCompletionRoutine,
        //APC参数
       BOOL fResume ); //休眠标识
       
       pDueTime - 正值,表示绝对时间
          负值,表示相对于现在的时间间隔
       lPeriod  - 0  定时器不再有后续触发
          大于0 按照间隔触发
             
       pDueTime | lPeriod | lPeriod ....
         
    2.3 等候定时器
      WaitForSingleObject
      WaitForMultipleObjects
    2.4 关闭定时器
      CloseHandle
    2.5 APC定时器
      VOID CALLBACK TimerAPCProc(
      LPVOID lpArgToCompletionRoutine   // data value
      DWORD dwTimerLowValue // timer low value
      DWORD dwTimerHighValue   // timer high value
		  );
		2.6 其他
		  OpenWaitableTimer 打开
		  CancelWaitableTimer 取消

 

    
    
    


    
       
   

    
          
    
    
  
  


    
    
    
    
      









