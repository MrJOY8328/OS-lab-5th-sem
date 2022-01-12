echo "enter the value of a "
read a
for (( i=1;i<=10;i++ ))
do
    r=`expr $a \* $i`
    echo "$a x $i = $r"
done