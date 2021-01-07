#include <gtk/gtk.h>
#include "app/data/data.h"
#include "args.h"

static GOptionEntry *get_args_entries(void);

/// Parse the program's arguments
void parse_args(gint argc, gchar **argv) {
    GOptionContext *context = g_option_context_new("Free open source kanban board for workgroups.");
    g_option_context_add_main_entries(context, get_args_entries(), NULL);
    g_option_context_add_group(context, gtk_get_option_group(TRUE));
    if (!g_option_context_parse(context, &argc, &argv, NULL)) {
        g_print ("option parsing failed\n");
        exit(1);
    }
}

static gboolean show_bar = FALSE;
/// Getter for the static variable [show_bar]
gboolean should_show_top_bar(void) {
    return !show_bar;
}

/// Return a list of [GOptionEntry] defining the arguments of the program
static GOptionEntry *get_args_entries(void) {
    static GOptionEntry entries[] = {
        {
            "bar",
            'b',
            G_OPTION_FLAG_NONE, G_OPTION_ARG_NONE,
            &show_bar,
            "Should show the top bar",
            NULL
        }
    };
    return entries;
}
