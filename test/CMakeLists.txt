


add_executable(SetTest core/SetTest.cpp $<TARGET_OBJECTS:Set>)
target_include_directories(SetTest PUBLIC ${PROJECT_SOURCE_DIR}/src/core)
#target_link_libraries(ElementTest )


add_executable(FunctionTest core/FunctionTest.cpp $<TARGET_OBJECTS:Set> $<TARGET_OBJECTS:Function>)
target_include_directories(FunctionTest PUBLIC ${PROJECT_SOURCE_DIR}/src/core)

