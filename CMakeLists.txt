cmake_minimum_required(VERSION 3.0.0)
project(test VERSION 0.1.0)

set(TARGET_NAME test)
# set(TARGET_2_NAME r_test)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 

include_directories(${TRIPLET_INCLUDE_DIRS}) 
include_directories("./vlc_include") 
include_directories("./vlcpp") 


# If you're using Boost:
# find_package(Boost 1.45.0 COMPONENTS filesystem) 
# if(Boost_FOUND)
    # include_directories(${Boost_INCLUDE_DIRS}) 

add_executable(${TARGET_NAME} test.cpp)
# add_executable(${TARGET_2_NAME} renderers.cpp)
# add_library(${TARGET_NAME} SHARED test.cpp)
# add_library(${TARGET_NAME} test.cpp)

target_link_libraries(${TARGET_NAME} ../../libvlc)
# target_link_libraries(${TARGET_2_NAME} ./libvlc)
# endif()

set_target_properties(${TARGET_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "./arc/"
    LIBRARY_OUTPUT_DIRECTORY "./lib/"
    RUNTIME_OUTPUT_DIRECTORY "./bin/"
    LINKER_LANGUAGE C
)
# set_target_properties(${TARGET_2_NAME}
#     PROPERTIES
#     ARCHIVE_OUTPUT_DIRECTORY "./arc/"
#     LIBRARY_OUTPUT_DIRECTORY "./lib/"
#     RUNTIME_OUTPUT_DIRECTORY "./bin/"
#     LINKER_LANGUAGE C
# )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
