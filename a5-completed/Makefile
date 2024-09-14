OPT = -Wall

a05: main.o Escape.o Hero.o MoveBehaviour.o Ninja.o Participant.o random.o Snorc.o
	g++ $(OPT) -o a05 main.o Escape.o Hero.o MoveBehaviour.o Ninja.o Participant.o random.o Snorc.o

main.o: main.cc defs.h List.h Escape.h
	g++ $(OPT) -c main.cc

Escape.o: Escape.cc Escape.h defs.h List.h Participant.h MoveBehaviour.h
	g++ $(OPT) -c Escape.cc

Hero.o: Hero.cc Hero.h
	g++ $(OPT) -c Hero.cc

MoveBehaviour.o: MoveBehaviour.cc MoveBehaviour.h
	g++ $(OPT) -c MoveBehaviour.cc

Ninja.o: Ninja.cc Ninja.h
	g++ $(OPT) -c Ninja.cc

Participant.o: Participant.cc Participant.h
	g++ $(OPT) -c Participant.cc

random.o: random.cc defs.h
	g++ $(OPT) -c random.cc

Snorc.o: Snorc.cc Snorc.h
	g++ $(OPT) -c Snorc.cc

clean:
	rm -f *.o a05