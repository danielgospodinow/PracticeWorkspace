#include <unistd.h>
#include <string.h>

int main(void) {
    char* buff = "Hello, world!\n";
    int p;

    if (fork() == 0) 
        write(1, buff, strlen(buff));
    p = fork();
    write(1, buff, strlen(buff));
}

// а) Колко пъти ще се изведе на стандартния изход текстът "Hello, world!"при изпълнението на програмата? Обосновете отговора си.
// б) Нарисувайте кореновото дърво с върхове процесите, които ще се стартират в резултат от изпълнението на програмата и ребра двойките родител-наследник.