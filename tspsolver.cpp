#include "tspsolver.hpp"

TSPSolver::TSPSolver(ListOfPoints &list) 
{
  m_list = list;
}

// This gives us the hesteric distnace i is the point being inserted between j and jNext 
float TSPSolver::getDistanceIncrease(Point i, Point j, Point jNext) // i is being inserted
{
  float d1 = i.getDistance(j);
  float d2 = i.getDistance(jNext);
  float d3 = j.getDistance(jNext);
  return d1 + d2 - d3;
}
// returns m_solution which is the solution
TSPCycle& TSPSolver::getSolution() 
{
  return m_solution;
}

// This is the main solver of the tsp solver 
void TSPSolver::solve() {

for (int i = 0; i < 3; i++)
{
  m_solution.addPoint(m_list.getPointAt(i));
}


for (int i = 3; i < m_list.getSize(); i++) {
    int bestIndex = 0;
    float bestDistance = getDistanceIncrease(m_list.getPointAt(i),m_solution.getPointAt(0),m_solution.getPointAt(1));
    for (int k = 1; k < i; k++) {
      float tempDistance = getDistanceIncrease(m_list.getPointAt(i),m_solution.getPointAt(k),m_solution.getPointAt((k+1)%i));
      if (tempDistance < bestDistance) {
        bestDistance = tempDistance;
        bestIndex = k;
      }       
    }
    string bestName = m_solution.getPointAt(bestIndex).getName();
    m_solution.addAfter(m_list.getPointAt(i),bestName);
  }
} 