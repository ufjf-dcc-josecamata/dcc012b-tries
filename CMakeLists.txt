cmake_minimum_required(VERSION 3.0.0)
project(trie VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(trie)
add_executable(trie main.cpp trie/trie.cpp trie/trie.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
