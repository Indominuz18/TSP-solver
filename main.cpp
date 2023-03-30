#include <iostream>
#include <cstdlib>

#include "point.hpp"
#include "listofpoints.hpp"
#include "tspsolver.hpp"
#include "tspcycle.hpp"

using namespace std;

void testPoint() {
  Point origin(0,0,"ORIGIN");
  cout << "--print using printPoint():" << endl;
  origin.printPoint();
  cout << "--print using toString():" << endl;
  cout << origin.toString() << endl;
  cout << "--print using << operator:" << endl;
  cout << origin << endl;
  

  Point q(3,4,"Q");
  //distance should be 5
  cout << "distance between ORIGIN and Q is " << q.getDistance(origin) << endl;

  //ListOfPoints list = ListOfPoints();

}


// gets a list of points and runs the solver on this list
// used in all tests below
void testSolver(ListOfPoints &input) {
  cout << "---run the solver---" << endl;
  TSPSolver solver(input);
  solver.solve();
  TSPCycle solution = solver.getSolution();

  cout << "Solution found is: " << endl;
  solution.printList();
  cout << "the length of the solution is: " << solution.getLength() << endl;
}

// given in the assignment
void test1() {
  Point p[4] = {Point(2,2,"A"),
                Point(2,6,"B"),
                Point(5,6,"C"),
                Point(5,9,"D")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<4;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw(); 

  testSolver(inputTSP);
}

// given in the assignment
void test2() {
  ListOfPoints inputTSP;
  Point p(0,0,"A");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<10;i++) {
    string s;
    s = 'A'+i;
    p = Point(i,0,s);
    inputTSP.addPoint(p);
  }
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}

// given in the assignment
void test3() {
  ListOfPoints inputTSP;
  Point p(0,0,"O");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<50;i++) {
    p = Point(rand() % 1000, rand() % 1000,"P"+to_string(i));
    inputTSP.addPoint(p);
  }
  // some coordinates values more than 20, so we do not use draw here

  testSolver(inputTSP);
}

void test4() {
  Point p[12] = {
                Point(0,6,"A"),
                Point(1,20,"B"),
                Point(9,17,"C"),
                Point(9,0,"D"),
                Point(13,8,"E"),
                Point(20,18,"F"),
                Point(7,14,"G"),
                Point(3,4,"H"),
                Point(6,15,"I"),
                Point(5,13,"J"),
                Point(12,19,"K"),
                Point(20,20,"L")
                };

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<12;i++)
    inputTSP.addPoint(p[i]);
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw(); 

  testSolver(inputTSP);
}


void test5() {
  ListOfPoints inputTSP;
  Point p(0,0,"A");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<21;i++) {
    string s;
    s = 'A'+i;
    p = Point(i,i,s);
    inputTSP.addPoint(p);
  }
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}

void test6() {
  ListOfPoints inputTSP;
  Point p[11] = {
    Point(19, 1, "A"),
    Point(20, 1, "B"),
    Point(9, 5, "C"),
    Point(10, 3, "D"),
    Point(3, 10, "E"),
    Point(8, 3, "F"),
    Point(2, 16, "G"),
    Point(9, 19, "H"),
    Point(8, 18, "I"),
    Point(5, 12, "J"),
    Point(16, 9, "K")
  };

  for(int i = 0; i < 11; i++) {
    inputTSP.addPoint(p[i]);
  }
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw(); 

  testSolver(inputTSP);
}


void test7() {
  ListOfPoints inputTSP;
  Point p(0, 0, "A");
  cout << "Creating a list of points:" << endl;

  for (int i=0;i<10;i++) {
    string s;
    s = 'A'+i;
    p = Point(rand() % 20 + 1,rand() % 20 + 1,s);
    inputTSP.addPoint(p);
  }
  
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}

void test8() {
  Point p[4] = {Point(0,0,"A"),
                Point(0,20,"B"),
                Point(20,0,"C"),
                Point(20,20,"D")};

  cout << "Creating a list of points:" << endl;
  ListOfPoints inputTSP;
  for (int i=0;i<4;i++)
    inputTSP.addPoint(p[i]);

  Point e(3,6,"E");
  Point f(8,13, "F");
  Point g(9, 12, "G");
  inputTSP.addAfter(e, "D");
  inputTSP.addAfter(f, "E");
  inputTSP.addAfter(g, "F");
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw(); 

  testSolver(inputTSP);
}


void test9() {
  ListOfPoints inputTSP;
  Point p(0, 0, "A");

  for(int i = 0; i < 10; i++) {
    string s;
    s = 'A'+ i;
    p = Point(20 - (i*2) % 10, i*2, s);
    inputTSP.addPoint(p);
  }
 
  cout << "Printing the list:" << endl;
  inputTSP.printList();  
  inputTSP.draw();  

  testSolver(inputTSP);
}


void test10() {
  ListOfPoints inputTSP;
  Point p[11] = {
    Point(1, 1, "A"),
    Point(6, 1, "B"),
    Point(8, 1, "C"),
    Point(10, 1, "D"),
    Point(3, 3, "E"),
    Point(6, 3, "F"),
    Point(1, 4, "G"),
    Point(5, 4, "H"),
    Point(8, 4, "I"),
    Point(3, 7, "J"),
    Point(6, 7, "K")
  };
  for (int i = 0; i < 11; i++) inputTSP.addPoint(p[i]);
  cout << "Printing the list:" << endl;
  inputTSP.printList();
  cout << "\n";
  inputTSP.draw();
  testSolver(inputTSP);
}

int main() {

  cout << "****Test point**" << endl;
  testPoint();
  cout << "****End of test point**" << endl << endl;

  cout << "****test1**:" << endl;
  test1();
  cout << "****end of test1**:" << endl << endl;

  cout << "****test2**:" << endl;
  test2();
  cout << "****end of test2**:" << endl << endl;
 
  cout << "****test3**:" << endl;
  test3();
  cout << "****end of test3**:" << endl << endl;

  cout << "****test4**:" << endl;
  test4();
  cout << "****end of test4**:" << endl << endl;
 
  cout << "****test5**:" << endl;
  test5();
  cout << "****end of test5**:" << endl << endl;
 
  cout << "****test6**:" << endl;
  test6();
  cout << "****end of test6**:" << endl << endl;

  cout << "****test7**:" << endl;
  test7();
  cout << "****end of test7**:" << endl << endl;
 
  cout << "****test8**:" << endl;
  test8();
  cout << "****end of test8**:" << endl << endl;
 
  cout << "****test9**:" << endl;
  test9();
  cout << "****end of test9**:" << endl << endl;

  cout << "****test10**:" << endl;
  test10();
  cout << "****end of test10**:" << endl << endl;


  return 0;
}