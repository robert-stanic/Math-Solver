
cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(MathSolver VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# add the MathCore library
add_subdirectory(src)
add_subdirectory(test)


# list(APPEND EXTRA_LIBS MathCore)


# add the executable
add_executable(MathSolver src/MathSolver.cpp)


# target_link_libraries(MathSolver PUBLIC ${EXTRA_LIBS})

# configured file will be written into the binary tree, we must add that directory
# target_include_directories(MathSolver PUBLIC
#                           "${PROJECT_BINARY_DIR}"
#                           )



# install(TARGETS MathSolver DESTINATION bin)
# install(FILES "${PROJECT_BINARY_DIR}/MathSolverConfig.hpp"
#  DESTINATION include
#  )





enable_testing()
add_test(NAME SetTest COMMAND SetTest)











#include(InstallRequiredSystemLibraries)
#set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
#set(CPACK_PACKAGE_VERSION_MAJOR "${MathSolver_VERSION_MAJOR}")
#set(CPACK_PACKAGE_VERSION_MINOR "${MathSolver_VERSION_MINOR}")
#include(CPack)


