# Reimplememnt later

CXX=g++
CXXFLAGS=-g -rdynamic
BUILD_DIR=./build
SRC_DIR=./src
SERVER_DIR=$(SRC_DIR)/server
CLIENT_DIR=$(SRC_DIR)/client

all: server client
