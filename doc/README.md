==== Installing interception-tools
This is how I installed
https://gitlab.com/interception/linux/tools[interception tools]
on my laptop, which runs Debian 9 Stretch.

Methods for other linux distributions will vary.

Some packages installed below, may be unnecessary for a minimal install.

[source, bash]
----
sudo apt-get install gcc libevdev-dev libinput-dev git binutils make csh g++ \
sed gawk autoconf automake autotools-dev checkinstall libudev-dev cmake \
libyaml-cpp-dev clang
git clone https://gitlab.com/interception/linux/tools.git /tmp/interception-tools
cd /tmp/interception-tools
cmake ./
make
sudo checkinstall -D --install=no --fstrans \
--requires=libudev-dev,cmake,libyaml-cpp-dev,clang \
--pkgname=interception-tools --pkglicense=GPLv3 \
--pkgsource=https://gitlab.com/interception/linux/tools \
--pakdir=/tmp --nodoc --pkgversion=1.0
sudo apt-get install /tmp/interception-tools_1.0-1_amd64.deb
----

==== Installing keydom

Now that interception-tools is installed, 
keydom can be installed by running:

[source, bash]
---
git clone https://github.com/plexal/keydom.git
cd ./keydom
sudo make install
---
