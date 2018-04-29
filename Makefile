CXX = g++ # This is the main compiler
CXXFLAGS = -std=c++11 -Wall
VPATH = test src include bin build


build:	000-CatchMain.o Image.o driver.o
	$(CXX) $(CXXFLAGS) -I ./include -o bin/imageops build/Image.o build/driver.o

run: build
	bin/imageops $(ARGS)

# test-all: test-tree test-node
	# ./bin/test-node --success && ./bin/test-tree --success


test: 000-CatchMain.o Image.o tester.o
	$(CXX) $(CXXFLAGS) -I ./include -o bin/tester build/000-CatchMain.o build/Image.o build/tester.o
	bin/tester --success

driver.o: driver.cpp
	$(CXX) $(CXXFLAGS) -c src/driver.cpp -o build/driver.o

tester.o: tester.cpp
	$(CXX) $(CXXFLAGS) -c test/tester.cpp -o build/tester.o


Image.o: Image.cpp
	$(CXX) $(CXXFLAGS) -c src/Image.cpp -o build/Image.o

# Utils.o: Utils.cpp
	# $(CXX) $(CXXFLAGS) -c src/Utils.cpp -o build/Utils.o

000-CatchMain.o: 000-CatchMain.cpp
	$(CXX) $(CXXFLAGS) -I ./include -c test/000-CatchMain.cpp -o build/000-CatchMain.o


clean:
	echo "Cleaning...";
	find . -type f -name "*.o" -delete;
	# rm -f bin/$(TEST_EXE_NAME) bin/$(EXE_NAME)


