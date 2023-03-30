#include "listofpoints.hpp"

ListOfPoints::ListOfPoints()
{
  // implement me
}

// This function adds points after the given name
void ListOfPoints::addAfter(Point &newPt, string name)
{
  for (int i = 0; i < getSize(); i++)
  {
    if (m_points[i].getName() == name)
    {
      m_points.insert(m_points.begin() + i + 1, newPt);
      break;
    }
  }
}

// This function simply adds the point to the very end of the vector
void ListOfPoints::addPoint(Point &newPt)
{
  m_points.push_back(newPt);
}

// This function gets the point from the ith index of the vector
Point &ListOfPoints::getPointAt(unsigned int i)
{
  return m_points[i];
}

// This gets the size of the vector
int ListOfPoints::getSize() const
{
  return m_points.size();
}

// This prints out the list of points
void ListOfPoints::printList() const
{

  for (int i = 0; i < m_points.size(); i++)
    m_points[i].printPoint();
}

// This prints out the graph and point placements
void ListOfPoints::draw() const
{
  bool found = false;

  for (int i = 0; i <= MAX_X; i++)
  {
    for (int j = 0; j <= MAX_Y; j++)
    {
      int k;
      for (k = 0; k < getSize(); k++)
      {
        if (m_points.at(k).getX() == i && m_points[k].getY() == j)
        {
          found = true;
          break;
        }
      }
      if (found)
      {
        cout << " " << m_points[k].getName() << " ";
        found = false;
      }
      else
      {
        cout << " - ";
      }
    }
    cout << endl;
  }
}

// work from here
