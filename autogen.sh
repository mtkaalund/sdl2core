#!/bin/bash

libtoolize --copy
aclocal
autoheader
automake --add-missing
autoconf
