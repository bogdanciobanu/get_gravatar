#ifndef GET_gravatar_H
#define GET_gravatar_H

#include<glib.h>
#include<libsoup/soup.h>
#include<stdio.h>

gchar* get_hash (gchar *str);
void message_callback (SoupSession *session, SoupMessage *msg, gpointer data);
void get_image (gchar *hash, GMainLoop *loop);

#endif
