add_executable("app_01_hello_triangle" ${CMAKE_SOURCE_DIR}/app/app_01_hello_triangle/main.cpp)
target_link_libraries("app_01_hello_triangle" ${COMMON_LIBS} engine_core)
