#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test comparison")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    ariel::Graph g1;
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph2);
    bool flag = g == g1;
    CHECK(flag == true);
    flag = g != g1;
    CHECK(flag == false);
    vector<vector<int>> graph3 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};
    g.loadGraph(graph3);
    vector<vector<int>> graph4 = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}};
    g1.loadGraph(graph4);
    flag = g <= g1;
    CHECK(flag == true);
    flag = g < g1;
    CHECK(flag == true);
    flag = g1 > g;
    CHECK(flag == true);
    flag = g1 >= g;
    CHECK(flag == true);
    flag = g1 > g1;
    CHECK(flag == false);
    vector<vector<int>> graph5 = {
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 0, 1, 1}};
    g1.loadGraph(graph5);
    flag = g1 >= g;
    CHECK(flag == false);
    vector<vector<int>> graph6 = {
        {1, 0, 1},
        {1, 1, 1},
        {1, 1, 1}};
    g.loadGraph(graph6);
    flag = g < g1;
    CHECK(flag == true);
}
TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    ariel::Graph g4;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    g4.loadGraph(expectedGraph);
    CHECK(g3 == g4);
    ariel::Graph g5;
    vector<vector<int>> graph5 = {
        {0, 0, 1},
        {-3, 0, 0},
        {0, 1, 0}};
    g5.loadGraph(graph5);
    ariel::Graph g6;
    vector<vector<int>> graph6 = {
        {0, -1, 0},
        {-1, 0, 1},
        {0, 1, 0}};
    g6.loadGraph(graph6);
    ariel::Graph sumGraph;
    expectedGraph = {
        {0, -1, 1},
        {-4, 0, 1},
        {0, 2, 0}};
    sumGraph.loadGraph(expectedGraph);
    g5 += g6;
    CHECK(g5 == sumGraph);
}
TEST_CASE("Test graph subtraction")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 - g2;
    ariel::Graph g4;
    vector<vector<int>> expectedGraph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g4.loadGraph(expectedGraph);
    CHECK(g3 == g4);
    ariel::Graph g5;
    vector<vector<int>> graph5 = {
        {0, -1, 1},
        {-4, 0, 1},
        {0, 2, 0}};
    g5.loadGraph(graph5);
    ariel::Graph g6;
    vector<vector<int>> graph6 = {
        {0, -1, 0},
        {-1, 0, 1},
        {0, 1, 0}};
    g6.loadGraph(graph6);
    ariel::Graph diffGraph;
    expectedGraph = {
        {0, 0, 1},
        {-3, 0, 0},
        {0, 1, 0}};
    diffGraph.loadGraph(expectedGraph);
    g5 -= g6;
    CHECK(g5 == diffGraph);
}
TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    ariel::Graph g5;
    vector<vector<int>> expectedGraph = {
        {1, 0, 2},
        {1, 3, 1},
        {1, 0, 2}};
    g5.loadGraph(expectedGraph);
    CHECK(g4 == g5);
    g5 *= 3;
    expectedGraph = {
        {3, 0, 6},
        {3, 9, 3},
        {3, 0, 6}};
    ariel::Graph multGraph;
    multGraph.loadGraph(expectedGraph);
    CHECK(g5 == multGraph);
    ariel::Graph g6;
    vector<vector<int>> graph6 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g6.loadGraph(graph6);
    ariel::Graph g7;
    vector<vector<int>> graph7 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g7.loadGraph(graph7);
    ariel::Graph result;
    expectedGraph = {
        {1, 3, 3, 4, 0},
        {0, 4, 0, 4, 0},
        {1, 1, 7, 0, 5},
        {0, 3, 0, 4, 0},
        {0, 0, 0, 0, 0}}; // g6*g7 according to https://www.calculator.net/matrix-calculator.html
    result.loadGraph(expectedGraph);
    ariel::Graph mult = g6 * g7;
    CHECK(mult == result);
    expectedGraph = {
        {1, 0, 1, 0, 0},
        {3, 4, 1, 3, 0},
        {3, 0, 7, 0, 0},
        {4, 4, 0, 4, 0},
        {0, 0, 5, 0, 0}}; // g7*g6 according to https://www.calculator.net/matrix-calculator.html
    result.loadGraph(expectedGraph);
    g7 *= g6;
    CHECK(g7 == result);
}
TEST_CASE("Test graph division")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {3, 0, 6},
        {3, 9, 3},
        {3, 0, 6}};
    g.loadGraph(graph);
    g /= 3;
    ariel::Graph result;
    vector<vector<int>> expectedGraph = {
        {1, 0, 2},
        {1, 3, 1},
        {1, 0, 2}};
    result.loadGraph(expectedGraph);
    CHECK(result == g);
}
TEST_CASE("Test graph increment and decrement")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}};
    g.loadGraph(graph);
    g++;
    ariel::Graph result;
    vector<vector<int>> exceptedGraph = {
        {1, 1, 1},
        {1, 2, 1},
        {1, 1, 1}};
    result.loadGraph(exceptedGraph);
    CHECK(g == result);
    g--;
    exceptedGraph = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}};
    result.loadGraph(exceptedGraph);
    CHECK(g == result);
    --g++;
    CHECK(g == result);
    ++g--;
    CHECK(g == result);
}
TEST_CASE("Test graph unary")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    -g;
    ariel::Graph result;
    vector<vector<int>> exceptedGraph = {
        {0, -1, 0},
        {-1, 0, -1},
        {0, -1, 0}};
    result.loadGraph(exceptedGraph);
    CHECK(g == result);
    -g;
    -result;
    +g;
    CHECK(g == result);
}
TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    CHECK_THROWS(g2.loadGraph(weightedGraph));
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);
    // Addition and subtraction of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
    CHECK_THROWS(g1 - g6);
}
TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 0, 0},
        {1, 0, 0},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 0, 0}};
    g1.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(g1) == false);
    CHECK(ariel::Algorithms::isConnected(g + g1) == true);
}
TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->2");
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}};
    g1.loadGraph(graph1);
    CHECK(ariel::Algorithms::shortestPath(g - g1, 0, 2) == "0->1->2");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");
    CHECK(ariel::Algorithms::isContainsCycle(g * 100) == "0");
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g1.loadGraph(graph1);
    CHECK(ariel::Algorithms::isContainsCycle(g1) == "The cycle is: 0->1->2->0");
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    g2.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g1 - g2) == "0");
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");
    CHECK(ariel::Algorithms::isBipartite(g * g) == "0");
}
TEST_CASE("Test negativeCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == "No negative cycle");
    -g;
    CHECK(ariel::Algorithms::negativeCycle(g) == "The negative cycle is: 1->2->3->1");
}
