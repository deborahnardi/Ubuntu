# @file  02PhaseFieldCpp/CMakeLists.txt  -- CMake file for the Phase Field Library

file(GLOB FEM *.h)
file(GLOB FEM_src *.cpp)

set(FEM ${FEM} PARENT_SCOPE)
set(FEM_SRC ${FEM_src} PARENT_SCOPE)