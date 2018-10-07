#include <Windows.h>

static int _Counter = 0;

#ifdef __cplusplus

extern "C" __declspec(dllexport) int __stdcall TestCount(int cnt)
{
	_Counter += cnt;
	return _Counter;
}

extern "C" __declspec(dllexport) LPSTR __stdcall TestLower(LPSTR str, int len)
{
	char* buf = new char[len + 1];
	::lstrcpyA(buf, str);
	::CharLowerA(buf);
	::lstrcpyA(str, buf);
	delete[] buf;
	return str;
}

extern "C" __declspec(dllexport) LPWSTR __stdcall TestFullWidth(LPWSTR str, int len)
{
	WCHAR* buf = new WCHAR[len + 1];
	::LCMapStringW(::GetUserDefaultLCID(), LCMAP_FULLWIDTH, str, len, buf, len);
	buf[len] = L'\0';
	::lstrcpynW(str, buf, len+1);
	delete[] buf;
	return str;
}
#endif


BOOL WINAPI DllMain(HINSTANCE hInstDll, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
