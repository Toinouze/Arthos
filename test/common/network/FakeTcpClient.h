#pragma once

#include <common/network/TcpClient.h>

class FakeTcpClient : public TcpClient {
public:
    void connect(std::string ip, int port, std::function<void(std::vector<uint8>)> callback) override {

    }
};