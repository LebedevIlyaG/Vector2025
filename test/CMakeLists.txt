set(target VectorLibTest)

file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../third_party/gtest/googletest/include/gtest")

add_executable(${target} ${srcs} ${hdrs})
target_link_libraries(${target} gtest ${library})
