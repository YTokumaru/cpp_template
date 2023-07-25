add_library(hello STATIC hello.cpp)
target_include_directories(hello
    PUBLIC "${PROJECT_SOURCE_DIR}/include")

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE hello)
target_include_directories(${PROJECT_NAME}
    PUBLIC "${PROJECT_SOURCE_DIR}/include")