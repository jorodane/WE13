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

//���߿� ���̺�� �ٲٸ� ���⼭�� �ٲ��ּ���!
string targetTable = "UserData";

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

bool LoadUser(string id)
{
	//���������Ϳ��� ���̵� ��ġ�ϴ� �༮�� ���� �����ɴϴ�!
	//SELECT * FROM UserData WHERE ID = "id";
	string query = "SELECT * FROM ";
	query += targetTable;
	query += " WHERE ID = \"";
	query += id;
	query += "\";";

	if (mysql_query(connectedDatabase, query.c_str()) != 0)
	{
		return false;
	};

	//Select���� ���� ����� "��������" �Ŵϱ�! ������ ��򰡿� �����ؾ߰���!
	//mySQL�� ���� ������ ���� ���� �������־��! �װ� ��������� ���ؾ� �ؿ�!
	queryResult = mysql_store_result(connectedDatabase);

	//�� ���·� �����;� �ϱ� ������! �̰� �� �� �� ���Դϴ�!
	queryRow = mysql_fetch_row(queryResult);

	return true;
}

void SaveUser(string id, string color)
{
	string query;
	//�ϴ� ������ �ҷ��ɴϴ�!
	if (LoadUser(id))
	{
		//�̹� ������ �־����ϱ�! ���� �ٲ��ָ� ����!
		//UPDATE UserData SET COLOR = "color" WHERE ID = "id";
		//UPDATE UserData SET COLOR = "color", INI = "a" WHERE ID = "id";
		query = "UPDATE ";
		query += targetTable;
		query += " SET COLOR=\"";
		query += color;
		query += "\" WHERE ID = \"";
		query += id;
		query += "\";";
	}
	else
	{
		//INSERT INTO UserData (ID, COLOR) VALUES ("id", "color");
		query = "INSERT INTO ";
		query += targetTable;
		query += " (ID, COLOR) VALUES(\"";
		//������ ID�߰����ֱ�!
		query += id;
		query += "\", \"";
		query += color;
		query += "\");";
	};

	if (mysql_query(connectedDatabase, query.c_str()) != 0)
	{
		cout << "Cannot Save Data" << endl;
		return;
	};
	cout << "Save Succeed" << endl;
}

//���߿��� �ϳ��ϳ� �ҷ����⺸�ٴ�! ����ü�� ����Ű����� �� ���� ���� �� �ְ�
//�غ��Ͻô� �͵� ��õ�帳�ϴ�!
string GetColor(string id)
{
	if (LoadUser(id))
	{
		//LoadUser�� �ϸ�! queryRow�� ������ ���ϴ�!
		//queryRow[0]�� ID����!
		return queryRow[1];
	};

	return "B";
}

void DeleteUser(string id)
{
	if (LoadUser(id))
	{
		//�ش� ID�� �ִ� ���� ���������ڴ�!
		//DELETE FROM UserData WHERE ID = "id";
		string query = "DELETE FROM ";
		query += targetTable;
		query += "WHERE ID = \"";
		query += id;
		query += "\";";
	};
}