#!/bin/zsh

diff	<(eval $1 ; echo 'seconds' $SECONDS) \
		<(SECONDS=0 ; eval $2 ; echo 'seconds' $SECONDS) \
	&& [ ${pipestatus[1]} -eq 0 ] && echo 'ok!' \
	|| echo -e "------------\nFailed command: $1\n============"
