#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>
#include<eigen3/Eigen/Dense>

int main(){



sf::RenderWindow window(sf::VideoMode(400,400),"collision checker");

window.setFramerateLimit(60);

sf::CircleShape circle(20.0f);

sf::CircleShape square(100.0f, 4);

sf::CircleShape octagon(100.0f, 8);

sf::VertexArray quad(sf::Quads, 4);

sf::Transform t;
t.translate(10.f, 100.f);
t.rotate(90.f);
t.translate(-10.f, 50.f);
t.scale(0.5f, 0.75f);

sf::RenderStates states;
states.transform = t;

// define it as a rectangle, located at (10, 10) and with size 100x100
quad[0].position = sf::Vector2f(10.f, 10.f);
quad[1].position = sf::Vector2f(110.f, 10.f);
quad[2].position = sf::Vector2f(110.f, 110.f);
quad[3].position = sf::Vector2f(10.f, 110.f);

// define its texture area to be a 25x50 rectangle starting at (0, 0)
quad[0].texCoords = sf::Vector2f(0.f, 0.f);
quad[1].texCoords = sf::Vector2f(25.f, 0.f);
quad[2].texCoords = sf::Vector2f(25.f, 50.f);
quad[3].texCoords = sf::Vector2f(0.f, 50.f);

sf::RectangleShape rect(sf::Vector2f(50.0f, 50.0f) );
rect.setOrigin(rect.getSize()/2.0f);
rect.setPosition(50.0f, 50.0f);

sf::RectangleShape rect2(sf::Vector2f(10.0f, 10.0f) );

sf::Vector2f inpt = {50.0f, 50.0f};

sf::Vertex lines[] = {

sf::Vertex(sf::Vector2f(50.0f, 50.0f)), sf::Vertex(sf::Vector2f(100.0f, 100.0f))


};

rect.rotate(30.0f);

sf::ConvexShape anyshape;

anyshape.setPointCount(2);

// anyshape.setPoint(0, sf::Vector2f(0.0f, 0.0f));
// anyshape.setPoint(1, sf::Vector2f(100.0f, 100.0f));
// anyshape.setPoint(2, sf::Vector2f(10.0f, 60.0f));

anyshape.setPoint(0, sf::Vector2f(0.f, 0.f));
anyshape.setPoint(1, sf::Vector2f(150.f, 10.f));
anyshape.setPoint(2, sf::Vector2f(120.f, 90.f));


anyshape.setFillColor(sf::Color::Green);

rect.setFillColor(sf::Color::Magenta);

rect.setFillColor(sf::Color::Blue);

circle.setFillColor(sf::Color::Blue);

square.setFillColor(sf::Color::Cyan);

octagon.setFillColor(sf::Color::Red);


sf::FloatRect bbx1 = rect.getGlobalBounds();
sf::FloatRect bbx2 = rect2.getGlobalBounds();

if(bbx1.intersects(bbx2)){

std::cout<<"colidding with quad"<<std::endl;


}

else{


    std::cout<<"not colliding"<<std::endl;
}

int i = 0;


while(window.isOpen())
{

    sf::Event event;

    while(window.pollEvent(event)){

        if(event.type == sf::Event::Closed){

            window.close();

        }


    }


    window.clear(sf::Color::Black);
    // window.draw(circle);

    while(i != 100){

        rect.rotate(i);
        window.draw(rect);
    // window.draw(rect2);
    // window.draw(square);
    // window.draw(octagon);
    // window.draw(rect, states);
    // window.draw(quad);
    // window.draw(lines, 2, sf::Lines);
    window.display();
     window.clear(sf::Color::Black);
     i+=5;

    }

}



return 0;



}