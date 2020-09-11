#include <iostream>
#include <string>

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>

#include "../gen-cpp/example.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace example;

int main() {
	std::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
	std::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	std::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
	exampleClient client(protocol);

	try {
		string timestamp;
		transport->open();

		client.showCurrentTimestamp(timestamp);
		cout << "Current timestamp " << timestamp << endl;

		// Note that C++ uses return by reference for complex types to avoid
		// costly copy construction
		// SharedStruct ss;
		// client.getStruct(ss, 1);
		// cout << "Received log: " << ss << endl;

		transport->close();
	} catch (TException& tx) {
		cout << "ERROR: " << tx.what() << endl;
	}
}