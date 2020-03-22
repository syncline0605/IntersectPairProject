#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "GeoFigures.h"

using namespace std;

//解析命令行
void parseCommandLine(int argc, char* argv[], string& inputstring, string& outputstring)
{
	string in = "-i";
	string out = "-o";
	for (int i = 1; i < argc; i++)
	{
		string command = argv[i];
		if (!command.compare(in))
		{
			inputstring = argv[++i];
		}
		else if (!command.compare(out))
		{
			outputstring = argv[++i];
		}
	}
}
//从输入文件里获取输入对象
void getInput(string inputstring, vector<Line>& lineSet,
	vector<Segment>& segmentSet, vector<Ray>& raySet, vector<Circle>& circleSet)
{
	ifstream input;
	input.open(inputstring, ios::in);
	int n;
	const string line = "L";
	const string segment = "S";
	const string ray = "R";
	const string circle = "C";
	input >> n;
	for (int i = 0; i < n; i++)
	{
		string kind;
		input >> kind;
		if (!kind.compare(line))
		{
			Line newLine;
			input >> newLine.p1.x >> newLine.p1.y >> newLine.p2.x >> newLine.p2.y;
			lineSet.push_back(newLine);
		}
		else if (!kind.compare(segment))
		{
			Segment newSegment;
			input >> newSegment.p1.x >> newSegment.p1.y >> newSegment.p2.x >> newSegment.p2.y;
			segmentSet.push_back(newSegment);
		}
		else if (!kind.compare(ray))
		{
			Ray newRay;
			input >> newRay.start.x >> newRay.start.y >> newRay.direction.x >> newRay.direction.y;
			raySet.push_back(newRay);
		}
		else if (!kind.compare(circle))
		{
			Circle newCircle;
			input >> newCircle.center.x >> newCircle.center.y >> newCircle.r;
			circleSet.push_back(newCircle);
		}
	}
	input.close();
}

//把计算结果输出到文件
void outputInFile(string filename, int n)
{
	ofstream output;
	output.open(filename, ios::out);

	output << n << endl;
	output.close();
}
