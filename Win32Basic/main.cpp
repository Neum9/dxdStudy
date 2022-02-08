// ����windowsͷ�ļ�, ���к��б�дWindowsӦ�ó������������Win32API�ṹ��,���������Լ�����������
#include <windows.h>

// ����ָ�������������ڵľ��
HWND ghMainWnd = 0;

// ��װ��ʼ��windowsӦ�ó�������Ĵ���. �����ʼ���ɹ�, �ú�������true, ���򷵻�false
bool InitWindowsApp(HINSTANCE instanceHandle, int show);

// ��װ��Ϣѭ������
int Run();

// ���ڹ��̻ᴦ���������յ�����Ϣ
LRESULT CALLBACK WndProc(HWND hWnd,UINT msg, WPARAM wParam, LPARAM lParam);

// ��windowsӦ�ó�����WinMain�������൱�ڴ���������е�main()����
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow) {
	// ���Ƚ�hInstance �� nShowCmd ��Ϊ���������÷�װ����(InitWindowsApp), ���Դ����ͳ�ʼ��Ӧ�ó����������
	if (!InitWindowsApp(hInstance, nCmdShow)) {
		return 0;
	}

	// һ���������õ�Ӧ�ó����ʼ����Ϻ�,���ǾͿ��Կ�����Ϣѭ����. ���, ��Ϣѭ���ͻ�ά����ת, ֱ�����յ�����ϢWM_QUIT--���ʾ��Ӧ�ó��򱻹ر�,����ֹ������
	return Run();
}

bool InitWindowsApp(HINSTANCE instanceHandle, int show)
{
	// ��һ���������ͨ����дWNDCLASS�ṹ��, ��������������������������һ������
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
