## LXD Terminal

LXD Terminal is a Developer Terminal that runs a system container on the desktop. This
allows the terminal itself to be fully confined and the underlying system to be
read-only. The system container itself can have anything you want installed in it, but
they are all separated from the rest of the system (both ways, depends on who you trust).

## Building

LXD Terminal is built with snapcraft. You can install that:

```
snap install --classic snapcraft
```

Then you can build LXD Terminal:

```
snapcraft
```

If you want to do so in your local system go with:

```
snapcraft --destructive-mode
```

## How it works

Really at it's core, LXD Terminal is just GNOME Terminal with a bunch of wrapper scripts
and minor customizations. All of the hard work has been done by the GNOME Terminal
developers and the LXD Developers, this just provides a connection between the two.

### First run

At first run the LXD Terminal creates a container that is connected into your desktop. It
is a full container, and you've got sudo rights, but there is also several sockets that
are bridged into the container.

 * X11, there is a DISPLAY variable set and you can run X apps in the container
 * Pulse Audio, the Pulse socket is bridged, so you can run audio apps in the container
 * LXD, if you want to manage LXD that socket is also bridged

Also your home directory is available at `~/host` so you can get files that are downloaded
from a webbrowser or edit files as you need to. **Note:** this means that programs
you install in the container can effect the files in your home directory, so still
be careful with what you install!

### Successive Runs

Now that the container is built the terminal just creates a login shell to the container
and you can do what ever you want. When you close all of the terminal windows the container
will be shutdown to save on resources.
