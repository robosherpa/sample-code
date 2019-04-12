cmake_minimum_required(VERSION 2.6)
project(sample-code)

# Locate GTest
find_package(GTest REQUIRED)

include_directories(
  ${PROJECT_SOURCE_DIR}
  ${GTEST_INCLUDE_DIRS}
  )

# Link executables
add_executable(
    sampleCryptoPangramsTest
    tests/cryptopangrams_test.cpp
    )

target_link_libraries(
    sampleCryptoPangramsTest
    ${GTEST_LIBRARIES}
    pthread
    )

# Link executables
add_executable(
    sampleTopKTest
    tests/topK_test.cpp
    )

target_link_libraries(
    sampleTopKTest
    ${GTEST_LIBRARIES}
    pthread
    )
