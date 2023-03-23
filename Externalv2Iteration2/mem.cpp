#include "pch.h"
#include "mem.h"

void mem::patchEx(BYTE* dst, BYTE* src, unsigned int size, HANDLE hProc)
{
	DWORD oldProtect;
	VirtualProtectEx(hProc, dst, size, PAGE_EXECUTE_READWRITE, &oldProtect);
	WriteProcessMemory(hProc, dst, src, size, 0);
	VirtualProtect(hProc, size, oldProtect, &oldProtect);
}

void mem::nopEx(BYTE* dst, unsigned int size, HANDLE hProc)
{
	BYTE* nopArr = new BYTE[size];
	memset(nopArr, 0x90, size);

	patchEx(dst, nopArr, size, hProc);
	delete[] nopArr;
}