cmake_minimum_required(VERSION 2.6)
project(cryptopangrams)

# Locate GTest
find_package(GTest REQUIRED)

include_directories(
  ${PROJECT_SOURCE_DIR}
  ${GTEST_INCLUDE_DIRS}
  )

# Link executables
add_executable(
    cryptopangramsTests
    tests/cryptopangrams_test.cpp
    )

target_link_libraries(
    cryptopangramsTests
    ${GTEST_LIBRARIES}
    pthread
    )
