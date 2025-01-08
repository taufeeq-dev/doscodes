#!/bin/bash

# Input marks for 5 subjects
echo "Enter marks for 5 subjects:"
read -a marks

# Calculate total and percentage
total=0
for mark in "${marks[@]}"; do
  total=$((total + mark))
done

percentage=$((total / 5))

# Determine the division
if [ $percentage -ge 60 ]; then
  echo "First division"
elif [ $percentage -ge 50 ]; then
  echo "Second division"
elif [ $percentage -ge 40 ]; then
  echo "Third division"
else
  echo "Fail"
fi
