# Target to build and run the test executable
mytests: mytests.o sorting.o
	g++ -o mytests mytests.o sorting.o
	./mytests

# Compile mytests.cpp into an object file
mytests.o: mytests.cpp sorting.hpp
	g++ -c mytests.cpp -o mytests.o

# Compile sorting.cpp into an object file
sorting.o: sorting.cpp sorting.hpp
	g++ -c sorting.cpp -o sorting.o

# Compile sorting algorithms only
sorting: sorting.cpp sorting.hpp
	g++ -c sorting.cpp -o sorting.o

# Clean up object files and executables
clean:
	rm -f *.o mytests