#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Content-Type: text/html\n\n");
    printf("<html><head><title>Contact Form Data</title></head><body>");

    // Отримання даних з форми
    char *data;
    char *name = NULL;
    char *email = NULL;
    long len = 0;
    char *method = getenv("REQUEST_METHOD");
    if (strcmp(method, "POST") == 0) {
        len = strtol(getenv("CONTENT_LENGTH"), NULL, 10);
        data = (char *)malloc(len + 1);
        if (data != NULL) {
            fgets(data, len + 1, stdin);
        }
    }

    // Розділення даних на поля
    char *pair = strtok(data, "&");
    while (pair != NULL) {
        char *key = strtok(pair, "=");
        char *value = strtok(NULL, "=");
        if (strcmp(key, "name") == 0) {
            name = value;
        } else if (strcmp(key, "email") == 0) {
            email = value;
        }
        pair = strtok(NULL, "&");
    }

    // Вивід даних
    printf("<h1>Contact Form Data:</h1>");
    if (name != NULL) {
        printf("<p>Name: %s</p>", name);
    }
    if (email != NULL) {
        printf("<p>Email: %s</p>", email);
    }

    printf("</body></html>");

    return 0;
}
