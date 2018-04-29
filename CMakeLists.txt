# CMake entry point
cmake_minimum_required(VERSION 2.8)
project (SilverEngine C CXX)

OPTION(MAKE_DEMO "Make Demo game application" ON)

find_package(OpenGL REQUIRED)

add_subdirectory (ExtLibs)

include_directories(
	${CMAKE_SOURCE_DIR}/ExtLibs/glfw-3.2.1/include/GLFW
	${CMAKE_SOURCE_DIR}/ExtLibs/glm-0.9.8.4
	${CMAKE_SOURCE_DIR}/ExtLibs/glew-1.9.0/include/
	${CMAKE_SOURCE_DIR}/ExtLibs/freetype2/include/
	${CMAKE_SOURCE_DIR}/ExtLibs
	
	${CMAKE_SOURCE_DIR}/SilverEngine
	${CMAKE_SOURCE_DIR}/Workspace
)

link_directories(
	${CMAKE_SOURCE_DIR}/ExtLibs/glfw-3.2.1/src
	${CMAKE_SOURCE_DIR}/SilverEngine
	${CMAKE_SOURCE_DIR}/ExtLibs/freetype2/win32
)

set(ALL_GRAPHICS_LIBS
	${OPENGL_LIBRARY}
	SilverEngine
	glfw
	GLEW_190
	${CMAKE_SOURCE_DIR}/ExtLibs/freetype2/win32/freetype.lib
)

add_custom_target(CustomDlls
  # todo: check if debug and release folder exist
  # debug version
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/ExtLibs/freetype2/win32/freetype.dll          ${CMAKE_BINARY_DIR}/Debug
  
  # release version
  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/ExtLibs/freetype2/win32/freetype.dll           ${CMAKE_BINARY_DIR}/Release

  # Output Message
  COMMENT "Copying Custom .dll binaries from '${CMAKE_SOURCE_DIR}/ExtLibs/freetype2/win32/freetype.dll' to '${CMAKE_BINARY_DIR}'" VERBATIM
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

####################################################################
# SilverEngine.lib                                                       #
####################################################################

file(GLOB SilverEngine_SRC
    SilverEngine/*.h
    SilverEngine/*.cpp
)

add_library(SilverEngine
	${SilverEngine_SRC}
)

file(
	COPY SilverEngine/shaders
	DESTINATION ${CMAKE_BINARY_DIR}
)
file(
	COPY SilverEngine/fonts
	DESTINATION ${CMAKE_BINARY_DIR}
)
file(
	COPY SilverEngine/assets
	DESTINATION ${CMAKE_BINARY_DIR}
)

SET_TARGET_PROPERTIES(SilverEngine PROPERTIES LINKER_LANGUAGE CXX)

IF(MAKE_DEMO)

file(GLOB Demo_SRC
    Workspace/Demo/*.h
    Workspace/Demo/*.cpp
)

	add_executable(Demo
		${Demo_SRC}
	)
	
	file(
		COPY Workspace/Demo/assets
		DESTINATION ${CMAKE_BINARY_DIR}
	)
	
	file(
		COPY Workspace/Demo/fonts
		DESTINATION ${CMAKE_BINARY_DIR}
	)
	
	file(
		COPY Workspace/Demo/shaders
		DESTINATION ${CMAKE_BINARY_DIR}
	)
	
	target_link_libraries(Demo
		${ALL_GRAPHICS_LIBS}
	)
	
	SET_TARGET_PROPERTIES(Demo PROPERTIES LINKER_LANGUAGE CXX)
	
ENDIF()

