cmake_minimum_required(VERSION 3.8)

project(BestCompiler)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_COMPILER clang++)
set(CMAKE_CXX_COMPILER clang++)

find_package(BISON)
find_package(FLEX)
find_package(LLVM REQUIRED CONFIG)

# create the generated source files
BISON_TARGET(MyGrammar grammar.y ${PROJECT_SOURCE_DIR}/src/grammar.cpp COMPILE_FLAGS "--debug -dv" DEFINES_FILE ${PROJECT_SOURCE_DIR}/src/grammar.h)
FLEX_TARGET(MyScanner scanner.lex ${PROJECT_SOURCE_DIR}/src/scanner.cpp COMPILE_FLAGS --bison-bridge)
ADD_FLEX_BISON_DEPENDENCY(MyScanner MyGrammar)

# include_directories(${CMAKE_CURRENT_BINARY_DIR} include)

include_directories(${LLVM_INCLUDE_DIRS} include)
add_definitions(${LLVM_DEFINITIONS})

add_custom_target(copy-test-cases ALL 
		COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/Tests ${PROJECT_BINARY_DIR}/Tests
		DEPENDS c--)

llvm_map_components_to_libnames(llvm_libs support core irreader)

add_executable(c-- main.cpp src/Driver.cpp src/Scoping.cpp src/Type.cpp src/scanner.cpp src/grammar.cpp src/grammar.h)
    # ${BISON_MyGrammar_OUTPUTS}
    # ${FLEX_MyScanner_OUTPUTS})

# target_link_libraries(c-- ${FLEX_LIBRARIES})
target_link_libraries(c-- ${llvm_libs})
