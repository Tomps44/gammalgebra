cmake_minimum_required(VERSION 3.23)
project(gammalgebra VERSION 1.0 LANGUAGES CXX)

include(GNUInstallDirs)

add_library(${PROJECT_NAME} INTERFACE)

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)

target_include_directories(
    ${PROJECT_NAME} 
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# add_executable(gam-tests main.cpp)
# target_link_libraries(gam-tests PUBLIC gammalgebra)



