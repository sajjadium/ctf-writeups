FROM ubuntu:UBUNTU_RELEASE

RUN apt-get update --fix-missing -y; exit 0;
RUN apt-get install -y apt-utils; exit 0;
RUN apt-get upgrade -y; exit 0;

RUN apt-get install -y python python-pip python-dev git libssl-dev libffi-dev build-essential gdb git vim xterm x11-xserver-utils ruby-full bash-completion bsdmainutils ruby-dev sudo wget; exit 0;

RUN apt-get install -y gdb-multiarch; exit 0;
RUN apt-get install -y gcc-arm-linux-gnueabihf; exit 0;
RUN apt-get install -y gdb-arm-none-eabi; exit 0;
RUN apt-get install -y binfmt*; exit 0;

RUN apt-get install -y qemu; exit 0;
RUN apt-get install -y qemu-user; exit 0;
RUN apt-get install -y qemu-user-static; exit 0;
RUN apt-get install -y libc6-arm64-cross; exit 0;
RUN apt-get install -y libc6-armhf-cross; exit 0;

RUN mkdir /etc/qemu-binfmt;
RUN ln -s /usr/arm-linux-gnueabihf/ /etc/qemu-binfmt/arm;
RUN ln -s /usr/aarch64-linux-gnu/ /etc/qemu-binfmt/aarch64;

RUN gem install one_gadget; exit 0;

RUN python -m pip install --upgrade pwntools;

RUN echo "set tabstop=4\nset autoindent\nset shiftwidth=4\nset expandtab" >> /etc/vim/vimrc;
RUN echo "xterm*faceName: Monospace\nxterm*faceSize: 18\nxterm*background: black\nxterm*foreground: green" > ~/.Xresources
RUN echo "xrdb -merge ~/.Xresources" >> ~/.bashrc
RUN echo ". /etc/bash_completion" >> ~/.bashrc
RUN echo "if [ ! -f /proc/sys/fs/binfmt_misc/register ]; then" >> ~/.bashrc
RUN echo "    mount binfmt_misc -t binfmt_misc /proc/sys/fs/binfmt_misc" >> ~/.bashrc
RUN echo "fi" >> ~/.bashrc

RUN git clone https://github.com/pwndbg/pwndbg;
RUN cd pwndbg; ./setup.sh; exit 0;

RUN python3 -m pip install capstone ropper; exit 0;

RUN export COLUMNS=`tput cols`
RUN export LINES=`tput lines`

ENV COLUMNS $COLUMNS
ENV LINES $LINES

WORKDIR /ctf

