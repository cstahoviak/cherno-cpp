cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)

project(Cherno)

# Create a macro-defined option with a default value of OFF
# TODO: This isn't working. Want to be able to set it via the command line
#   using 'cmake -DCS_DEBUG ..'
# TODO: Make this option Debug/Release mode dependent
add_compile_definitions(CS_DEBUG=0)

# TODO: Move away from using GLOB
file(GLOB LIB_SOURCES src/*.cpp)
file(GLOB LIB_HEADERS include/*.h)

# Create a library
add_library(ChernoLib ${LIB_SOURCES} ${LIB_HEADERS})

# TODO: If I don't include this line, then I cannot #include any header
# files withinin the cpp files of my app directory. Is there a better way
# to manage this? 
include_directories("${PROJECT_SOURCE_DIR}/include")

# Build all app executables
file( GLOB APP_SOURCES app/*.cpp )
foreach( testsourcefile ${APP_SOURCES} )
    # Cut off the file extension and directory path
    get_filename_component( testname ${testsourcefile} NAME_WE )
    add_executable( ${testname} ${testsourcefile} )
    # Make sure YourLib is linked to each app
    target_link_libraries( ${testname} ChernoLib )
endforeach( testsourcefile ${APP_SOURCES} )
