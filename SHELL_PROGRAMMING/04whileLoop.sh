echo "enter the value of a "
read a
while [ $a -lt 11 ]
do
    echo "$a"
    a=`expr $a + 1`
done