#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include "Shader.hpp"

int main()
{

	unsigned int size = 500;

	sf::ContextSettings glSettings;
	glSettings.majorVersion = 3;
	glSettings.minorVersion = 0;

    sf::RenderWindow window(sf::VideoMode(size, size), 
    						"Viewer3d -- SFML / OpenGL Shader", 
    						sf::Style::Titlebar|sf::Style::Resize|sf::Style::Close,
    						glSettings );

    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    

    sf::CircleShape shape(size/2);


    shape.setFillColor(sf::Color::Green);

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



		Shader shader;
		shader.SetVertexShader("../src/shaders/vertexShader.vsh");
		shader.SetFragmentShader("../src/shaders/fragmentShader.vsh");
		shader.MakeProgram();




        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        window.clear();
        window.draw(shape);
        window.display();
    }

    return EXIT_SUCCESS;
}

