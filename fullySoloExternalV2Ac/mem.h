#pragma once

#include "pch.h"

namespace mem
{
	void patchEx(BYTE* dst, BYTE* src, unsigned int size, HANDLE hProc);

	void nopEx(BYTE* dst, unsigned int size, HANDLE hProc);
}