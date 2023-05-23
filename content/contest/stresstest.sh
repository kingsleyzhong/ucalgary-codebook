# stresstest.sh TEST_COUNT BRUTE.CPP OPTIMAL.CPP
# testcase.py should write to testcase.txt
# ADD LINE: sys.stdout = open("testcase.txt", "w")
n=$1
g++ $2 -o brute_executable
g++ $3 -o optimal_executable
# running loop for n times (N files)
for (( i=1; i<=n; ++i ))
do
  python testcase.py 
  ./brute_executable < testcase.txt > brute_out.txt
  ./optimal_executable < testcase.txt > optimal_out.txt
  if [[ $(diff brute_out.txt optimal_out.txt) ]]
  then
    echo "$(diff -Z brute_out.txt optimal_out.txt)" > difference_file.txt
    break
  else
    echo "Test $i passed"
  fi
done
echo "Done"