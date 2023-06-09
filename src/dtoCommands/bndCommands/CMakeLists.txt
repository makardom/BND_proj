SET(bndMethods_list
        BNDCommand.cpp
        Create.cpp
        Print.cpp
        )
add_library(bndMethods STATIC ${bndMethods_list})
