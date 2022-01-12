
echo "Please talk to me ..."
while :
do
    echo "enter your choice"
    echo "1 print calender"
    echo "2 print date"
    read INPUT
    case $INPUT in
	    1)
		    cal 2022
		    ;;
	    2)
		    date
		    ;;
	    *)
		    break
		    ;;
    esac
done