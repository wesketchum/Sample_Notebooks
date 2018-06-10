# Sample_Notebooks

This is a set of my notebooks that do various things in ROOT and larsoft analysis (via gallery).

They're mostly made using the ROOT kernel for jupyter notebooks. You can see a tiny bit about that here:
https://root.cern.ch/how/how-create-rootbook
https://root.cern.ch/how/how-use-root-notebook

Here is what I do to set things up on a uboonegpvm:

#setup your desired uboonecode. Here, let's say v06_79_00
source /cvmfs/uboone.opensciencegrid.org/products/setup_uboone.sh
setup uboonecode v06_79_00 -qe15:prof

#create a python libs area to install your personal python products
#Note, if you don't need to install anything additional, you can point to mine
export PYTHONUSERBASE=/uboone/app/users/wketchum/python_libs
mkdir -p $PYTHONUSERBASE
export PYTHONPATH=$PYTHONUSERBASE/bin:$PYTHONPATH
export PATH=$PYTHONUSERBASE/bin:$PATH

#then, if you need* to install python libraries, do so like this:
# *that is, you're not using my area!
pip install --user jupyter metakernel zmq

#then, go to where you want to set up a notebook area (I'd recommned a new dir), and do
root --notebook

OK, when you do that, you should see an output like:
[I 17:33:53.217 NotebookApp] Serving notebooks from local directory: ***
[I 17:33:53.217 NotebookApp] 0 active kernels
[I 17:33:53.217 NotebookApp] The Jupyter Notebook is running at:
[I 17:33:53.217 NotebookApp] http://localhost:8888/?token=e393f2b1f6145dffa5a2958ba5112bcd203ddd20bd5263f7

Also, it will try to start a browser locally. Just exit out of it as soon as it pops up unless you want to use a browser over the connection. If not, we'll set up port forwarding.

To do that, note the port number in that link! in the above example, that's 8888. Then, from your machine, do something like:

ssh -L localhost:8888:localhost:8888 uboonegpvm04.fnal.gov

Where the 8888 matches the port number, and you connect to the gpvm you started the notebook from. Then, copy the link above into your local browser, and you should see the notebook area!

