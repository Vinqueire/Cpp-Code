#include "memory.h"
#include <thread>
#include <iostream>

// clients dlls
namespace offsets
{
	constexpr ::std::ptrdiff_t localPlayer = 0xDEA964;
	constexpr ::std::ptrdiff_t entityList = 0x4DFFEF4;
	constexpr ::std::ptrdiff_t glowObjectManager = 0x535A9C8;

	// entities
	constexpr ::std::ptrdiff_t teamNum = 0xF4;
	constexpr ::std::ptrdiff_t glowIndex = 0x10488;

}

struct colours
{
	constexpr colours(float r, float g, float b, float a = 1.f) noexcept :
		r(r), g(g), b(b), a(a) {}

	float r, g, b, a;
};

int main()
{
	auto mem = Memory{ "csgo.exe" };

	const auto client = mem.GetModuleAddress("client.dll");
	std::cout << "client.dll -> " << "0x" << std::hex << client << std::dec << std::endl;

	const auto color = colours{ 0.f, 1.f, 1.f }; // Here you can change colours of the glow :)


	while (true)
	{
		const auto localPlayer = mem.Read<std::uintptr_t>(client + offsets::localPlayer);
		const auto glowObjectManager = mem.Read<std::uintptr_t>(client + offsets::glowObjectManager);

		for (auto i = 0; i < 64; ++i)
		{
			const auto entity = mem.Read<std::uintptr_t>(client + offsets::entityList + i * 0x10);

			if (mem.Read<std::uintptr_t>(entity + offsets::teamNum) == mem.Read<std::uintptr_t>(localPlayer + offsets::teamNum))
				continue;

			const auto glowIndex = mem.Read<std::int32_t>(entity + offsets::glowIndex);

			mem.Write<colours>(glowObjectManager + (glowIndex * 0x38) + 0x8, color); // color

			mem.Write<bool>(glowObjectManager + (glowIndex * 0x38) + 0x27, true);
			mem.Write<bool>(glowObjectManager + (glowIndex * 0x38) + 0x28, true);
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}

	return 0;
}