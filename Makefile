# Reimplememnt later

CXX=g++
TARGET_DIR=./build/

all: sim

sim: src/sim.cpp src/World.cpp src/Entity.cpp src/util.cpp
	$(CXX) -o $(TARGET_DIR)/$@ -ldl $^
