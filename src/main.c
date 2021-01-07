#include <gtk/gtk.h>
#include <app/app.h>

int main(int argc, char *argv[])
{
    parse_args(argc, argv);
    setup("http://localhost:3000");
    gtk_main();
    return 0;
}
