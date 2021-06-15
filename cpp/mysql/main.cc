#include <iostream>
#include <stdlib.h>

#include <mysql/mysql.h>

using namespace std;

void f(std::string const& statement) {
  try {
    // Format a MySQL object
    MYSQL *conn = mysql_init(NULL);

    // Establish a MySQL connection
    if (!mysql_real_connect(conn, "localhost", "keatest", "keatest",
                            "keatest", 3306, nullptr, 0)) {
      cerr << mysql_error(conn) << endl;
      return;
    }

    // Execute a sql statement
    if (mysql_query(conn, statement.c_str())) {
      cerr << mysql_error(conn) << endl;
      return;
    }

    // Get a result set
    MYSQL_RES *res = mysql_use_result(conn);

    MYSQL_ROW row;
    // Fetch a result set
    size_t const column_count(mysql_num_fields(result.result_));
    while ((row = mysql_fetch_row(res)) != NULL) {
      for (size_t i = 0; i < column_count; ++i) {
        cout << row[i] << endl;
      }
    }

    // Release memories
    mysql_free_result(res);

    // Close a MySQL connection
    mysql_close(conn);
  } catch (char *e) {
    cerr << "[EXCEPTION] " << e << endl;
    return;
  }
}

int main() {
    f("SHOW GLOBAL VARIABLES LIKE 'pxc_strict_mode'");
    f("CREATE TABLE tabl3 ( timestamp TIMESTAMP );");
    f("INSERT INTO tabl3 ( timestamp ) VALUES ( 214748364 );");
    f("SELECT timestamp FROM tabl3;");
    return 0;
}
