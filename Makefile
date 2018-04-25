CXX = g++
CXXFLAGS = -std=c++11
VPATH = test src include bin build

run: build
	bin/imageops $(ARGS)

test: test-build
	./bin/tester --success

build: Image.cpp
	$(CXX) -c src/Image.cpp -o build/Image.o $(CXXFLAGS) 
	$(CXX) build/Image.o -o bin/imageops 

test-build: build 000-CatchMain.o tester.o 
	$(CXX) $(CXXFLAGS) -c -I include test/tester.cpp -o build/tester.o
	$(CXX) build/Image.o build/tester.o build/000-CatchMain.o -o bin/tester $(FLAGS)

000-CatchMain.o: 000-CatchMain.cpp
	$(CXX) $(CXXFLAGS) -c -I include test/000-CatchMain.cpp -o build/000-CatchMain.o



clean:
	echo "Cleaning...";
	find . -type f -name "*.o" -delete;
	# rm -f bin/$(TEST_EXE_NAME) bin/$(EXE_NAME)


