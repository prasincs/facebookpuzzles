// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "ThreadsTest.h"
#include <protocol/TBinaryProtocol.h>
#include <server/TThreadPoolServer.h>
#include <transport/TSocket.h>
#include <transport/TTransportUtils.h>
#include <thrift/concurrency/Monitor.h>
#include <thrift/concurrency/ThreadManager.h>
#include <thrift/concurrency/PosixThreadFactory.h>

using boost::shared_ptr;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace apache::thrift::server;
using namespace apache::thrift::concurrency;

int main(int argc, char **argv) {
  int port = 9090;
  std::string host = "localhost";

  shared_ptr<TTransport> transport(new TSocket(host, port));
  shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

  transport->open();

  ThreadsTestClient client(protocol);
  int val;
  val = client.threadOne(5);
  fprintf(stderr, "%d\n", val);
  val = client.stop();
  fprintf(stderr, "%d\n", val);
  val = client.threadTwo(5);
  fprintf(stderr, "%d\n", val);

  transport->close();

  fprintf(stderr, "done.\n");

  return 0;
}

