cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

set(project_name "opengl_sandbox")

project(${project_name} VERSION 0.1.0 LANGUAGES C CXX)

# c standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

# cpp standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# external directory libraries
add_subdirectory(ext)

# application directory
add_subdirectory(app)
