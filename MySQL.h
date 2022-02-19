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
		cout << "MySQL �ʱ�ȭ�� �����Ͽ����ϴ�!" << endl;
		return false;
	};
	cout << "���������� MySQL�� �ʱ�ȭ�߽��ϴ�!" << endl;

	//                      MySQL ������ ��ġ!  MySQL�� �ּ�!   ID      ���              ��Ʈ��ȣ
	if (!mysql_real_connect(connectedDatabase, "localhost", "root", "password", nullptr, 3306, nullptr, 0))
	{
		cout << "MySQL ���ῡ �����Ͽ����ϴ�!" << endl;
		return false;
	};

	cout << "���������� MySQL�� �����߽��ϴ�!" << endl;
	return true;
}

void MySQLClose()
{
	mysql_close(connectedDatabase);
}