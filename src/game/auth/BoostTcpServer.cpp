#include "BoostTcpServer.h"
#include <boost/asio.hpp>
#include <iostream>

BoostTcpServer::BoostTcpServer() {
}

BoostTcpServer::~BoostTcpServer() {
}

typedef struct AUTH_LOGON_CHALLENGE_C
{

    std::uint8_t cmd;
    std::uint8_t error;
    std::uint16_t size;
    std::uint8_t gamename[4];
    std::uint8_t version[3];
    std::uint8_t build_1;
    std::uint8_t build_2;
    std::uint8_t platform[4];
    std::uint8_t os[4];
    std::uint8_t country[4];
    std::uint32_t timezone_bias;
    std::uint32_t ip;
    std::uint8_t I_len;

    /*
     * std::uint8_t opCode;
    std::uint8_t error;
    std::uint8_t size_1;
    std::uint8_t size_2;
    std::uint8_t gamename_1;
    std::uint8_t gamename_2;
    std::uint8_t gamename_3;
    std::uint8_t gamename_4;
    std::uint8_t version_1;
    std::uint8_t version_2;
    std::uint8_t version_3;
    std::uint8_t build;
    std::uint8_t platform_1;
    std::uint8_t platform_2;
    std::uint8_t platform_3;
    std::uint8_t platform_4;
    std::uint8_t os_1;
    std::uint8_t os_2;
    std::uint8_t os_3;
    std::uint8_t os_4;
    std::uint8_t country_1;
    std::uint8_t country_2;
    std::uint8_t country_3;
    std::uint8_t country_4;
    std::uint8_t timezone_bias_1;
    std::uint8_t timezone_bias_2;
    std::uint8_t timezone_bias_3;
    std::uint8_t timezone_bias_4;
    std::uint8_t ip_1;
    std::uint8_t ip_2;
    std::uint8_t ip_3;
    std::uint8_t ip_4;
    std::uint8_t I_len;
     */

} sAuthLogonChallenge_C;

void BoostTcpServer::startAcceptingConnections(std::string ip, int port, std::function<void(std::vector<std::uint8_t>)> callback) {
    boost::asio::ip::tcp::acceptor acceptor((*new boost::asio::io_service()), boost::asio::ip::tcp::endpoint(boost::asio::ip::address::from_string(ip), port));
    boost::asio::ip::tcp::iostream stream;

    acceptor.accept(*stream.rdbuf());

    // Read first bit : it's the command
    //

    std::vector<uint8_t> buf;

    std::for_each(std::istreambuf_iterator<char>(stream),
                  std::istreambuf_iterator<char>(),
                  [&buf](const char c){
                      buf.push_back(c);
                  });
    callback(buf);
/*
    stream.read(reinterpret_cast<char *>(&test.opCode), 1);
    stream.read(reinterpret_cast<char *>(&test.error), 1);
    stream.read(reinterpret_cast<char *>(&test.size_1), 1);
    stream.read(reinterpret_cast<char *>(&test.size_2), 1);
    stream.read(reinterpret_cast<char *>(&test.gamename_1), 1);
    stream.read(reinterpret_cast<char *>(&test.gamename_2), 1);
    stream.read(reinterpret_cast<char *>(&test.gamename_3), 1);
    stream.read(reinterpret_cast<char *>(&test.gamename_4), 1);
    stream.read(reinterpret_cast<char *>(&test.version_1), 1);
    stream.read(reinterpret_cast<char *>(&test.version_2), 1);
    stream.read(reinterpret_cast<char *>(&test.version_3), 1);
    stream.read(reinterpret_cast<char *>(&test.build_1), 1);
    stream.read(reinterpret_cast<char *>(&test.build_2), 1);
    stream.read(reinterpret_cast<char *>(&test.platform_1), 1);
    stream.read(reinterpret_cast<char *>(&test.platform_2), 1);
    stream.read(reinterpret_cast<char *>(&test.platform_3), 1);
    stream.read(reinterpret_cast<char *>(&test.platform_4), 1);
    stream.read(reinterpret_cast<char *>(&test.os_1), 1);
    stream.read(reinterpret_cast<char *>(&test.os_2), 1);
    stream.read(reinterpret_cast<char *>(&test.os_3), 1);
    stream.read(reinterpret_cast<char *>(&test.os_4), 1);
    stream.read(reinterpret_cast<char *>(&test.country_1), 1);
    stream.read(reinterpret_cast<char *>(&test.country_2), 1);
    stream.read(reinterpret_cast<char *>(&test.country_3), 1);
    stream.read(reinterpret_cast<char *>(&test.country_4), 1);
    stream.read(reinterpret_cast<char *>(&test.timezone_bias_1), 1);
    stream.read(reinterpret_cast<char *>(&test.timezone_bias_2), 1);
    stream.read(reinterpret_cast<char *>(&test.timezone_bias_3), 1);
    stream.read(reinterpret_cast<char *>(&test.timezone_bias_4), 1);
    stream.read(reinterpret_cast<char *>(&test.ip_1), 1);
    stream.read(reinterpret_cast<char *>(&test.ip_2), 1);
    stream.read(reinterpret_cast<char *>(&test.ip_3), 1);
    stream.read(reinterpret_cast<char *>(&test.ip_4), 1);
    stream.read(reinterpret_cast<char *>(&test.I_len), 1);
*/
}


void BoostTcpServer::stopAcceptingConnections() {

}

