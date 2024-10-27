score = input('Enter the student''s score (0-100): ');
switch true
    case (score >= 90)
        grade = 'A';
    case (score >= 80)
        grade = 'B';
    case (score >= 70)
        grade = 'C';
    case (score >= 60)
        grade = 'D';
    otherwise
        grade = 'F';
end

fprintf('The grade is: %s\n', grade);