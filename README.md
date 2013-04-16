get_gravatar
============

Gets the gravatar image based on an e-mail provided, using libsoup.

Depends on glib and libsoup. 
It is needed to have .pc files for those libs. You might need to install the dev version of the libraries to 
have those files by default.
Also, the folder where the .pc files are located must be in PKG_CONFIG_PATH.
(export PKG_CONFIG_PATH = /usr/lib/x86_64-linux-gnu/pkgconfig)

Compiling
=========

Just run make command.


Using 
=====

run ./get_gravatar email_address
