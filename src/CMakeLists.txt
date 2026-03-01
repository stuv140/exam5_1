cmake_minimum_required(VERSION 3.10)

# Проект называется Editor
project(Editor VERSION 0.1.0 LANGUAGES CXX)

# Стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ищем все файлы в папке src
#file(GLOB_RECURSE SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.cpp" "*.hpp")
set(SOURCE_FILES
    Editor.cpp
    Document.cpp
    Controller.cpp
    GraphicPrimitive.cpp
    Line.cpp
    Circle.cpp
    Rectangles.cpp
    View.cpp
)

# Добавляем исполняемый файл
add_executable(Editor ${SOURCE_FILES})

# Подключаем директории с заголовочными файлами
target_include_directories(Editor PRIVATE ${PROJECT_SOURCE_DIR}/../include)

# Установим исполняемый файл
install(TARGETS Editor RUNTIME DESTINATION bin)
