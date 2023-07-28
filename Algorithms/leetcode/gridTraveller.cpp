#include<iostream>

// int maze[5][5] = {

//     {1,0,0,1,0},
//     {1,1,0,0,1},
//     {1,1,1,0,0},
//     {0,0,1,1,0},
//     {0,1,1,1,1}

// };

int maze[3][3] = {
    {1, 0, 0},
    {1, 1, 0},
    {1, 1, 1}
};


int gridTraveller(int m, int n){

    if(m < 0 || n < 0) return 0; // out of bounds

    if(maze[m][n] == 0) return 0;  // reached a blocked cell

    if(m == 0 && n == 0) return 1; // reached goal
	
	
	return gridTraveller(m,n-1) + gridTraveller(m-1,n);
	
	}


    /*
    
    
    2 by 2
    {1,1,0}
    {1,1,1}

            2,2
           /   \
          1,2  2,1
          / \     /  \
                 1,1  2,0
              /  \           /    \
           0,1   1,0        1,0     2,-1
                           /  \
                         0,0   1,-1

                         1 + 0 + 0 +  

    */          




int main(){


 int paths = gridTraveller(2,2);

 std::cout<<"number of paths: "<<paths<<std::endl;

 return 0;



}




// #include <iostream>

// int maze[5][5] = {
//     {1, 0, 0, 1, 0},
//     {1, 1, 0, 0, 1},
//     {1, 1, 1, 0, 0},
//     {0, 0, 1, 1, 0},
//     {0, 1, 1, 1, 1}
// };

// int gridTraveller(int m, int n) {
//     // Base cases
//     if (m < 0 || n < 0) {
//         return 0; // Out of bounds
//     }
//     if (maze[m][n] == 0) {
//         return 0; // Cell is blocked
//     }
//     if (m == 0 && n == 0) {
//         return 1; // Reached the destination
//     }

//     // Recursive cases
//     return gridTraveller(m, n - 1) + gridTraveller(m - 1, n);
// }

// int main() {
//     int paths = gridTraveller(4, 4);
//     std::cout << "Number of paths: " << paths << std::endl;
//     return 0;
// }
