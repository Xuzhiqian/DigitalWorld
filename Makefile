# Reimplememnt later

CXX=g++

all: sim

sim: src/sim.cpp src/World.cpp src/Entity.cpp src/util.cpp
	$(CXX) -o $@ -ldl $^
