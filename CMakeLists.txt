add_library(Cryptolyser_Common INTERFACE)
target_include_directories(Cryptolyser_Common INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

message(STATUS "Copying over .clang-format from Cryptolyser_Common to the root of the parent project.")
file(COPY .clang-format DESTINATION ${PROJECT_SOURCE_DIR})
