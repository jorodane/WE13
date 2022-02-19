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
	if (!mysql_real_connect(connectedDatabase, "localhost", "root", "password", nullptr, 3306, nullptr, 0))
	{
		cout << "Failed to Connect MySQL" << endl;
		return false;
	};

	cout << "Successfully Connected to MySQL" << endl;

	//mysql�� ���ǹ��� �����ϴ�!         ���ǹ��� ���ڿ� ���ʿ� �����ø� �˴ϴ�!
	//                                  �����ͺ��̽� ����!
	if (mysql_query(connectedDatabase, "USE ServerData;") != 0)
	{
		cout << "Database is Invalid" << endl;
		return false;
	};
	cout << "Database has Open" << endl;

	return true;
}

void MySQLClose()
{
	mysql_close(connectedDatabase);
}

void SaveUser(string id, string color)
{
	string query = "INSERT INTO UserData (ID, COLOR) VALUES (\"";
	//������ ID�߰����ֱ�!
	query += id;
	query += "\", \"";
	query += color;
	query += "\");";

	if (mysql_query(connectedDatabase, query.c_str()) != 0)
	{
		cout << "Cannot Save Data" << endl;
		return;
	};

	cout << "Save Succeed" << endl;
}