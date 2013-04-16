#include"get_gravatar.h"
#include<string.h>

gchar*
get_hash (gchar *email)
{
    gchar  *hash, *copy;

    copy = g_strdup(email);
    copy = g_strstrip(copy);

    hash = g_compute_checksum_for_string (G_CHECKSUM_MD5, copy, -1);
    g_free(copy);
    return hash;
}

void
message_callback(SoupSession *session, SoupMessage *msg,gpointer loop)
{
    SoupBuffer *buffer;
    FILE *outputfile = fopen ("avatar", "wb");
    if (!outputfile)
    {
        return;
    }

    if (msg->status_code != 200)
    {
        printf ("HTTP error!\n");
        return ;
    }

    buffer = soup_message_body_flatten (msg->response_body);
    fwrite (buffer->data, 1, buffer->length, outputfile);
    g_main_quit ((GMainLoop *) loop);
}

void
get_image (gchar *hash, GMainLoop *main_loop)
{
    gchar *url;
    SoupSession *session;
    SoupMessage *msg;
    SoupMessageBody *body;
    SoupBuffer *buffer;

    url = g_strdup_printf ("http://www.gravatar.com/avatar/%s", hash);

    session = soup_session_async_new ();
    msg = soup_message_new ("GET", url);
    soup_session_queue_message (session, msg, message_callback, main_loop);
}
