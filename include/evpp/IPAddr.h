#ifndef EVPP_IPADDR_H
#define EVPP_IPADDR_H

#ifdef OS_LINUX
#include <arpa/inet.h>
#elif OS_WINDOWS
#include <winsock2.h>
#else
#error Unimplemented OS in evpp/IPAddr.h
#endif

#include <string>

#include <cstdint>

namespace evpp {

class IPAddr
{
public:
	enum class Type {
		IPV4,
		IPV6,
		INVALID
	};

	IPAddr( const char *addr, int port );

	IPAddr()
	  : type( Type::INVALID )
	{ }

	IPAddr( const IPAddr& other ) = default;

	IPAddr( IPAddr&& other ) noexcept = default;

	~IPAddr() noexcept = default;

	IPAddr& operator= ( const IPAddr& other ) {
		type = other.type;
		addrStr = other.addrStr;
		sockaddr = other.sockaddr;

		return *this;
	}

	IPAddr& operator= ( const IPAddr&& other ) noexcept {
		type = other.type;
		addrStr = other.addrStr;
		sockaddr = other.sockaddr;

		return *this;
	}

	static bool isIPAddress( const char *addr );

	bool isValid() const {
		return type != Type::INVALID;
	}

	const void *getNativeAddr() const {
		switch( type ) {
			case Type::IPV4: {
				return &sockaddr.addr4;
			}

			case Type::IPV6: {
				return &sockaddr.addr6;
			}

			default: {
				return nullptr;
			}
		}
	}

	size_t getNativeAddrSize() const {
		switch( type ) {
			case Type::IPV4: {
				return sizeof(addr4type);
			}

			case Type::IPV6: {
				return sizeof(addr6type);
			}

			default: {
				return 0;
			}
		}
	}

	const std::string& asString() const {
		return addrStr;
	}

	int getFamily() const {
		switch( type ) {
			case Type::IPV4: { return AF_INET;  }
			case Type::IPV6: { return AF_INET6; }
			default:         { return -1;       }
		}
	}

	int getDomain() const {
		switch( type ) {
			case Type::IPV4: { return PF_INET;  }
			case Type::IPV6: { return PF_INET6; }
			default:         { return -1;       }
		}
	}

private:
#ifdef OS_LINUX
	using addr4type = struct sockaddr_in;
	using addr6type = struct sockaddr_in6;
#elif OS_WINDOWS
	using addr4type = SOCKADDR_STORAGE;
	using addr6type = SOCKADDR_STORAGE;
#else
#error Unimplemented OS in evpp/IPAddr.h
#endif
 
	Type type;
	std::string addrStr;
	uint16_t port;

	union {
		addr4type addr4;
		addr6type addr6;
	} sockaddr;
};

} /*namespace evpp*/

#endif /*EVPP_IPADDR_H*/

