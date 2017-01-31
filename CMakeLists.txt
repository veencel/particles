cmake_minimum_required(VERSION 3.5)
project(Charged_Particles)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")
set(SOURCE_FILES main.cpp GParticle.h GParticle.cpp Vector.cpp Vector.h GParticleSet.h Ring.h Constans.h)
add_executable(Charged_Particles ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Charged_Particles ${SFML_LIBRARIES})
endif()

find_package(Boost 1.61.0)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(Charged_Particles ${Boost_LIBRARIES})
endif()
