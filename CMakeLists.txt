cmake_minimum_required(VERSION 3.10)
project(CasoFinalIntegradorTema4)

set(CMAKE_CXX_STANDARD 11)

# Add the include directory for json11
include_directories(${CMAKE_SOURCE_DIR}/json11-master)

# Add the source files for your project
add_executable(CasoFinalIntegradorTema4
    casoFinalIntegrador4.cpp
    main.cpp
    json11-master/json11.cpp
)

# Exclude test.cpp from the compilation
set_source_files_properties(json11-master/test.cpp PROPERTIES HEADER_FILE_ONLY TRUE)