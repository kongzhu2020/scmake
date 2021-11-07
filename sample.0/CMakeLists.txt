cmake_minimum_required(VERSION 3.10)

# set the project name and version number
project(SCMake VERSION 1.0)

# user define
option(USE_SMATH "Use tutorial provided math implementation" ON)
message("USE_SMATH=${USE_SMATH}")

# configure a header file to pass the version number to the source code
configure_file(SCMakeConfig.h.in SCMakeConfig.h)

# specify the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

if(USE_SMATH)
  add_library(smath SHARED 
          smath/smath.c
          )
  target_include_directories(smath PUBLIC
          smath/smath.h
          )

  list(APPEND EXTRA_LIBS smath)
  list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/smath")
endif()

# add the executable
add_executable(main main.c)


message("EXTRA_INCLUDES=${EXTRA_INCLUDES}")
message("EXTRA_LIBS=${EXTRA_LIBS}")

# target link library
target_link_libraries(main PUBLIC
        ${EXTRA_LIBS}
        )


# add the include tree 
target_include_directories(main PUBLIC 
        ${PROJECT_BINARY_DIR} 
        ${EXTRA_INCLUDES}
        )

