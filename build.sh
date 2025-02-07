#!/bin/bash

DEST_DIR=build/
TARGET_NAME=main

g++ -o $TARGET_NAME main.cpp agents.cpp swarm.cpp robot.cpp

mkdir $DEST_DIR

mv $TARGET_NAME $DEST_DIR
