SET(catalogUnitMethods_list
        CatalogUnitCommand.cpp
        Print.cpp
        DeleteThisUnit.cpp
        )
add_library(catalogUnitMethods STATIC ${catalogUnitMethods_list})
