set(SOURCES
    main.cpp
)
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC 
		Qt5::Widgets
		Qt5::OpenGL	
		OpenGL::GL
		core
		entity
)