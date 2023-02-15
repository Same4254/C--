cmake_minimum_required(VERSION 3.8)

project(BestCompiler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_COMPILER clang++)
set(CMAKE_CXX_COMPILER clang++)

find_package(BISON)
find_package(FLEX)

# create the generated source files
BISON_TARGET(MyGrammar grammar.y ${PROJECT_SOURCE_DIR}/src/grammar.cpp COMPILE_FLAGS "--debug -dv" DEFINES_FILE ${PROJECT_SOURCE_DIR}/src/grammar.h)
FLEX_TARGET(MyScanner scanner.lex ${PROJECT_SOURCE_DIR}/src/scanner.cpp COMPILE_FLAGS --bison-bridge)
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyGrammar)

# include_directories(${CMAKE_CURRENT_BINARY_DIR} include)

include_directories(include)

add_executable(c-- main.cpp src/Driver.cpp src/Scoping.cpp src/Type.cpp src/scanner.cpp src/grammar.cpp src/grammar.h)
    # ${BISON_MyGrammar_OUTPUTS}
    # ${FLEX_MyScanner_OUTPUTS})

# target_link_libraries(c-- ${FLEX_LIBRARIES})

