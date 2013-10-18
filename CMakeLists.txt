
cmake_minimum_required(VERSION 2.6.2)

# Set package properties
project(vpp-example)

# Locally-developed modules dist'ed with this app - always have this first.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(VirtuoseVPP REQUIRED)
find_package(Boost REQUIRED)

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/eigen/Eigen/Core")
    message(FATAL_ERROR "Missing Eigen submodule - try git submodule update --init --recursive")
endif()

include_directories("${VIRTUOSEVPP_INCLUDE_DIRS}"
    "${CMAKE_CURRENT_SOURCE_DIR}/eigen"
    "${Boost_INCLUDE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(SimpleAttractorImpedance)
