window.exe : window.obj
	cl window.c /c
	link window.obj user32.lib