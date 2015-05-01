#include "evpp/windows/Win32EventLoopImpl.h"

namespace evpp {

std::unique_ptr<EventLoop> EventLoop::AllocateSystemEventLoop()
{
	return std::unique_ptr<EventLoop>( new evpp::internal::windows::Win32EventLoopImpl() );
}

} /*namespace evpp*/

