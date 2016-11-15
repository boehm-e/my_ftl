.phony:clean

all:example-client example-server

example-client:test.c
	gcc test.c -o example-client -lpthread -lwebsockets

example-server:example-server.c
	gcc test.c -o example-server -lwebsockets

clean:
	-rm example-client example-server
