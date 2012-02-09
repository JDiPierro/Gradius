project(gradius)

cmake_minimum_required(VERSION 2.8)

find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)
find_package(SDL_ttf REQUIRED)

link_libraries(	${SDL_LIBRARY}
		${SDLIMAGE_LIBRARY}
		${SDLTTF_LIBRARY}
		SDLmain)

set(SOURCES
	./app/Animation.cpp
	./app/App.cpp
	./app/App_LoadSettings.cpp
	./app/App_OnCleanup.cpp
	./app/App_OnEvent.cpp
	./app/App_OnInit.cpp
	./app/App_OnLoop.cpp
	./app/App_OnRender.cpp
	./app/Event.cpp
	./app/FPS.cpp
	./app/Surface.cpp
	
	./game/Entity.cpp
	./game/EntityCol.cpp
	./game/Player.cpp
	./game/Bullet.cpp
	./game/Enemy.cpp
	./game/Powerup.cpp
	
	./settings/Settings.cpp
	./settings/settings.txt
	
	./world/Camera.cpp
	./world/Level.cpp
	./world/Tile.cpp
	./world/Zone.cpp
)

add_executable(gradius ${SOURCES})