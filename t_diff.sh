#!/bin/zsh

diff	<(eval $1) <(eval $2) \
	&& [ ${pipestatus[1]} -eq 0 ] && echo 'ok!' \
	|| echo -e "------------\nFailed command: $1\n============"
