FROM ARCHITECTURE/ubuntu:UBUNTU_RELEASE

COPY qemu-arm-static /usr/bin/
COPY qemu-aarch64-static /usr/bin/

RUN apt-get update -y; exit 0;
RUN apt-get install -y apt-utils; exit 0;
RUN apt-get upgrade -y; exit 0;

RUN apt-get install -y python python-pip python-dev git libssl-dev libffi-dev build-essential gdb git vim xterm x11-xserver-utils ruby-full bash-completion; exit 0;

RUN gem install one_gadget; exit 0;

RUN python -m pip install --upgrade pwntools; exit 0;

RUN apt-get install qemu qemu-system qemu-system-arm qemu-system-common qemu-system-x86 qemu-user qemu-user-static; exit 0;

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

