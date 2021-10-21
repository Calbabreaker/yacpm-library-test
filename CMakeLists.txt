cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(yacpm_library_test)

# set YACPM_TEST_LIB_SET_ME to "lets go" to sucessfully build
option(YACPM_TEST_LIB_SET_ME "no set")

if(NOT YACPM_TEST_LIB_SET_ME STREQUAL "lets go")
    message(FATAL_ERROR "YACPM_TEST_LIB_SET_ME needs to be value 'lets go'")
endif()

if(NOT EXISTS "${CMAKE_BINARY_DIR}/yacpm.cmake")
    file(DOWNLOAD "https://github.com/Calbabreaker/yacpm/raw/v1/yacpm.cmake" "${CMAKE_BINARY_DIR}/yacpm.cmake")
endif()

include(${CMAKE_CURRENT_BINARY_DIR}/yacpm.cmake)

add_library(${PROJECT_NAME} yacpm_test_lib.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} glm)
