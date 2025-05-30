#include "includes.h"

const GLuint WIDTH = 1200, HEIGHT = 900;

GLfloat last_time = 0.0f;
GLint frame_count = 0, fps = 0;

void framebuffer_size_callback(GLFWwindow *window, GLint width, GLint height) {
  glViewport(0, 0, width, height);
}

GLFWwindow *create_window(GLchar const *title) {
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, title, nullptr, nullptr);

  if (window == nullptr) {
    std::cout << "\tERROR::Failed to create window." << std::endl;
    return nullptr;
  }
  glfwMakeContextCurrent(window);

  if (window == nullptr)
    return nullptr;

  glewExperimental = GL_TRUE;
  if (GLEW_OK != glewInit()) {
    std::cout << "\tFailed to initionalize GLEW." << std::endl;
    return NULL;
  }
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  return window;
}

void close_action_button(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}

// Function to update and display FPS
void updateFPS(GLFWwindow* window) {
    double current_time = glfwGetTime();
    frame_count++;

    // If a second has passed
    if (current_time - last_time >= 1.0) {
        fps = frame_count / (current_time - last_time);
        frame_count = 0;
        last_time = current_time;

        // Update window FPS
        std::cout << "FPS: " << fps << std::endl;
    }
}
