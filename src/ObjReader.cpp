#include <ifstream>
#include "Mesh.hpp"



bool OBJReader::ReadMeshFromFile( Mesh* mesh, std::string filename ){

	ifstream inputFile( filename, ios::in | ios::binary | ios::nocreate );
    if ( inputFile.fail() ) return false;   // "Couldn't Open The Model File."


    // Get file size
    inputFile.seekg( 0, ios::end );
	long fileSize = inputFile.tellg();
	inputFile.seekg( 0, ios::beg );


	// Tmp data buffer
	GLbyte *tmpDataBuffer = new GLbyte[fileSize];
	inputFile.read( tmpDataBuffer, fileSize );




	const GLbyte *pPtr = tmpDataBuffer;
	MS3DHeader *pHeader = ( MS3DHeader* )pPtr;
	pPtr += sizeof( MS3DHeader );
	 
	if ( strncmp( pHeader->m_ID, "MS3D000000", 10 ) != 0 )
	    return false;   // "Not A Valid Milkshape3D Model File."
	 
	if ( pHeader->m_version < 3 || pHeader->m_version > 4 )
	    return false;   // "Unhandled File Version.  Only Milkshape3D Version 1.3 And 1.4 Is Supported."








	

	delete[] tmpDataBuffer;
	inputFile.close();

}


bool Mesh::Draw()
{

    GLboolean texEnabled = glIsEnabled( GL_TEXTURE_2D );

}



