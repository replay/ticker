OPTS="-O0 --std=c++14 -fprofile-arcs -ftest-coverage -ggdb"
INCLUDES="-I . "
FILES="main.cc option_parser.cc ticker.cc gdax_provider.cc"
LIBS="-lboost_program_options -ldl"

echo "building"
BUILDING="g++ -c ${INCLUDES} ${OPTS} ${FILES}"
echo ${BUILDING}
${BUILDING} || exit 1

echo "linking"
LINKING="g++ ${OPTS} -o ticker ./main.o ./option_parser.o ./ticker.o ${LIBS}"
echo ${LINKING}
${LINKING}

g++ -I . -fPIC -c -o gdax_provider.o gdax_provider.cc
g++ -shared -Wl,-soname,gdax_provider.so -o gdax_provider.so gdax_provider.o  -lc

rm *.gcno *.o *.gch
