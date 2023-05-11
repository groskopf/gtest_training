FROM ubuntu:22.04

# Set locales
RUN apt-get update && apt-get install -y --no-install-recommends locales && \
    locale-gen en_US.UTF-8 && \
    update-locale LANG=en_US.UTF-8 \
    && apt-get autoclean && apt-get -y autoremove && rm -rf /var/lib/apt/lists/

RUN ln -fs /usr/share/zoneinfo/CET /etc/localtime

ENV LC_ALL en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US.UTF-8

# Install general packages
RUN apt-get update && apt-get install -y --no-install-recommends \
    vim \
    sudo \
    wget \
    && apt-get autoclean && apt-get -y autoremove && rm -rf /var/lib/apt/lists/

# Install packages specially need for sw developement
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    gcc-multilib \
    clang-format \
    clang-tidy \
    clangd \
    cmake \
    gdb \
    gdb-multiarch \
    git \
    gcovr \
    lcov \
    plantuml \
    ssh \
    && apt-get autoclean && apt-get -y autoremove && rm -rf /var/lib/apt/lists/

# Create the SW developer user
ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

# [Optional] Set the default user. Omit if you want to keep the default as root.
USER $USERNAME
RUN mkdir -p /home/${USERNAME}/.ssh

