# Minimum required version of cmake
cmake_minimum_required(VERSION 3.5)

# ===

set(ProjectName "CommandLineParser")
set(ProjectVersion "1.0")
set(LibraryName "cliparser")

set(CMakeFlags "-std=c++17")
set(CMakeDebugFlags "-g")

option(CLI_PARSER_STATIC "If true, compiles as a static library, else compiles as a shared library" OFF)

# ===

project("${ProjectName}" VERSION "${ProjectVersion}")

# Project root directory and the source directory src/
set(ProjectDir "${PROJECT_SOURCE_DIR}") # PROJECT_SOURCE_DIR is set by calls to project()
set(SourceDir "${ProjectDir}/src")

# ===

set(Libraries "") # Example: -lglfw -lGL -ldl

set(SourceFiles
	"${SourceDir}/parser/CommandLineParser.cpp"
	"${SourceDir}/parser/CommandLineOption.cpp"
	"${SourceDir}/parser/CommandLineArg.cpp"
)

set(HeaderFiles
	"${SourceDir}/parser/CommandLineParser.h"
	"${SourceDir}/parser/CommandLineOption.h"
	"${SourceDir}/parser/CommandLineArg.h"
)

# ===

set(CMAKE_CXX_FLAGS_DEBUG "${CMakeDebugFlags}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMakeFlags}")

message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")

if("${SharedLib}")
	add_library("${LibraryName}" SHARED "${SourceFiles}" "${HeaderFiles}")
else()
	add_library("${LibraryName}" STATIC "${SourceFiles}" "${HeaderFiles}")
endif()

target_include_directories("${LibraryName}" PRIVATE "${SourceDir}")

target_link_libraries("${LibraryName}" PRIVATE "${Libraries}")

install(TARGETS ${LibraryName} DESTINATION "${CMAKE_INSTALL_LIBDIR}")