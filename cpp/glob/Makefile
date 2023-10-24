all:
	rm -f ./a.out || true
	g++ -ggdb3 -O0 ./main.cc
	./a.out
	gnuplot ./plot.gp || true
	mogrify -shave 0%x20% ./a.png || true

