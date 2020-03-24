#include <iostream>
#include "GeoFigures.h"
#include "GeoCalculate.h"
#include "CommandLine.h"
#include "Exception.h"
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

	try {
		parseCommandLine(argc, argv, inputstring, outputstring);
	}
	catch (commandException& e) {
		cout << "命令行参数是其他字符！" << endl;
		return 0;
	}

	try {
		getInput(inputstring, lineSet, segmentSet, raySet, circleSet);
	}
	catch (illegalInputPattern& e) {
		cout << "非法输入格式！" << endl;
		return 0;
	}
	catch (notEnoughInputElement& e) {
		cout << "输入的几何对象个数不足！" << endl;
		return 0;
	}
	catch (TooManyInputElements& e) {
		cout << "文件尾输入了无关的信息或过多的几何对象！" << endl;
		return 0;
	}
	
	const int n = calPoint(lineSet, segmentSet, raySet, circleSet, pointSet);
	outputInFile(outputstring, n);

	//getInput("input.txt", lineSet, segmentSet, raySet, circleSet);
	//int k = calPoint(lineSet, segmentSet, raySet, circleSet, pointSet);
	//cout << k << endl;

	//set<Point>::iterator it;
	//for (it=pointSet.begin(); it != pointSet.end(); it++)
	//{
	//	cout << (*it).x << " " << (*it).y << endl;
	//}
}