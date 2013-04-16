#include "get_gravatar.h"

int main(int argc, char **argv)
{
    GMainLoop *main_loop = NULL;
    g_type_init();
    gchar *email, *hash;
    SoupBuffer *response;

    
    main_loop = g_main_loop_new (NULL, TRUE);
    hash = get_hash (argv[1]);
    get_image (hash, main_loop);
    g_main_loop_run (main_loop);
    g_main_loop_unref (main_loop);

    return 0;
}
