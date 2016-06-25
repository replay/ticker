CC = g++

INCLUDES = -I.

CFLAGS  = -g -ggdb -Wall -fPIC --std=c++14
LDFLAGS = -lc -lcurl -ldl -lboost_program_options

LDFLAGS_SO = -shared

MAIN = ticker
MAIN_SRCS = main.cc option_parser.cc ticker.cc

GDAX = gdax_provider.so
GDAX_SRCS = gdax_provider.cc

all: $(MAIN) $(GDAX)

$(MAIN):
	$(CC) $(CFLAGS) $(INCLUDES) $(MAIN_SRCS) -o $(MAIN) $(LDFLAGS)

$(GDAX):
	$(CC) $(CFLAGS) $(INCLUDES) $(GDAX_SRCS) -o $(GDAX) $(LDFLAGS) $(LDFLAGS_SO)

clean:
	$(RM) $(MAIN) $(GDAX) *.gcda
