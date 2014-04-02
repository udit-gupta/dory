rm -rf outputs
mkdir outputs
for OUTPUT in $(ls test/in*)
do
	echo  "Processing file $OUTPUT"
	./demo $OUTPUT >  outputs/${OUTPUT/test\/in/out}
done

for OUTPUT in $(ls outputs/out*)
do
	echo "Processing output file $OUTPUT"
	diff -w ${OUTPUT/outputs/test} $OUTPUT
done
