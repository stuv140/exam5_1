set(Boost_NO_BOOST_CMAKE ON)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

# Только файлы тестов, например, Edittest.cpp
add_executable(Edit_tests Edittest.cpp 
${PROJECT_SOURCE_DIR}/src/Document.cpp 
${PROJECT_SOURCE_DIR}/src/Line.cpp
${PROJECT_SOURCE_DIR}/src/Circle.cpp
${PROJECT_SOURCE_DIR}/src/Rectangles.cpp
${PROJECT_SOURCE_DIR}/src/Controller.cpp
${PROJECT_SOURCE_DIR}/src/View.cpp)

target_include_directories(Edit_tests PRIVATE ${PROJECT_SOURCE_DIR}/include ${Boost_INCLUDE_DIRS})

target_link_libraries(Edit_tests PRIVATE ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_test(NAME Edit_tests COMMAND Edit_tests)
