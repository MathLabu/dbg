cmake_minimum_required (VERSION 3.1)
project(dbg VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

# Define the libraries targets
add_library(on INTERFACE)
target_compile_options(on
    INTERFACE "-DDBG_DEBUG_FLAG_=1"
)
target_compile_definitions(on
    INTERFACE LIBRARY_HEADER_ONLY
)

add_library(off INTERFACE)
target_compile_options(off
    INTERFACE "-DDBG_DEBUG_FLAG_=0"
)
target_compile_definitions(off
    INTERFACE LIBRARY_HEADER_ONLY
)

# Configure version
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${PROJECT_BINARY_DIR}/dbg-version.cmake"
    VERSION 0.1
    COMPATIBILITY AnyNewerVersion
)
# Install the header files of the library.       
install(FILES dbg.h DESTINATION include/dbg)
set(DBG_INSTALL_DIR lib/dbg)

# Generate the dbg-config file which makes dbg available to find_package commands.
include(CMakePackageConfigHelpers)
configure_package_config_file(
    dbg-config.cmake.in
    "${PROJECT_BINARY_DIR}/dbg-config.cmake"
    INSTALL_DESTINATION ${DBG_INSTALL_DIR}
)

# Define dbg export as the export for target dbg.
install(TARGETS on off
    EXPORT dbg-targets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include 
    PUBLIC_HEADER DESTINATION include
    BUNDLE DESTINATION bin
)

# Install an export file which allows consumers to use the target dbg::on and dbg::off in their project.
install(EXPORT dbg-targets
  NAMESPACE dbg::
  DESTINATION ${DBG_INSTALL_DIR}/cmake
)

# Installe the auto generated files to make the targets available through find_package.
install(FILES ${CMAKE_BINARY_DIR}/dbg-config.cmake
  DESTINATION ${DBG_INSTALL_DIR}/cmake
)
