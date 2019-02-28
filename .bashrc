#!/bin/bash
stty -ixon # Disable ctrl-s and ctrl-q.
shopt -s autocd #Allows you to cd into directory merely by typing the directory name.
HISTSIZE= HISTFILESIZE= # Infinite history.

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

alias ls='ls --color=auto'
PS1='\e[35m[ \w ]\e[0m '
#aliases
alias c='clear'
alias shutd='shutdown -h now'
alias sx='startx'
alias :q='exit'
alias v='vim'
alias sv='sudo vim'
alias xi='sudo xbps-install'		#-S -Su
alias xr='sudo xbps-remove'		#   -R
alias xq='sudo xbps-query' 		#-Rs
alias smci='sudo make clean install'
