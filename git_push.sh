#!/bin/sh
git init
git add .
git commit -m 'Linux java connect c'
#git remote add origin git@github.com:acanoe/androidmanager.git
git config --global user.email "imcanoe@gmail.com"
git config --global user.name "acanoe"
git push -f git@github.com:acanoe/c_connect_java.git master 
