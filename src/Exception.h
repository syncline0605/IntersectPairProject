#pragma once

struct outRangeException : public exception
{
	const char* what() const throw ()
	{
		return "���귶Χ���ޣ�";
	}
};

struct numException : public exception
{
	const char* what() const throw ()
	{
		return "������������";
	}
};

struct commandException : public exception
{
	const char* what() const throw ()
	{
		return "�����в����������ַ���";
	}
};

struct infException : public exception
{
	const char* what() const throw ()
	{
		return "�������Ϊ�������";
	}
};