cmake_minimum_required(VERSION 2.8)
project(sample-code)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Locate GTest
find_package(GTest REQUIRED)

include_directories(
  ${PROJECT_SOURCE_DIR}
  ${GTEST_INCLUDE_DIRS}
  )

# Link executables
add_executable(
    build/sampleCryptoPangramsTest
    tests/cryptopangrams_test.cpp
    )

target_link_libraries(
    build/sampleCryptoPangramsTest
    ${GTEST_LIBRARIES}
    pthread
    )

# Link executables
add_executable(
    build/sampleTopKTest
    tests/topK_test.cpp
    )

target_link_libraries(
    build/sampleTopKTest
    ${GTEST_LIBRARIES}
    pthread
    )
