#!/bin/bash

# Check if the number is provided as an argument
if [ $# -eq 0 ]; then
  echo "Usage: $0 <number>"
  exit 1
fi

# Read the number
n=$1
factorial=1

# Calculate factorial
for (( i=1; i<=n; i++ ))
do
  factorial=$((factorial * i))
done

# Output the result
echo "Factorial of $n is $factorial"
