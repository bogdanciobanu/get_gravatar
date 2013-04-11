#include "get_gravatar.h"
#include<stdio.h>

int main(int argc, char **argv)
{
    g_type_init();
    gchar *email, *hash;
    SoupBuffer *response;

    FILE *outputfile=fopen("avatar", "wb");
    if(!outputfile)
    {
        printf("Error trying to open file.");
        return -1;
    }

    hash = get_hash(argv[1]);
    response = get_image(hash);
    fwrite(response->data, 1, response->length, outputfile);

    return 0;
}
