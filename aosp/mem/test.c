#include <execinfo.h>
#define NULL 0

static int dump_stack_user(void) {
    void *bt_buffer[1024];
    char **strings = NULL;
    int depth = -1;
    int i = 0;
    depth = backtrace(bt_buffer, 10);

    strings = backtrace_symbols(bt_buffer, depth);
    if (!strings) {
        perror("backtrace_symbols");
	exit(1);
    }

    for(i = 0; i < depth; i++) {
        printf("#%d: %s\n", i, strings[i]);
    }

    free(strings);
    return 0;
}

static void func(int n) {
    if (n == 0) {
        return ;
    }
    n--;
    dump_stack_user();
    return;
}

int main() {
    int n = 10;
    func(n);
    return 0;
}
