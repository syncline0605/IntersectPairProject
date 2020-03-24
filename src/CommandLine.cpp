#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include "GeoFigures.h"
#include "Exception.h"

using namespace std;

const regex Nregex("\\s*(0|([1-9][0-9]*))\\s*");
const regex ENDregex("\\s*");
const regex THREEregex("(\\s+-?(0|([1-9][0-9]*))){3}\\s*");
const regex FOURregex("(\\s+-?(0|([1-9][0-9]*))){4}\\s*");


//解析命令行
void parseCommandLine(int argc, char* argv[], string& inputstring, string& outputstring)
{
	string in = "-i";
	string out = "-o";
	if (argc != 5)
	{
		throw commandException();
	}
	string command = argv[1];
	if (command.compare(in))
	{
		throw commandException();
	}
	inputstring = argv[2];
	command = argv[3];
	if (command.compare(out))
	{
		throw commandException();
	}
	inputstring = argv[4];
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
	
	stringstream inputLineStream;
	string nString;
	getline(input, nString);
	if (!regex_match(nString, Nregex)) {
		//未找到符合要求的n，非法输入格式！
		throw illegalInputPattern();
		return;
	}
	n = stoi(nString);//字符串变整数
	
	//input >> n;
	for (int i = 0; i < n; i++)
	{
		inputLineStream.clear();
		string kind;
		input >> kind;
		string newInputLine;
		if (!kind.compare(line))
		{
			getline(input, newInputLine);
			if (!regex_match(newInputLine, FOURregex))
			{
				throw illegalInputPattern();
				return;
			}
			inputLineStream << newInputLine;
			Line newLine;
			inputLineStream >> newLine.p1.x >> newLine.p1.y >> newLine.p2.x >> newLine.p2.y;
			lineSet.push_back(newLine);
		}
		else if (!kind.compare(segment))
		{
			getline(input, newInputLine);
			if (!regex_match(newInputLine, FOURregex))
			{
				throw illegalInputPattern();
				return;
			}
			inputLineStream << newInputLine;
			Segment newSegment;
			inputLineStream >> newSegment.p1.x >> newSegment.p1.y >> newSegment.p2.x >> newSegment.p2.y;
			segmentSet.push_back(newSegment);
		}
		else if (!kind.compare(ray))
		{
			getline(input, newInputLine);
			if (!regex_match(newInputLine, FOURregex))
			{
				throw illegalInputPattern();
				return;
			}
			inputLineStream << newInputLine;
			Ray newRay;
			inputLineStream >> newRay.start.x >> newRay.start.y >> newRay.direction.x >> newRay.direction.y;
			raySet.push_back(newRay);
		}
		else if (!kind.compare(circle))
		{
			getline(input, newInputLine);
			if (!regex_match(newInputLine, THREEregex))
			{
				throw illegalInputPattern();
				return;
			}
			inputLineStream << newInputLine;
			Circle newCircle;
			inputLineStream >> newCircle.center.x >> newCircle.center.y >> newCircle.r;
			circleSet.push_back(newCircle);
		}
		else
		{
			//输入元素不足
			throw notEnoughInputElement();
			return;
		}
	}
	string testEndString;
	getline(input, testEndString);
	if (!regex_match(testEndString, ENDregex)) {
		//输入无关元素
		throw TooManyInputElements();
		return;
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
