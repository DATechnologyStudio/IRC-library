/*!
 * \file irc/constructor.hpp
 * \brief 这个文件实现了构造函数和析构函数。
 * \author 吞噬黑洞的数据（745275633）
 */

#ifndef DA_IRC_CONSTRUCTOR_HPP
#define DA_IRC_CONSTRUCTOR_HPP

#include <irc/main.hpp>
#include <boost/make_shared.hpp>

namespace DA
{

irc::irc()
{
	sock = boost::make_shared<boost::asio::ip::tcp::socket>(ioser);
}

irc::~irc()
{
	quit();
}

irc::irc(std::string name, std::string port)
{
	sock = boost::make_shared<boost::asio::ip::tcp::socket>(ioser);
	boost::system::error_code ec;
	resolv_connec_v2(name, port, ec);
	DA_IRC_THROW_ERROR(ec);
}

}

#endif
