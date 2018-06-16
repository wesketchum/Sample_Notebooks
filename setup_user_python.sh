#! /bin/sh

# W. Ketchum (wketchum@fnal.gov). Created 16 June 2018.
#
# Script to setup/initialize/install python utilities into a user area.
#
# This script assumes that you have the version of python you want set up
# properly. Typically this will mean the version automaticlly setup with
# the version of larsoft you are using. So setup larsoft first.
#

#print your version of python
your_python=$(which python)
echo "Using python from $your_python"

#create a python user area
#change this to be what you like, but this is probably a good default on gpvm
export PYTHONUSERBASE=/$EXPERIMENT/app/users/$USER/python_libs
mkdir -p $PYTHONUSERBASE

#add your python area to the path ... maybe this is done automatically, but
#I've had trouble in the past so just to be sure
export PYTHONPATH=$PYTHONUSERBASE/bin:$PYTHONPATH
export PATH=$PYTHONUSERBASE/bin:$PATH

#install the modules you want. These are the ones needed for the ROOT notebook.
#if they're already installed, it'll just print a bunch of stuff to tell you so
pip install --user jupyter metakernel zmq
