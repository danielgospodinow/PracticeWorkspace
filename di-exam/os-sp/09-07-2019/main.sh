# start the script with arguments 'ab cd ef gh'
# when asked to input two numbers, input '3 1'

grep `head  -1 f1` `tail -1 f1` | wc -l > f2
a=`cat f2`
echo $a $3
set  9  7  5  3
shift 2
for j in 1  2  3  4  5
do for i
  do
  if test $a -lt $i
    then cat f1 f2 > f3
      wc -l f3
      echo $i  $j  $a >> f4 
    else tee f2 f3 < f1
      wc -w f2
      echo $i  $j  $a >> f4
    fi
  done
  echo $# >> f4
  break
done
read key1 key2
while cat f4 | grep $key2
do sort f4
  a=`wc -c < f4`
  echo -n "Character count: $a"
  exit
done
grep $key1 f4
b=`wc -l < f4`
echo -n "Lines count: $b"

#Output:

#4 ef
#2 f3
#line
#x12 f2
#3 1 (this is the input from the command line)
#5 1 4
#3 1 4
#2
#3 1 4
#5 1 4
#Character count: 14