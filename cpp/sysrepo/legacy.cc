#include <sysrepo.h>

int main() {
    sr_conn_ctx_t *connection = NULL;
    sr_session_ctx_t *session = NULL;
    sr_connect("configure_test", SR_CONN_DEFAULT, &connection);
    sr_disconnect(connection);
}
