cmake_minimum_required(VERSION 2.8.4)

project(parser)

set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -std=c11")

set(
  SOURCE_FILES

  main.cc
  lexer.yy.c
  parser.tab.c
  node.c
  )

add_executable(
  parser
  ${SOURCE_FILES}
  )
