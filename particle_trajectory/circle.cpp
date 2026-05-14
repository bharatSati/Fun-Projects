#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>


int main(){
    sf::RenderWindow window(sf::VideoMode({1000,1000}),"Circular Particle");
    
    // lets draw the centre
    sf::CircleShape centre;
    centre.setRadius(2.f);
    centre.setPosition({500.f - 2.f,500.f - 2.f});

    float r = 100.0f;

    // lets draw the outline of the trajectory circle
    sf::CircleShape trajectory;
    trajectory.setRadius(r);
    trajectory.setPosition({500.f - r,500.f - r});
    trajectory.setFillColor(sf::Color::Transparent);
    trajectory.setOutlineThickness(1.f);
    trajectory.setOutlineColor(sf::Color::White);

    
    // lets draw a point particle
    // this particle will move in a radious of 100
    float angle = 0.f;
    sf::CircleShape particle;
    particle.setFillColor(sf::Color::Cyan);
    particle.setRadius(5.f);
    


    while(window.isOpen()){
         while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        angle += 0.001f;
        float x = 500 + r * std::cos(angle);
        float y = 500 + r * std::sin(angle);
        particle.setPosition({x-5.f,y-5.f});

        window.draw(centre);
        window.draw(trajectory);
        window.draw(particle);
        
        window.display();
    }
}
