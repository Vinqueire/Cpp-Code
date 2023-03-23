#include "pch.h"
#include "mem.h"

void mem::patchEx(BYTE* dst, BYTE* src, unsigned int size, HANDLE hProc)
{
	DWORD oldProtect;
	VirtualProtectEx(hProc, dst, size, PAGE_EXECUTE_READWRITE, &oldProtect);
	WriteProcessMemory(hProc, dst, src, size, 0);
	VirtualProtectEx(hProc, dst, size, oldProtect, &oldProtect);
}

void mem::nopEx(BYTE* dst, unsigned int size, HANDLE hProc)
{
	BYTE* nopArray = new BYTE[size];
	memset(nopArray, 0x90, size);

	patchEx(dst, nopArray, size, hProc);
	delete[] nopArray;
}