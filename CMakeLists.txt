# CMake 工程，读者应该熟悉了，我就不一一注释了
cmake_minimum_required( VERSION 2.8 )
project( test_project )

set( CMAKE_BUILD_TYPE Release )
set( CMAKE_CXX_FLAGS "-std=c++11 -Wall -O2 -march=native" )

list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules )


find_package( OpenCV REQUIRED )
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package( Ceres REQUIRED )
find_package( Eigen3 REQUIRED )

include_directories( 
${EIGEN3_INCLUDE_DIR} 
${CHOLMOD_INCLUDE_DIR}
${CERES_INCLUDE_DIRS}
${OPENGL_INCLUDE_DIRS}
${GLUT_INCLUDE_DIRS}
"/usr/local/include"
"/usr/include/SDL2"
)

link_directories("/usr/local/lib")

add_executable( test test.cpp )
target_link_libraries( test
    ${OpenCV_LIBS}
    ${CHOLMOD_LIBRARIES}
    ${CERES_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARY}
    simple2d
    SDL2
    SDL2_ttf
    SDL2_image
    SDL2_mixer
    GL
)
