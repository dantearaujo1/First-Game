cmake_minimum_required(VERSION 3.17)

project(RPGame 	VERSION 1.0
				DESCRIPTION "Primeiro projeto que irei completar"
				LANGUAGES CXX)

#Set export compile_commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#Set some directories
# set(SFML_DIR "D:/Code/Package Managers/Vcpkg/packages/sfml_x64-windows/share/sfml")
# set(ImGui_DIR "D:/Code/vcpkg/packages/imgui_x64-windows/share/imgui")
# set(ImGui-SFML_DIR "D:/Code/vcpkg/packages/imgui-sfml_x64-windows/share/imgui-sfml")
# set(fmt_DIR "D:/Code/Package Managers/Vcpkg/packages/fmt_x64-windows/share/fmt")
# set(spdlog_DIR "D:/Code/Package Managers/Vcpkg/packages/spdlog_x64-windows/share/spdlog")

find_package(SFML 2.5.1 COMPONENTS 	system
									graphics
									audio
									network
									window
									REQUIRED)
find_package(ImGui CONFIG REQUIRED)
find_package(ImGui-SFML CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)


add_executable(RPGame 	src/main.cpp
						src/Game.cpp
						src/Tiles/Tilemap.cpp
						src/States/GameState.cpp
						src/Managers/ResourceManager.cpp
						src/Managers/StateManager.cpp
						includes/Managers/ResourceManager.hpp
						includes/Managers/StateManager.hpp
						includes/States/GameState.hpp
						includes/States/AppState.hpp
						includes/Game.hpp
						includes/Misc/Utils.hpp
						includes/Tiles/Tilemap.hpp)

set_target_properties	(RPGame	PROPERTIES
								RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
								LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/lib
								ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/lib
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

	target_link_libraries(RPGame PRIVATE	imgui::imgui
											ImGui-SFML::ImGui-SFML)

	target_link_libraries(RPGame PRIVATE	spdlog::spdlog
											spdlog::spdlog_header_only)

	target_link_libraries(RPGame PRIVATE	fmt::fmt
											fmt::fmt-header-only)

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
