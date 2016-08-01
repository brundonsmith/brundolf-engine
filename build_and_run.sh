#!/bin/bash

### OBJECT FILE BUILDS

# core
g++ -c lib/src/core/components/transform.cpp -I./include -I ./dependencies/include -o lib/obj/core/components/transform.o
g++ -c lib/src/core/util/vector3.cpp -I./include -I ./dependencies/include -o lib/obj/core/util/vector3.o
g++ -c lib/src/core/component.cpp -I./include -I ./dependencies/include -o lib/obj/core/component.o
g++ -c lib/src/core/entity.cpp -I./include -I ./dependencies/include -o lib/obj/core/entity.o
g++ -c lib/src/core/game.cpp -I./include -I ./dependencies/include -o lib/obj/core/game.o
g++ -c lib/src/core/scene.cpp -I./include -I ./dependencies/include -o lib/obj/core/scene.o

# graphics-sdl
g++ -c lib/src/graphics_sdl/components/sdl_renderer.cpp -I ./include -I ./dependencies/include -o lib/obj/graphics_sdl/components/sdl_renderer.o
g++ -c lib/src/graphics_sdl/sdl_gfx_context.cpp -I ./include -I ./dependencies/include -o lib/obj/graphics_sdl/sdl_gfx_context.o



### ARCHIVE FILE BUILD
ar rvs lib/brundolf_engine.a \
  \
  lib/obj/core/components/transform.o \
  lib/obj/core/util/vector3.o \
  lib/obj/core/component.o \
  lib/obj/core/entity.o \
  lib/obj/core/game.o \
  lib/obj/core/scene.o \
  \
  lib/obj/graphics_sdl/components/sdl_renderer.o \
  lib/obj/graphics_sdl/sdl_gfx_context.o



### EXECUTABLE BUILD AND RUN
if g++ main.cpp \
    lib/brundolf_engine.a \
    dependencies/lib/sdl/SDL2 \
    -I ./include \
    -I ./dependencies/include \
    -o game.exe; \
then
  ./game.exe
else
  echo "--- BUILD FAILED ---"
fi
