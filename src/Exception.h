#pragma once

struct outRangeException : public exception
{
	const char* what() const throw ()
	{
		return "坐标范围超限！";
	}
};

struct numException : public exception
{
	const char* what() const throw ()
	{
		return "参数个数有误！";
	}
};

struct commandException : public exception
{
	const char* what() const throw ()
	{
		return "命令行参数是其他字符！";
	}
};

struct infException : public exception
{
	const char* what() const throw ()
	{
		return "交点个数为无穷个！";
	}
};