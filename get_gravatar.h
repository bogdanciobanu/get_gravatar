#ifndef GET_gravatar_H
#define GET_gravatar_H

#include<glib.h>
#include<libsoup/soup.h>

gchar* get_hash (gchar *str);

SoupBuffer* get_image (gchar *hash);

#endif
