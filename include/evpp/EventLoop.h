#ifndef EVPP_EVENTLOOP_H
#define EVPP_EVENTLOOP_H

#include <memory>

namespace evpp {

class TCPAcceptSocket;
class Timer;

class EventLoop
{
public:
	static std::unique_ptr<EventLoop> AllocateSystemEventLoop();

	virtual std::unique_ptr<TCPAcceptSocket> AllocateTCPAcceptSocket() = 0;
	virtual std::unique_ptr<Timer> AllocateTimer() = 0;

	virtual int Run() = 0;
};

} /*namespace evpp*/

#endif /*EVPP_EVENTLOOP_H*/

