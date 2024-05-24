# **Assignment 2 - Graph Operators**

## **Overview**

  This C++ program extends the capabilities of our graph manipulation toolkit to include a variety of new operators.
  In addition to the fundamental arithmetic and comparison operators, we've introduced functionality for scaling edges by a scalar,
  performing graph multiplication, and providing an output operator for logical graph printing.


## **Files**

  Graph.hpp: Defines the Graph class, which represents a graph and includes implementations of various graph operators.
  Graph.cpp: Implements the functions of the Graph class, including the operators.
  demo.cpp: Contains some example usage of the graph operators.
  test.cpp: contains unit tests for both the graph operators implemented in the program and the graph algorithms from Assignment 1,
    aiming to verify how the operators affect the behavior and results of the algorithms.
  Algorithms.hpp: Defines the Algorithms class, which contains implementations of various graph algorithms.
  Algorithms.cpp: Implements the functions of the Algorithms class.
  Makefile: Provides commands to build, run, and clean the project.

## **Graph Representation**
  Just like in Assignment 1, the Graph class utilizes an adjacency matrix to represent the graph,
  where graph[i][j] denotes the weight of the edge from vertex i to vertex j. A weight of 0 signifies the absence of an edge between the vertices.

## **The Operators**

### **Arithmetic Operators**

  Addition (+): This operator allows you to add the weights of corresponding edges in two graphs. When you use the addition operator between two graphs,
  the resulting graph will have weights equal to the sum of the corresponding edges in the two input graphs.

  Addition Assignment (+=): This operator works similarly to the addition operator,
  but it modifies the first graph by adding the weights of corresponding edges from the second graph. After using +=,
  the first graph will be updated with the sum of weights from both graphs.

  Unary Plus (+): The unary plus operator is used to represent the identity operation. When you apply the unary plus operator to a graph,
  it doesn't change the graph itself.

  Subtraction (-): The subtraction operator allows you to subtract the weights of corresponding edges in two graphs.
  When you use the subtraction operator between two graphs, the resulting graph will have weights equal to the difference
  of the corresponding edges in the two input graphs.

  subtraction Assignment (-=): This operator works similarly to the Subtraction operator,
  but it modifies the first graph by Subtracting the weights of corresponding edges from the second graph. After using -=,
  the first graph will be updated with the difference of weights from both graphs.

  Unary Minus (-): The unary minus operator, would negate the weights of all edges in the graph.

  Increment (++) and Decrement (--): These operators increase or decrease by 1 all the weights of the edges in the graph, respectively.

  Multiplication by Integer Scalar (int): This operator multiplies the weight of all edges in the graph by a scalar value.

  Graph Multiplication (*): The multiplication operation between two graphs multiplies their representative matrices. The result is a matrix representing a new graph. 
  This operation should only be performed on graphs of the same size order, or an error will be thrown.

### **Comparison Operators**
  isSubgraph(g1,g2)- The isSubgraph private function in the Graph class is utilized internally to determine if one graph is a subgraph of another.
  It takes two graphs as input parameters and checks if the first graph is contained directly within the second graph.
  This function is particularly useful for comparison operators such as > and <, where we need to determine if one graph has more or fewer edges than another.
  By checking if a graph is a subgraph of another, we can efficiently perform these comparisons based on the number of edges contained within each graph.

  Equal (==) and Not-Equal (!=): Graphs G1 and G2 are considered equal if they have the same number of vertices and edges, and corresponding edges have the same weights.

  Greater (>) and Greater-Than-Equal (>=): A graph G2 is considered greater than a graph G1 under the following conditions:
    G1 is not a subgraph of G2.
    If G1 and G2 have a different number of edges, the graph with more edges is considered greater.
    If the number of edges is the same, the graph with more vertices is considered greater.

  Less (<) and Less-Than-Equal (<=): A graph G1 is considered lesser than a graph G2 under the following conditions:
    G2 is a subgraph of G1.
    If G1 and G2 have a different number of edges, the graph with fewer edges is considered lesser.
    If the number of edges is the same, the graph with fewer vertices is considered lesser.

### **Output Operator**

  Output Operator (<<): This operator provides a logical representation of the graph when printed. 

## **Testing Graph Algorithms with Graph Operators**

  The tests check how the graph algorithms work when we change the graph using different math operations like adding, removing, or changing the strength of connections.
  We want to make sure the algorithms still give correct answers even after we change the graph.
  

