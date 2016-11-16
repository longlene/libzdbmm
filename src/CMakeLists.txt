find_package(Libzdb REQUIRED)
include(CMakePushCheckState)
include(CheckFunctionExists)

cmake_push_check_state(REST)
set(CMAKE_REQUIRED_LIBRARIES ${LIBZDB_LIBRARIES})
check_function_exists(Exception_init HAVE_EXCEPTION_INIT)
cmake_pop_check_state()

if (NOT HAVE_EXCEPTION_INIT)
    message(FATAL_ERROR "Exception_init required in libzdb")
endif()

file(GLOB_RECURSE libzdbmm_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*.cc ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)

include_directories(${LIBZDB_INCLUDE_DIRS})

add_library(zdbmm SHARED ${libzdbmm_SRCS})

install(TARGETS zdbmm DESTINATION lib)
install(FILES zdbmm.h DESTINATION include/zdbmm)
