make || exit 1

tt.sh './aa /bin/echo'
tt.sh '/bin/echo 1'

tt.sh '/bin/echo 1 2 ; /bin/echo'
tt.sh '/bin/echo 3 ;'
tt.sh '; /bin/echo 4'
tt.sh '/bin/echo 5 ; ; /bin/echo 6 ;'
tt.sh '; /bin/echo 7 ; ; /bin/echo 8 ;'
tt.sh '/bin/sleep 1 ; /bin/echo 9'

tt.sh '/bin/ls . | /usr/bin/wc -w'
tt.sh '/usr/bin/seq 21 | /usr/bin/paste -s -d"*" - | /usr/bin/bc'
tt.sh '/bin/sleep 1 | /bin/echo 10'

tt.sh 'cd /usr/bin ; /bin/pwd'

tt.sh '/bin/ls | /usr/bin/grep aa ; /bin/echo i love my aa'
t_diff.sh 'echo "WOOT ; /bin/echo NOPE; ; ;\nYEAH"' \
          './aa /bin/echo WOOT "; /bin/echo NOPE;" "; ;" ";" /bin/echo YEAH'

t_diff.sh 'echo "error: cannot execute nothing"' './aa nothing  2>&1'
t_diff.sh 'echo "error: cannot execute main.c"' './aa main.c 2>&1'
