project(AStar)
file(GLOB SRC_FILES "*.cpp" "*.c")
file(GLOB HEAD_FILES "*.h")
add_executable(AStar ${SRC_FILES} ${HEAD_FILES})