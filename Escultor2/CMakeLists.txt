cmake_minimum_required(VERSION 3.0.0)
project(Sculptor VERSION 0.1.0)

add_executable(${PROJECT_NAME})

file(GLOB SOURCES ./*.cpp)
file(GLOB HEADERS ./*.h)

target_sources(${PROJECT_NAME}
    PRIVATE
      ${SOURCES}
      ${HEADERS}
)