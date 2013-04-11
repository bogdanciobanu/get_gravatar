#include"get_gravatar.h"
#include<string.h>

gchar*
get_hash (gchar *email)
{
    gchar *end, *hash;

    /* Trim leading and trailing whitespaces*/
    while(g_ascii_isspace(*email))
        email++;
    if(*email == '\0')
        return email;
    end = email + strlen(email) - 1;
    while(end > email && g_ascii_isspace(*end))
        end--;
    *(end+1) = '\0';

    hash = g_compute_checksum_for_string (G_CHECKSUM_MD5, email, -1);
    return hash;
}

SoupBuffer*
get_image (gchar *hash)
{
    gchar url[200];
    SoupSession *session;
    SoupMessage *msg;
    SoupMessageBody *body;
    SoupBuffer *buffer;

    g_strlcpy(url, "http://www.gravatar.com/avatar/", 200);
    g_strlcat(url, hash, 200);

    session = soup_session_async_new ();
    msg = soup_message_new("GET", url);
    soup_session_send_message (session, msg);

    buffer = soup_message_body_flatten (msg->response_body);
    return buffer;
}
