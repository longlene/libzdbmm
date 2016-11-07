find_package(PkgConfig)

pkg_check_modules(LIBZDB QUIET zdb)

find_path(LIBZDB_INCLUDE_DIR zdb.h
    PATH_SUFFIXES zdb)

find_library(LIBZDB_LIBRARY NAMES zdb libzdb)

set(LIBZDB_LIBRARIES ${LIBZDB_LIBRARY} )
set(LIBZDB_INCLUDE_DIRS ${LIBZDB_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(libzdb DEFAULT_MSG
    LIBZDB_LIBRARY LIBZDB_INCLUDE_DIR)

#message(STATUS "Found Libzdb: ${LIBZDB_INCLUDE_DIRS}")
#message(STATUS "Found Libzdb: ${LIBZDB_LIBRARIES}")

mark_as_advanced(LIBZDB_INCLUDE_DIR LIBZDB_LIBRARY )
