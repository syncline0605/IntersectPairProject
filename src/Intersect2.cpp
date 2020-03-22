#include <iostream>
#include "GeoFigures.h"
#include "GeoCalculate.h"
#include "CommandLine.h"
using namespace std;

int main(int argc, char* argv[])
{
	string inputstring = "";
	string outputstring = "";
	vector<Line> lineSet;
	vector<Segment> segmentSet;
	vector<Ray> raySet;
	vector<Circle> circleSet;
	set<Point> pointSet;

	parseCommandLine(argc, argv, inputstring, outputstring);
	getInput(inputstring, lineSet, segmentSet, raySet, circleSet);
	const int n = calPoint(lineSet, segmentSet, raySet, circleSet, pointSet);
	outputInFile(outputstring, n);

	//getInput("input.txt", lineSet, segmentSet, raySet, circleSet);
	//int k = calPoint(lineSet, segmentSet, raySet, circleSet, pointSet);
	//cout << k << endl;
}