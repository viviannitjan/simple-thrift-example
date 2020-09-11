port = 9090

import sys
import glob
# your gen-py dir
sys.path.append('./gen-py')

import time

# Example files
from example import *
from example.ttypes import *

# Thrift files
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
from thrift.server import TServer

# Server implementation
class ExampleHandler:
    # return current time stamp
    def showCurrentTimestamp(self):
        timeStamp = time.time()
        return str(timeStamp)

    # print something to string, wait five secs, than print something again
    def asynchronousJob(self):
        print('Assume that this work takes five seconds')
        time.sleep(5)
        print('Job finished, but client didn\'t wait for five seconds')


# set handler to our implementation
handler = ExampleHandler()

processor = example.Processor(handler)
transport = TSocket.TServerSocket("0.0.0.0", port)
tfactory = TTransport.TBufferedTransportFactory()
pfactory = TBinaryProtocol.TBinaryProtocolFactory()

# set server
server = TServer.TThreadedServer(processor, transport, tfactory, pfactory)

print('Starting server')
server.serve()