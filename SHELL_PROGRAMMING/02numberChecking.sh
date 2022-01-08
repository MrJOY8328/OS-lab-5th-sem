read  a
read  b

add=`expr $a + $b`
echo "Addition of a and b are" $add

sub=`expr $a - $b`
echo "Subtraction of a and b are" $sub

mul = $((a * b))
echo Multiplication of a and b are $mul

div = $((a / b))
echo division of a and b are $div

mod = $((a % b))
echo Modulus of a
	and b are $mod

	((++a))
echo Increment
		operator when applied on "a" results into a = $a

	((--b))
echo Decrement
		operator when applied on "b" results into b = $b
