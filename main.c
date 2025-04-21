
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <stdarg.h>


#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

int rand_int() {
    return (int)(random() % __INT_MAX__);
}


int main(int argc, const char **argv) {
    srandom(time(0));

    if (argc != 2) {
        fprintf(stderr, "USAGE: %s <output-file>\n", argv[0]);
        exit(1);
    }

    const char *filename = argv[1];
    FILE *f = fopen(filename, "w");

    if (!f) {
        perror("cannot open file");
        exit(1);
    }

    // helper macro
    #define print(msg, ...)   fprintf(f, msg, ##__VA_ARGS__)
    #define println(msg, ...) print(msg "\n", ##__VA_ARGS__)


    const char *vars[] = {"a", "b", "c", "d", "e"};
    const char *operations[] = {"+", "-", "*"};

    println("#include <stdio.h>");
    println("#include <stdlib.h>");
    println("#include <time.h>");
    println("int main(void) {");
    println("    srand(time(0));");

    print("    int %s", vars[0]);
    for (size_t i = 1; i < ARRAY_SIZE(vars); i++) {
        print(", %s", vars[i]);
    }
    print(";\n");

    for (size_t i = 0; i < ARRAY_SIZE(vars); i++) {
        println("    %s = rand();", vars[i]);
    }

    for (size_t i = 0; i < ARRAY_SIZE(vars); i++) {
        const char *var = vars[i];
        println("    printf(\"%s = %s\\n\", %s);", var, "%d", var);
    }
    for (size_t i = 0; i < 1*1000*1000; i++) {
        const char *assign_to = vars      [rand_int()%ARRAY_SIZE(vars)      ];
        const char *arg1      = vars      [rand_int()%ARRAY_SIZE(vars)      ];
        const char *arg2      = vars      [rand_int()%ARRAY_SIZE(vars)      ];
        const char *op        = operations[rand_int()%ARRAY_SIZE(operations)];

        println("    %s ^= %s %s %s + %d;", assign_to, arg1, op, arg2, rand_int());
    }

    for (size_t i = 0; i < ARRAY_SIZE(vars); i++) {
        const char *var = vars[i];
        println("    printf(\"%s = %s\\n\", %s);", var, "%d", var);
    }
    println("    return 0;");
    println("}");

    fclose(f);

    return 0;
}
