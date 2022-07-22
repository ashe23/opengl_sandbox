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

SET(COMMON_LIBS glfw glm spdlog glad)

FILE(GLOB_RECURSE ENGINE_HDRS "${CMAKE_SOURCE_DIR}/src/core/*.h")
FILE(GLOB_RECURSE ENGINE_SRCS "${CMAKE_SOURCE_DIR}/src/core/*.cpp")

add_library(engine_core STATIC)
target_sources(engine_core PUBLIC ${ENGINE_HDRS} PRIVATE ${ENGINE_SRCS})
target_link_libraries(engine_core PRIVATE ${COMMON_LIBS})
target_include_directories(engine_core PUBLIC "${CMAKE_SOURCE_DIR}/src/")

# application directory
add_subdirectory(app)
