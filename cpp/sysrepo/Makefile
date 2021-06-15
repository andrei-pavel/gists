all: gcc clang legacy-gcc legacy-clang

gcc:
	g++ -g3 -ggdb -O0 -U_FORTIFY_SOURCE -Wall -Wextra -I/opt/libyang/include/ -I/opt/sysrepo/include/ -DOS_LINUX a.cc -L/opt/libyang/lib/ -L/opt/sysrepo/lib/ -lsysrepo -lsysrepo-cpp

clang:
	clang++ -g3 -ggdb -O0 -U_FORTIFY_SOURCE -Wall -Wextra -I/opt/libyang/include/ -I/opt/sysrepo/include/ -DOS_LINUX a.cc -L/opt/libyang/lib/ -L/opt/sysrepo/lib/ -lsysrepo -lsysrepo-cpp

legacy-gcc:
	g++ -g3 -ggdb -O0 -U_FORTIFY_SOURCE -Wall -Wextra -I/opt/libyang-legacy/include/ -I/opt/sysrepo-legacy/include/ -DOS_LINUX legacy.cc -L/opt/libyang-legacy/lib/ -L/opt/sysrepo-legacy/lib/ -lsysrepo -lSysrepo-cpp

legacy-clang:
	clang++ -g3 -ggdb -O0 -U_FORTIFY_SOURCE -Wall -Wextra -I/opt/libyang-legacy/include/ -I/opt/sysrepo-legacy/include/ -DOS_LINUX legacy.cc -L/opt/libyang-legacy/lib/ -L/opt/sysrepo-legacy/lib/ -lsysrepo -lSysrepo-cpp
