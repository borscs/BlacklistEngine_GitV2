set(SOURCES
        main.cpp
        Database.cpp
        Engine.cpp
        EngineHandler.cpp
        )

add_executable(BLackEngine ${SOURCES})

target_link_libraries(BLackEngine Qt5::Core Qt5::Sql)