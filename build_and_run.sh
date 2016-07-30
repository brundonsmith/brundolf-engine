#!/bin/bash

g++ -c lib/src/core/component.cpp -I./include -o lib/obj/core/component.o
g++ -c lib/src/core/entity.cpp -I./include -o lib/obj/core/entity.o
g++ -c lib/src/core/scene.cpp -I./include -o lib/obj/core/scene.o
g++ -c lib/src/core/game.cpp -I./include -o lib/obj/core/game.o

ar rvs lib/brundolf_engine.a lib/obj/core/component.o lib/obj/core/entity.o lib/obj/core/game.o lib/obj/core/scene.o

if g++ main.cpp lib/brundolf_engine.a -I./include -o ./game.exe; then
  ./game.exe
else
  echo "--- BUILD FAILED ---"
fi
