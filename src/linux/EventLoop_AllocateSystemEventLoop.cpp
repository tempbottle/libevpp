#include "evpp/linux/EPollEventLoopImpl.h"

namespace evpp {

std::unique_ptr<EventLoop> EventLoop::AllocateSystemEventLoop()
{
	return std::unique_ptr<EventLoop>( new evpp::internal::linux::EPollEventLoopImpl() );
}

} /*namespace evpp*/

