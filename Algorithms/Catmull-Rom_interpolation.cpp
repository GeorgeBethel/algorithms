#include<iostream>
#include<vector>
#include <cmath>
#include <SFML/Graphics.hpp>


/*


Introduction
=======================
Splines are a mathematical means of representing a curve, by specifying a series of points at intervals along the curve and defining a 
function that allows additional points within an interval to be calculated.  There are various functions available to approximate a curve, 
but in this method is focused on a spline known as the Catmull-Rom spline.

Catmull-Rom Splines
======================
The points that define a spline are known as "Control Points".  One of the features of the Catmull-Rom spline is 
that the specified curve will pass through all of the control points - this is not true of all types of splines. 


-P0-
  -          -P2-
    -       -   -
     -    -       -
      -p1-          -P3-

To calculate a point on the curve, two points on either side of the desired point are required, as shown on the left.  
The point is specified by a value t that signifies the portion of the distance between the two nearest control points.
Given the control points P0, P1, P2, and P3, and the value t, the location of the point can be calculated as (assuming uniform spacing of control points):

                             [ 0 2 0 0][P0]
                             [-1 0 1 0][P1]
q(t) = 0.5 * (1.0f,t,t2,t3) *[ 2 -5 4 -1][P2]
                             [-1 3 -3 1][P3]


      or 

q(t) = 0.5 *(  	(2 * P1) + (-P0 + P2) * t + (2*P0 - 5*P1 + 4*P2 - P3) * t2 + (-P0 + 3*P1- 3*P2 + P3) * t3)

the line will pass through all intermediate control points created by the above equation

## dependencies

SMFL 

    # Installation commands

    - sudo apt-get install libopenal-dev 

    - sudo apt-get install -y vorbis-tools 

    - sudo apt-get install libvorbis-dev 

    - sudo apt install libflac-dev 

    Or install from source 

    - git clone https://github.com/SFML/SFML.git 

    - cd SFML 

    - mkdir build && cd build 

    - cmake .. 

    - make 

    - make install 

## how to compile

compile using the command: c++ -o Catmull-Rom_interpolation Catmull-Rom_interpolation.cpp -lsfml-graphics -lsfml-window -lsfml-system

*/

struct Point
{
    
    float x_;
    float y_;

    Point(float x, float y): x_{x}, y_{y}
    {}

};

class catmullRomInterpolation{

    public:
        std::vector<Point> points_;
        catmullRomInterpolation(std::vector<Point>& points);
        catmullRomInterpolation();
        void get_intermediatePoints(std::vector<Point>& points);
        void printPoints();
        std::vector<Point> getPoints();

    private:

        std::vector<Point> output_points;
        void makePoint(float c_tx, float c_ty);

};

catmullRomInterpolation::catmullRomInterpolation(std::vector<Point>& points): points_{points}{}

catmullRomInterpolation::catmullRomInterpolation(){std::cout<<"hello"<<std::endl;}

std::vector<Point> catmullRomInterpolation::getPoints(){



    return output_points;

}

void catmullRomInterpolation::get_intermediatePoints(std::vector<Point>& points){

    for(int p = 1; p < points.size()-2; p++){ // to ensure that there is exactly 4 points available to interpolate

        Point p0 = points[p - 1];
        Point p1 = points[p];
        Point p2 = points[p + 1];
        Point p3 = points[p + 2];

        // this is the loop where the intermediate points are calculated
        for(int i = 0; i < 10; i++){


            float t = (float)i /10.0f;

            float x = 0.5f * ((2.0f * p1.x_) +
                    (-p0.x_ + p2.x_) * t +
                    (2.0f * p0.x_ - 5.0f * p1.x_ + 4.0f * p2.x_ - p3.x_) * t*t +
                    (-p0.x_ + 3.0f * p1.x_ - 3.0f * p2.x_ + p3.x_) * t*t*t);

            float y = 0.5f * ((2.0f * p1.y_) +
                    (-p0.y_ + p2.y_) * t +
                    (2.0f * p0.y_ - 5.0f * p1.y_ + 4.0f * p2.y_ - p3.y_) * t*t +
                    (-p0.y_ + 3.0f * p1.y_ - 3.0f * p2.y_ + p3.y_) * t*t*t);

            makePoint(x, y); // turns the coordinates into point types and push them into the vectors of Points
        }

    
    }
}

void catmullRomInterpolation::makePoint(float c_tx, float c_ty){


    Point C_xy = Point(c_tx, c_ty);

    output_points.push_back(C_xy);
    
}


void catmullRomInterpolation::printPoints(){

    for(int p = 0; p < output_points.size(); p++){

            std::cout<<"Point ("<<output_points[p].x_<<","<<output_points[p].y_<<")"<<std::endl;

    }
}


int main(){

//creat window object
sf::RenderWindow window(sf::VideoMode(800, 600), "before Catmull-Rom Interpolation");
sf::RenderWindow window2(sf::VideoMode(800, 600), "after Catmull-Rom Interpolation");

//set frame rate limit
window2.setFramerateLimit(60);
window.setFramerateLimit(60);

// creat vector of type point. add more points as you wish

std::vector<Point> input_points = {{100.0, 300.0}, {200.0, 200.0}, {300.0, 250.0}, {400.0, 150.0}, {500.0, 350.0}, {600.0, 250.0}, {700.0, 300.0}, {780, 250}};

catmullRomInterpolation interpolate;

interpolate.get_intermediatePoints(input_points);

interpolate.printPoints();

auto interpolatedPoints = interpolate.getPoints();

sf::VertexArray lines(sf::LineStrip, input_points.size());
    for (int i = 0; i < input_points.size(); i++) {
        lines[i].position = sf::Vector2f(input_points[i].x_, input_points[i].y_);
        lines[i].color = sf::Color::Red;
    }

sf::VertexArray curves(sf::LineStrip, interpolatedPoints.size());
    for (int i = 0; i < interpolatedPoints.size(); i++) {
        curves[i].position = sf::Vector2f(interpolatedPoints[i].x_, interpolatedPoints[i].y_);
        curves[i].color = sf::Color::Red;
    }

    while (window.isOpen() && window2.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }

        sf::Event event1;
        while (window2.pollEvent(event1))
        {
            if (event1.type == sf::Event::Closed)
                window2.close();

        }

        window.clear(sf::Color::Black);
        window.draw(lines);
        window2.draw(curves);
        window.display();
        window2.display();
    }

return 0;


}