#!/bin/bash

read -p "commit message" cmessage

git commit -m "$cmessage"

git push
