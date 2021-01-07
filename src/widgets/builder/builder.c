#include "builder.h"
#include <assert.h>

static const char *get_builder_file_path(void) {
	return "glade/layout.glade";
}

/// Return an [GtkWidget] with name [name] from the [GtkBuilder]
GtkWidget *get_widget(const gchar *name) {
	return GTK_WIDGET(get_object(name));
}

/// Return an [GObject] with name [name] from the [GtkBuilder]
GObject *get_object(const char *name) {
	return gtk_builder_get_object(get_builder(), name);
}

/// Return the [GtkBuilder] of the app
GtkBuilder *get_builder(void)
{
	static GtkBuilder *builder = NULL;
	if (!builder) {
		builder = gtk_builder_new_from_file(get_builder_file_path());
		assert(builder);
	}
	return builder;
}

/// Clear the builder
void free_builder(void)
{
	GtkBuilder *builder = get_builder();
	g_clear_object(&builder);
	builder = NULL;
}
