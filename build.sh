#!/bin/bash

DEST_DIR=build/
SRC_DIR=src/
AGENTS_DIR=agents/
SWARM_DIR=swarm/
TARGET_NAME=main

g++ -o $TARGET_NAME ${SRC_DIR}main.cpp ${SRC_DIR}${AGENTS_DIR}agents.cpp \
    ${SRC_DIR}${SWARM_DIR}swarm.cpp

mkdir -p $DEST_DIR

mv -f $TARGET_NAME $DEST_DIR
