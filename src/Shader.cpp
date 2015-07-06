#include "Shader.hpp"
#include <istream>
#include <cstring>
#include <glm/glm.hpp>
#include <iostream>

using namespace std;
using namespace sf;


Shader::Shader( string filename , GLenum shaderType )
{

	_vao = 0;

	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);
	
	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);

	Compile( LoadFromFile(filename), shaderType );

}

Shader::~Shader( void )
{

	glDeleteBuffers(1, &_shaderID);
	glDeleteBuffers(1, &_vbo);
	glDeleteBuffers(1, &_vao);

	std::cout<<"release Shader"<<std::endl;

}


string Shader::LoadFromFile( string filename )
{

	// Open the file
	FILE* fp = fopen (filename.c_str(), "r");
	
	// Move the file pointer to the end of the file and determing the length
	fseek(fp, 0, SEEK_END);
	long file_length = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	
	// Allocate and zero out memory
	string shaderTxt;
	char* fileContent = new char[file_length+1];
	memset(fileContent, 0, file_length+1);
	
	// Read
	fread (fileContent , 1, file_length, fp);
	fileContent[file_length+1] = '\0';
	strcpy(fileContent, shaderTxt.c_str());

	// Free memory and close file
	delete [] fileContent;
	fclose(fp);


	return shaderTxt;
	
}


void Shader::Compile( string source , GLenum shaderType )
{

	GLchar* content = new GLchar[source.length()];
	copy( source.begin(), source.end(), content);


	_shaderID = glCreateShader( shaderType );
	
	glShaderSource( _shaderID , 1, (const GLchar**)&content , NULL);
	glCompileShader( _shaderID );

	delete [] content;

}

void Shader::Delete( void )
{
	glDeleteShader( _shaderID );
	std::cout<<"delete program"<<std::endl;
}

GLuint Shader::getID( void )
{
	return _shaderID;
}


ShaderProgram::ShaderProgram( void )
{
	_shaderProgramID = glCreateProgram();
}

ShaderProgram::~ShaderProgram( void )
{
	glDeleteProgram( _shaderProgramID );
	std::cout<<"release program"<<std::endl;
}


/* 
delete the shader - it won't actually be
destroyed until the program that it's attached
to has been destroyed 
*/
void ShaderProgram::Make( Shader* vertexShader, Shader* fragmentShader ) 
{

	glAttachShader( _shaderProgramID, vertexShader->getID() );
	glAttachShader( _shaderProgramID, fragmentShader->getID() );
	glLinkProgram( _shaderProgramID );

	vertexShader->Delete();
	fragmentShader->Delete();

}

void ShaderProgram::Use( void ) 
{
	glUseProgram(_shaderProgramID);
}



