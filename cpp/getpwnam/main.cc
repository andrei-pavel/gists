#include <cstring>
#include <stdio.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <shadow.h>

char* auth_password_get_pwd_hash(const char *username)
{
    struct passwd *pwd, pwd_buf;
    struct spwd *spwd, spwd_buf;
    char *pass_hash = NULL, buf[256];

    getpwnam_r(username, &pwd_buf, buf, 256, &pwd);
    if (!pwd) {
        printf("User \"%s\" not found locally.", username);
        return NULL;
    }

    if (!strcmp(pwd->pw_passwd, "x")) {
        getspnam_r(username, &spwd_buf, buf, 256, &spwd);
        if (!spwd) {
            printf("Failed to retrieve the shadow entry for \"%s\".", username);
            return NULL;
        }

        pass_hash = spwd->sp_pwdp;
    } else {
        pass_hash = pwd->pw_passwd;
    }

    if (!pass_hash) {
        printf("No password could be retrieved for \"%s\".", username);
        return NULL;
    }

    /* check the hash structure for special meaning */
    if (!strcmp(pass_hash, "*") || !strcmp(pass_hash, "!")) {
        printf("User \"%s\" is not allowed to authenticate using a password.", username);
        return NULL;
    }
    if (!strcmp(pass_hash, "*NP*")) {
        printf("Retrieving password for \"%s\" from a NIS+ server not supported.", username);
        return NULL;
    }

    return strdup(pass_hash);
}

int main() {
    printf("%s\n", auth_password_get_pwd_hash("andrei"));
}
