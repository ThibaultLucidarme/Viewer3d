
#ifndef __BUDDHA__
#define __BUDDHA__

#include <SFML/OpenGL.hpp>
#include <vector>
#include <glm/glm.hpp>

#include "Shader.hpp"


class Mesh
{


	private:

	std::vector<glm::vec3> _vertices;
	std::vector<glm::vec3> _normals;
	std::vector<glm::vec3> _indices;
	std::vector<glm::vec2> _uv;
	GLuint iab_id;


	GLfloat test_vertices[9] = {
		-0.5000f, -0.5000f, 0.0000f,
	  	 0.0000f,  0.5000f, 0.0000f,
	  	 0.5000f, -0.5000f, 0.0000f
	};


	GLfloat test_normals[9] = {
	  	0.0000f, 0.0000f, 1.0000f,
	  	0.0000f, 0.0000f, 1.0000f,
	  	0.0000f, 0.0000f, 1.0000f
	};

	GLfloat test_indices[3] = {
		1, 2, 3
	};


	void LoadToGPU( bool useUVTexture=false, bool useIndexArrayBuffer=false );

	public:

	Mesh();
	~Mesh();

	std::vector<glm::vec3> GetVertices();
	std::vector<glm::vec3> GetNormals();
	std::vector<glm::vec2> GetUV();
	std::vector<glm::vec3> GetIndexBufferArray();

	void Draw( ShaderProgram* pgrm );


};




#endif
