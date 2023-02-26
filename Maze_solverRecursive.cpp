#include<iostream>

using namespace std;

//initializing the maze dimension or boundaries
int const maze_dim = 5; 

//initializing the solution matrix
int sol_mat[maze_dim][maze_dim] = {

    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}

};

//initializing the maze matrix

int maze[maze_dim][maze_dim] = {

    {1,0,0,1,0},
    {1,1,0,0,1},
    {1,1,1,0,0},
    {0,0,1,1,0},
    {0,1,1,1,1}

};

//display the configuaration space for the maze

void display(){

    cout<<"<<<<<<<<<<<<<<<<<<<<<<< Maze Runner: The rat maze. >>>>>>>>>>>>>>>>>>>>>>"<<endl;

    cout<<"<<<<<<<<<<<<<<<<<<<<<<< 1 for allowe path, 0 for blocked path. Plans path for different initial conditions. >>>>>>>>>>>>>>>>>>>>>>"<<endl;

    //loop through all the paths in the maze matrix

    for (int i = 0; i <= maze_dim - 1; i++)
    {
       for (int j = 0; j <= maze_dim - 1; j++)
       {
        
        cout<< maze[i][j];
        cout<<" ";

       }

         cout<<endl;
       
    }

}

// prints the complete path to the goal in the solution mtrix

void printPath(){

    for (int i = 0; i <= maze_dim - 1; i++)
    {
       for (int j = 0; j <= maze_dim - 1; j++)
       {
        
       cout<<sol_mat[i][j];
        cout<<" ";

       }

         cout<<endl;
       
    }

    cout<<"coordinates"<<endl;

    for (int i = 0; i <= maze_dim - 1; i++)
    {
       for (int j = 0; j <= maze_dim - 1; j++)
       {

        if(sol_mat[i][j] == 1){
        
       cout<<"("<<i<<","<<j<<"), ";
        cout<<" ";

        }

       }
       
      
    }

    

};
//Checks if the chosen x, y coordinate is correct >> are they binary, are they within the maze walls,  

bool isSafe(int x, int y){

    if(x >= 0 && x < maze_dim && y >=0 && y < maze_dim && maze[x][y] == 1) return true;

    else return false;

};

// A recursion function to get the complete path to the goal.

bool findPathRecursively(int goal_x, int goal_y, int x, int y){

    //checks if the coordinate is at the goal
    if(isSafe(x, y) == true && x == goal_x && y == goal_y && maze[x][y] == 1){

        sol_mat[x][y] = 1;

        return true;
    }


    //if the goal is not at the initial x, y location, enter the recursion loop to try other paths

    if(isSafe(x, y) == true){

        //checks if the current location is already in the solution matrix. if it is exit the loop

        if(sol_mat[x][y] == 1){

            return false;
        }

        //if the current coordinate is not in the solution, add it to the path coordinate for futher testing

        sol_mat[x][y] = 1;

        // checks if there is a solution right the current coordinate
        if(findPathRecursively(goal_x, goal_y, x+1, y) == true) return true;

        // checks if there is a solution left the current coordinate
        if(findPathRecursively(goal_x, goal_y, x-1, y) == true) return true;

        // checks if there is a solution down the current coordinate
        if(findPathRecursively(goal_x, goal_y, x, y+1) == true) return true;

        // checks if there is a solution up the current coordinate
        if(findPathRecursively(goal_x, goal_y, x, y-1) == true) return true;

        //if no path way there, then you have to discard the coordinate because its a dead end. set the current coordinate to 0 in he solution matrix
        sol_mat[x][y] = 0;

        //return false
        return false;

    }

    //return false
    return false;

};

//function that calls the recusive function

bool solveMaze(int x, int y){

    if(findPathRecursively(1,1,x,y) == true){

        cout<<"path found!"<<endl;

        printPath();

        return true;

    }

    else{

        cout<<"No path found"<<endl;

        return false;
    }


};



//main function
int main(int argc, char const *argv[])
{
    
    display();

    solveMaze(3,3);

    cout<<" "<<endl;

    // printPath();

    //printPath(maze);
    return 0;
}
