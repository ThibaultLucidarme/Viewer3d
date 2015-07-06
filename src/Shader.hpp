#ifndef __SHADER__
#define __SHADER__

#include <SFML/OpenGL.hpp>
#include <string>



class Shader 
{

private:

	GLuint _shaderID;

	GLuint _vao;
	GLuint _vbo;

	bool _useUVTexture;
	bool _useIndexArrayBuffer;


	std::string LoadFromFile( std::string filename );
	void Compile( std::string source , GLenum shaderType );
	// void LoadMeshToGPU( Mesh* mesh, bool useUVTexture=false, bool useIndexArrayBuffer=false );


public:

	Shader( std::string filename , GLenum vertexType );
	~Shader( void );

	void Delete( void );
	GLuint getID( void );


};

class ShaderProgram
{

private: 
	GLuint _shaderProgramID;

public:

	ShaderProgram( void );
	~ShaderProgram( void );
	void Make( Shader* vertexShader, Shader* fragmentShader );
	void Use( void );

};




#endif