#version 460 core
out vec4 FragColor;
uniform vec4 change_color;

void main() {
    FragColor = change_color;
}
