add_library(report STATIC Reporter.cpp)

# include top-level directory to allow full include paths
target_include_directories(report PUBLIC ${CMAKE_SOURCE_DIR})  # for model/Types.h
