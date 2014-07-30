project(MultiSliceSobelEdgeDetector)

cmake_minimum_required(VERSION 2.8)

find_package(ITK REQUIRED)

include(${ITK_USE_FILE})

add_executable(MultiSliceSobelEdgeDetector
  main.cxx
)

target_link_libraries(MultiSliceSobelEdgeDetector
  ${ITK_LIBRARIES}
)