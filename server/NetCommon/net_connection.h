#pragma once

#include "net_common.h"
#include "net_tsqueue.h"
#include "net_message.h"


namespace olc
{
	namespace net
	{
		template<typename T>
		class connection : public std::enable_shared_from_this<connection<T>>
		{
		public:
			connection()
			{}

			virtual ~connection()
			{}

		public:
			bool ConnectToServer();
			bool Disconnect();
			bool IsConnected() const;

			bool Send(const message<T>& msg);

		protected:
			asio::ip::tcp::socket m_socket;
			asio::io_context& m_asioContext;
			tsqueue<message<T>> m_qMessageOut;
			tsqueue<owned_message<T>> m_qMessageIn;
		};
	}
}