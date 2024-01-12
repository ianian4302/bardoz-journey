cmake_minimum_required(VERSION 3.28)

include_directories(./include)

project(bardoz_journey)

file(GLOB SOURCES "./src/*.cpp")

add_executable(main main.cpp ${SOURCES})

find_package( raylib CONFIG REQUIRED )
target_link_libraries( main PRIVATE raylib )


find_path(RAYGUI_INCLUDE_DIRS "raygui.h")
target_compile_definitions(main PRIVATE RAYGUI_IMPLEMENTATION)
message(STATUS "RAYGUI_INCLUDE_DIRS: ${RAYGUI_INCLUDE_DIRS}")
target_include_directories(main PRIVATE ${RAYGUI_INCLUDE_DIRS})
