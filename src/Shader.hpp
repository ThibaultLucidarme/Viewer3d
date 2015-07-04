#ifndef __SHADER__
#define __SHADER__

#include <SFML/OpenGL.hpp>
#include <string>



class Shader 
{

private:

	GLint _vertexShaderID;
	GLint _fragmentShaderID;
	GLint _shaderProgramID;

	GLint _vao;
	GLint _vbo;
	GLint _indexBuffer;

	bool _useUVTexture;
	bool _useIndexArrayBuffer;


	std::string LoadFromFile( std::string filename );
	GLint MakeShader( std::string filename , GLint vertexType );

public:

	Shader( void );
	void SetVertexShader( std::string filename );
	void SetFragmentShader( std::string filename ); 
	GLint MakeProgram( void );
	//void LoadDataToGPU( Mesh* mesh, bool useUVTexture, bool useIndexArrayBuffer );


};




#endif