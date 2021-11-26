add_subdirectory(test)

file(GLOB SOURCE_FILES *.h *.cpp)

add_library(raytracer_lib STATIC ${SOURCE_FILES})
target_link_libraries(raytracer_lib ${CONAN_LIBS})

add_executable(raytracer main.cpp)
target_link_libraries(raytracer raytracer_lib)
