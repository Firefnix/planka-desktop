#include "data.h"
#include <glib.h>

/// Return the default URI of Planka
const gchar *get_uri(void)
{
    static const gchar *uri = "http://localhost:3000";
    return uri;
}
