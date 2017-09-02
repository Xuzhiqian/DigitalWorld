# Reimplememnt later

CXX=g++
BUILD_DIR=./build/
CXXFLAGS=-g

all: sim .sample

sim: src/sim.cpp src/World.cpp src/Entity.cpp src/utils.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) -o $(BUILD_DIR)/$@ $(CXXFLAGS) -ldl $^

.sample: sample/world.cpp sample/entity.cpp
	mkdir -p $(BUILD_DIR)/worlds
	mkdir -p $(BUILD_DIR)/entities
	$(CXX) -shared -fPIC -o $(BUILD_DIR)/worlds/default.so sample/world.cpp
	$(CXX) -shared -fPIC -o $(BUILD_DIR)/entities/default.so sample/entity.cpp
