project(gradius)

add_subdirectory(app)
add_subdirectory(game)
add_subdirectory(gfx)
add_subdirectory(settings)
add_subdirectory(world)

add_executable(gradius app/App.cpp)