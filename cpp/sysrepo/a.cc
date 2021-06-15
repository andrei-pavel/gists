#include <sysrepo.h>
#include <sysrepo-cpp/Session.hpp>

int main() {
    sysrepo::Connection();
    sr_conn_ctx_t *connection = NULL;
    sr_connect(SR_CONN_DEFAULT, &connection);
    sr_disconnect(connection);
}
