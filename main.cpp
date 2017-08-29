#include <iostream>
#include <mysql/mysql.h>
#include <string>
using namespace std;

int main()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;

    conn = mysql_init(0);

    if(conn)
    {
        cout << "Connection object ok" << endl;
    }
    else
    {
        cout << "conn object problem" << mysql_error(conn) << endl;
    }

    conn = mysql_real_connect(conn, "localhost", "root", "34781294", "teste1", 0, NULL, 0);

    if(conn)
    {
        cout << "connection to database done" << conn << endl;

        cout << "Enter id:" << endl;
        string id = "";
        cin >> id;

        cout << "Enter name:" << endl;
        string name = "";
        cin >> name;

        cout << "Enter email:" << endl;
        string email = "";
        cin >> email;

        string query = "insert into users(id, name, email) values('"+id+"','"+name+"','"+email+"')";

        const char* q = query.c_str();

        cout << "query is: " << q << endl;

        int qstate;
        qstate = mysql_query(conn, q);

        if (!qstate) {
            cout << "insert has a successfully..." << endl;
        }
        else
        {
            cout << "query problem: " << mysql_error(conn) << endl;
        }

        qstate = 0;

        qstate  = mysql_query(conn, "select * from users");

        if (!qstate)
        {
            res = mysql_store_result(conn);
            while(row = mysql_fetch_row(res))
            {
                cout << "id: "    << row[0] << " "
                     << "name: "  << row[1] << " "
                     << "email: " << row[2] << endl;
            }
        }
        else
        {
             cout << "Query execution problem!" << mysql_error(conn) << endl;
        }
    }
    else
    {
        cout << "conn object problem" << mysql_error(conn) << endl;
    }

    cout << "Finish" << endl;
    return 0;
}
