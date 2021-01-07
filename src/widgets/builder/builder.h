#include <gtk/gtk.h>

GObject *get_object(const char *name);
GtkWidget *get_widget(const gchar *name);
GtkBuilder *get_builder(void);
void free_builder(void);
