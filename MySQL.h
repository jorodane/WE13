#include "/usr/include/mysql/mysql.h"
#include <iostream>

using namespace std;

//����� MYSQL�� ������ �ص���!
MYSQL* connectedDatabase;

//Result! �����ͺ��̽��� "����"�� �Ѵٰ� �ؿ�!
//"����"�� �����̳�! Ư�� �����͸� �ܾ���� ����!
//�ܾ�� �����Ϳ� ���� ���� �����!�� ���� ���´ٰ� ���ø� �ſ�!
MYSQL_RES* queryResult;
//�����͸� �����Դµ�..? ��û���� ū �����Ͱ� ���� �ſ���!
//�̰Ÿ� �� �������� �����;� �մϴ�!
MYSQL_ROW queryRow;

bool MySQLInitialize()
{
	if (!(connectedDatabase = mysql_init((MYSQL*)nullptr)))
	{
		cout << "Cannot Initialize MySQL" << endl;
		return false;
	};
	cout << "MySQL Successfully Initialized" << endl;

	//                      MySQL ������ ��ġ!  MySQL�� �ּ�!   ID      ���              ��Ʈ��ȣ
	if (!mysql_real_connect(connectedDatabase, "localhost", "root", "pasword", nullptr, 3306, nullptr, 0))
	{
		cout << "Failed to Connect MySQL" << endl;
		return false;
	};

	cout << "Successfully Connected to MySQL" << endl;
	return true;
}

void MySQLClose()
{
	mysql_close(connectedDatabase);
}