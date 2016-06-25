OPTS="-O0 -Wall --std=c++14 -fprofile-arcs -fPIC -ftest-coverage -ggdb"
INCLUDES="-I . "
FILES="main.cc option_parser.cc ticker.cc gdax_provider.cc"
LIBS="-lboost_program_options -ldl"
GDAX_LIBS="-lc -lcurl"

echo "building"
BUILDING1="g++ -c ${INCLUDES} ${OPTS} ${FILES}"

echo ${BUILDING1}
${BUILDING1} || exit 1

#BUILDING2="g++ -c ${INCLUDES} ${OPTS} ${GDAX_FILES}"

#echo ${BUILDING2}
#${BUILDING2} || exit 1

echo "linking"

LINKING1="g++ ${OPTS} -o ticker ./main.o ./option_parser.o ./ticker.o ${LIBS}"

echo ${LINKING1}
${LINKING1}

LINKING2="g++ ${OPTS} -shared -Wl,-soname,gdax_provider.so-o gdax_provider.so ./gdax_provider.o ${GDAX_LIBS}"

echo ${LINKING2}
${LINKING2}

#g++ -shared -Wl,-soname,gdax_provider.so -o gdax_provider.so gdax_provider.o  -lc -lcurl

rm *.gcno *.o *.gch
