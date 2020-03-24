#pragma once

struct outRangeException : public exception
{
	const char* what() const throw ()
	{
		return "坐标范围超限！";
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

struct illegalInputPattern : public exception
{
	const char* what() const throw ()
	{
		return "非法输入格式！";
	}
};

struct notEnoughInputElement : public exception
{
	const char* what() const throw ()
	{
		return "输入的几何对象不足！";
	}
};

struct TooManyInputElements : public exception
{
	const char* what() const throw ()
	{
		return "文件尾输入了无关的信息或过多的几何对象！";
	}
};