/*
 * Demo program for Exercise 2.
 * Author: Benjamin Saldman.
 */

#include "Graph.hpp"
#include "Algorithms.hpp"
using ariel::Algorithms;
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{
    ariel::Graph g;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 3 vertices and 4 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 0, 2) << endl; // Should print: 0->1->2.
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2}, B={1}."
    cout << Algorithms::negativeCycle(g) << endl;

    // 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 8 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "-1" (there is no path between 0 and 4).
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "The cycle is: 0->1->2->0".
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "0" (false).
    cout << Algorithms::negativeCycle(g) << endl;

    // 5x5 matrix that reprsents a connected weighted graph.
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 8 edges."
    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: 0->1->2->3->4.
    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2, 4}, B={1, 3}."
    cout << Algorithms::negativeCycle(g) << endl;

    // 5x4 matrix that reprsents invalid graph.
    vector<vector<int>> graph4 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    try
    {
        g.loadGraph(graph4); // Load the graph to the object.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
    }
    vector<vector<int>> graph5 = {
        {0, 0, 1},
        {-3, 0, 0},
        {0, 1, 0}};
    g.loadGraph(graph5);
    cout << Algorithms::negativeCycle(g) << endl;
    vector<vector<int>> graph6 = {
        {0, -1, 0},
        {-1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph6);
    cout << Algorithms::negativeCycle(g) << endl;
    ariel::Graph g1;
    g1.loadGraph(graph5);
    ariel::Graph resultGraph = g + g1; // graph5+graph6
    cout << resultGraph << endl;
    g += g1; // same result as graph5+graph6
    cout << g << endl;
    +g;
    cout << g << endl;
    -g;
    cout << g << endl;
    -g;
    g -= g1; // g is graph6 again
    cout << g << endl;
    resultGraph = g1 - g; // graph5-graph6
    cout << resultGraph << endl;
    ++g;
    cout << g << endl;
    --g;
    cout << g << endl;
    g--;
    cout << g << endl;
    g++;
    cout << g << endl;
    resultGraph = g * 3;
    cout << resultGraph << endl;
    g *= 4;
    cout << g << endl;
    resultGraph = g / 4;
    cout << resultGraph << endl;
    bool flag = g == resultGraph;
    cout << flag << endl; // should print 0
    g /= 4;
    cout << resultGraph << endl;
    flag = g == resultGraph;
    cout << flag << endl; // should print 1
    g1.loadGraph(graph3);
    flag = g1 == g;
    cout << flag << endl; // should print 0
    flag = g != g1;
    cout << flag << endl; // should print 1
    try
    {
        resultGraph = g + g1; // graph6+graph3
        cout << resultGraph << endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl; // should print: "Matrix dimentions don't match for addition."
    }
    try
    {
        g -= g1; // graph6+graph3
        cout << g << endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl; // should print: "Matrix dimentions don't match for substraction."
    }
    try
    {
        resultGraph = g * g1; // graph6*graph3
        cout << resultGraph << endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl; // should print: "The number of columns in the first matrix must be equal to the number of rows in the second matrix."
    }
    vector<vector<int>> graph7 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};
    g.loadGraph(graph7);
    vector<vector<int>> graph8 = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}};
    g1.loadGraph(graph8);
    flag = g >= g1;
    cout << flag << endl; // should print 0
    flag = g1 >= g;
    cout << flag << endl; // should print 1
    flag = g1 >= g1;
    cout << flag << endl; // should print 1
    flag = g1 > g;
    cout << flag << endl; // should print 1
    flag = g1 > g1;
    cout << flag << endl; // should print 0
    flag = g < g1;
    cout << flag << endl; // should print 1
    flag = g < g;
    cout << flag << endl; // should print 0
    flag = g <= g;
    cout << flag << endl; // should print 1
    flag = g <= g1;
    cout << flag << endl; // should print 1
    g.loadGraph(graph2);
    g1.loadGraph(graph3);
    resultGraph = g * g1;
    cout << resultGraph << endl;
    resultGraph = g1 * g;
    cout << resultGraph << endl;
    g *= g1;
    cout << g << endl;
    ariel::Graph g2;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph9 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph9); // Load the graph to the object.

    cout << g2 << endl; // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]

    // 3x3 matrix that represents a weighted connected graph.
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    ariel::Graph g3;
    g3.loadGraph(weightedGraph); // Load the graph to the object.

    ariel::Graph g4 = g2 + g3; // Add the two graphs together.
    cout << g4 << endl;        // Should print the matrix of the graph: [0, 2, 1], [2, 0, 3], [1, 3, 0]

    g2 *= -2;           // Multiply the graph by -2.
    cout << g2 << endl; // Should print the matrix of the graph: [0, -2, 0], [-2, 0, -2], [0, -2, 0]

    g2 /= -2;
    ariel::Graph g5 = g2 * g3; // Multiply the two graphs together.
    cout << g5 << endl;        // Should print the multiplication of the matrices of g2 and g3: [1, 0, 2], [1, 3, 1], [1, 0, 2]

    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> graph10 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    ariel::Graph g6;
    g6.loadGraph(graph10); // Load the graph to the object.
    ----g6;
    cout<<g6<<endl;
    g6++++++;
    cout<<g6<<endl;
    try
    {
        ariel::Graph g7 = g6 * g2; // Multiply the two graphs together.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print "The number of columns in the first matrix must be equal to the number of rows in the second matrix."
    }

}