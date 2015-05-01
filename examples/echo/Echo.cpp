#include "evpp/EventLoop.h"

int main()
{
	auto loop = evpp::EventLoop::AllocateSystemEventLoop();

	return loop->Run();
}

