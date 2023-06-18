enable_testing()

cmake_policy(VERSION 3.16...3.24)

# ----------GTest Connect
include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


include(GoogleTest)
# ----------GTest Connect
add_executable(
        BND_tests
        commandFactoryTest.cpp
        TestFunctions.hpp)
target_link_libraries(
        BND_tests
        GTest::gtest_main
        monitor
        BNDCommands
        BND
        bndMethods
        catalogUnitMethods
        catalogMethods
)
gtest_discover_tests(BND_tests)