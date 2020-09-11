# Simple Example of client and server implementation using apache thrift

A simple example demonstrating server in python and client in cpp or python with apache thrift

## Requirements
- [Thrift](http://thrift.apache.org/docs/install/)
- g++ compiler
- python3

## Thrift content
Thrift is DDL defining services that will be implemented in server and run by client.
The service are:
- Service that print current timestamp
- Service that run async job


## Build and run project
Here is instructions to build and run the project

### Create generated code from thrift
To run this project, first create generated code in targeted language using thrift. In our case, the targeted language is cpp and python
```
thrift --gen py example.thrift
thrift --gen cpp example.thrift
```
This command will generate two folders in project folder: gen-cpp/ and gen-py/

### Run server
In this example, server is built using python. The server implements the service to show current timestamp and run async job which is defined in thrift file
```
python3 server/server.py
```

### Run client
In this example, client can be run in either cpp or python

To run cpp client
```
g++ gen-cpp/example.cpp client/cppclient.cpp -o client/cppclient.o -L/usr/local/lib -lthrift -Wl,-rpath=/usr/local/lib 
./client/cppclient.o
```

To run python client
```
python3 client/pyclient.py
```

Notes: All the commands are tested in Ubuntu. The command may be different if you use other operating system.