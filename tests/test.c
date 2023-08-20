#include <stdio.h>
#include <string.h>

int is_map_valid(char* map[], int rows) {
    int i, j;

    // Get the maximum length from all rows
    int max_len = 0;
    for (i = 0; i < rows; i++) {
        int len = strlen(map[i]);
        max_len = len > max_len ? len : max_len;
    }

    // Validate if the boundaries are
    for (i = 0; i < rows; i++) {
        int len = strlen(map[i]);
        for (j = 0; j < len; j++) {
            if (i == 0 || i == rows-1 || j == 0 || j == len -1 ) {
                if (map[i][j] != '1') {
                    return 0;
                }
            }
        }
    }

    for (i = 1; i < rows - 1; i++) {
        for (j = 1; j < max_len - 1; j++) {
            if(map[i][j] == '1') {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    
    char* map1[] = {
        "1111",
        "1001",
        "10N1",
        "1001",
        "1111"
    };
    printf("Map 1 is %s\n", is_map_valid(map1, 5) ? "valid" : "invalid");

    char* map2[] = {
        "111111111",
        "1001",
        "10N1",
        "1001",
        "1111"
    };
    printf("Map 2 is %s\n", is_map_valid(map2, 5) ? "valid" : "invalid");

    return 0;
}