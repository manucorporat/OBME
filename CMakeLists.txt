cmake_minimum_required(VERSION 1.0)
project( OBME )


set(CMAKE_C_FLAGS "-O2")
set(CMAKE_CXX_FLAGS "-g -O2")


set(LIBRARY_NAME obme)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(PATH "")


set(SRC_FILES
obme.cpp
mersenne/mt19937-64.c
)


add_library(
    ${LIBRARY_NAME}
    STATIC
    ${SRC_FILES}
)

# Make sure the compiler can find include files from our Hello library. 
include_directories (${OBME_SOURCE_DIR}/${PATH}) 

# Make sure the linker can find the Hello library once it is built. 
link_directories (${OBME_BINARY_DIR}/${PATH}) 

add_executable (test_primitives test_primitives.cpp) 
add_executable (test_score test_score.cpp) 
add_executable (test_text test_text.cpp) 
add_executable (test_integers test_integers.cpp)


# Link the executable to the Hello library. 
target_link_libraries (test_primitives ${LIBRARY_NAME}) 
target_link_libraries (test_score ${LIBRARY_NAME}) 
target_link_libraries (test_text ${LIBRARY_NAME}) 
target_link_libraries (test_integers ${LIBRARY_NAME}) 

