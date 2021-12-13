make || exit 1

tt.sh './aa /bin/echo'
tt.sh '/bin/echo 1'

tt.sh '/bin/echo 1 ; /bin/echo 2'
tt.sh '/bin/echo 3 ;'
tt.sh '; /bin/echo 4'
tt.sh '/bin/echo 5 ; ; /bin/echo 6'

tt.sh '/bin/echo a | /usr/bin/wc -w'
tt.sh '/bin/echo a b | /usr/bin/wc -w | /usr/bin/sed'
tt.sh '/bin/echo 6 | /bin/cat'

tt.sh 'cd / ; /bin/pwd'

tt.sh '/bin/ls | /usr/bin/grep aa ; /bin/echo i love my aa'
tt.sh '/bin/echo WOOT ; /bin/echo NOPE; ; ; ; /bin/echo YEAH'

./aa asdf
./aa main.c
