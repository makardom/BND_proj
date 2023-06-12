SET(catalogMethods_list
        CatalogCommand.cpp
        Print.cpp
        AddRecord.cpp
        MakeNewMassive.cpp
        DecSize.cpp
        SearchRecordByName.cpp
        )
add_library(catalogMethods STATIC ${catalogMethods_list})
