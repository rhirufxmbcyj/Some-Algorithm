file(GLOB SRC_FILES "*.cpp" "*.c")
file(GLOB HEAD_FILES "*.h")
add_executable(BigNumber ${SRC_FILES} ${HEAD_FILES})