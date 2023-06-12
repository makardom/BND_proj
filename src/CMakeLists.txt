
if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

# make commands directory visible in cmake
add_subdirectory(commands) # includes adding util funcs
add_subdirectory(dtoCommands)

#add_definitions(-DMONITOR_WITHFILE)

if( WIN32 )
    add_link_options(-static -static-libgcc -static-libstdc++)
endif()
add_library(BND STATIC
        LibraryData.cpp
        serializer/BinSerializer.cpp UtilsFunctions.hpp)

add_executable(BND_main main.cpp)
target_link_libraries(BND_main monitor BNDCommands BND bndMethods catalogUnitMethods catalogMethods)