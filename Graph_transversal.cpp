#include<iostream>
#include<map>
#include<list>
#include<queue>

using namespace std;

class Graph{

    public:

        // map to hold visited nodes
        map<int, bool> visited; 

        // map to hold edges
        map<int, list<int>> edges;

        Graph(){}; // default contructor

        //function to add nodes to the tree
        void AddNodes(int x, int y){

            //links x to y
            edges[x].push_back(y);

            //neccesary so that the search can start from any node on the tree e.g you can reach 5 from 6 and also 6 from 5 
            edges[y].push_back(x);  

        }

        // BFS algorithm initialized by a start node
        void BreathFirstSearch(int start){

            queue<int> ntVisited; //queue to hold nodes that are not visited

            ntVisited.push(start); // push the starting node into the queue

            visited[start] = true; //mark it as visited

            //loop continues untill nodes not visited is empty
            while(!ntVisited.empty()){

                int Node = ntVisited.front() ; // take the top node on the stack

                ntVisited.pop(); // remove it from the list of not visited nodes

                for(auto N: edges[Node]){  // loop through each node connected to the edge

                    if(!visited[N]){  // if node has not been visited
                        
                        ntVisited.push(N);} // push it into the not visited node list
                        visited[N] = true;
                    
                }

               cout<<" Nodes visited: "<<Node<<endl;



            }

            

        }


};

int main(int argc, const char** argv) {

    Graph graph; // create th graph object

    // add edges

    graph.AddNodes(1,2);
    graph.AddNodes(1,3);
    graph.AddNodes(3,4);
    graph.AddNodes(4,5);
    graph.AddNodes(5,6);

    graph.BreathFirstSearch(6);  // calling the BFS method

    return 0;
}