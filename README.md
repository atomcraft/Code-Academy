# Code-Academy

## Testing 

# On Linux automated way:
## for building the game run:

./build.sh

#after the build finishes, to start the game run:

./run.sh

# On Linux manual way:
## for building the game run:

(if it does not exists already):

mkdir build 
cd build
cmake ..

## after the build finishes, run:

make -j

## to compile the project

## To execute the program (run from within build folder):
./chess 

# Troubleshooting:
## if build.sh or run.sh does not execute, make sure they have execute flag:
chmod +x build.sh
chmod +x run.sh

## if cmake building fails and the build directory is created, remove it (rm -fr build/) and run cmake again.

# Windows version is coming soon.

# Enjoy!
