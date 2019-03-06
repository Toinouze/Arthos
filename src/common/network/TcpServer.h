#pragma once
#include <functional>
#include <vector>
#include "common/type/Numbers.h"

class TcpServer {
public:
    virtual void startAcceptingConnections(int port, std::function<void(std::vector<uint8>)> callback) = 0;
    virtual void stopAcceptingConnections() = 0;
    virtual ~TcpServer() {};
};