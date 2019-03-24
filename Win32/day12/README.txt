一 Windows卷(Volumn)

  1 卷的获取
    GetLogicalDrives 返回一个DWORD值,这个值
      的每个位代表是否存在相应的卷
    GetLogicalDriveStrings 获取一个所卷的盘符
      的字符串
      DWORD GetLogicalDriveStrings(
  		DWORD nBufferLength,//BUFF的大小
  		LPTSTR lpBuffer );//BUFF的指针
  		BUFF存放数据的格式:
  		  A:\ + 0 + C:\ + 0 ... + 0
    Windows的盘符从A-Z
    
  2 卷的类型
    UINT GetDriveType(
  		LPCTSTR lpRootPathName );//盘符
		返回盘的类型			
 
  3 卷的信息
    BOOL GetVolumeInformation(
  		LPCTSTR lpRootPathName, //盘符
      LPTSTR lpVolumeNameBuffer, //存放卷标的BUFF
      DWORD nVolumeNameSize,//存放卷标的BUFF的长度 length of lpVolumeNameBuffer
      LPDWORD lpVolumeSerialNumber,//卷的序列号
      LPDWORD lpMaximumComponentLength,
              //路径最大的字符串的长度
      LPDWORD lpFileSystemFlags,//文件系统的标识
      LPTSTR lpFileSystemNameBuffer,
          //存放文件系统的名称的BUFF
      DWORD nFileSystemNameSize );//文件系统的BUFF的长度
   
   4 卷的大小
     4.1 获取指定卷的大小
     GetDiskFreeSpace  - 2G以下使用
      BOOL GetDiskFreeSpace(
       LPCTSTR lpRootPathName,//盘符
       LPDWORD lpSectorsPerCluster, //每个簇包含的扇区
       LPDWORD lpBytesPerSector,//每个扇区的字节数
       LPDWORD lpNumberOfFreeClusters,
                             //空余簇的数量
       LPDWORD lpTotalNumberOfClusters  );
                             //总共的簇的数量
     GetDiskFreeSpaceEx- 不限制
       BOOL GetDiskFreeSpaceEx(
  	  	LPCTSTR lpDirectoryName, //盘符
        PULARGE_INTEGER lpFreeBytesAvailableToCaller, // receives the number of bytes on
                 //可用的空余字节数
        PULARGE_INTEGER lpTotalNumberOfBytes,
           //全部的字节数
        PULARGE_INTEGER lpTotalNumberOfFreeBytes
        );     //空余的字节数
    4.2 簇
			文件系统是通过簇管理硬盘,每个簇是由
			连续的几个扇区组成. 例如:1/2/4/8/16/32
			扇区构成1个簇. 
			常见的文件系统和簇的大小,例如:
			   FAT32文件系统 1个簇=8K字节
			   NTFS 文件系统 1个簇=4K字节
			簇是文件系统存放文件数据的最小单位.
			即使文件只有1个字节也需要占用1个簇.
	5 修改卷的名称
	  BOOL SetVolumeLabel(
     LPCTSTR lpRootPathName,//盘符
     LPCTSTR lpVolumeName);//新名称

二 目录
  1 系统和当前目录
    1.1 获取Windows目录
    UINT GetWindowsDirectory(
  		LPTSTR lpBuffer,//BUFF的地址
  		UINT uSize ); //BUFF的长度
  		例如: C:\Windows
    1.2 获取System目录
    UINT GetSystemDirectory(
  		LPTSTR lpBuffer,  //BUFF的地址
  		UINT uSize ); //BUFF的长度
  		例如: C:\Windows\System32
  	1.3 获取临时文件的路径
    DWORD GetTempPath(
  	 DWORD nBufferLength,//BUFF的长度
  	 LPTSTR lpBuffer);    //BUFF的地址
    1.4 当前目录
      应用程序当前正在使用的默认目录
      获取
       DWORD GetCurrentDirectory(
  		 DWORD nBufferLength,  //BUFF的长度
       LPTSTR lpBuffer); //BUFF的地址
      设置
        BOOL SetCurrentDirectory(
  			LPCTSTR lpPathName); //新的当前目录

  2 目录的使用
    2.1 创建目录
       BOOL CreateDirectory(
 			 LPCTSTR lpPathName,//创建的目录的路径
       LPSECURITY_ATTRIBUTES lpSecurityAttributes );安全属性
    2.2 删除目录
       BOOL RemoveDirectory(
  			LPCTSTR lpPathName );//删除的目录的路径
  		 要删除目录中不能包含其它文件等,
  		 只能是空目录.
    2.3 修改目录名称
       BOOL MoveFile(
  	   LPCTSTR lpExistingFileName, //旧名称
       LPCTSTR lpNewFileName); //新名称

三 文件

  1 文件的创建或打开
    HANDLE CreateFile(
	  LPCTSTR lpFileName,//文件路径和名称
	  DWORD dwDesiredAccess, //访问方式
	  DWORD dwShareMode,//共享模式
	  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	                               //安全属性
	  DWORD dwCreationDisposition,  //创建方式
	  DWORD dwFlagsAndAttributes,//文件属性
	  HANDLE hTemplateFile );//拷贝的文件句柄
  2 文件的关闭
    BOOL CloseHandle(
  	HANDLE hObject );//要关闭的句柄

  3 文件的数据写入
    BOOL WriteFile(
     HANDLE hFile, //文件句柄
　　 LPCVOID lpBuffer, //写入数据的BUFF的地址
　　 DWORD nNumberOfBytesToWrite,
　　　　　　//写入数据的BUFF的长度
　　 LPDWORD lpNumberOfBytesWritten,  
　　　　　　//返回被写入数据的长度
  　LPOVERLAPPED lpOverlapped);//默认NULL

  4 文件的数据读取
    BOOL ReadFile(
	  HANDLE hFile, // 文件句柄
	  LPVOID lpBuffer, //读入数据的BUFF的地址
	  DWORD nNumberOfBytesToRead,
	  			//读入数据的BUFF的长度
	  LPDWORD lpNumberOfBytesRead, 
	  　　　//返回被读入数据的长度
	  LPOVERLAPPED lpOverlapped );//默认NULL
  5 获取文件长度	
    DWORD GetFileSize(
  		HANDLE hFile,//文件的句柄
　　  LPDWORD lpFileSizeHigh );//高32位
    返回值是低32位
    文件的长度64位 = (低32位, 高32位 )

  6 设置文件指针
  　DWORD SetFilePointer(
	  HANDLE hFile, //文件的句柄
	  LONG lDistanceToMove, //偏移量，低32位 
	  PLONG lpDistanceToMoveHigh, //偏移量，高
	  DWORD dwMoveMethod );　//相对位置
	　返回值是返回偏移量的低32

  7 拷贝文件
  　BOOL CopyFile(
    LPCTSTR lpExistingFileName,//源
　  LPCTSTR lpNewFileName,  //目的
  　BOOL bFailIfExists );
  　　//是否覆盖目的同名文件，FALSE为覆盖
  8 删除文件
    BOOL DeleteFile(
  　　LPCTSTR lpFileName );//要删除的文件

　9 文件的属性
　　9.1 GetFileAttributes
     DWORD GetFileAttributes(
      LPCTSTR lpFileName );文件名
　　返回值是获取到的文件的属性标示
 　 9.2 GetFileAttributesEx
     BOOL GetFileAttributesEx(
      LPCTSTR lpFileName,//文件名
      GET_FILEEX_INFO_LEVELS fInfoLevelId, 
              //获取文件属性信息的级别
  　　LPVOID lpFileInformation 
  　　　　　  //对应级别的数据结构的地址
　　　);
    9.3 设置文件属性
     BOOL SetFileAttributes(
  　　　LPCTSTR lpFileName,  //文件名 pointer to filename
  　　DWORD dwFileAttributes  ); //属性标示
  
四 文件的查找
　
	1 查找文件
	　HANDLE FindFirstFile(
     LPCTSTR lpFileName,//查找的路径
　　 LPWIN32_FIND_DATA lpFindFileData　//返回查找信息
　　);
　　返回值 - 查找句柄 
	2 获取查找到的结果
	  BOOL FindNextFile(
     HANDLE hFindFile,  //查找句柄
    LPWIN32_FIND_DATA lpFindFileData 
                     //返回查找信息
    );
    返回值 - 成功是TRUE
	3 关闭查找
    BOOL FindClose(
     HANDLE hFindFile   //查找句柄
    );
    
  4 关于查找结果排序，需要自己增加排序
  　功能。






  
  

  



			
	

 


    
  









