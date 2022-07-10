cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

set(project_name "opengl_sandbox")

project(${project_name} VERSION 0.1.0 LANGUAGES C CXX)

# cpp standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(ext)

add_executable(${project_name} "src/main.cpp")
target_link_libraries(${project_name} glfw glm spdlog glad)
target_include_directories(${project_name} PRIVATE ${CMAKE_SOURCE_DIR}/ext/glfw/include)
target_include_directories(${project_name} PRIVATE ${CMAKE_SOURCE_DIR}/ext/glm/)