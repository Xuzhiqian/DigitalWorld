# Reimplememnt later

CXX=g++
CXXFLAGS=-g -rdynamic
BUILD_DIR=./build
SRC_DIR=./src
SIMULATOR_DIR=$(SRC_DIR)/simulator
MONITOR_DIR=$(SRC_DIR)/monitor

all: $(BUILD_DIR)/simulator $(BUILD_DIR)/monitor
