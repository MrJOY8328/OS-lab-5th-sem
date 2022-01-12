add()
{
    c=`expr $1 + $2`
    echo "sum:"$c
}

sub()
{
    c=`expr $1 - $2`
    echo "sub:"$c
}

mul()
{
    c=`expr $1 \* $2`
    echo "mul:"$c
}

div()
{
    c=`expr $1 / $2`
    echo "div:"$c
}


add 5 4
sub 5 4
mul 5 4
div 5 4



