APP_NAME=cpp-microservice

CPPVER=c++17
CFLAGS=-Wall -I /usr/local/include
LDFLAGS=-lboost_system -lcrypto -lssl -lcpprest -L /usr/local/lib -l gtest -l pthread

SRC=./src/inc/utils.cpp ./src/logger_stdout.cpp ./src/logger_file.cpp ./src/http_ctrl.cpp

APP_TESTS=./tests/utils.cpp ./tests/logger_stdout.cpp ./tests/logger_file.cpp
MAIN_TEST=./tests/main.cpp

URLA?=http://0.0.0.0:
PORT?=8998
URLB?=/health

default:
	make clean ; make test && make install && make run

install:
	mkdir bin ; g++ -std=${CPPVER} ${CFLAGS} ${SRC} ./src/main.cpp -o ./bin/${APP_NAME} ${LDFLAGS}

run:
	./bin/${APP_NAME} 

clean:
	rm -rf ./bin ./debug

test:
	clear
	rm -rf ./debug && mkdir debug
	g++ -std=${CPPVER} ${CFLAGS} ${APP_TESTS} ${MAIN_TEST} ${SRC} -o ./debug/${APP_NAME}_tests ${LDFLAGS} ; ./debug/${APP_NAME}_tests

demo:
	curl ${URLA}${PORT}${URLB}
	curl -X POST -d '{"key1":"value1", "key2":"value2"}' -H "Content-Type: application/json" ${URLA}${PORT}${URLB}
	curl -X PUT -d '{"key1":"value1", "key2":"value2"}' -H "Content-Type: application/json" ${URLA}${PORT}${URLB}
	curl -X DELETE ${URLA}${PORT}${URLB}

