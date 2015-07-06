#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "Shader.hpp"
#include "Mesh.hpp"


using namespace std;

int main()
{

	unsigned int size = 500;

	sf::ContextSettings glSettings;
	glSettings.majorVersion = 4;
	glSettings.minorVersion = 4;

    sf::RenderWindow window(sf::VideoMode(size, size), 
    						"Viewer3d -- SFML / OpenGL Shader", 
    						sf::Style::Titlebar|sf::Style::Resize|sf::Style::Close,
    						glSettings );

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    

    glClearColor(1.0f,0.0f,1.0f,1.0f);


    cout<<"create shaders"<<endl;
    Shader vertexShader( "../src/shaders/vertexShader.vsh", GL_VERTEX_SHADER );
    Shader fragmentShader( "../src/shaders/fragmentShader.fsh", GL_FRAGMENT_SHADER );
    
    cout<<"create program"<<endl;
    ShaderProgram prgm;
    prgm.Make( &vertexShader, &fragmentShader );


    cout<<"create mesh"<<endl;
    Mesh mesh;


//*
    bool running = true;
    while (running)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed ||
            	sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
	        	sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
				running = false;

			else if (event.type == sf::Event::Resized)
            	glViewport(0, 0, event.size.width, event.size.height);

        }

//*/

        mesh.Draw( &prgm );

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        window.clear();
        // window.draw(shape);
        window.display();
    }

        cout<<"end"<<endl;
    return EXIT_SUCCESS;
}

