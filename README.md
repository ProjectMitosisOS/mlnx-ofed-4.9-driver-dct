# mlnx-ofed-4.9-driver-dct

This is our extension to the MLNX-OFED-4.9 driver,
aiming to support dynamic connected transport in the **kernel-space** RDMA driver. 

Tested platform:
- Software: ubuntu
- Hardware: ConnectX-4 NIC

## Steps for build (Take ubuntu16.04 as an example)

First, we need the original driver, and install the default version on our machine. 

```shell
wget https://www.mellanox.com/downloads/ofed/MLNX_OFED-4.9-3.1.5.0/MLNX_OFED_LINUX-4.9-3.1.5.0-ubuntu16.04-x86_64.tgz
tar zxf MLNX_OFED_LINUX-4.9-3.1.5.0-ubuntu16.04-x86_64.tgz
cd MLNX_OFED_LINUX-4.9-3.1.5.0-ubuntu16.04-x86_64 
sudo ./mlnxofedinstall
sudo /etc/init.d/openibd restart
```
Then, reboot your machine if no error prints.
```shell
sudo reboot -n
```

Afterwards, we can build our  patch. Assuming we are in directory `MLNX_OFED_LINUX-4.9-3.1.5.0-ubuntu16.04-x86_64` (see the first step). 

```
cd src
tar zxf MLNX_OFED_SRC-4.9-3.1.5.0.tgz
mv MLNX_OFED_SRC-4.9-3.1.5.0/SOURCES/mlnx-ofed-kernel_4.9.orig.tar.gz PATH-to-REPO.
 cd $PATH-to-REPO$
./build.sh
```

Run `./build.sh`, and follows the steps prompted by the commandline.
ps: if the commandline prompts the patch name, than type any name is ok.


## Trouble shooting
What if `ib_dc_wr` is not found? 
- Please remove `/usr/src/ofa_kernel/default` (i.e. `sudo rm -rf /usr/src/ofa_kernel/default`), and reinstall the patch. 
