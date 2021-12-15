#!/bin/sh

ARG=${1/;/\";\"}
ARG=${ARG/|/\"|\"}
t_diff.sh	"$1" "./aa $ARG"
