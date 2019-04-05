FROM ubuntu:UBUNTU_RELEASE

RUN apt-get update --fix-missing -y; exit 0;
RUN apt-get install -y apt-utils; exit 0;
RUN apt-get upgrade -y; exit 0;

RUN apt-get install -y python python-pip python-dev git libssl-dev libffi-dev build-essential gdb git vim xterm x11-xserver-utils ruby-full bash-completion;

RUN gem install one_gadget;

RUN python -m pip install --upgrade pwntools;

RUN apt-get install qemu qemu-user qemu-user-static;

RUN echo "set tabstop=4\nset autoindent\nset shiftwidth=4\nset expandtab" >> /etc/vim/vimrc;
RUN echo "xterm*faceName: Monospace\nxterm*faceSize: 18\nxterm*background: black\nxterm*foreground: green" > ~/.Xresources
RUN echo "xrdb -merge ~/.Xresources" >> ~/.bashrc
RUN echo ". /etc/bash_completion" >> ~/.bashrc

RUN git clone https://github.com/pwndbg/pwndbg;
RUN cd pwndbg; ./setup.sh; exit 0;

RUN export COLUMNS=`tput cols`
RUN export LINES=`tput lines`

ENV COLUMNS $COLUMNS
ENV LINES $LINES

WORKDIR /ctf

