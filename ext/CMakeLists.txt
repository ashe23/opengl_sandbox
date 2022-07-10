# if glfw missing update all git submodules
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/ext/glfw/CMakeLists.txt")
	find_package(Git QUIET)
	if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
		# Update submodules as needed
		option(GIT_SUBMODULE "Check submodules during build" ON)
		if(GIT_SUBMODULE)
			message(STATUS "Submodule update")
			execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
							WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
							RESULT_VARIABLE GIT_SUBMOD_RESULT)
			if(NOT GIT_SUBMOD_RESULT EQUAL "0")
				message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
			endif()
		endif()
	endif()
endif()

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(glfw EXCLUDE_FROM_ALL)

# glm
add_subdirectory(glm EXCLUDE_FROM_ALL)

# glad
add_library(glad INTERFACE)
target_sources(glad PUBLIC ${CMAKE_SOURCE_DIR}/ext/glad/include/glad/glad.h PRIVATE ${CMAKE_SOURCE_DIR}/ext/glad/src/glad.c)

# spdlog
add_subdirectory(spdlog EXCLUDE_FROM_ALL)
