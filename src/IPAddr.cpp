#include "evpp/IPAddr.h"

#include <cstdio>
#include <cstring>

namespace evpp {

IPAddr::IPAddr( const char *addrStr, int port )
  : type( Type::INVALID )
  , addrStr( addrStr )
  , port( port )
{
	memset( &sockaddr, 0, sizeof(sockaddr) );

	if( 1 == inet_pton(AF_INET, addrStr, &sockaddr.addr4.sin_addr) ) {
		sockaddr.addr4.sin_family = AF_INET;
		sockaddr.addr4.sin_port = htons( port );
		type = Type::IPV4;
	}
	else if( 1 == inet_pton(AF_INET6, addrStr, &sockaddr.addr6.sin6_addr) ) {
		sockaddr.addr6.sin6_family = AF_INET6;
		sockaddr.addr6.sin6_port = htons( port );
		type = Type::IPV6;
	}
}

} /*namespace evpp*/

