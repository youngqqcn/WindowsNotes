#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{

	//MessageBox(NULL, "HelloWorld", "Yqq", MB_OK);
	MessageBox(NULL, lpCmdLine, "Yqq", MB_OK);

	return 0;
}
