#include<iostream>
#include<vector>

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
        catmullRomInterpolation(std::vector<Point> points);
        catmullRomInterpolation();
        void get_intermediatePoints(std::vector<Point> points);
        void printPoints();

    private:

        std::vector<Point> output_points;
        void computePolynomial(float c_tx, float c_ty);

};


catmullRomInterpolation::catmullRomInterpolation(std::vector<Point> points): points_{points}


{}

  catmullRomInterpolation::catmullRomInterpolation(){std::cout<<"hello"<<std::endl;}

void catmullRomInterpolation::get_intermediatePoints(std::vector<Point> points){

    for(int p = 1; p < points.size(); p++){

        Point Q_i = Point((points[p-1].x_ + points[p].x_)/2, (points[p-1].y_ + points[p].y_)/2);

        Point R_i = Point((points[p].x_ + points[p+1].x_)/2, (points[p].y_ + points[p+1].y_)/2);

        for(int i = 0; i < 10; i++){


            float t = (float)i /10.0f;

            float a_x = 2.0f * points[p-1].x_ - 2.0f * points[p].x_ + Q_i.x_ - R_i.x_;
            float a_y = 2.0f * points[p-1].y_ - 2.0f * points[p].y_ + Q_i.y_ - R_i.y_;


            float b_x = -3.0f * points[p-1].x_ + 3.0f * points[p].x_ + Q_i.x_ + R_i.x_;
            float b_y = -3.0f * points[p-1].y_ + 3.0f * points[p].y_ + Q_i.y_ + R_i.y_;

            float c_x = Q_i.x_ - points[p].x_;
            float c_y = Q_i.y_ - points[p].y_;

            float d_x = points[p].x_;
            float d_y = points[p].y_;

            float c_tx = a_x * t*t*t + b_x*t*t + c_x*t + d_x;

            float c_ty = a_y*t*t*t + b_y*t*t + c_y*t + d_y;

            computePolynomial(c_tx, c_ty);


        }


    }
}

void catmullRomInterpolation::computePolynomial(float c_tx, float c_ty){


            Point C_xy = Point(c_tx, c_ty);

            output_points.push_back(C_xy);
    
}


void catmullRomInterpolation::printPoints(){


    for(int p = 0; p < output_points.size(); p++){

            std::cout<<"Point ("<<output_points[p].x_<<","<<output_points[p].y_<<")"<<std::endl;

    }

}




int main(){


std::vector<Point> input_points = {Point(0.0f, 0.0f), Point(1.0f, 1.0f), Point(2.0f, 0.0f), Point(3.0f, 1.0f), Point(4.0f, 0.0f)};


catmullRomInterpolation interpolate;

interpolate.get_intermediatePoints(input_points);

interpolate.printPoints();

return 0;


}