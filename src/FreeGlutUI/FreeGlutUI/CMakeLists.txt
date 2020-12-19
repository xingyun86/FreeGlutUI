# CMakeList.txt : CMake project for FreeGlutUI, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(project_name "FreeGlutUI")
project(${project_name})

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/vendor
	${CMAKE_SOURCE_DIR}/vendor/glut-ui-2.37/include
	${CMAKE_SOURCE_DIR}/vendor/freeglut-3.2.1/include
)
link_directories(
	${CMAKE_CURRENT_BINARY_DIR}
	${CMAKE_BINARY_DIR}/vendor/glut-ui-2.37
	${CMAKE_BINARY_DIR}/vendor/freeglut-3.2.1
)
file(GLOB SRCS "*.cpp" "*.c")

# Add source to this project's executable.
add_executable (${project_name} ${SRCS})

if (MSVC)
	MESSAGE(STATUS "CMAKE_BUILD_TYPE=" ${CMAKE_BUILD_TYPE})

	set(CompilerFlags
		CMAKE_CXX_FLAGS
		CMAKE_CXX_FLAGS_DEBUG
		CMAKE_CXX_FLAGS_RELEASE
		CMAKE_C_FLAGS
		CMAKE_C_FLAGS_DEBUG
		CMAKE_C_FLAGS_RELEASE
		)
	foreach(CompilerFlag ${CompilerFlags})
		string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
	endforeach()
endif(MSVC)

target_compile_definitions(${project_name} PRIVATE _CRT_SECURE_NO_WARNINGS)
target_link_libraries(${project_name} 
	PRIVATE glut_ui_static
	PRIVATE freeglut_static
)
if(MSVC)
#SET_TARGET_PROPERTIES(${project_name} PROPERTIES LINK_FLAGS ${ADMIN_LEVEL})
endif(MSVC)