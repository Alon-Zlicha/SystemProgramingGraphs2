/*2564 alonz1414@gmail.com*/
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>

namespace ariel
{
    class Graph
    {
    private:
        std::vector<std::vector<int>> adjMatrix;
        int countEdges() const;
        static bool isSubgraph(const Graph &g1, const Graph &g2);

    public:
        void loadGraph(std::vector<std::vector<int>> &graph);
        void printGraph();
        const std::vector<std::vector<int>> &getAdjMatrix() const;
        size_t getNumOfVertices() const;
        int getWeight(size_t start, size_t end) const;
        friend Graph operator+(const Graph &g1, const Graph &g2);
        friend void operator+=(Graph &g1, const Graph &g2);
        friend void operator+(Graph &g);
        friend Graph operator-(const Graph &g1, const Graph &g2);
        friend void operator-=(Graph &g1, const Graph &g2);
        friend void operator-(Graph &g);
        friend Graph &operator++(Graph &g);
        friend Graph &operator++(Graph &g, int);
        friend Graph &operator--(Graph &g);
        friend Graph &operator--(Graph &g, int);
        friend Graph operator*(const Graph &g, int x);
        friend void operator*=(Graph &g, int x);
        friend Graph operator*(const Graph &g1, const Graph &g2);
        friend void operator*=(Graph &g1, const Graph &g2);
        friend Graph operator/(const Graph &g, int x);
        friend void operator/=(Graph &g, int x);
        friend bool operator==(const Graph &g1, const Graph &g2);
        friend bool operator!=(const Graph &g1, const Graph &g2);
        friend bool operator>=(const Graph &g1, const Graph &g2);
        friend bool operator>(const Graph &g1, const Graph &g2);
        friend bool operator<(const Graph &g1, const Graph &g2);
        friend bool operator<=(const Graph &g1, const Graph &g2);
        friend std::ostream &operator<<(std::ostream &os, Graph &g);
    };
}
#endif