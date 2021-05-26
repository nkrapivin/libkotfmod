#!/bin/sh
# If you're getting an error like 'Bad interpreter /bin/sh^M' then convert this file to Unix line endings! (e.g. dos2unix)

# libkotfmod Linux build script.

# change stuff if u care.
LKF_ARCH=$(uname -m)

# which compiler to use?
LKF_CXX=clang++
# screw g++
# LKF_CXX=g++

# where you store the fmod api directory
# i just store it in the source path.
LKF_FMOD_DIR=./fmodstudioapi20109linux

# L for log version, empty for none.
LKF_FMOD_SUFFIX=

# name of the final library.
LKF_OUTPUT_NAME=libkotfmod_linux.so

# any extra flags?
LKF_EXTRA_CXXFLAGS=

echo Build architecture: $LKF_ARCH
echo Compiler: $LKF_CXX
echo FMOD Library suffix: $LKF_FMOD_SUFFIX
echo Output name: $LKF_OUTPUT_NAME


# actual build stuff starts here...

rm -f $LKF_OUTPUT_NAME

$LKF_CXX \
	-I$LKF_FMOD_DIR/api/core/inc \
	-I$LKF_FMOD_DIR/api/studio/inc \
	-L$LKF_FMOD_DIR/api/core/lib/$LKF_ARCH \
	-L$LKF_FMOD_DIR/api/studio/lib/$LKF_ARCH \
	-lfmod$LKF_FMOD_SUFFIX -lfmodstudio$LKF_FMOD_SUFFIX \
	$LKF_EXTRA_CXXFLAGS -o $LKF_OUTPUT_NAME \
	-Wl,-rpath,assets/ -fPIC -shared libkotfmod_*.cpp	

echo Done.

