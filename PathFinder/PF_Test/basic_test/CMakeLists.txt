include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runPFTest
        basic_check.cpp
        pathfinder_check.cpp)
add_executable(MapFixture MapFixture.cpp)
add_executable(MapPathFindTest MapPathFindTest.cpp)
target_link_libraries(runPFTest gtest gtest_main)
