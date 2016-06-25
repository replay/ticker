CC = g++

INCLUDES = -I.

CFLAGS  = -g -ggdb -Wall -fPIC --std=c++14
LDFLAGS = -lc -lcurl -ldl -lboost_program_options

LDFLAGS_SO = -shared

MAIN = ticker
MAIN_SRCS = main.cc option_parser.cc ticker.cc
MAIN_OBJS = $(MAIN_SRCS:.cc=.o)

GDAX = gdax_provider.so
GDAX_SRCS = gdax_provider.cc data_provider.cc
GDAX_OBJS = $(GDAX_SRCS:.cc=.o)

all: $(MAIN) $(GDAX)

$(MAIN): $(MAIN_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(MAIN_OBJS) -o $(MAIN) $(LDFLAGS)

main.o: main.cc
	$(CC) $(CFLAGS) $(INCLUDES) main.cc -c -o main.o $(LDFLAGS)

option_parser.o: option_parser.cc
	$(CC) $(CFLAGS) $(INCLUDES) option_parser.cc -c -o option_parser.o $(LDFLAGS)

ticker.o: ticker.cc
	$(CC) $(CFLAGS) $(INCLUDES) ticker.cc -c -o ticker.o $(LDFLAGS)

$(GDAX): $(GDAX_OBJS)
	$(CC) $(LDFLAGS_SO) $(CFLAGS) $(INCLUDES) $(GDAX_OBJS) -o $(GDAX) $(LDFLAGS)

gdax_provider.o: gdax_provider.cc
	$(CC) $(LDFLAGS_SO) $(CFLAGS) $(INCLUDES) gdax_provider.cc -c -o gdax_provider.o $(LDFLAGS)

data_provider.o: data_provider.cc
	$(CC) $(LDFLAGS_SO) $(CFLAGS) $(INCLUDES) data_provider.cc -c -o data_provider.o $(LDFLAGS)

clean:
	$(RM) $(MAIN) $(GDAX) *.gcda *.o
