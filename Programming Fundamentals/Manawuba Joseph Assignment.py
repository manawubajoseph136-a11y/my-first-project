#loop for 10 student
for i in range (10):
    mark = int(input(f"Enter mark for student {i+1} grade:"))
    if 80 <=mark <=100:
         grade = 'A'
    elif 70 <= mark <= 79:
          grade = 'B'
    elif 60 <= mark <= 69:
          grade = 'C'
    elif 50 <= mark <= 59:
          grade = 'D'
    else:
         grade = 'F'
    print(f"student {i+1} grade:{grade}")