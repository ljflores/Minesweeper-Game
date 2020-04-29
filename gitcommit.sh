#!/bin/bash
echo "This is James's getcommit tool for OOSD final project"
echo "What would you like your comment to be for your commit"
read mycomment
git pull origin master
git add --all
git commit -m "$mycomment"
git push origin master
