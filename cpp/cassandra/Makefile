# Makefile

all: gcc clang

gcc:
	g++ -I/opt/dt-cpp-driver/include -L/opt/dt-cpp-driver/lib ./a.cc \
		-lcassandra_static -lstdc++ -luv -lrt -lpthread -lnsl -ldl -lssl -lcrypto -lz --verbose

clang:
	clang++ -I/opt/dt-cpp-driver/include -L/opt/dt-cpp-driver/lib ./a.cc \
		-lcassandra_static -lstdc++ -luv -lrt -lpthread -lnsl -ldl -lssl -lcrypto -lz
