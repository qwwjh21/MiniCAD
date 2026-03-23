project(M_Core)

file(GLOB SRCS *.cpp)
file(GLOB HDRS *.h *.hpp)

add_library(${PROJECT_NAME} STATIC ${HDRS} ${SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC 
	Qt5::OpenGL	
	OpenGL::GL
)