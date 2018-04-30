CXX = g++ # This is the main compiler
CXXFLAGS = -std=c++11 -Wall
VPATH = test src include bin build


build:	000-CatchMain.o Filter.o Image.o driver.o
	$(CXX) $(CXXFLAGS) -I ./include -o bin/imageops build/Filter.o build/Image.o build/driver.o

run: build
	bin/imageops $(ARGS)

# test-all: test-tree test-node
	# ./bin/test-node --success && ./bin/test-tree --success


test: 000-CatchMain.o Filter.o Image.o tester.o
	$(CXX) $(CXXFLAGS) -I ./include -o bin/tester build/000-CatchMain.o build/Filter.o build/Image.o build/tester.o
	bin/tester

driver.o: driver.cpp
	$(CXX) $(CXXFLAGS) -c src/driver.cpp -o build/driver.o
	

tester.o: tester.cpp
	$(CXX) $(CXXFLAGS) -c test/tester.cpp -o build/tester.o


Image.o: Image.cpp
	$(CXX) $(CXXFLAGS) -c src/Image.cpp -o build/Image.o

Filter.o: Filter.cpp
	$(CXX) $(CXXFLAGS) -c src/Filter.cpp -o build/Filter.o

000-CatchMain.o: 000-CatchMain.cpp
	$(CXX) $(CXXFLAGS) -I ./include -c test/000-CatchMain.cpp -o build/000-CatchMain.o


clean:
	echo "Cleaning..."
	find . -type f \( -name "*.o" ! -name "000-CatchMain.o" -or -name "tester" \) -delete
	find . -type f \( -name "*.gch" -or -name "imageops" \) -delete
    # find . -type f -name "*.gch" -delete
    # find . -type f \( -name "*lorem.*" ! -name "lorem.txt" -or -name "lorem" \) -delete



