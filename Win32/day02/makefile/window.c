#include <windows.h>




int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
				   LPSTR pszCmdLine,
				   int nShowCmd
			)
{
	MessageBox(NULL, "HelloWorld", "HelloWorld", MB_OKCANCEL);

	return 0 ;
}