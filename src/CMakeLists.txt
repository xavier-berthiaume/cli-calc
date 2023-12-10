include_directories(.)

add_executable(cli-calc main.cpp)
target_sources(cli-calc
	PUBLIC interface.cpp
	PUBLIC operations.cpp
)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

target_link_libraries(cli-calc ${CURSES_LIBRARIES})
