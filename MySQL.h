#include "/usr/include/mysql/mysql.h"
#include <iostream>

using namespace std;

//연결된 MYSQL을 저장을 해두죠!
MYSQL* connectedDatabase;

//Result! 데이터베이스에 "쿼리"를 한다고 해요!
//"쿼리"는 무엇이냐! 특정 데이터를 긁어오는 행위!
//긁어온 데이터에 대한 내용 결과물!이 여기 들어온다고 보시면 돼요!
MYSQL_RES* queryResult;
//데이터를 가져왔는데..? 엄청나게 큰 데이터가 왔을 거에요!
//이거를 줄 형식으로 가져와야 합니다!
MYSQL_ROW queryRow;

bool MySQLInitialize()
{
	if (!(connectedDatabase = mysql_init((MYSQL*)nullptr)))
	{
		cout << "Cannot Initialize MySQL" << endl;
		return false;
	};
	cout << "MySQL Successfully Initialized" << endl;

	//                      MySQL 저장할 위치!  MySQL의 주소!   ID      비번              포트번호
	if (!mysql_real_connect(connectedDatabase, "localhost", "root", "password", nullptr, 3306, nullptr, 0))
	{
		cout << "Failed to Connect MySQL" << endl;
		return false;
	};

	cout << "Successfully Connected to MySQL" << endl;

	//mysql에 질의문을 던집니다!         질의문을 문자열 안쪽에 넣으시면 됩니다!
	//                                  데이터베이스 설정!
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
	//쿼리에 ID추가해주기!
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