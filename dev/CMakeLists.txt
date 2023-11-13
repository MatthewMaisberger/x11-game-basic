cmake_minimum_required(VERSION 3.9)

project(
	x11game
	LANGUAGES CXX
	)

find_package(X11 REQUIRED)


file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/*.cpp)
add_library(gamelibs STATIC ${SRC_FILES})
target_include_directories(gamelibs PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/x11game)
target_compile_features(gamelibs PUBLIC cxx_std_17)

add_executable(x11game main.cpp) 
target_link_libraries(x11game PUBLIC gamelibs ${X11_LIBRARIES})
