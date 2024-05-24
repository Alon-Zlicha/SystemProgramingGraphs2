/*2564 alonz1414@gmail.com*/
#include "Graph.hpp"
#include <stdexcept>

namespace ariel
{
    void Graph::loadGraph(std::vector<std::vector<int>> &matrix)
    {
        if (matrix.size() != matrix[0].size())
        {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
        this->adjMatrix = matrix;
    }
    void Graph::printGraph()
    {
        int edgeCount = this->countEdges();
        std::cout << "Graph with " << this->getNumOfVertices() << " vertices and " << edgeCount << " edges." << std::endl;
    }
    int Graph::countEdges() const
    {
        int edgeCount = 0;
        for (size_t i = 0; i < this->adjMatrix.size(); i++)
        {
            for (size_t j = 0; j < this->adjMatrix.size(); j++)
            {
                if (this->adjMatrix[i][j] != 0)
                {
                    edgeCount++;
                }
            }
        }
        return edgeCount;
    }
    const std::vector<std::vector<int>> &Graph::getAdjMatrix() const
    {
        return this->adjMatrix;
    }
    size_t Graph::getNumOfVertices() const
    {
        return this->adjMatrix.size();
    }
    int Graph::getWeight(size_t start, size_t end) const
    {
        return this->adjMatrix[start][end];
    }
    Graph operator+(const Graph &g1, const Graph &g2)
    {
        if (g1.adjMatrix.size() != g2.adjMatrix.size())
        {
            throw std::invalid_argument("Matrix dimensions don't match for addition.");
        }
        Graph sum;
        std::vector<std::vector<int>> sumMatrix(g1.adjMatrix.size(), std::vector<int>(g1.adjMatrix.size(), 0));
        for (size_t i = 0; i < sumMatrix.size(); i++)
        {
            for (size_t j = 0; j < sumMatrix.size(); j++)
            {
                sumMatrix[i][j] = g1.adjMatrix[i][j] + g2.adjMatrix[i][j];
            }
        }
        sum.loadGraph(sumMatrix);
        return sum;
    }
    void operator+=(Graph &g1, const Graph &g2)
    {
        g1 = g1 + g2; // Using the operator+ function
    }
    void operator+(Graph &g)
    {
    }
    Graph operator-(const Graph &g1, const Graph &g2)
    {
        if (g1.adjMatrix.size() != g2.adjMatrix.size())
        {
            throw std::invalid_argument("Matrix dimensions don't match for subtraction.");
        }
        Graph diff;
        std::vector<std::vector<int>> diffMatrix(g1.adjMatrix.size(), std::vector<int>(g1.adjMatrix.size(), 0));
        for (size_t i = 0; i < diffMatrix.size(); i++)
        {
            for (size_t j = 0; j < diffMatrix.size(); j++)
            {
                diffMatrix[i][j] = g1.adjMatrix[i][j] - g2.adjMatrix[i][j];
            }
        }
        diff.loadGraph(diffMatrix);
        return diff;
    }
    void operator-=(Graph &g1, const Graph &g2)
    {
        g1 = g1 - g2; // Using the operator- function
    }
    void operator-(Graph &g)
    {
        for (size_t i = 0; i < g.adjMatrix.size(); i++)
        {
            for (size_t j = 0; j < g.adjMatrix.size(); j++)
            {
                g.adjMatrix[i][j] *= -1;
            }
        }
    }
    Graph &operator++(Graph &g)
    {
        for (size_t i = 0; i < g.adjMatrix.size(); i++)
        {
            for (size_t j = 0; j < g.adjMatrix[i].size(); j++)
            {
                g.adjMatrix[i][j]++;
            }
        }
        return g;
    }
    Graph &operator--(Graph &g)
    {
        for (size_t i = 0; i < g.adjMatrix.size(); i++)
        {
            for (size_t j = 0; j < g.adjMatrix[i].size(); j++)
            {
                g.adjMatrix[i][j]--;
            }
        }
        return g;
    }
    Graph &operator++(Graph &g, int)
    {
        Graph &temp = g;
        ++g;
        return temp;
    }
    Graph &operator--(Graph &g, int)
    {
        Graph &temp = g;
        --g;
        return temp;
    }
    Graph operator*(const Graph &g, int x)
    {
        Graph mult;
        std::vector<std::vector<int>> multMatrix(g.adjMatrix.size(), std::vector<int>(g.adjMatrix.size(), 0));
        for (size_t i = 0; i < multMatrix.size(); i++)
        {
            for (size_t j = 0; j < multMatrix.size(); j++)
            {
                multMatrix[i][j] = g.adjMatrix[i][j] * x;
            }
        }
        mult.loadGraph(multMatrix);
        return mult;
    }
    void operator*=(Graph &g, int x)
    {
        g = g * x;
    }
    Graph operator*(const Graph &g1, const Graph &g2)
    {
        if (g1.getNumOfVertices() != g2.getNumOfVertices())
        {
            throw std::invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
        }
        Graph mult;
        std::vector<std::vector<int>> multMatrix(g1.adjMatrix.size(), std::vector<int>(g1.adjMatrix.size(), 0));
        for (size_t i = 0; i < multMatrix.size(); i++)
        {
            for (size_t j = 0; j < multMatrix.size(); j++)
            {
                int sum = 0;
                for (size_t k = 0; k < multMatrix.size(); k++)
                {
                    sum += g1.getWeight(i, k) * g2.getWeight(k, j);
                }
                multMatrix[i][j] = sum;
            }
        }
        mult.loadGraph(multMatrix);
        return mult;
    }
    void operator*=(Graph &g1, const Graph &g2)
    {
        g1 = g1 * g2;
    }
    Graph operator/(const Graph &g, int x)
    {
        Graph quotient;
        std::vector<std::vector<int>> quotientMatrix(g.adjMatrix.size(), std::vector<int>(g.adjMatrix.size(), 0));
        for (size_t i = 0; i < quotientMatrix.size(); i++)
        {
            for (size_t j = 0; j < quotientMatrix.size(); j++)
            {
                quotientMatrix[i][j] = g.adjMatrix[i][j] / x;
            }
        }
        quotient.loadGraph(quotientMatrix);
        return quotient;
    }
    void operator/=(Graph &g, int x)
    {
        g = g / x;
    }
    bool operator==(const Graph &g1, const Graph &g2)
    {
        if (g1.adjMatrix.size() != g2.adjMatrix.size())
        {
            return false;
        }
        for (size_t i = 0; i < g1.adjMatrix.size(); i++)
        {
            for (size_t j = 0; j < g1.adjMatrix.size(); j++)
            {
                if (g1.adjMatrix[i][j] != g2.adjMatrix[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool operator!=(const Graph &g1, const Graph &g2)
    {
        if (!(g1 == g2))
        { // Using the opertor==
            return true;
        }
        return false;
    }
    // Helper function to check if g1 is a subgraph of g2
    bool Graph::isSubgraph(const Graph &g1, const Graph &g2)
    {
        if (g1.getNumOfVertices() > g2.getNumOfVertices())
        {
            return false;
        }
        for (size_t i = 0; i < g1.getNumOfVertices(); i++)
        {
            for (size_t j = 0; j < g1.getNumOfVertices(); j++)
            {
                if (g1.getWeight(i, j) > 0 && g2.getWeight(i, j) == 0 && g1.getWeight(i, j) != g2.getWeight(i, j))
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool operator>(const Graph &g1, const Graph &g2)
    {
        if (Graph::isSubgraph(g1, g2))
        {
            return false;
        }
        if (g1.countEdges() < g2.countEdges())
        {
            return false;
        }
        else if (g1.countEdges() > g2.countEdges())
        {
            return true;
        }
        else
        {
            return g1.getNumOfVertices() > g2.getNumOfVertices();
        }
    }
    bool operator>=(const Graph &g1, const Graph &g2)
    {
        if (g1 == g2)
        {
            return true;
        }
        return g1 > g2;
    }
    bool operator<=(const Graph &g1, const Graph &g2)
    {
        return g2 >= g1; // Use the >= operator
    }
    bool operator<(const Graph &g1, const Graph &g2)
    {
        return !(g1 >= g2); // Use the >= operator with negation
    }
    std::ostream &operator<<(std::ostream &os, Graph &g)
    {
        os << "{";
        for (size_t i = 0; i < g.adjMatrix.size(); i++)
        {
            os << "{";
            for (size_t j = 0; j < g.adjMatrix[i].size(); j++)
            {
                os << g.adjMatrix[i][j];
                if (j != g.adjMatrix[i].size() - 1)
                {
                    os << ", ";
                }
            }
            os << "}";
            if (i != g.adjMatrix.size() - 1)
            {
                os << std::endl;
            }
        }
        os << "}" << std::endl;
        return os;
    }
}