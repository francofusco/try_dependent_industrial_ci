cmake_minimum_required(VERSION 3.0)
project(bar)
add_compile_options(-std=c++11)
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs foo sequences)

catkin_package(
  CATKIN_DEPENDS roscpp std_msgs foo sequences
  INCLUDE_DIRS include
)


###########
## BUILD ##
###########

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(bar_node src/bar_node.cpp)
target_link_libraries(bar_node ${catkin_LIBRARIES})

add_executable(collatz_node src/collatz_node.cpp)
target_link_libraries(collatz_node ${catkin_LIBRARIES})


#############
## INSTALL ##
#############

# executables
install(TARGETS bar_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(TARGETS collatz_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

# headers
install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  PATTERN ".svn" EXCLUDE
)
