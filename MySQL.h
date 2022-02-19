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
		cout << "MySQL 초기화에 실패하였습니다!" << endl;
		return false;
	};
	cout << "성공적으로 MySQL을 초기화했습니다!" << endl;

	//                      MySQL 저장할 위치!  MySQL의 주소!   ID      비번              포트번호
	if (!mysql_real_connect(connectedDatabase, "localhost", "root", "password", nullptr, 3306, nullptr, 0))
	{
		cout << "MySQL 연결에 실패하였습니다!" << endl;
		return false;
	};

	cout << "성공적으로 MySQL에 연결했습니다!" << endl;
	return true;
}

void MySQLClose()
{
	mysql_close(connectedDatabase);
}