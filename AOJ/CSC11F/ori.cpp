#include <iostream>
#include <memory>
#include <vector>
#include <limits>
#include <queue>

constexpr unsigned int MY_UINT32_MAX = std::numeric_limits<unsigned int>::max();

struct Node;
using NodePtr = std::shared_ptr<Node>;

struct Edge {
  Edge() = default;
  Edge(const NodePtr& dest_, const unsigned int distance_) : dest(dest_), distance(distance_) {}
  NodePtr dest;
  const unsigned int distance;
};

struct Node {
  Node() : visited(false), cost(MY_UINT32_MAX), id(0), edges() {}
  Node(const unsigned int id_) : visited(false), cost(MY_UINT32_MAX), id(id_), edges() {}
  bool visited;
  unsigned int cost;
  const unsigned int id;
  std::vector<Edge> edges;
};

struct CompareNodePriorityTy {
  bool operator()(NodePtr lhs, NodePtr rhs) {
    return lhs->cost > rhs->cost;
  }
};

using TraversalNodeQueue = std::priority_queue<NodePtr, std::vector<NodePtr>, CompareNodePriorityTy>;

void UpdateDistanceToNeighbor(TraversalNodeQueue& traversableNodes) {
  auto startNode = traversableNodes.top();
  traversableNodes.pop();
  //  if ( startNode->visited ) return;
  
  startNode->visited = true;


  for (auto& edge : startNode->edges) {
    const auto totalCostToNeighbor = startNode->cost + edge.distance;
    if (edge.dest->cost > totalCostToNeighbor) {
      edge.dest->cost = totalCostToNeighbor;
    }
    if (!edge.dest->visited) {
      traversableNodes.push(edge.dest);
    }
    /*
    if (!edge.dest->visited) {
      if (edge.dest->cost > totalCostToNeighbor) {
	edge.dest->cost = totalCostToNeighbor;
	traversableNodes.push(edge.dest);
      }
    }
    */

  }
}

int main() {
  unsigned int numVertices;
  unsigned int numEdges;
  unsigned int startNodeId;
  std::cin >> numVertices >> numEdges >> startNodeId;
  NodePtr startNode;
  std::vector<NodePtr> vertices(numVertices);
  for (auto i = 0u; i < numVertices; ++i) {
    vertices[i] = std::make_shared<Node>(i);
  }
  vertices[startNodeId]->cost = 0;;
  for (auto i = 0u; i < numEdges; ++i) {
    unsigned int srcId;
    unsigned int dstId;
    unsigned int distance;
    std::cin >> srcId >> dstId >> distance;
    vertices[srcId]->edges.emplace_back(vertices[dstId], distance);
  }

  TraversalNodeQueue traversableNodes;
  traversableNodes.push(vertices[startNodeId]);
  while (!traversableNodes.empty()) {
    UpdateDistanceToNeighbor(traversableNodes);
  }

  for (const auto& vertex : vertices) {
    if (vertex->cost == MY_UINT32_MAX) {
      std::cout << "INF" << std::endl;
    }
    else {
      std::cout << vertex->cost << std::endl;
    }
  }
}
