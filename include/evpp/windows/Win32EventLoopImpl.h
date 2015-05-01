#ifndef EVPP_WINDOWS_WIN32EVENTLOOPIMPL_H
#define EVPP_WINDOWS_WIN32EVENTLOOPIMPL_H

#include "evpp/EventLoop.h"
#include "evpp/TCPAcceptSocket.h"
#include "evpp/Timer.h"

namespace evpp { namespace internal { namespace windows {

class Win32EventLoopImpl : public EventLoop
{
private:
	std::unique_ptr<TCPAcceptSocket> AllocateTCPAcceptSocket() override final {
		return std::unique_ptr<TCPAcceptSocket>( nullptr );
	}

	std::unique_ptr<Timer> AllocateTimer() override final {
		return std::unique_ptr<Timer>( nullptr );
	}

	int Run() override final {
		return 1;
	}
};

}}} /*namespace evpp::internal::windows*/

#endif /*EVPP_WINDOWS_EPOLLEVENTLOOPIMPL_H*/

