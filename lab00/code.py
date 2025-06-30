def fizzbuzz(num):
    if num % 3 == 0 and num % 5 == 0:
        print(f"{num}: FizzBuzz")
    elif num % 3 == 0:
        print(f"{num}: Fizz")
    elif num % 5 == 0:
        print(f"{num}: Buzz")
    else:
        print(f"{num}")

for i in range(1, 20):
    fizzbuzz(i)
