#include <iostream>
#include <memory>

using TlsContext = int;

struct HAConfig {
    HAConfig() : tls_context_(new TlsContext(42)) {}

    std::shared_ptr<TlsContext>& tlsContext() {
        return tls_context_;
    }

private:
    std::shared_ptr<TlsContext> tls_context_;
};

void f(std::shared_ptr<TlsContext>& tlsContext) {
    std::cout << *tlsContext << std::endl;
}

int main() {
    f(HAConfig().tlsContext());
    return 0;
}
