# run from root of project 
# $1 is command, "init", "test"
# $2 is name of root directory
EXE="./Straights"
REFEXE="./straights"

if [ $1 ] && [ $1 == "init" ]
then
	if [ $2 ]
	then
		mkdir -p $2/tests
		mkdir -p $2/testout
		mkdir -p $2/refout
		mkdir -p $2/diff
	else
		mkdir -p tests
		mkdir -p testout
		mkdir -p refout
		mkdir -p diff
	fi
else
	# $1 specifies the executable e.g. ./executable.out
	if [ $1 ]
	then
		EXE=$1
	fi
	for file in ./tests/*
	do
		# $REFEXE $file > ./refout/$(basename $file).ref
		$REFEXE < $file > ./refout/$(basename $file).ref
	done

	for file in ./tests/*
	do
		echo "$file"
		# $EXE $file > ./testout/$(basename $file).out
		$EXE < $file > ./testout/$(basename $file).out
		if [ -f ./refout/$(basename $file).ref ]
		then
			diff ./testout/$(basename $file).out ./refout/$(basename $file).ref | xxd > ./diff/$(basename $file).dif
			echo `diff ./testout/$(basename $file).out ./refout/$(basename $file).ref`
			# cat ./diff/$(basename $file).dif
		else
			echo "Reference output for \"$(basename $file)\" does not exist in testout directory."
		fi			
	done
fi