cmake_minimum_required(VERSION 3.17)

project(RPGame 	VERSION 1.0
				DESCRIPTION "Primeiro projeto que irei completar"
				LANGUAGES CXX)

#Set a toolchain file
set(CMAKE_TOOLCHAIN_FILE "$ENV{PMNG}/scripts/buildsystems/vcpkg.cmake")

#Set export compile_commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#Set some directories
set(SFML_DIR "D:/Code/Package Managers/Vcpkg/packages/sfml_x64-windows/share/sfml")

find_package(SFML 2.5.1 COMPONENTS 	system
									graphics
									audio
									network
									window
									REQUIRED)

add_executable(RPGame 	src/main.cpp
						src/TileSheet.cpp
						src/ResourceManager.cpp
						includes/ResourceManager.hpp
						includes/TileSheet.hpp)

set_target_properties	(RPGame	PROPERTIES
								RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}\\bin
								LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}\\bin\\lib
								ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}\\bin\\lib
								CXX_STANDARD 17
								CXX_STANDARD_REQUIRED ON
								CXX_EXTENSIONS OFF
								RUNTIME_OUTPUT_NAME "Game"
								)


target_include_directories(RPGame 	PUBLIC include
									PRIVATE src)

if (SFML_FOUND)

	target_link_libraries(RPGame
							PRIVATE
							sfml-system
							sfml-window
							sfml-graphics
							sfml-network
							sfml-audio)

endif()

if(WIN32)
	if(MSVC)
		target_compile_options(RPGame PRIVATE 	"/W4"
												"/WX")
	else()
		target_compile_options(RPGame PRIVATE 	"-W"
												"-Wall"
												"-Werror")

	endif(MSVC)
endif(WIN32)
