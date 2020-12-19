# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("FreeGlutUI")

if(MSVC)
set(ADMIN_LEVEL "/MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\"")
add_compile_definitions(
	_CRT_SECURE_NO_WARNINGS
	_WINSOCK_DEPRECATED_NO_WARNINGS
)
else(MSVC)
endif(MSVC)
# Include sub-projects.
add_subdirectory("vendor/pdcurses-3.9")
add_subdirectory("vendor/freeglut-3.2.1")
add_subdirectory("vendor/glut-ui-2.37")
add_subdirectory("vendor/libartnet-1.1.2")
#add_subdirectory("vendor/artnet-examples-0.3.13")
add_subdirectory ("FreeGlutUI")
add_subdirectory ("StationConsole")
