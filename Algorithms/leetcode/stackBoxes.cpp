#include <iostream>
#include<vector>
#include<algorithm>
#include<map>


struct Box
{
    int height;
    int width;
    int length;

    Box(int l, int w, int h): length(l), width(w), height(h){};

    Box(){};

};

class stackboxes{


    public:

        stackboxes(){};

        std::map<int, std::vector<Box>> stack;

        bool stackable(Box& box_1, Box& box_2){

        if (box_2.width < box_1.width && box_2.length < box_1.length) return true;
        else return false; 

        }

        bool boxEquals(const Box& a, const Box& b) {
            
            return a.length == b.length && a.width == b.width && a.height == b.height;
        
        }

        int TallestStack(std::vector<Box>& boxes){

            int height = 0;

            std::vector<int> heightVec;
            if(boxes.empty()) return 0;
            if (boxes.size() == 1) return boxes[0].height;	
            
            while(!boxes.empty()){

                Box current_base = boxes.back();
                boxes.pop_back();
                for (int i=0; i<boxes.size(); i++)
                    if (stackable(current_base, boxes[i]) && !boxEquals(boxes[i], current_base)){
                        
                        height += boxes[i].height;
                        std::cout<<"heights calculated: "<<height<<std::endl;
                      

                    }

                 heightVec.push_back(current_base.height + height);
              

            }

             std::sort(heightVec.begin(), heightVec.end(), [](int a, int b) { return a > b; });

              for(int i =0; i < heightVec.size(); i++){

                std::cout<<"heights calculated: "<<heightVec[i]<<std::endl;
              }
              return heightVec[0];

        }


};


int main(){

    std::vector<Box> boxes = {Box(4, 5, 3), Box(2, 3, 2), Box(3, 6, 2), Box(1, 5, 4), Box(2, 4, 1), Box(1, 2, 2)};
    // std::vector<Box> boxes = {{3,4,7}, {1,2,6},{3,7,8}};

    stackboxes tallest;

    int height = tallest.TallestStack(boxes);

    std::cout<<"tallest height: "<< height<<std::endl;

    

      return 0;

}


