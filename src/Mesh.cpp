#include "Mesh.hpp"

#include <iostream>

Mesh::Mesh()
{

	for(int i=0; i<9; i++)
	{
		glm::vec3 v(test_vertices[i], test_vertices[i+1], test_vertices[i+2]);
		_vertices.push_back(v);
		i+=2;
	}

	for(int i=0; i<9; i++)
	{
		glm::vec3 n(test_normals[i], test_normals[i+1], test_normals[i+2]);
		_normals.push_back(n);
		i+=2;
	}

	for(int i=0; i<3; i++)
	{
		glm::vec3 idx(test_indices[i], test_indices[i+1], test_indices[i+2]);
		_indices.push_back(idx);
		i+=2;
	}

}

Mesh::~Mesh()
{
	std::cout<<"release Mesh"<<std::endl;
}


std::vector<glm::vec3> Mesh::GetVertices()
{
	return _vertices;
}

std::vector<glm::vec3> Mesh::GetNormals()
{
	return _normals;
}

std::vector<glm::vec2> Mesh::GetUV()
{
	return _uv;
}

std::vector<glm::vec3> Mesh::GetIndexBufferArray()
{
	return _indices;
}

void Mesh::Draw( ShaderProgram* pgrm )
{

	std::cout<<"Mesh::Draw 1"<<std::endl;

	LoadToGPU();

	std::cout<<"Mesh::Draw 2"<<std::endl;
	pgrm->Use(); 
	glDrawArrays(GL_TRIANGLE_STRIP, 0, _vertices.size() );
	glUseProgram(0);

}

void Mesh::LoadToGPU( bool useUVTexture, bool useIndexArrayBuffer )
{

	std::cout<<"Mesh::LoadToGPU 1"<<std::endl;
	// 8 pieces of data: position (x, y, z), normal (x, y, z), UV (s, t)
	// 6 pieces of data: position (x, y, z), normal (x, y, z), no UV
	int dimension = (useUVTexture) ? 8 : 6;

	// Create the buffer, but don't load anything yet
	glBufferData(GL_ARRAY_BUFFER, dimension * _vertices.size(), NULL, GL_STATIC_DRAW);
	// Load the vertex points, colors
	glBufferSubData(GL_ARRAY_BUFFER, 0				  				  , _vertices.size() * sizeof(glm::vec3), &_vertices[0] );
	glBufferSubData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(glm::vec3), _normals.size() * sizeof(glm::vec3) , &_normals[0] );

	std::cout<<"Mesh::LoadToGPU 2"<<std::endl;

	// Load UV
	/*
	if( useUVTexture)
	{
	glBufferSubData(GL_ARRAY_BUFFER, 2*sizeof(glm::vec3)*_vertices.size(), _uv.size()*sizeof(glm::vec2), &_uv[0] );
	}

	if( useIndexArrayBuffer )
	{
	glGenBuffers(1, &_indexBufferID) ;
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBufferID );
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexBuffer.size()*sizeof(glm::vec3), &indexBuffer[0], GL_STATIC_DRAW);

	}
	*/

}