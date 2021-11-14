# Code-Academy

## Testing 

##On Linux automated way:
#for building the game run:

./build.sh

#after the build finishes, run:

./run.sh

#to start the game


##On Linux manual way:
#for building the game run:

mkdir build (if it does not exists already)
cd build
cmake ..

#after the build finishes, run:

make -j

# to compile the project


##To execute the program (run from within build folder):
./chess 

## Troubleshouting
# if build.sh or run.sh does not execute, make sure they have execute flag:
chmod +x build.sh
chmod +x run.sh

# if cmake building fails and the build directory is created, remove it (rm -fr build/) and run cmake again.

## Windows version is coming soon.

# Enjoy!
