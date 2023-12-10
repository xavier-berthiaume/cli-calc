include_directories(.)

add_executable(cli-calc main.cpp)
target_sources(cli-calc
	PUBLIC interface.cpp
	PUBLIC operations.cpp
)
