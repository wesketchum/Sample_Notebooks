# Sample Notebooks

This is a set of example notebooks that do various things in ROOT and larsoft analysis (via gallery).
_All this is just playing around by W. Ketchum (wketchum@fnal.gov). No guarantees or anything, but you can always message me if you have questions or whatever._

These are mostly made using the ROOT kernel for jupyter notebooks. You can read a tiny bit about that here:
* https://root.cern.ch/how/how-create-rootbook
* https://root.cern.ch/how/how-use-root-notebook

## Setup

Typically, you want to setup the version of larsoft you will be using first. For MicroBooNE, that's something like:
```
source /cvmfs/uboone.opensciencegrid.org/products/setup_uboone.sh
setup uboonecode v06_80_02 -qe15:prof
```
Consult your experiment's documentation/local expert/slack channel for what you should do.

Then, you likely will need to add python modules beyond what comes in the pre-packaged version of python with larsoft. Often you may not have write access to the python install area, but you can instead setup a "user" area into which you can install what's needed. Note: this should work for all different kinds of python modules, not just what's done here.

You can do that setup blindly by executing the setup script included:
```
source setup_user_python.sh
```

### Details on setup
Want to know what that does? First it creates and sets the paths for a user area:
```
#create a python user area
#change this to be what you like, but this is probably a good default on gpvm
export PYTHONUSERBASE=/$EXPERIMENT/app/users/$USER/python_libs
mkdir -p $PYTHONUSERBASE

#add your python area to the path ... maybe this is done automatically, but
#I've had trouble in the past so just to be sure
export PYTHONPATH=$PYTHONUSERBASE/bin:$PYTHONPATH
export PATH=$PYTHONUSERBASE/bin:$PATH
```

Then for running ROOT notebooks, you will need to make sure Jupyter, Metakernel, and ZMQ are installed. Do this:

```
#install the modules you want. These are the ones needed for the ROOT notebook.
#if they're already installed, it'll just print a bunch of stuff to tell you so
pip install --user jupyter metakernel zmq
```

## Starting the ROOT notebook
In the directory where you have your notebooks, do the following:
```
root --notebook
```

OK, when you do that, you should see an output like:
```
[I 17:33:53.217 NotebookApp] Serving notebooks from local directory: ***
[I 17:33:53.217 NotebookApp] 0 active kernels
[I 17:33:53.217 NotebookApp] The Jupyter Notebook is running at:
[I 17:33:53.217 NotebookApp] http://localhost:8888/?token=e393f2b1f6145dffa5a2958ba5112bcd203ddd20bd5263f7
```

Also, it will try to start a browser locally. Just exit out of it as soon as it pops up unless you want to use a browser over the connection. If not, move on to setting up the port forwarding.

## Port forwarding
Note the port number in that link in the above example: it's 8888. Then, from your machine, do something like:
```
ssh -L localhost:8888:localhost:8888 <remote_machine>.fnal.gov
```
Where the 8888 matches the port number, and <remote_machine> is the gpvm or whatever you started the notebook from. Then, copy the link from the ROOT notebook start into your local browser (it contains a token to authenticate that you have write access to that area), and you should see the notebook area in a nice browsable format!

## Using the notebooks
Walk through some of the examples a bit, and lookup online for more information on ROOT, PyROOT, notebookes, and the like. 

Have fun!
