cmake_minimum_required(VERSION 3.30.3)
project(HR.cm VERSION 0.1.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set cross-compilation BEFORE any other commands
if(MINGW OR CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_SYSTEM_NAME Windows)
    set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
    set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
endif()

# Set the policy to suppress the warning
if(POLICY CMP0072)
    cmake_policy(SET CMP0072 NEW)
endif()

# Find the required packages
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)

set(GLEW_INCLUDE_DIRS /usr/x86_64-w64-mingw32/include)
set(GLEW_LIBRARIES /usr/x86_64-w64-mingw32/lib/libglew32.a)


# Include directories
include_directories(${GLEW_INCLUDE_DIRS} ${GLM_INCLUDE_DIRS})

# Add the executable
add_executable(HR.cm src/main.cpp)

# Link the libraries
target_link_libraries(HR.cm
    glfw
    OpenGL::GL
    GLEW::GLEW
)

# Copy shader files and others file to the build directory
file(COPY shaders/ DESTINATION ${CMAKE_BINARY_DIR})
file(COPY src/resources/images/ DESTINATION ${CMAKE_BINARY_DIR})

#Includes the folder
include_directories(${PROJECT_SOURCE_DIR}/include/)
