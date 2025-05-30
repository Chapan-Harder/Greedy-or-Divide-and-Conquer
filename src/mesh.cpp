#include "shader.hpp"

class Mesh {
public:
  GLint color = 0;
  GLint transform_loc = 0;
  glm::vec3 position = glm::vec3(0.0f);
  float scale = 1.0f;

  Mesh() : VBO(0), VAO(0) , mesh_shader(nullptr) {}

  ~Mesh() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
  }


  /// Make the 2D triangle like --> triangle.make_triangle(0.5f, 0.5f)
  // --------------------------------------------------------------------------
	void make_triangle(GLfloat vrt_x, GLfloat vrt_y) {
  	GLfloat vertices[] = {
  		// Positions
  		-vrt_x, -vrt_y, 0.0f,
  		vrt_x, -vrt_y, 0.0f,
  		vrt_x - vrt_x, vrt_y, 0.0f
  	};

    glGenVertexArrays(1, &VAO);
  	glGenBuffers(1, &VBO);

  	glBindBuffer(GL_ARRAY_BUFFER, VBO);
  	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  	glBindVertexArray(VAO);

  	// Position Attribute
  	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
  	glEnableVertexAttribArray(0);

  	glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

	  mesh_shader = new Shader("Mesh-Vert.vs", "Mesh-Frag.fs");
	  color = glGetUniformLocation(mesh_shader->ID, "change_color"); // Get uniform location
	  transform_loc = glGetUniformLocation(mesh_shader->ID, "transform");
	}

  void draw_triangle() {
    mesh_shader->use();

    // Create transformations
    glm::mat4 transform = glm::mat4(1.0f);
    transform = glm::translate(transform, position);
    transform = glm::scale(transform, glm::vec3(scale, scale, 1.0f));

    // Pass transformation matrix to shader
    glUniformMatrix4fv(transform_loc, 1, GL_FALSE, glm::value_ptr(transform));

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
  }
  // --------------------------------------------------------------------------

  /// Make the 2D square like --> square.make_square(0.5f, 0.5f)
  // --------------------------------------------------------------------------
	void make_square(GLfloat vrt_x, GLfloat vrt_y) {
	  GLfloat vertices[] = {
	    // Positions-1
	    -vrt_x, -vrt_y, 0.0f,
	    vrt_x, -vrt_y, 0.0f,
	    vrt_x, vrt_y, 0.0f,
	    // Positions-2
	    -vrt_x, -vrt_y, 0.0f,
	    -vrt_x, vrt_y, 0.0f,
	    vrt_x, vrt_y, 0.0f,
	  };

    glGenVertexArrays(1, &VAO);
  	glGenBuffers(1, &VBO);

  	glBindBuffer(GL_ARRAY_BUFFER, VBO);
  	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  	glBindVertexArray(VAO);

  	// Position Attribute
  	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
  	glEnableVertexAttribArray(0);

  	glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

	  mesh_shader = new Shader("Mesh-Vert.vs", "Mesh-Frag.fs");
	  color = glGetUniformLocation(mesh_shader->ID, "change_color"); // Get uniform location
	  transform_loc = glGetUniformLocation(mesh_shader->ID, "transform");
	}

  void draw_square() {
    mesh_shader->use();

    // Create transformations
    glm::mat4 transform = glm::mat4(1.0f);
    transform = glm::translate(transform, position);
    transform = glm::scale(transform, glm::vec3(scale, scale, 1.0f));

    // Pass transformation matrix to shader
    glUniformMatrix4fv(transform_loc, 1, GL_FALSE, glm::value_ptr(transform));

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
  }
  // --------------------------------------------------------------------------

  /// Set the color for the meshes, like --> mesh_name.set_color(1.0f, 1.0f, 1.0f, 1.0f)
  // -------------------------------------------------------------------------- 
  void set_color(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    mesh_shader->use();
    glUniform4f(color, red, green, blue, alpha);
  }
  // -------------------------------------------------------------------------- 

  // Set the position
  // -------------------------------------------------------------------------- 
  void set_position(GLfloat x, GLfloat y) {
    position = glm::vec3(x, y, 0.0f);
  }
  // -------------------------------------------------------------------------- 

  // Set the scale
  // -------------------------------------------------------------------------- 
  void set_scale(GLfloat s) {
    scale = s;
  }
  // -------------------------------------------------------------------------- 

private:
  GLuint VBO, VAO;
  Shader *mesh_shader;
};
