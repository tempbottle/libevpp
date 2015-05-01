#ifndef EVPP_LINUX_EPOLLEVENTLOOPIMPL_H
#define EVPP_LINUX_EPOLLEVENTLOOPIMPL_H

#include "evpp/EventLoop.h"
#include "evpp/TCPAcceptSocket.h"
#include "evpp/Timer.h"

namespace evpp { namespace internal { namespace linux {

class EPollEventLoopImpl : public EventLoop
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

}}} /*namespace evpp::internal::linux*/

#endif /*EVPP_LINUX_EPOLLEVENTLOOPIMPL_H*/

