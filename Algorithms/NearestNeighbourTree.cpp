#include<iostream>
#include<eigen3/Eigen/Dense>
#include<cmath>
#include<vector>
#include<random>


struct Node{

    Node* parent;
    Eigen::Vector2f child;

    Node(Eigen::Vector2f chld){

        this->child = chld;
        this->parent = nullptr;

    }
    Node():parent{nullptr}{}


};


class Tree{


    public:

        float num_iteration = 100;
        float upperLim = 300;
        float lowerLim = 0;
        float step_size = 0.5;
        Eigen::Vector2f start_;
        Eigen::Vector2f stop_;
        Node* root;
        std::vector<Eigen::Vector2f> points;
        // std::vector<Eigen::Vector2f> path;

        Tree(Eigen::Vector2f start, Eigen::Vector2f stop);

        Eigen::Vector2f generateRandomPoints();
        Eigen::Vector2f getNearestNeighbour(Eigen::Vector2f RandomNode, std::vector<Eigen::Vector2f> nodeTree);
        void connectNode(Eigen::Vector2f parent, Eigen::Vector2f child);
        // Eigen::Vector2f RRT


};

Tree::Tree(Eigen::Vector2f start, Eigen::Vector2f stop){
            
            root = nullptr;
            start_ = start;
            stop_ = stop;
            points.push_back(start_);

            };

Eigen::Vector2f Tree::generateRandomPoints(){


    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> yPoint(lowerLim, upperLim);
    std::uniform_real_distribution<float> xPoint(lowerLim, upperLim);

    Eigen::Vector2f RandomPoint = {xPoint, yPoint};

    return RandomPoint; 

}


Eigen::Vector2f Tree::getNearestNeighbour(Eigen::Vector2f RandomNode, std::vector<Eigen::Vector2f> nodeTree){

    if(nodeTree.empty()){

        std::cout<<"tree is empty"<<std::endl;
    }

    // for(int i = 0; i < nodeTree.size(); i++){

    //     float xDist = nodeTree[0[0]]



    // }


}




