all: demo

demo: demo.o html.h

clean:
	rm -f *.o demo

