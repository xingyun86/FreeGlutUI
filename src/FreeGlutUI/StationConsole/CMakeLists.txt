# CMakeList.txt : CMake project for StationConsole, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(project_name "StationConsole")
project(${project_name})

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/vendor/getopt
	${CMAKE_SOURCE_DIR}/vendor/pdcurses-3.9
	${CMAKE_SOURCE_DIR}/vendor/libartnet-1.1.2
	${CMAKE_BINARY_DIR}/vendor/libartnet-1.1.2
)
link_directories(
	${CMAKE_CURRENT_BINARY_DIR}
	${CMAKE_BINARY_DIR}/vendor/pdcurses-3.9
	${CMAKE_BINARY_DIR}/vendor/libartnet-1.1.2
)

file(GLOB GETOPT_SRCS "${CMAKE_SOURCE_DIR}/vendor/getopt/*.c")
file(GLOB SRCS "*.cpp" "*.c")

# Add source to this project's executable.
add_executable (${project_name} ${SRCS} ${GETOPT_SRCS})

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

target_compile_definitions(${project_name}
	PRIVATE HAVE_CONFIG_H=1
	PRIVATE HAVE_FTIME=1
)

if(MSVC)
set(EXT_LIB ws2_32 iphlpapi)
else(MSVC)
endif(MSVC)

target_link_libraries(${project_name}
	PRIVATE libartnet_static
	PRIVATE pdcurses_static
	PRIVATE ${EXT_LIB}
)

if(MSVC)
#SET_TARGET_PROPERTIES(${project_name} PROPERTIES LINK_FLAGS ${ADMIN_LEVEL})
endif(MSVC)