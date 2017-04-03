cmake_minimum_required(VERSION 3.6)
project(PathFinder)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Terrain.h Ground.cpp Ground.h Map.cpp Map.h MapSearchNode.cpp MapSearchNode.h fsa.h stlastar.h)
add_executable(PathFinder ${SOURCE_FILES})
set(EXECUTABLE_NAME "PathFinder")

#img dir
configure_file(img/red.png ${CMAKE_CURRENT_BINARY_DIR}/img/red.png COPYONLY)
configure_file(img/ground_one.png ${CMAKE_CURRENT_BINARY_DIR}/img/ground_one.png COPYONLY)
configure_file(img/ground_nine.png ${CMAKE_CURRENT_BINARY_DIR}/img/ground_nine.png COPYONLY)

#txt dir
configure_file(txt/text.txt ${CMAKE_CURRENT_BINARY_DIR}/txt/text.txt COPYONLY)

#test
add_subdirectory(PF_Test)

# Detect and add SFML
set(SFML_DIR "~/ClionProjects/PathFinder/SFML-2.4.0/share/SFML/cmake/Modules")
set(CMAKE_MODULE_PATH "~/ClionProjects/PathFinder/SFML-2.4.0/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()