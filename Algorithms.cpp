/*2564 alonz1414@gmail.com*/
#include "Algorithms.hpp"
#include <queue>
#include <iostream>
#include <vector>
#include <climits>
#include <stack>
namespace ariel
{

    /* Check if there is a path between every two vertices using BFS*/
    int Algorithms::isConnected(const Graph &g)
    {
        std::vector<bool> hasPathToAll(g.getNumOfVertices(), false);
        // BFS from each vertex
        for (size_t i = 0; i < g.getNumOfVertices(); i++)
        {
            std::vector<bool> visited(g.getNumOfVertices(), false);
            if (!visited[i])
            {
                BFS(g, visited, hasPathToAll, i); // Start BFS from vertex i
            }
            if (!hasPathToAll[i])
            {
                return 0;
            }
        }
        return 1;
    }
    void Algorithms::BFS(const Graph &g, std::vector<bool> &visited, std::vector<bool> &hasPathToAll, size_t start)
    {
        std::queue<size_t> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty())
        {
            size_t current = q.front();
            q.pop();
            for (size_t i = 0; i < g.getNumOfVertices(); i++)
            {
                if ((g.getWeight(current, i) != 0) && (!visited[i]))
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        // Check if the BFS from start has visited in the all vertices of the graph
        for (int i = 0; i < visited.size(); i++)
        {
            if (!visited[i])
            {
                hasPathToAll[start] = false;
                return;
            }
        }
        hasPathToAll[start] = true;
    }
    /* Find the shortest path between every 2 vertices by usuing Bellman-Ford algorithm*/
    std::string Algorithms::shortestPath(const Graph &g, size_t start, size_t end)
    {
        std::vector<int> dist(g.getNumOfVertices(), INT_MAX);
        std::vector<int> parents(g.getNumOfVertices(), -1);
        dist[start] = 0;
        // Run Bellman-Ford algorithm.|v|-1 Relaxes.
        for (size_t i = 0; i < g.getNumOfVertices() - 1; i++)
        {
            for (size_t u = 0; u < g.getNumOfVertices(); u++)
            {
                for (size_t v = 0; v < g.getNumOfVertices(); v++)
                {
                    int weight = g.getWeight(u, v);
                    if ((weight != 0) && (dist[u] != INT_MAX) && (dist[u] + weight < dist[v]))
                    {
                        dist[v] = dist[u] + weight;
                        parents[v] = u;
                    }
                }
            }
        }
        // One more Relax to check for negative cycle
        for (size_t u = 0; u < g.getNumOfVertices(); u++)
        {
            for (size_t v = 0; v < g.getNumOfVertices(); v++)
            {
                int weight = g.getWeight(u, v);
                if ((weight != 0) && (dist[u] != INT_MAX) && (dist[u] + weight < dist[v]))
                { //
                    return "Negative cycle";
                }
            }
        }
        if (dist[end] == INT_MAX)
        { // No path from start to end
            return "-1";
        }
        // Build the shortest path from start to end
        std::vector<int> path;
        size_t current = end;
        while (current != static_cast<size_t>(-1))
        {
            path.push_back(static_cast<int>(current));
            current = static_cast<size_t>(parents[current]);
        }
        std::string spStr;
        for (size_t i = path.size() - 1; i > 0; i--)
        {
            spStr += std::to_string(path[i]) + "->";
        }
        spStr += std::to_string(path[0]);
        return spStr;
    }
    /*Search for cycle in a graph by running DFS from each vertex in the graph */
    std::string Algorithms::isContainsCycle(const Graph &g)
    {
        std::vector<bool> visited(g.getNumOfVertices(), false);
        std::vector<bool> recStack(g.getNumOfVertices(), false);
        std::stack<size_t> path;
        for (size_t i = 0; i < g.getNumOfVertices(); i++)
        {
            if (!visited[i] && hasCycleDFS(g, visited, recStack, path, i, g.getNumOfVertices()))
            {
                // Build the path of the cycle
                std::stack<size_t> cyclePath;
                while (!path.empty())
                {
                    size_t vertex = path.top();
                    path.pop();
                    cyclePath.push(vertex);
                    if (vertex == i)
                    {
                        break;
                    }
                }
                // Build the cycle sring represention
                std::string cycleSTR = "The cycle is: ";
                while (!cyclePath.empty())
                {
                    cycleSTR += std::to_string(cyclePath.top()) + "->";
                    cyclePath.pop();
                }
                cycleSTR += std::to_string(i);
                return cycleSTR;
            }
        }
        return "0"; // No cycle found
    }
    /*Recursive function that uses DFS algorithm to to find cycle in a graph*/
    bool Algorithms::hasCycleDFS(const Graph &g, std::vector<bool> &visited, std::vector<bool> &recStack, std::stack<size_t> &path, size_t current, size_t parent)
    {
        visited[current] = true;
        recStack[current] = true;
        path.push(current);
        for (size_t i = 0; i < g.getNumOfVertices(); i++)
        {
            if (g.getWeight(current, i) != 0)
            {
                if (!visited[i])
                {
                    if (hasCycleDFS(g, visited, recStack, path, i, current))
                    {
                        return true;
                    }
                }
                else if (recStack[i] && i != parent)
                { // Check if the edge is back edges
                    return true;
                }
            }
        }
        recStack[current] = false;
        path.pop();
        return false;
    }
    /* Check if there is partiton of the graph into a bipartite graph using BFS algorithm and coloring the vertices.
    The graph vertices is colored while BFS running.if the graph contains 2 adjacent vertices with the same color, the graph is not bipartite. */
    std::string Algorithms::isBipartite(const Graph &g)
    {
        std::vector<int> colors(g.getNumOfVertices(), -1); // Initialize all vertices with no color
        std::queue<size_t> q;
        for (size_t i = 0; i < g.getNumOfVertices(); i++)
        {
            if (colors[i] == -1)
            {
                colors[i] = 0; // Color vertex i with color 0
                q.push(i);
                while (!q.empty())
                {
                    size_t current = q.front();
                    q.pop();
                    // visit all adj vertices
                    for (size_t j = 0; j < g.getNumOfVertices(); j++)
                    {
                        if (g.getWeight(current, j) != 0) //
                        {
                            // If the adj vertex is not colored yet colored it with the opposite color of the current vertex
                            if (colors[j] == -1)
                            {
                                colors[j] = 1 - colors[current];
                                q.push(j);
                            }
                            else if (colors[j] == colors[current])
                            {
                                // If the adj vertex has the same color as the current vertex, the graph is not bipartite
                                return "0";
                            }
                        }
                    }
                }
            }
        }
        // The graph is bipartite. Build the partition of the graph
        return buildPartition(colors);
    }
    /*The function gets the colored vertices of a bipartite graph and returns a string representing its partition. */
    std::string Algorithms::buildPartition(std::vector<int> &colors)
    {
        std::vector<size_t> setA, setB;
        for (size_t i = 0; i < colors.size(); ++i)
        {
            if (colors[i] == 0)
            {
                setA.push_back(i);
            }
            else
            {
                setB.push_back(i);
            }
        }
        std::string partition = "The graph is bipartite: A={";
        for (size_t i = 0; i < setA.size(); ++i)
        {
            partition += std::to_string(setA[i]);
            if (i != setA.size() - 1)
            {
                partition += ", ";
            }
        }
        partition += "}, B={";
        for (size_t i = 0; i < setB.size(); ++i)
        {
            partition += std::to_string(setB[i]);
            if (i != setB.size() - 1)
            {
                partition += ", ";
            }
        }
        partition += "}";
        return partition;
    }
    /*Find negative cycle in*/
    /* Find negative cycle in the graph using Bellman-Ford algorithm */
    std::string Algorithms::negativeCycle(const Graph &g)
    {
        if(isContainsCycle(g)=="0"){
            return "No negative cycle";
        }
        std::vector<int> dist(g.getNumOfVertices(), INT_MAX);
        std::vector<int> parents(g.getNumOfVertices(), -1);
        dist[0] = 0; // Start from vertex 0

        // Run Bellman-Ford algorithm for |V| - 1 iterations
        for (size_t i = 0; i < g.getNumOfVertices() - 1; i++)
        {
            for (size_t u = 0; u < g.getNumOfVertices(); u++)
            {
                for (size_t v = 0; v < g.getNumOfVertices(); v++)
                {
                    int weight = g.getWeight(u, v);
                    if (weight != 0 && dist[u] != INT_MAX && dist[u] + weight < dist[v])
                    {
                        dist[v] = dist[u] + weight;
                        parents[v] = u;
                    }
                }
            }
        }

        // Check for negative cycles
        for (size_t u = 0; u < g.getNumOfVertices(); u++)
        {
            for (size_t v = 0; v < g.getNumOfVertices(); v++)
            {
                int weight = g.getWeight(u, v);
                if (weight != 0 && dist[u] != INT_MAX && dist[u] + weight < dist[v])
                {
                    // Build the negative cycle path
                    std::vector<bool> visited(g.getNumOfVertices(), false);
                    std::string cycleStr = "The negative cycle is: ";
                    size_t current = v;
                    while (!visited[current])
                    {
                        cycleStr += std::to_string(current) + "->";
                        visited[current] = true;
                        current = parents[current];
                    }
                    cycleStr += std::to_string(v); // Close the cycle
                    return cycleStr;
                }
            }
        }
        return "No negative cycle";
    }

}