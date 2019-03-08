cmake_minimum_required( VERSION 3.10 )
project( neuralnet CXX C )

if ( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR} )
    message( FATAL_ERROR "In-source builds not allowed. See README.md for use." )
endif()

set_property(GLOBAL PROPERTY CXX_STANDARD 14)
set( CMAKE_CXX_FLAGS "-Wall -Wextra" )
set( CMAKE_CXX_FLAGS_DEBUG "-g" )
set( CMAKE_CXX_FLAGS_RELEASE "-O3" )

include_directories( include )
file( GLOB_RECURSE SOURCES src/*.cpp )

add_executable( neuralnet app/main.cpp ${SOURCES})

enable_testing()

file( GLOB_RECURSE TEST_FILES test/*.cpp )
foreach( test_full_file ${TEST_FILES} )
    get_filename_component( test_name ${test_full_file} NAME_WE )
    string( REPLACE "test_" "" test_source ${test_name} )
    string( PREPEND test_source "${CMAKE_SOURCE_DIR}/src/" )
    string( APPEND  test_source ".cpp"  )

    if(EXISTS ${test_source})
        add_executable( ${test_name} ${test_full_file} ${test_source})
    else()
        # header only files
        add_executable( ${test_name} ${test_full_file})
    endif()

    add_test( ${test_name} ${test_name} )

endforeach( test_full_file ${TEST_FILES} )