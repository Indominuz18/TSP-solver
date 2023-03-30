#include <iostream>

#include "tspcycle.hpp"

TSPCycle::TSPCycle() {
// implement me
//  cout << "default TSPCycle constructor" << endl;
}


// returns the length of the cycle
float TSPCycle::getLength()  {
  float totalDistance = 0;

  for (int i = 0; i < getSize(); i++)
  {
    int nextIndex = (i+1) % getSize();
    Point cur = m_points.at(i);
    Point next_cur = m_points.at(nextIndex);
    totalDistance += cur.getDistance(next_cur);
  }

  return totalDistance;
}
