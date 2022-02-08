// 包含windows头文件, 其中含有编写Windows应用程序所需的所有Win32API结构体,数据类型以及函数的声明
#include <windows.h>

// 用于指认所创建主窗口的句柄
HWND ghMainWnd = 0;

// 封装初始化windows应用程序所需的代码. 如果初始化成功, 该函数返回true, 否则返回false
bool InitWindowsApp(HINSTANCE instanceHandle, int show);

// 封装消息循环代码
int Run();

// 窗口过程会处理窗口所接收到的消息
LRESULT CALLBACK WndProc(HWND hWnd,UINT msg, WPARAM wParam, LPARAM lParam);

// 在windows应用程序中WinMain函数就相当于大多数语言中的main()函数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow) {
	// 首先将hInstance 和 nShowCmd 作为参数来调用封装函数(InitWindowsApp), 用以创建和初始化应用程序的主窗口
	if (!InitWindowsApp(hInstance, nCmdShow)) {
		return 0;
	}

	// 一旦将创建好的应用程序初始化完毕后,我们就可以开启消息循环了. 随后, 消息循环就会维持运转, 直至接收到的消息WM_QUIT--这表示此应用程序被关闭,该终止运行了
	return Run();
}

bool InitWindowsApp(HINSTANCE instanceHandle, int show)
{
	// 第一项任务便是通过填写WNDCLASS结构体, 并根据其中描述的特征来创建一个窗口
	WNDCLASS wc;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = instanceHandle;
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = 0;
	wc.lpszClassName = L"BasicWndClass";


	return false;
}
