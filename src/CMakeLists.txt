find_package(Libzdb REQUIRED)

file(GLOB_RECURSE libzdbmm_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*.cc ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)

include_directories(${LIBZDB_INCLUDE_DIRS})

add_library(zdbmm SHARED ${libzdbmm_SRCS})

install(TARGETS zdbmm DESTINATION lib)
install(FILES zdbmm.h SQLExceptionmm.h DESTINATION include/zdbmm)
