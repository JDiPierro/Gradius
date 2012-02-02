project(gradius)

find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)

link_libraries(	${SDL_LIBRARY}
		${SDLIMAGE_LIBRARY}
		SDLmain)

set(
	SOURCES
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
	./game/Player.cpp
	
	./settings/Settings.cpp
	./settings/settings.txt
	
	./world/Camera.cpp
	./world/Level.cpp
	./world/Tile.cpp
	./world/Zone.cpp
	
	./gfx/option.png
)

add_executable(gradius ${SOURCES})