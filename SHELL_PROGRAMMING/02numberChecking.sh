num=(1 2 3 4 5 6)
for i in "${num[@]}"
do
	c=`expr $i % 2`
	if [ $c != 0 ]
	then
		echo "$i is odd number"
	else
		echo "$i is even number"
	fi
done