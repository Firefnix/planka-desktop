#include <gtk/gtk.h>

GtkWidget *get_window(void);
void add_window_callback_symbols(void);

void maximize_window(void);
void on_window_main_destroy(void);
gboolean on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer user_data);
