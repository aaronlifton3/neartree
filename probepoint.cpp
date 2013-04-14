/* Test your implementation by generating 1 million random points against which to probe and 1000 randomly generated probe points.
 Brute Force 26.7 seconds. NearTree 18.6 seconds. I have designed it by making different functions for each task needed in the program.
 The first function is makeDatabase() which creates 1 million random 3 dimensional points and keeps them in an array.
 The next function is findNearest() which is the search used to find the nearest cell to a probecell taking from NearTree.
 cellNearTreeBuild() builds the tree structure from the database that was made. It sends the array values into NearTree which then
 sorts the values using probecell's operator - and Norm functions. They are used to create L1 algorithm.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "TNear.h"
#include "triple.h"
#include "rhrand.h"
#include "probecell.h"

using namespace std;

CNearTree <probecell, int> cellTree;
const int NUM_POINTS = 1000000;
int numRand = 0;
int databaseArray[NUM_POINTS][3];
int probeArray[3];

void makeDatabase()
{
	for (int i = 0; i < NUM_POINTS; i++)
	{
		numRand = rand() % 1000 + 1;
		databaseArray[i][0] = numRand;

		numRand = rand() % 1000 + 1;
		databaseArray[i][1] = numRand;

		numRand = rand() % 1000 + 1;
		databaseArray[i][2] = numRand;
	}
}

void findNearest()
{
	for (int i = 0; i < 1000; i++)
	{
		numRand = rand() % 1000 + 1;
		probeArray[0] = numRand;

		numRand = rand() % 1000 + 1;
		probeArray[1] = numRand;

		numRand = rand() % 1000 + 1;
		probeArray[2] = numRand;

		probecell unknownCell = probecell(probeArray[0], probeArray[1], probeArray[2]);
		cout << probeArray[0] << "/" << probeArray[1] << "/" << probeArray[2] << endl;
		probecell nearestData = *cellTree.NearestNeighbor(1000000, unknownCell);
		cout << nearestData.getData(0) << "/" << nearestData.getData(1) << "/" << nearestData.getData(2) << endl;
	}
}

void cellNearTreeBuild(void)
{
	for (int i = 0; i < NUM_POINTS; i++)
	{
		probecell *cellData = new probecell(databaseArray[i][0], databaseArray[i][1], databaseArray[i][2]);
		cellTree.ImmediateInsert(*cellData);
	}
}

int main ()
{
  srand (time(NULL));
  makeDatabase();

  cellNearTreeBuild();
  findNearest();

  system("PAUSE");
  return 0;
}