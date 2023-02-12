#include "memory.h"
#include <thread>

namespace offsets
{
	constexpr ::std::ptrdiff_t localPlayer = 0xDEA964;
	constexpr ::std::ptrdiff_t flags = 0x104;
	constexpr ::std::ptrdiff_t forceJump = 0x52BBC7C;
}
	
int main()
{
	auto mem = Memory("csgo.exe");

	std::cout << "Process id: " << mem.GetProcessId() << std::endl;

	const auto client = mem.GetModuleAdress("client.dll");
	std::cout << "client.dll -> " << "0x" << std::hex << client << std::dec << std::endl;

	while (1)
	{
		const auto localPlayer = mem.Read<uintptr_t>(client + offsets::localPlayer);

		if (localPlayer)
		{
			const auto onGround = mem.Read<bool>(localPlayer + offsets::flags);

			if (GetAsyncKeyState(VK_SPACE) && onGround & (1 << 0))
			{
				mem.Write<BYTE>(client + offsets::forceJump, 6);
			}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(5));
	}
}