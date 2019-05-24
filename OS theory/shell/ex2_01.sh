#!binbash
echo Enter the 'num1 operator num2'
read calc_string
expr $calc_string
unset calc_string
