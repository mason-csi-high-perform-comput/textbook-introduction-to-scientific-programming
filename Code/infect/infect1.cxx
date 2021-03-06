/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** infect1.cxx : multiple persons random infection
 ****               using classes
 ****
 ****************************************************************/

#include <cmath>
#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <vector>

using namespace std;

#include "infect_lib.h"

int main() {

  // initialize random generator
  srand(100*time(NULL)%100);

  int npeople;
  cout << "Size of population? ";
  cin >> npeople;
  cout  << endl;
  Population population(npeople);

  // set patient zero
  population.random_infection();

  std::vector<int> history;
  int max_infected = 1;
  int step = 1;
  //codesnippet infect1loop
  for ( ; ; step++) {

    int count_infected{0};
    population.update();
    count_infected = population.count_infected();
    cout << "In step " << setw(3) << step
         << " #sick: " << setw(4) << count_infected
         << " : " << population.display() << endl;
    //cout << "#infected: " << count_infected << endl;

    if (count_infected==0)
      break;
  }
  cout << "Disease ran its course by step " << step << endl;
  //codesnippet end

  return 0;
}
