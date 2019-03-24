Windows的内存管理

一 地址空间

  1 地址空间
  
  一个程序最大的寻址范围。对于Win32操作系统
  最大的寻址范围是2的32次方，0-0xFFFFFFFF。
  这个寻址范围由CPU决定。CPU的寻址范围越大，
  程序难度降低。
  
  2 地址空间的划分
    通常情况下：
    2.1 用户空间 
       地址范围 0 - 0x7FFFFFFF（2G），运行
       应用程序代码、数据等等。
       2.2.1 空指针区(NULL区)
         地址范围 0 - 0x0000FFFF
       2.2.2 用户区
         地址范围 0x00010000 - 0x7FFEFFFF
       2.2.3 64K禁入区
         地址范围 0x7FFEFFFF - 0x7FFFFFFF
    2.2 内核空间 
       地址范围 0x80000000 - 0xFFFFFFFF，被
       系统使用，运行驱动、内核的数据和代码。
  
二 地址映射

  1 区域
    区域指一段连续的地址空间，区域的粒度和
    CPU的粒度、操作系统相关。目前通常都是以
    64K粒度存在，地址的对齐方式是以64K为边界。
    区域的状态：
      1）空闲 - 空闲的，可以被使用
      2）私有 - 已经被占有，但是还未使用
      3）映像 - 程序的代码使用
      4）映射 - 程序的数据使用
      
  2 物理内存
    实际可以使用的物理存储器。
    
	3 虚拟内存
	  使用硬盘空间作为内存扩展，也可以当作
	  物理内存使用。
	  
	4 内存页
		操作系统使用内存页的方式管理物理内存
		和虚拟内存。通常情况下，内存页的大小
		为4K或者8K。
		每个内存页具有自己的状态，例如
		  只读/可写/可执行
		  
  5 页目表
    用于管理内存页的表。
    页目  - 页表   - 内存页
                   - 内存页 
          - 页表
          - 页表
          
    指针 31 -----22 21-------12 11-----------0
            页目       页表         偏移量
            
  6 地址空间的访问
    
    6.1 地址空间已经存在映射好的物理内存，
        直接使用，返回。
    6.2 系统去虚拟内存中，查找对应的内存页。
        如果未找到，系统错误返回。
    6.3 系统将虚拟内存的内存页切换到物理
        内存当中。
    6.4 返回实际物理内存地址，使用数据。
    
  7 内存的使用
    7.1 虚拟内存
       适合对于大内存分配使用。一般情况下
       如果分配的内存大于1M，应该使用虚拟
       内存分配方式。
    7.2 堆内存
       适合对于小内存分配使用。一般情况下
       对于小于1M的内存分配使用。例如
       malloc/new。
    7.3 堆栈内存
       系统维护的内存区。    
       
二 虚拟内存
  1 虚拟内存
    常用于大内存分配，分配的速度快，可以
    根据需要指定分配方式。
  2 虚拟内存的使用
    2.1 分配内存 
    LPVOID VirtualAlloc(
		LPVOID lpAddress,//NULL或者用于提交的内存地址
    DWORD dwSize,//分配的大小，一般是页倍数
    DWORD flAllocationType,//分配的方式
    DWORD flProtect );//内存访问方式
    分配的最大空间小于用户区间（通常是2G）。
    2.2 提交内存
       VirtualAlloc使用MEM_COMMIT方式。例如：
       	pszBuf = (CHAR *)
				VirtualAlloc( 
				  pszBuf, //需要提交内存地址
					1024 * 1024 * 1024,
					MEM_COMMIT,
					PAGE_READWRITE );
    2.3 使用内存
    2.4 释放内存
    BOOL VirtualFree(
       LPVOID lpAddress,//释放的内存
       DWORD dwSize, //释放的大小
       DWORD dwFreeType ); //释放的方式
       
  3 内存信息
    VOID GlobalMemoryStatus(
    LPMEMORYSTATUS lpBuffer  //获取内存信息
    ); 
    
三 堆内存

  1 堆内存的特点
    一般分配小数据内存，一般小于1M数据使用
    堆内存分配。
    一般程序执行后，会有一个默认堆，这个堆
    的大小一般为1M。一个程序可以多个堆。通
    过堆内存管理器来管理堆中的内存。
    内存分配速度比VirtualAlloc慢。
    
  2 堆内存的使用
    2.1 创建堆
      HANDLE HeapCreate(
      DWORD flOptions,//创建标示
      DWORD dwInitialSize,  //初始化大小
      DWORD dwMaximumSize ); //最大大小
    2.2 分配内存
      LPVOID HeapAlloc(
      HANDLE hHeap,  //堆的句柄
      DWORD dwFlags, //分配标示
      DWORD dwBytes );  //分配大小
    2.3 使用内存
    2.4 释放内存
      BOOL HeapFree(
      HANDLE hHeap,  //堆的句柄
      DWORD dwFlags, //释放标示
      LPVOID lpMem );  //释放的地址
    2.5 释放堆
      BOOL HeapDestroy(
      HANDLE hHeap );  //堆的句柄

  3 malloc/HeapAlloc/VirtualAlloc
    malloc内部调用HeapAlloc。
    HeapAlloc内部调用的VirtualAlloc。
    malloc分配内存：
     例如100字节
     | 内存头 | 100字节 | 4字节尾部标示 |
     所用使用malloc分配的内存,会使用这个
     内存头构成链表.
     
  4 堆的信息
    GetProcessHeap 当前进程默认堆的句柄
    GetProcessHeaps 当前进程所有堆的句柄
    
四 堆栈内存
  堆栈都是小数据的使用,系统维护,栈的大小
  一般在1M左右. 
  例如,Windows下可以使用_alloca函数从栈上
  分配内存.
  
 
五 内存映射文件

  1 内存映射文件
    可以将文件映射成内存,我们可以像使用内
    存一样使用文件.
    
  2 内存映射文件的使用
    2.1 创建或打开一个文件
    	 CreateFile
    2.2 创建内存映射文件
      HANDLE CreateFileMapping(
  		HANDLE hFile, //文件句柄
      LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
                             //安全属性
      DWORD flProtect, //保护模式
      DWORD dwMaximumSizeHigh,//大小的高32位
      DWORD dwMaximumSizeLow,    //大小的低32位
      LPCTSTR lpName ); //文件映射内核对象的名称
    2.3 映射成内存地址
    	 LPVOID MapViewOfFile(
       HANDLE hFileMappingObject, //文件映射句柄
       DWORD dwDesiredAccess, //访问模式
       DWORD dwFileOffsetHigh, //地址偏移高32位
       DWORD dwFileOffsetLow,//地址偏移低32位
       DWORD dwNumberOfBytesToMap ); //要映射的字节数

    2.4 使用内存
    2.5 卸载映射
       BOOL UnmapViewOfFile(
  		  LPCVOID lpBaseAddress //卸载的地址
       );
    2.6 关闭内存映射文件
       CloseHandle
    2.7 文件关闭
       CloseHandle
       






