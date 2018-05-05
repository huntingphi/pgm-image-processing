# CSC3022H - Assignment 4 - Basic Image Processing

Jethro Moller  
30 April 2018

----

# Instructions

#### Running the image operations

1. Navigate to the project root directory `basic-image-processing`.
2. Run `make` to build the executable, `imageops` in the `bin` directory.
3. Run `make run ARGS="<options> <output_file_name>"` to run `imageops` with the given input and output names.  
   NB: These files should be in the `assets` directory, and the resulting output will be in the `saved_pgms` directory.
4. Alternatively, the executable binary can be found in the bin folder and executed from the terminal using imageops <options><output_file_name>, or bin/imageops <options><output_file_name> from the root directory.
5. Run `make clean` to delete any artifacts created when compiling & running the compression program.

#### Running the Unit Tests

1. Navigate to the project root directory `basic-image-processing`.
2. Run `make test` to build and run the executable, `test` in the `build/Tests` directory.
3. Run `make clean` to delete any artifacts created when running the tests.

#### Additional notes

-g is used to invoke the filter operation. eg: bin/imageops MyImage.pgm MyFilter.fir MyOutput.pgm

The filter is assumed to be found in assets/sample_filters

The filter function doesn't work but please still try to award marks for code logic and test cases.
