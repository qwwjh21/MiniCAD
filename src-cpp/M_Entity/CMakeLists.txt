project(M_Entity)

file(GLOB SRCS *.cpp)
file(GLOB HDRS *.h *.hpp)

add_library(${PROJECT_NAME} STATIC ${HDRS} ${SRCS})

include_directories(${CMAKE_SOURCE_DIR}/src-cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC
		M_Core
)