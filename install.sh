#!/bin/bash

# Drush executable.
[[ $DRUSH && ${DRUSH-x} ]] || DRUSH=drush

# Make sure at least one argument was provided.
if [ "$#" -eq 0 ]; then
  echo "Error: Mising destination directory name."
  exit 1
fi

SRCDIR=$(pwd -P)

drush make marketplace.make -y "$1"

ln -s $SRCDIR "$1/profiles/marketplace"
