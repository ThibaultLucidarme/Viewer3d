#include "Shader.hpp"
#include <istream>
#include <cstring>

using namespace std;
using namespace sf;


Shader::Shader( void )
{

	_vao = 0;

	// Create the "remember all"
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);
	
	glGenBuffers(1, &_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);

}


string Shader::LoadFromFile( string filename )
{

	// Open the file
	FILE* fp = fopen (filename, "r");
	
	// Move the file pointer to the end of the file and determing the length
	fseek(fp, 0, SEEK_END);
	long file_length = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	
	// Allocate and zero out memory
	string shaderTxt;
	char* fileContent = new char[file_length+1];
	memset(fileContent, 0, sizeof fileContent);
	
	// Read
	fread (fileContent, 1, file_length, fp);
	fileContent[file_length+1] = '\0';
	strcpy(fileContent, shaderTxt.c_str());

	// Free memory and close file
	delete [] fileContent;
	fclose(fp);


	return shaderTxt;
	
}


GLint Shader::MakeShader( string filename , GLint vertexType )
{

	string content = LoadFromFile( filename.c_str() );
	
	GLint id = glCreateShader(GL_FRAGMENT_SHADER);
	
	glShaderSource( id , 1, (const GLchar**)& content.c_str() , NULL);
	glCompileShader( id );
	

	bool compiledCorrectly = compiledStatus( vertexShaderID );

	return (compiledCorrectly) ? id : -1;

}

void Shader::SetVertexShader( string filename ) 
{
	_vertexShaderID = MakeShader( filename, GL_VERTEX_SHADER );
}


void Shader::SetFragmentShader( string filename ) 
{
	_fragmentShaderID =  MakeShader( filename, GL_FRAGMENT_SHADER );
}



GLint Shader::MakeProgram( void ) 
{

	_shaderProgramID = glCreateProgram();

	glAttachShader(_shaderProgramID, _vertexShaderID);
	glAttachShader(_shaderProgramID, _fragmentShaderID);
	glLinkProgram(_shaderProgramID);

	return _shaderProgramID;
}

/*
void Shader::LoadDataToGPU( Mesh* mesh, bool useUVTexture, bool useIndexArrayBuffer )
{

	// 8 pieces of data: position (x, y, z), normal (x, y, z), UV (s, t)
	// 6 pieces of data: position (x, y, z), normal (x, y, z), no UV
	int dimension = (useUVTexture) ? 8 : 6;

	int verticesSize = mesh->GetNumberVertices()*sizeof(GLfloat);

	// Create the buffer, but don't load anything yet
	glBufferData(GL_ARRAY_BUFFER, size*verticesSize, NULL, GL_STATIC_DRAW);
	// Load the vertex points, colors
	glBufferSubData(GL_ARRAY_BUFFER, 0, 			 3*verticesSize, mesh->GetVertices() );
	glBufferSubData(GL_ARRAY_BUFFER, 3*verticesSize, 3*verticesSize, mesh->GetNormals() );
	// Load UV
	if( useUVTexture)
		glBufferSubData(GL_ARRAY_BUFFER, 6*verticesSize, 2*verticesSize, mesh->GetUV() );



	if( useIndexArrayBuffer )
	{

		IndexBufferArray indexBuffer = mesh->GetIndexBufferArray();

		glGenBuffers(1, &(indexBuffer->id) ;
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer->id);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexBuffer->size*sizeof(GLint), indexBuffer->array, GL_STATIC_DRAW);
	
	}
	
}

*/

/*
double arr[100];
copy(v.begin(), v.end(), arr);



IndexBufferArray* Mesh::GetIndexBufferArray();

Mesh::GetNumberVertices
Mesh::GetVertices
Mesh::GetNormals
Mesh::GetUV

template struct IndexBufferArray 
{
	GLint id
	GLint size
	GLint* array
	
} IndexBufferArray;












*/