add_compile_options(
        #        -Werror
        -pedantic-errors

        -Weffc++

        -Wall
        -Wextra
        -Wpedantic

        -Wcast-align
        -Wcast-qual
        -Wconversion
        -Wctor-dtor-privacy
        -Wduplicated-branches
        -Wduplicated-cond
        -Wextra-semi
        -Wfloat-equal
        -Wlogical-op
        -Wnon-virtual-dtor
        -Wold-style-cast
        -Woverloaded-virtual
        -Wredundant-decls
        -Wsign-conversion
        -Wsign-promo
)

if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

# make commands directory visible in cmake
add_subdirectory(commands) # includes adding util funcs

#add_definitions(-DMONITOR_WITHFILE)

if( WIN32 )
    add_link_options(-static -static-libgcc -static-libstdc++)
endif()

add_library(BND STATIC
        LibraryData.cpp
        serializer/BinSerializer.cpp UtilsFunctions.hpp)

add_executable(BND_main main.cpp)
target_link_libraries(BND_main monitor BNDCommands BND)