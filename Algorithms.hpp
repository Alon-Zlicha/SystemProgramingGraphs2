/*2564 alonz1414@gmail.com*/
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <stack>
namespace ariel
{
    class Algorithms
    {
    public:
        static int isConnected(const Graph &g);
        static std::string shortestPath(const Graph &g, size_t start, size_t end);
        static std::string isContainsCycle(const Graph &g);
        static std::string isBipartite(const Graph &g);
        static std::string negativeCycle(const Graph &g);

    private:
        static void BFS(const Graph &g, std::vector<bool> &visited, std::vector<bool> &hasPathToAll, size_t start);
        static bool hasCycleDFS(const Graph &g, std::vector<bool> &visited, std::vector<bool> &recStack, std::stack<size_t> &path, size_t current, size_t parent);
        static std::string buildPartition(std::vector<int> &colors);
    };
}
#endif