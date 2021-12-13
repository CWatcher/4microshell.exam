#!/bin/zsh

ARG=${1/;/\";\"}
diff <(eval $1) <(eval ./aa ${ARG/|/\"|\"}) \
	&& [ ${pipestatus[1]} -eq 0 ] && echo 'ok!' \
	|| echo -e "------------\nFailed command: $1\n============"
