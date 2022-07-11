add_executable("null_window" ${CMAKE_SOURCE_DIR}/app/null_window/null_window.cpp)
target_link_libraries("null_window" glfw glm spdlog glad)

add_executable("triangle" ${CMAKE_SOURCE_DIR}/app/triangle/triangle.cpp)
target_link_libraries("triangle" glfw glm spdlog glad)
