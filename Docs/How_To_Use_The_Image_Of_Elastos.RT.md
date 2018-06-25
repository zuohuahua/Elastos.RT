# How to use the image of Elastos.RT

For convenience, we provide an AWS AMI(Host image) that you can use it to start an online build environment(you need to pay for that cloud host), following blow steps:

1. Login and choose EC2 services

2. Click "instances" on left menu

3. Click "Launch Instance" on the left top

4. Click "Community AMIs" on left menu and input "Elastos" to search Elastos.RT image

5. Select "Elastos-RT" (ami-084f7d94d94bbe80d)

6. Choose an instance type (We recommond use compute optimized instance)

Then click "Review and Launch" on the bottom, and choose your SSH keys to start this instance.

Once you login your host with username `ubuntu`, you will find the "Elastos.RT" source code dirctory in your home. We have intalled all dependencies and build tools, you can refer [getting_started](./getting_started.md) to build `Elastos RT`.