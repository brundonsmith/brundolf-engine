#!/bin/bash

### OBJECT FILE BUILDS

# core
g++ -c lib/src/core/components/transform.cpp -I./include -o lib/obj/core/components/transform.o
g++ -c lib/src/core/util/vector3.cpp -I./include -o lib/obj/core/util/vector3.o
g++ -c lib/src/core/entity.cpp -I./include -o lib/obj/core/entity.o
g++ -c lib/src/core/game.cpp -I./include -o lib/obj/core/game.o
g++ -c lib/src/core/scene.cpp -I./include -o lib/obj/core/scene.o

# graphics-sdl


### ARCHIVE FILE BUILD
ar rvs lib/brundolf_engine.a \
  \
  lib/obj/core/components/transform.o \
  lib/obj/core/util/vector3.o \
  lib/obj/core/entity.o \
  lib/obj/core/game.o \
  lib/obj/core/scene.o

if g++ main.cpp lib/brundolf_engine.a -I./include -o ./game.exe; then
  ./game.exe
else
  echo "--- BUILD FAILED ---"
fi
