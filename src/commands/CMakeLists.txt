# make library
SET(BNDcommands_list
        Init.cpp
        Print.cpp
        )
add_library(BNDCommands STATIC ${BNDcommands_list})

# make utils visible in cpp
include_directories("${Monitor_SOURCE_DIR}/monitor/commands")

target_link_libraries(BNDCommands commands_base monitor_common)