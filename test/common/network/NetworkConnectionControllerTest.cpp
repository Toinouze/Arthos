#include <gtest/gtest.h>
#include <common/network/NetworkConnectionController.h>
#include <game/world/WorldCommandsMap.h>
#include "FakeNetworkConnection.h"
#include "../command/FakeCommand.h"
#include "../command/FakeCommandsMap.h"

class NetworkConnectionControllerTest : public ::testing::Test {
protected:
    Bytes EXPECTED_BYTES_1 = { 1 };
    Bytes EXPECTED_BYTES_2 = { 2 };
    Bytes EXPECTED_BYTES_3 = { 3 };

    NetworkConnectionControllerTest() {
    }
};

TEST_F(NetworkConnectionControllerTest, ShouldSequentiallyInvokeAdaptersFromReceivedPackets) {
    FakeNetworkConnection connection;

    FakeCommandAdapter adapter;
    FakeCommandsMap commandsMap = FakeCommandsMap(adapter);
    CommandRouter<Bytes&> router = CommandRouter(commandsMap);

    NetworkConnectionController controller = NetworkConnectionController(connection, router);
    controller.waitForInput();

    connection.simulateReceivedBytes(EXPECTED_BYTES_1);
    connection.simulateReceivedBytes(EXPECTED_BYTES_2);
    connection.simulateReceivedBytes(EXPECTED_BYTES_3);

    controller.processReceivedPackets();

    ASSERT_EQ(EXPECTED_BYTES_1, adapter.invokeArgs.at(0));
    ASSERT_EQ(EXPECTED_BYTES_2, adapter.invokeArgs.at(1));
    ASSERT_EQ(EXPECTED_BYTES_3, adapter.invokeArgs.at(2));
}

TEST_F(NetworkConnectionControllerTest, ShouldHandleBadOpcodes) {
    ASSERT_TRUE(false);
}