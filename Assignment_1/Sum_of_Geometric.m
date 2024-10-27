a = input('Enter the value of a (first term): ');
r = input('Enter the value of r (common ratio): ');
n = input('Enter the value of n (number of terms): ');

S = 0;
i = 0;

while i <= n
    S = S + a * r^i;
    i = i + 1;
end

fprintf('The sum of the geometric series is: %.2f\n', S);