#pragma once

struct outRangeException : public exception
{
	const char* what() const throw ()
	{
		return "���귶Χ���ޣ�";
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

struct illegalInputPattern : public exception
{
	const char* what() const throw ()
	{
		return "�Ƿ������ʽ��";
	}
};

struct notEnoughInputElement : public exception
{
	const char* what() const throw ()
	{
		return "����ļ��ζ����㣡";
	}
};

struct TooManyInputElements : public exception
{
	const char* what() const throw ()
	{
		return "�ļ�β�������޹ص���Ϣ�����ļ��ζ���";
	}
};