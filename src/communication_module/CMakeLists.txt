set(TARGET_TITLE communication_module)

add_library(${TARGET_TITLE}
   ${TARGET_TITLE}.cpp
   ${TARGET_TITLE}.h)

add_library(Backend::CommunicationModule ALIAS ${TARGET_TITLE})

target_include_directories(${TARGET_TITLE}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(${TARGET_TITLE}
   PRIVATE
     Qt5::Core
     Qt5::Network)
