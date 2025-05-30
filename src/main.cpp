#include "includes.h"
#include "window.cpp"
#include "mesh.cpp"
#include "ui.c"

// Clamp position based on screen bounds and object scale
void clampToBounds(glm::vec2& position, float scale) {
    float halfScale = scale * 0.5f;
    position.x = glm::clamp(position.x, -1.0f + halfScale, 1.0f - halfScale);
    position.y = glm::clamp(position.y, -1.0f + halfScale, 1.0f - halfScale);
}

// Process keyboard input
void processInput(GLFWwindow* window, glm::vec2& position, float speed, float scale) {
    static double lastTime = glfwGetTime();
    double currentTime = glfwGetTime();
    float deltaTime = currentTime - lastTime;
    lastTime = currentTime;

    float adjustedSpeed = speed * deltaTime * 60.0f; // Normalize to 60 FPS

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        position.y += adjustedSpeed;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        position.y -= adjustedSpeed;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        position.x -= adjustedSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        position.x += adjustedSpeed;

    clampToBounds(position, scale);
}

int main() {
    static GLFWwindow *window = create_window("---Practice---");

    // Create entities
    // --------------------------------------------------------------------------
    Mesh yellow_triangle;
    yellow_triangle.make_triangle(0.5f, 0.5f);
    yellow_triangle.set_color(1.0f, 1.0f, 0.0f, 1.0f);
    yellow_triangle.set_position(-0.8f, 0.8f);
    yellow_triangle.set_scale(0.2f);
    float triangle_scale = 0.2f;

    Mesh red_triangle;
    red_triangle.make_triangle(0.5f, 0.5f);
    red_triangle.set_color(1.0f, 0.0f, 0.0f, 1.0f);
    red_triangle.set_position(-0.8f, 0.8f);
    red_triangle.set_scale(0.2f);

    Mesh green_square;
    green_square.make_square(0.5f, 0.5f);
    green_square.set_color(0.0f, 1.0f, 0.0f, 1.0f);
    green_square.set_position(0.8f, -0.8f);
    green_square.set_scale(0.2f);
    float square_scale = 0.2f;
    // --------------------------------------------------------------------------

    glm::vec2 triangle_pos(-0.8f, 0.8f);
    glm::vec2 red_triangle_pos(-0.8f, 0.8f);
    glm::vec2 player_pos(0.8f, -0.8f);
    GLfloat movement_speed = 0.01f;
    GLfloat follow_speed = 0.005f;

    struct nk_context *ctx = nk_glfw3_init(window, NK_GLFW3_INSTALL_CALLBACKS, MAX_VERTEX_BUFFER, MAX_ELEMENT_BUFFER);
    struct nk_colorf bg_color = {0.07f, 0.07f, 0.07f, 1.0f}; 
    struct nk_colorf mesh_color = {1.0f, 0.0f, 1.0f, 1.0f}; 

    struct nk_font_atlas *defult_ui_font;
    nk_glfw3_font_stash_begin(&defult_ui_font);
    nk_glfw3_font_stash_end();

    set_style(ctx, THEME_CATPPUCCIN_MOCHA);

    bool show_main_ui = true;
    bool divide = false;
    bool greedy = false;

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        updateFPS(window);
        close_action_button(window);
        nk_glfw3_new_frame();

        // Player movement input
        processInput(window, player_pos, movement_speed, square_scale);
        green_square.set_position(player_pos.x, player_pos.y);

        // GUI
        if (show_main_ui) {
            create_main_menu_ui(ctx, &show_main_ui, &divide, &greedy);
        }

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Divide and conquer approach to make triangle follow square
        // --------------------------------------------------------------------------
        if (divide) {
            glm::vec2 direction = player_pos - triangle_pos;
            float distance = glm::length(direction);

            if (distance > 0.01f) {
                direction = glm::normalize(direction);
                triangle_pos += direction * follow_speed;
                if (glm::length(player_pos - triangle_pos) < follow_speed) {
                    triangle_pos = player_pos;
                }
            }

            clampToBounds(triangle_pos, triangle_scale);
            yellow_triangle.set_position(triangle_pos.x, triangle_pos.y);

            create_back_option(ctx, &show_main_ui, &divide, &greedy);
            green_square.draw_square();
            yellow_triangle.draw_triangle();
        }
        // --------------------------------------------------------------------------

        // greedy approach to make triangle follow square
        // --------------------------------------------------------------------------
        if (greedy) {
            float dx = player_pos.x - red_triangle_pos.x;
            float dy = player_pos.y - red_triangle_pos.y;

            if (std::abs(dx) > std::abs(dy)) {
                red_triangle_pos.x += (dx > 0 ? follow_speed : -follow_speed);
            } else {
                red_triangle_pos.y += (dy > 0 ? follow_speed : -follow_speed);
            }

            if (glm::length(player_pos - red_triangle_pos) < follow_speed) {
                red_triangle_pos = player_pos;
            }

            clampToBounds(red_triangle_pos, triangle_scale);
            red_triangle.set_position(red_triangle_pos.x, red_triangle_pos.y);

            create_back_option(ctx, &show_main_ui, &divide, &greedy);
            green_square.draw_square();
            red_triangle.draw_triangle();
        }
        // --------------------------------------------------------------------------

        nk_glfw3_render(NK_ANTI_ALIASING_ON);
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
