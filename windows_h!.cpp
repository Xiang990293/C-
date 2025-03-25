#include <stdio.h>
#include <windows.h>
using namespace std;

//之後要把這行銷掉 
#pragma comment(linker, "/subsystem:console /entry:WinMainCRTStartup")


/*
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wndclass = {sizeof(wndclass), 
		CS_HREDRAW|CS_VREDRAW,                //style
		WndProc,                             
		0, 0, hInstance,                     
		LoadIcon(NULL, IDI_APPLICATION),      //hIcon
		LoadCursor(NULL,IDC_ARROW),           //hCursor
		(HBRUSH)(COLOR_WINDOW+1),             //hbrBackground
		NULL,                                 //hMenu
		L"window", 
		LoadIcon(NULL, IDI_APPLICATION)};     //hIconSm

	RegisterClassEx(&wndclass);

	HWND hWnd = CreateWindowEx(
		0,                              //dwExStyle 
		L"window", L"window",             //視窗標題
		WS_OVERLAPPEDWINDOW,            //dwStyle
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, 
		NULL, NULL, hInstance, NULL);

    ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	printf("TestWindow!!\n");
    printf("argc = %d\n", __argc); 
    printf("argv1 = %s\n", __argv[1]);
    printf("argv2 = %s\n", __argv[2]);

	MSG msg;
	while( GetMessage(&msg, NULL, 0, 0 ))
	{
	    TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT ps;
	switch(msg)
	{
		case WM_PAINT:
			hDC = BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			return 0;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}*/

