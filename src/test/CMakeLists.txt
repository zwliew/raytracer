include_directories(..)

file(GLOB SOURCE_FILES *.h *.cpp)

add_executable(raytracer_test ${SOURCE_FILES})
target_link_libraries(raytracer_test raytracer_lib)
