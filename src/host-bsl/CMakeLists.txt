add_custom_command(OUTPUT
	"${CMAKE_CURRENT_BINARY_DIR}/rlparse.c"
	"${CMAKE_CURRENT_BINARY_DIR}/rlreduce.cc"
	DEPENDS rlparse.lm
	COMMAND colm::colm
	ARGS -I.. -c -b rlparseBsl
	-o "${CMAKE_CURRENT_BINARY_DIR}/rlparse.c"
	-m "${CMAKE_CURRENT_BINARY_DIR}/rlreduce.cc"
	rlparse.lm
	WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}")

add_custom_command(OUTPUT
	"${CMAKE_CURRENT_BINARY_DIR}/rlhc.c"
	DEPENDS rlhc.lm
	COMMAND colm::colm
	ARGS -I.. -c -b rlhcBsl
	-o "${CMAKE_CURRENT_BINARY_DIR}/rlhc.c"
	rlhc.lm
	WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}")

add_executable(ragel-bsl main.cc
	"${CMAKE_CURRENT_BINARY_DIR}/rlhc.c"
	"${CMAKE_CURRENT_BINARY_DIR}/rlparse.c"
	"${CMAKE_CURRENT_BINARY_DIR}/rlreduce.cc")

target_link_libraries(ragel-bsl PRIVATE libragel libfsm)

if(${PROJECT_NAME}_MAKE_INSTALL)
	install(TARGETS ragel-bsl
		EXPORT ${_PACKAGE_NAME}-targets
		RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
		LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
		ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}")
endif()
