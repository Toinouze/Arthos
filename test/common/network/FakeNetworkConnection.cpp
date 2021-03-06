#include "FakeNetworkConnection.h"

void FakeNetworkConnection::read(VoidCallback<Bytes&> onBytesReceived_) {
    onBytesReceived = onBytesReceived_;
    startedReading = true;
}

void FakeNetworkConnection::send(Bytes& bytes) {
    sentBytes.push_back(bytes);
}

void FakeNetworkConnection::simulateReceivedBytes(Bytes bytes) {
    onBytesReceived(bytes);
}