#pragma once

#include <string>
#include <vector>
#include "GeoFigures.h"

void parseCommandLine(int argc, char* argv[], string& inputstring, string& outputstring);
void getInput(string inputstring, vector<Line>& lineSet, vector<Segment>& segmentSet, vector<Ray>& raySet, vector<Circle>& circleSet);
void outputInFile(string filename, int n);