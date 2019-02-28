#!/usr/bin/env bash

# Description: Check and update to latest version of nnn manually on Debian 9 Stretch
#
# Shell: bash
# Author: Arun Prakash Jana
# NOTE: This script installs a package, should be issued with admin privilege

cur=`nnn -v`
new=`curl -s "https://github.com/jarun/nnn/releases/latest" | grep -Eo "[0-9]+\.[0-9]+"`

if [ $cur_ver == $new_ver ]; then
    echo 'Already at latest version'
    exit 0
fi

# get the package
wget "https://github.com/jarun/nnn/releases/download/v$new/nnn_$new-1_debian9.amd64.deb"

# install it
dpkg -i nnn_$new-1_debian9.amd64.deb

# remove the file
rm -rf nnn_$new-1_debian9.amd64.deb